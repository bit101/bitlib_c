#include <gtk/gtk.h>
#include <math.h>
#include <stdbool.h>
#include "drawing.h"
#include "point.h"
#include "color.h"


void cairo_set_source_color(cairo_t *cr, color *c)
{
  cairo_set_source_rgba(cr, c->r, c->g, c->b, c->a);
}

void cairo_fill_text(cairo_t *cr, char *text, double x, double y)
{
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_show_text(cr, text);
  cairo_fill(cr);
  cairo_restore(cr);
}
void cairo_stroke_text(cairo_t *cr, char *text, double x, double y)
{
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_show_text(cr, text);
  cairo_stroke(cr);
  cairo_restore(cr);
}

void cairo_clear_rgba(cairo_t *cr, double r, double g, double b, double a)
{
  cairo_save(cr);
  cairo_set_source_rgba(cr, r, g, b, a);
  cairo_paint(cr);
  cairo_restore(cr);
}

void cairo_clear_rgb(cairo_t *cr, double r, double g, double b)
{
  cairo_clear_rgba(cr, r, g, b, 1.0);
}

void cairo_clear_color(cairo_t *cr, color *c)
{
  cairo_clear_rgb(cr, c->r, c->g, c->b);
}

void cairo_line(cairo_t *cr, double x0, double y0, double x1, double y1)
{
  cairo_move_to(cr, x0, y0);
  cairo_line_to(cr, x1, y1);
  cairo_stroke(cr);
}

void cairo_line_through(cairo_t *cr, double x0, double y0, double x1, double y1, double overlap)
{
  double dx = x1 - x0;
  double dy = y1 - y0;
  double dxy = dx * dx + dy * dy;
  double p2 = sqrt(dxy);

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

void draw_path(cairo_t *cr, point_list *list)
{
  point *curr = list->head;
  while(curr != NULL)
  {
    cairo_line_to(cr, curr->x, curr->y); 
    curr = curr->next;
  }
}

void cairo_path(cairo_t *cr, point_list *path)
{
  draw_path(cr, path);
}

void cairo_stroke_path(cairo_t *cr, point_list *path, bool close)
{
  cairo_path(cr, path);
  if (close) {
    cairo_close_path(cr);
  }
  cairo_stroke(cr);
}

void cairo_fill_path(cairo_t *cr, point_list *path)
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

void cairo_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation)
{
  double r;
  double angle;

  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_rotate(cr, rotation);
  for (int i = 0; i < points * 2; i++)
  {
    r = r1;
    if (i % 2 == 1)
    {
      r = r0;
    }
    angle = G_PI / (double)points * (double)i;
    cairo_line_to(cr, cos(angle) * r, sin(angle) * r);
  }
  cairo_close_path(cr);
  cairo_restore(cr);
}

void cairo_stroke_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation)
{
  cairo_star(cr, x, y, r0, r1, points, rotation);
  cairo_stroke(cr);
}

void cairo_fill_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation)
{
  cairo_star(cr, x, y, r0, r1, points, rotation);
  cairo_fill(cr);
}

void cairo_stroke_curve(cairo_t *cr, double x0, double y0, double x1, double y1, double x2, double y2)
{
  cairo_curve_to(cr, x0, y0, x1, y1, x2, y2);
  cairo_stroke(cr);
}

void cairo_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1)
{
  double px;
  double py;

  cairo_get_current_point(cr, &px, &py);
  cairo_curve_to(
      cr,
      2.0 / 3.0 * x0 + 1.0 / 3.0 * px,
      2.0 / 3.0 * y0 + 1.0 / 3.0 * py,
      2.0 / 3.0 * x0 + 1.0 / 3.0 * x1,
      2.0 / 3.0 * y0 + 1.0 / 3.0 * y1,
      x1,
      y1
  );
}
void cairo_plot(cairo_t *cr, double x, double y)
{
  cairo_save(cr);
  cairo_translate(cr, x, y);
  cairo_fill_rectangle(cr, -0.5, -0.5, 1, 1);
  cairo_restore(cr);
}


void cairo_stroke_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1)
{
  cairo_quad_curve_to(cr, x0, y0, x1, y1);
  cairo_stroke(cr);
}

