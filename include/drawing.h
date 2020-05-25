#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "bitlib.h"
#include "point.h"
#include <cairo.h>
#include <stdbool.h>

/**
 * Plots a single point.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the point.
 * @param double y The y position of the point.
 *
 * **Examples**
 *
 *
 */
void cairo_plot(cairo_t *cr, double x, double y);

/**
 * Draws a line between two x, y points.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x position of the first point.
 * @param double y0 The y position of the first point.
 * @param double x1 The x position of the second point.
 * @param double y1 The y position of the second point.
 *
 * **Examples**
 *
 *
 */
void cairo_line(cairo_t *cr, double x0, double y0, double x1, double y1);

/**
 * Draws a line through two x, y points, overlapping each by a specified amount.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_line_through(cairo_t *cr, double x0, double y0, double x1, double y1,
                        double overlap);

/**
 * Draws a line segment from an x, y point at a specified length and angle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_ray(cairo_t *cr, double x, double y, double angle, double offset,
               double length);

/**
 * Draws the stroked outline of a rectangle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_rectangle(cairo_t *cr, double x, double y, double w,
                            double h);

/**
 * Draws a filled rectangle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_rectangle(cairo_t *cr, double x, double y, double w, double h);

/**
 * Creates a rectangle with rounded corners.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_round_rectangle(cairo_t *cr, double x, double y, double w, double h,
                           double r);

/**
 * Draws the stroked outline of a rounded rectangle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_round_rectangle(cairo_t *cr, double x, double y, double w,
                                  double h, double r);

/**
 * Draws a filled rounded rectangle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_round_rectangle(cairo_t *cr, double x, double y, double w,
                                double h, double r);

/**
 * Creates a circle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_circle(cairo_t *cr, double x, double y, double r);

/**
 * Draws the stroked outline of a circle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_circle(cairo_t *cr, double x, double y, double r);

/**
 * Draws a filled circle.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_circle(cairo_t *cr, double x, double y, double r);

/**
 * Creates an ellipse.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_ellipse(cairo_t *cr, double x, double y, double xr, double yr);

/**
 * Draws the stroked outline of an ellipse.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_ellipse(cairo_t *cr, double x, double y, double xr,
                          double yr);

/**
 * Draws a filled ellipse.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_ellipse(cairo_t *cr, double x, double y, double xr, double yr);

/**
 * Creates a path by connecting a series of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_path(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked shape of a path of connected points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_path(cairo_t *cr, bl_point_list *path, bool close);

/**
 * Draws a filled path of connected points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_path(cairo_t *cr, bl_point_list *path);

/**
 * Creates a regular polygon with the specified number of sides.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_polygon(cairo_t *cr, double x, double y, double r, int sides,
                   double rotation);

/**
 * Draws the stroked outline of a regular polygon.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_polygon(cairo_t *cr, double x, double y, double r, int sides,
                          double rotation);

/**
 * Draws a filled regular polygon.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_polygon(cairo_t *cr, double x, double y, double r, int sides,
                        double rotation);

/**
 * Creates a star shape with the specified number of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_star(cairo_t *cr, double x, double y, double r0, double r1,
                int points, double rotation);

/**
 * Draws the stroked outline of a star.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_star(cairo_t *cr, double x, double y, double r0, double r1,
                       int points, double rotation);

/**
 * Draws a filled star.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_star(cairo_t *cr, double x, double y, double r0, double r1,
                     int points, double rotation);

/**
 * Draws the stroke of a Bezier curve.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_curve_to(cairo_t *cr, double x0, double y0, double x1,
                           double y1, double x2, double y2);

/**
 * Creates a quadratic curve.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_quad_curve_to(cairo_t *cr, double x0, double y0, double x1,
                         double y1);

/**
 * Draws the stroke of a quadratic curve.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_quad_curve_to(cairo_t *cr, double x0, double y0, double x1,
                                double y1);

/**
 * Draws the specified text with a fill.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_text(cairo_t *cr, char *text, double x, double y);

/**
 * Draws text using a format string and variables.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_printf(cairo_t *cr, double x, double y, char *fmt, ...);

/**
 * Draws the specified text with a stroke.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_text(cairo_t *cr, char *text, double x, double y);

/**
 * Creates a splat shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_splat(cairo_t *cr, double x, double y, int num_nodes, double radius,
                 double inner_radius, double variation);

/**
 * Draws the stroked outline of a splat shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_splat(cairo_t *cr, double x, double y, int num_nodes,
                        double radius, double inner_radius, double variation);

/**
 * Draws a filled splat shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_splat(cairo_t *cr, double x, double y, int num_nodes,
                      double radius, double inner_radius, double variation);

/**
 * Creates a smooth, closed curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked outline of a smooth closed curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled smooth closed curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Creates an open smooth curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked path of an open smooth curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled, open smooth curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled circle for each point in a list.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_draw_points(cairo_t *cr, bl_point_list *path, double radius);

/**
 * Creates a fractal line between two points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fractal_line(cairo_t *cr, double x0, double y0, double x1, double y1,
                        double roughness, int iterations);

/**
 * Draws the stroked path of a fractal line between two points.
 *
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_fractal_line(cairo_t *cr, double x0, double y0, double x1,
                               double y1, double roughness, int iterations);

/**
 * Creates a heart shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_heart(cairo_t *cr, double x, double y, double w, double h, double r);

/**
 * Draws the stroked outline of a heart shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_stroke_heart(cairo_t *cr, double x, double y, double w, double h,
                        double r);

/**
 * Draws a filled heart shape.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_fill_heart(cairo_t *cr, double x, double y, double w, double h,
                      double r);

/**
 * Draws a stroked grid.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *
 */
void cairo_grid(cairo_t *cr, double x, double y, double w, double h,
                double xres, double yres);

#endif
