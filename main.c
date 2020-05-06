#include <gtk/gtk.h>
#include <math.h>
#include "point.h"
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
  cairo_stroke_ellipse(cr, 600, 600, 150, 200);

  g_random_set_seed(time(0));
  point *path;
  path = make_point(g_random_double_range(0, 800), g_random_double_range(0, 800));
  for (int i = 1; i < 10; i++)
  {
    add_point(path, g_random_double_range(0, 800), g_random_double_range(0, 800));
  }

  cairo_stroke_path(cr, path, 1);

  cairo_stroke_polygon(cr, 300, 100, 50, 4, 0);
  cairo_stroke_polygon(cr, 400, 100, 50, 5, 0);
  cairo_stroke_polygon(cr, 500, 100, 50, 6, 0);
  cairo_stroke_polygon(cr, 600, 100, 50, 7, 0);


  cairo_surface_write_to_png(surface, "out.png");

  return 0;
}

