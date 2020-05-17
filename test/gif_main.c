#include "bitlib.h"
#include <cairo.h>
#include <glib.h>
#include <math.h>

#define WIDTH 400
#define HEIGHT 400
#define FRAME_COUNT 600
#define FPS 30
#define OUT_NAME "out.gif"

void render(cairo_t *cr, double percent) {
  double p = bl_lerp_sin(percent, 0, 1);
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_translate(cr, WIDTH / 2, HEIGHT / 2);
  cairo_rotate(cr, -p * G_PI);
  cairo_scale(cr, p, p);
  cairo_fill_rectangle(cr, -200, -200, 400, 400);
}

int main(int argc, char **argv) {
  bl_anim *anim = bl_make_anim(WIDTH, HEIGHT, FRAME_COUNT, FPS);
  bl_render_gif(anim, OUT_NAME, 4, render);
  free(anim);
  bl_view_image(OUT_NAME);
  return 0;
}
