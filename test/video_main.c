#include <cairo.h>
#include <glib.h>
#include <math.h>
#include "bitlib.h"

#define WIDTH 1280
#define HEIGHT 720
#define FRAME_COUNT 60
#define FPS 30
#define OUT_NAME "out.mp4"

void render(cairo_t *cr, double percent) {
  double p = bl_lerp_sin(percent, 0, 1);
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_translate(cr, WIDTH / 2, HEIGHT / 2);
  cairo_rotate(cr, -p * G_PI);
  cairo_scale(cr, p, p);
  cairo_fill_rectangle(cr, -200, -200, 400, 400);
}

int main(int argc, char **argv) {
  bl_render_video(WIDTH, HEIGHT, FRAME_COUNT, FPS, OUT_NAME, render);
  bl_vlc(OUT_NAME);
  return 0;
}

