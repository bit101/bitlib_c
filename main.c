#include <gtk/gtk.h>
#include "drawing.h"

int main(int argc, char **argv) {
  cairo_surface_t *surface;
  cairo_t *cr;
  
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 800, 800);
  cr = cairo_create(surface);
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_set_line_width(cr, 0.5);


  cairo_fill_rectangle(cr, 10, 10, 100, 100);

  cairo_line(cr, 105, 400, 405, 100);
  cairo_line_through(cr, 100, 400, 400, 100, 50);

  for (double i = 0.0; i < G_PI * 2; i += 0.1) {
    cairo_ray(cr, 400, 400, i, 0, 100);
  }

  cairo_stroke_round_rectangle(cr, 300, 300, 200, 200, 20);
  cairo_stroke(cr);
  
  cairo_fill_circle(cr, 600, 600, 100);

  cairo_surface_write_to_png(surface, "out.png");

  return 0;
}

