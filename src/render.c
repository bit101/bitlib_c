#include <gtk/gtk.h>
#include "bitlib.h"
#include "render.h"

void bl_render_anim( double width, double height, double frames, double fps, char *gif_name, void (*render)(cairo_t *cr, double percent)){
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

  bl_convert_frames_to_gif("_frames", "out.gif", fps, true);
  system("rm -rf _frames");
}

void bl_render_image(double width, double height, char *png_file_name, void (*render)(cairo_t *cr)) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t *cr = cairo_create(surface);
  render(cr);
  cairo_surface_write_to_png(surface, png_file_name);
}


void bl_convert_frames_to_gif(char *frames_dir, char *file_name, double fps, bool optimize) {
  char command[255];
  double delay = bl_round_to(1000.0 / fps / 10.0, 4);
  if (optimize) {
    sprintf(command, "convert -delay %f -layers Optimize %s/*png %s", delay, frames_dir, file_name);
  }
  else {
    sprintf(command, "convert -delay %f %s/*png %s", delay, frames_dir, file_name);
  }
  system(command);
}

void bl_view_image(char *file_name) {
  char command[255];
  sprintf(command, "eog %s", file_name);
  system(command);
}
