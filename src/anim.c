#include "anim.h"
#include "bitlib.h"
#include <glib.h>
#include <stdio.h>
#include <time.h>

typedef struct _render_props {
  bl_anim *anim;
  int start_frame;
  int end_frame;
  char *tmp;
  bl_anim_callback render;
} render_props;

bl_anim *bl_make_anim(double width, double height, double frames, double fps) {
  bl_anim *anim = malloc(sizeof(bl_anim));
  anim->width = width;
  anim->height = height;
  anim->frames = frames;
  anim->fps = fps;
  return anim;
}

render_props *_make_render_props(bl_anim *anim, int start_frame, int end_frame,
                                 char *tmp, bl_anim_callback render) {
  render_props *props = malloc(sizeof(render_props));
  props->anim = anim;
  props->start_frame = start_frame;
  props->end_frame = end_frame;
  props->tmp = tmp;
  props->render = render;
  return props;
}

void *_thread_render_anim(void *arg) {
  render_props *props = (render_props *)arg;
  bl_anim *anim = props->anim;
  static double done = 0;
  char frame_name[255];
  int last_frame = fmin(anim->frames, props->end_frame);

  cairo_surface_t *surface = cairo_image_surface_create(
      CAIRO_FORMAT_ARGB32, anim->width, anim->height);

  for (int i = props->start_frame; i < last_frame; i++) {
    double percent = (double)i / anim->frames;
    cairo_t *cr = cairo_create(surface);

    props->render(cr, percent);
    cairo_destroy(cr);

    sprintf(frame_name, "%s/frame_%.4d.png", props->tmp, i);
    cairo_surface_write_to_png(surface, frame_name);

    done++;
    g_print("\r%f", done / anim->frames);
  }
  free(props);
}

void _render_anim(bl_anim *anim, char *gif_name, bl_anim_callback render,
                  char *tmp, int num_threads) {
  pthread_t threads[num_threads];
  printf("rendering on %d threads\n", num_threads);
  time_t start_time = time(NULL);
  for (int i = 0; i < num_threads; i++) {
    int start = 0;
    int end = anim->frames;
    if (num_threads > 1) {
      int batch = (int)anim->frames / num_threads;
      start = batch * i;
      end = start + batch;
    }
    render_props *props = _make_render_props(anim, start, end, tmp, render);
    pthread_create(&threads[i], NULL, _thread_render_anim, props);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
  time_t end_time = time(NULL);
  time_t elapsed = end_time - start_time;
  double spf = (double)elapsed / anim->frames;
  g_print("\n%d frames in %d seconds. %f seconds per frame\n",
          (int)anim->frames, elapsed, spf);
}

void _convert_frames_to_video(bl_anim *anim, char *frames_dir, char *file_name,
                              double fps) {
  char command[255];

  /* apparently optimized for youtube? todo: research settings. */
  sprintf(command,
          "ffmpeg -framerate %f -i %s/frame_%%04d.png -s:v %dx%d -c:v libx264 "
          "-profile:v high -crf 20 -pix_fmt yuv420p -v 0 -y %s",
          fps, frames_dir, (int)anim->width, (int)anim->height, file_name);

  system(command);
}

void _convert_frames_to_gif(char *frames_dir, char *file_name, double fps) {
  char command[255];
  double delay = bl_round_to(1000.0 / fps / 10.0, 4);
  sprintf(command, "convert -delay %f -layers Optimize %s/*png %s", delay,
          frames_dir, file_name);
  system(command);
}
