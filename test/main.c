#include <gtk/gtk.h>
#include <math.h>
#include "bitlib.h"

#define WIDTH 800
#define HEIGHT 800

void render(cairo_surface_t *surface, cairo_t *cr) {
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_set_line_width(cr, 0.5);

  point_list *path = make_point_list();
  for (int i = 0; i < 100; i++) {
    add_point(path, random_point(0, 0, 400, 400));
  }
  cairo_stroke_path(cr, path, 0);
  cairo_translate(cr, 400, 0);
  cairo_stroke_path(cr, path, 0);
  cairo_translate(cr, 0, 400);
  cairo_stroke_path(cr, path, 0);
  cairo_translate(cr, -400, 0);
  cairo_stroke_path(cr, path, 0);
}

int main(int argc, char **argv) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
  cairo_t *cr = cairo_create(surface);

  render(surface, cr);

  cairo_surface_write_to_png(surface, "out.png");
  return 0;
}

