#include <gtk/gtk.h>
#include <math.h>
#include "bitlib.h"

#define WIDTH 800
#define HEIGHT 800

void render(cairo_surface_t *surface, cairo_t *cr) {
  cairo_clear_color(cr, bl_color_red());
  cairo_set_line_width(cr, 0.5);

  cairo_fractal_line(cr, 0, 400, 800, 400, 0.6, 10);
  cairo_line_to(cr, 800, 800);
  cairo_line_to(cr, 0, 800);
  cairo_fill(cr);

  cairo_set_source_rgba(cr, 1, 1, 0, 0.5);
  cairo_fill_heart(cr, 400, 400, 300, 300, 0); 


  cairo_set_source_rgba(cr, 0, 1, 0, 0.5);
  cairo_grid(cr, 0, 0, 800, 800, 50, 50);

}

int main(int argc, char **argv) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
  cairo_t *cr = cairo_create(surface);

  render(surface, cr);

  cairo_surface_write_to_png(surface, "out.png");
  return 0;
}

