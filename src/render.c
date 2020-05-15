#include <cairo.h>
#include <glib.h>
#include <stdio.h>
#include "bitlib.h"
#include "render.h"


void render_anim( double width, double height, double frames, double fps, bl_anim_callback render) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  char frame_name[255];
  system("mkdir -p _frames");
  system("rm -f _frames/*");

  for (int i = 0; i < frames; i++) {
    double percent = (double)i / frames;
    g_print("\r%.0f%%", (double)(i + 1) / frames * 100);

    cairo_t *cr = cairo_create(surface);
    render(cr, percent);
    cairo_destroy(cr);

    sprintf(frame_name, "_frames/frame_%.4d.png", i);
    cairo_surface_write_to_png(surface, frame_name);
  }
  g_print("\n");

}

void bl_render_gif( double width, double height, double frames, double fps, char *gif_name, bl_anim_callback render) {
  render_anim(width, height, frames, fps, render);
  bl_convert_frames_to_gif("_frames", gif_name, fps);
  system("rm -rf _frames");
}

void bl_render_video( double width, double height, double frames, double fps, char *mp4_name, void (*render)(cairo_t *cr, double percent)){
  render_anim(width, height, frames, fps, render);
  bl_convert_frames_to_video("_frames", mp4_name, fps);
  system("rm -rf _frames");
}

void bl_render_image(double width, double height, char *png_file_name, bl_image_callback render) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t *cr = cairo_create(surface);
  render(cr);
  cairo_surface_write_to_png(surface, png_file_name);
}

void bl_convert_frames_to_gif(char *frames_dir, char *file_name, double fps) {
  char command[255];
  double delay = bl_round_to(1000.0 / fps / 10.0, 4);
  sprintf(command, "convert -delay %f -layers Optimize %s/*png %s", delay, frames_dir, file_name);
  system(command);
}

void bl_convert_frames_to_video(char *frames_dir, char *file_name, double fps) {
  char command[255];

  /* apparently optimized for youtube? todo: research settings. */
  sprintf(command, "ffmpeg -framerate %f -i %s/frame_%%04d.png -s:v 1280x720 -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p -v 0 -y %s", fps, frames_dir, file_name);

  system(command);
}

void bl_view_image(char *file_name) {
  char command[255];
  sprintf(command, "eog %s", file_name);
  system(command);
}

void bl_vlc(char *file_name) {
  char command[255];
  sprintf(command, "vlc --verbose 0 %s", file_name);
  system(command);
}
