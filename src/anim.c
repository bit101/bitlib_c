#include "anim.h"
#include <glib.h>
#include <stdio.h>
#include <time.h>
#include "bitlib.h"
#include "render.h"

typedef struct _render_props {
  bl_render_config* config;
  int start_frame;
  int end_frame;
  char* tmp;
  bl_render_callback render;
} render_props;

bl_render_config* bl_make_render_config(double width, double height, double frames, double fps) {
  bl_render_config* config = malloc(sizeof(bl_render_config));
  config->width = width;
  config->height = height;
  config->frames = frames;
  config->fps = fps;
  return config;
}

render_props* _make_render_props(bl_render_config* config,
                                 int start_frame,
                                 int end_frame,
                                 char* tmp,
                                 bl_render_callback render) {
  render_props* props = malloc(sizeof(render_props));
  props->config = config;
  props->start_frame = start_frame;
  props->end_frame = end_frame;
  props->tmp = tmp;
  props->render = render;
  return props;
}

void* _thread_render_frames(void* arg) {
  render_props* props = (render_props*)arg;
  bl_render_config* config = props->config;
  static double done = 0;
  char frame_name[255];
  int last_frame = fmin(config->frames, props->end_frame);

  cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, config->width, config->height);

  for (int i = props->start_frame; i < last_frame; i++) {
    double percent = (double)i / config->frames;
    cairo_t* cr = cairo_create(surface);

    props->render(cr, percent);
    cairo_destroy(cr);

    sprintf(frame_name, "%s/frame_%.4d.png", props->tmp, i);
    cairo_surface_write_to_png(surface, frame_name);

    done++;
    char* bl_quiet = getenv("BL_QUIET");
    if (bl_quiet == NULL || strcmp(bl_quiet, "1")) {
      g_print("\r%f", done / config->frames);
    }
  }
  free(props);
}

void _render_frames(bl_render_config* config, char* gif_name, bl_render_callback render, char* tmp, int num_threads) {
  pthread_t threads[num_threads];
  char* bl_quiet = getenv("BL_QUIET");
  if (bl_quiet == NULL || strcmp(bl_quiet, "1")) {
    g_print("rendering on %d threads\n", num_threads);
  }
  time_t start_time = time(NULL);
  for (int i = 0; i < num_threads; i++) {
    int start = 0;
    int end = config->frames;
    if (num_threads > 1) {
      int batch = (int)config->frames / num_threads;
      start = batch * i;
      end = start + batch;
    }
    render_props* props = _make_render_props(config, start, end, tmp, render);
    pthread_create(&threads[i], NULL, _thread_render_frames, props);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
  time_t end_time = time(NULL);
  time_t elapsed = end_time - start_time;
  double spf = (double)elapsed / config->frames;
  if (bl_quiet == NULL || strcmp(bl_quiet, "1")) {
    g_print("\n%d frames in %d seconds. %f seconds per frame\n", (int)config->frames, elapsed, spf);
  }
}

void _convert_frames_to_video(bl_render_config* config, char* frames_dir, char* file_name, double fps) {
  char command[255];

  // -framerate fps
  // -i input - the frames
  // -s:v size for video stream - wxh
  // -c:v codec for video stream
  // -profile:v H.264 profile for video
  // -crf constant rate factor (0-51: 0 = lossless, 23 = default, 51 = potato)
  // -pix_fmt pixel format - not sure how important this is
  // -v logging verbosity - shut up
  // -y overwrite existing file
  sprintf(command,
          "ffmpeg -framerate %f -i %s/frame_%%04d.png -s:v %dx%d -c:v libx264 "
          "-profile:v high -crf 20 -pix_fmt yuv420p -v 0 -y %s",
          fps, frames_dir, (int)config->width, (int)config->height, file_name);

  system(command);
}

void _convert_frames_to_gif(char* frames_dir, char* file_name, double fps) {
  char command[255];
  double delay = bl_round_to(1000.0 / fps / 10.0, 4);
  sprintf(command, "convert -delay %f -layers Optimize %s/*png %s", delay, frames_dir, file_name);
  system(command);
}
