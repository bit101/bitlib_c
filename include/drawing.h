#ifndef _DRAWING_H_
#define _DRAWING_H_

#include <gtk/gtk.h>
#include <stdbool.h>
#include "bitlib.h"

void cairo_set_source_color(cairo_t *cr, bl_color *c);

void cairo_clear_color(cairo_t *cr, bl_color *c);
void cairo_clear_rgb(cairo_t *cr, double r, double g, double b);
void cairo_clear_rgba(cairo_t *cr, double r, double g, double b, double a);

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

void cairo_path(cairo_t *cr, bl_point_list *path);
void cairo_stroke_path(cairo_t *cr, bl_point_list *path, bool close);
void cairo_fill_path(cairo_t *cr, bl_point_list *path);

void cairo_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);
void cairo_stroke_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);
void cairo_fill_polygon(cairo_t *cr, double x, double y, double r, int sides, double rotation);

void cairo_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);
void cairo_stroke_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);
void cairo_fill_star(cairo_t *cr, double x, double y, double r0, double r1, int points, double rotation);

void cairo_stroke_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1, double x2, double y2);
void cairo_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1);
void cairo_stroke_quad_curve_to(cairo_t *cr, double x0, double y0, double x1, double y1);

void cairo_fill_text(cairo_t *cr, char *text, double x, double y);
void cairo_stroke_text(cairo_t *cr, char *text, double x, double y);

void cairo_splat(cairo_t *cr, double x, double y, int num_nodes,
    double radius, double inner_radius, double variation);
void cairo_stroke_splat(cairo_t *cr, double x, double y, int num_nodes,
    double radius, double inner_radius, double variation);
void cairo_fill_splat(cairo_t *cr, double x, double y, int num_nodes,
    double radius, double inner_radius, double variation);

void cairo_multi_loop(cairo_t *cr, bl_point_list *path);
void cairo_stroke_multi_loop(cairo_t *cr, bl_point_list *path);
void cairo_fill_multi_loop(cairo_t *cr, bl_point_list *path);

void cairo_multi_curve(cairo_t *cr, bl_point_list *path);
void cairo_stroke_multi_curve(cairo_t *cr, bl_point_list *path);
void cairo_fill_multi_curve(cairo_t *cr, bl_point_list *path);

void cairo_draw_points(cairo_t *cr, bl_point_list *path, double radius);

void cairo_fractal_line(cairo_t *cr, double x0, double y0, double x1, double y1, double roughness, int iterations);
void cairo_stroke_fractal_line(cairo_t *cr, double x0, double y0, double x1, double y1, double roughness, int iterations);

void cairo_heart(cairo_t *cr, double x, double y, double w, double h, double r);
void cairo_stroke_heart(cairo_t *cr, double x, double y, double w, double h, double r);
void cairo_fill_heart(cairo_t *cr, double x, double y, double w, double h, double r);

void cairo_grid(cairo_t *cr, double x, double y, double w, double h, double xres, double yres);

#endif
