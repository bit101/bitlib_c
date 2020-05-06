#include <gtk/gtk.h>
#include <math.h>
#include "drawing.h"
#include "point.h"


void cairo_clear_rgb(cairo_t *cr, double r, double g, double b)
{
  cairo_save(cr);
  cairo_set_source_rgb(cr, r, g, b);
  cairo_paint(cr);
  cairo_restore(cr);
}

void cairo_plot(cairo_t *cr, double x, double y)
{
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_fill_rectangle(cr, -0.5, -0.5, 1, 1);
  cairo_restore(cr);
}

void cairo_line(cairo_t *cr, double x0, double y0, double x1, double y1)
{
  cairo_move_to(cr, x0, y0);
  cairo_line_to(cr, x1, y1);
  cairo_stroke(cr);
}

void cairo_line_through(cairo_t *cr, double x0, double y0, double x1, double y1, double overlap)
{
  double p2;
  double dx;
  double dy;
  double dxy;

  dx = x1 - x0;
  dy = y1 - y0;
  dxy = dx * dx + dy * dy;
  p2 = sqrt(dxy);

  cairo_save(cr);
  cairo_translate(cr, x0, y0);
  cairo_rotate(cr, atan2(dy, dx));
  cairo_move_to(cr, -overlap, 0);
  cairo_line_to(cr, p2 + overlap, 0);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_ray(cairo_t *cr, double x, double y, double angle, double offset, double length)
{
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, angle);
  cairo_move_to(cr, offset, 0);
  cairo_line_to(cr, offset + length, 0);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_stroke_rectangle(cairo_t *cr, double x, double y, double w, double h)
{
  cairo_rectangle(cr, x, y, w, h);
  cairo_stroke(cr);
}

void cairo_fill_rectangle(cairo_t *cr, double x, double y, double w, double h)
{
  cairo_rectangle(cr, x, y, w, h);
  cairo_fill(cr);
}

void cairo_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r)
{
  r = fmin(r, w/2);
  r = fmin(r, h/2);
  cairo_move_to(cr, x + r, y);
  cairo_line_to(cr, x + w - r, y);
  cairo_arc(cr, x + w - r, y + r, r, -G_PI_2, 0);
  cairo_line_to(cr, x + w, y + h - r);
  cairo_arc(cr, x + w -r, y + h - r, r, 0, G_PI_2);
  cairo_line_to(cr, x + r, y + h);
  cairo_arc(cr, x + r, y + h - r, r, G_PI_2, G_PI);
  cairo_line_to(cr, x, y + r);
  cairo_arc(cr, x + r, y + r, r, G_PI, -G_PI_2);
}
void cairo_stroke_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r)
{
  cairo_round_rectangle(cr, x, y, w, h, r);
  cairo_stroke(cr);
}

void cairo_fill_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r)
{
  cairo_round_rectangle(cr, x, y, w, h, r);
  cairo_fill(cr);
}

void cairo_circle(cairo_t *cr, double x, double y, double r) {
  cairo_arc(cr, x, y, r, 0, G_PI * 2);
}

void cairo_stroke_circle(cairo_t *cr, double x, double y, double r)
{
  cairo_circle(cr, x, y, r);
  cairo_stroke(cr);
}

void cairo_fill_circle(cairo_t *cr, double x, double y, double r) {
  cairo_circle(cr, x, y, r);
  cairo_fill(cr);
}

void cairo_ellipse(cairo_t *cr, double x, double y, double xr, double yr)
{
  if (xr <= 0 || yr <= 0)
  {
    return;
  }
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_scale(cr, xr, yr);
  cairo_circle(cr, 0, 0, 1);
  cairo_restore(cr);
}

void cairo_stroke_ellipse(cairo_t *cr, double x, double y, double xr, double yr)
{
  cairo_ellipse(cr, x, y, xr, yr);
  cairo_stroke(cr);
}

void cairo_fill_ellipse(cairo_t *cr, double x, double y, double xr, double yr)
{
  cairo_ellipse(cr, x, y, xr, yr);
  cairo_fill(cr);
}

void draw_path(cairo_t *cr, point *head)
{
  point *curr;
  curr = head;
  while(curr != NULL)
  {
    cairo_line_to(cr, curr->x, curr->y); 
    curr = curr->next;
  }
}

void cairo_path(cairo_t *cr, point *path)
{
  draw_path(cr, path);
}

void cairo_stroke_path(cairo_t *cr, point *path, int close)
{
  cairo_path(cr, path);
  if (close) {
    cairo_close_path(cr);
  }
  cairo_stroke(cr);
}

void cairo_fill_path(cairo_t *cr, point *path)
{
  cairo_path(cr, path);
  cairo_fill(cr);
}

void cairo_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation)
{
  double angle;
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_move_to(cr, r, 0);
  for (int i = 0; i < sides; i++)
  {
    angle = G_PI * 2 / (double)sides * (double)i;
    cairo_line_to(cr, cos(angle) * r, sin(angle) * r);
  }
  cairo_line_to(cr, r, 0);
  cairo_restore(cr);
}

void cairo_stroke_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation)
{
  cairo_polygon(cr, x, y, r, sides, rotation);
  cairo_stroke(cr);
}

void cairo_fill_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation)
{
  cairo_polygon(cr, x, y, r, sides, rotation);
  cairo_fill(cr);
}
