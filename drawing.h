#ifndef _DRAWING_H_
#define _DRAWING_H_

#include <gtk/gtk.h>
#include "point.h"

void cairo_clear_rgb(cairo_t *cr, double r, double g, double b);

void cairo_plot(cairo_t *cr, double x, double y);

void cairo_line(cairo_t *cr, double x0, double y0, double x1, double y1);
void cairo_line_through(cairo_t *cr, double x0, double y0, double x1, double y1, double overlap);
void cairo_ray(cairo_t *cr, double x, double y, double angle, double offset, double length);

void cairo_stroke_rectangle(cairo_t *cr, double x, double y, double w, double h);
void cairo_fill_rectangle(cairo_t *cr, double x, double y, double w, double h);
void cairo_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r);
void cairo_stroke_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r);
void cairo_fill_round_rectangle(cairo_t *cr, double x, double y, double w, double h, double r);

void cairo_circle(cairo_t *cr, double x, double y, double r);
void cairo_stroke_circle(cairo_t *cr, double x, double y, double r);
void cairo_fill_circle(cairo_t *cr, double x, double y, double r);

void cairo_ellipse(cairo_t *cr, double x, double y, double xr, double yr);
void cairo_stroke_ellipse(cairo_t *cr, double x, double y, double xr, double yr);
void cairo_fill_ellipse(cairo_t *cr, double x, double y, double xr, double yr);

void cairo_path(cairo_t *cr, point_list *path);
void cairo_stroke_path(cairo_t *cr, point_list *path, int close);
void cairo_fill_path(cairo_t *cr, point_list *path);

void cairo_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);
void cairo_stroke_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);
void cairo_fill_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);

void cairo_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);
void cairo_stroke_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);
void cairo_fill_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);

void cairo_stroke_curve(cairo_t *cr, double x0, double y0, double x1, double y1, double x2, double y2);
void cairo_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1);
void cairo_stroke_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1);
#endif