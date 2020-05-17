#include "render.h"
#include "anim.h"
#include "bitlib.h"
#include <glib.h>
#include <stdio.h>
#include <unistd.h>

void bl_render_gif(bl_anim *anim, char *gif_name, int threads,
                   bl_anim_callback render) {
  char template[] = "/tmp/frames.XXXXXX";
  char *tmp = mkdtemp(template);
  _render_anim(anim, gif_name, render, tmp, threads);

  g_print("compiling gif from frames...\n");
  _convert_frames_to_gif(tmp, gif_name, anim->fps);
  rmdir(tmp);
}

void bl_render_video(bl_anim *anim, char *mp4_name, int threads,
                     bl_anim_callback render) {
  char template[] = "/tmp/frames.XXXXXX";
  char *tmp = mkdtemp(template);
  _render_anim(anim, mp4_name, render, tmp, threads);

  g_print("compiling video from frames...\n");
  _convert_frames_to_video(anim, tmp, mp4_name, anim->fps);
  rmdir(tmp);
}

void bl_render_image(double width, double height, char *png_file_name,
                     bl_image_callback render) {
  cairo_surface_t *surface =
      cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t *cr = cairo_create(surface);
  render(cr);
  cairo_surface_write_to_png(surface, png_file_name);
}
