#ifndef _DRAWING_H_
#define _DRAWING_H_

#include "bitlib.h"
#include "point.h"
#include <cairo.h>
#include <stdbool.h>

/**
 * Plots a single point.
 *
 * Draws a single pixel rectangle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the point.
 * @param double y The y position of the point.
 *
 * **Examples**
 *
 *     cairo_plot(cr, 100, 100);
 */
void cairo_plot(cairo_t *cr, double x, double y);

/**
 * Draws a line between two x, y points.
 *
 * Same as `cairo_move_to` to the first point, `cairo_line_to` to the second
 * point and then `cairo_stroke`.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x position of the first point.
 * @param double y0 The y position of the first point.
 * @param double x1 The x position of the second point.
 * @param double y1 The y position of the second point.
 *
 * **Examples**
 *
 *     cairo_line(cr, 100, 100, 200, 200);
 */
void cairo_line(cairo_t *cr, double x0, double y0, double x1, double y1);

/**
 * Draws a line through two x, y points, overlapping each by a specified amount.
 *
 * Instead of simply starting and ending on each point, the drawn line will
 * extend beyond the points to the specified amount. Often you'll want to make
 * the `overlap` large enough so that it is outside of the drawing area to make
 * the line appear infinitely long.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x position of the first point.
 * @param double y0 The y position of the first point.
 * @param double x1 The x position of the second point.
 * @param double y1 The y position of the second point.
 * @param double overlap How far beyond each point to draw the line.
 *
 * **Examples**
 *
 *     cairo_line_through(cr, 100, 100, 200, 200, 100);
 */
void cairo_line_through(cairo_t *cr, double x0, double y0, double x1, double y1,
                        double overlap);

/**
 * Draws a line segment from an x, y point at a specified length and angle.
 *
 * A ray is a line segment that extends from a point at a certain angle. This
 * function also adds an offset so you can start the ray at a distance from the
 * point.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the point.
 * @param double y The y position of the point.
 * @param double angle The angle of the ray.
 * @param double offset How far from the point to start drawing the ray.
 * @param double length The length of the ray.
 *
 * **Examples**
 *
 *     cairo_ray(cr, 100, 100, G_PI / 2, 0, 100);
 */
void cairo_ray(cairo_t *cr, double x, double y, double angle, double offset,
               double length);

/**
 * Draws the stroked outline of a rectangle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 *
 * **Examples**
 *
 *     cairo_stroke_rectangle(cr, 100, 100, 200, 300);
 */
void cairo_stroke_rectangle(cairo_t *cr, double x, double y, double w,
                            double h);

/**
 * Draws a filled rectangle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 *
 * **Examples**
 *
 *     cairo_fill_rectangle(cr, 100, 100, 200, 300);
 */
void cairo_fill_rectangle(cairo_t *cr, double x, double y, double w, double h);

/**
 * Creates a rectangle with rounded corners.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 * @param double r The corner radius of the rectangle.
 *
 * **Examples**
 *
 *     cairo_round_rectangle(cr, 100, 100, 200, 300, 20);
 */
void cairo_round_rectangle(cairo_t *cr, double x, double y, double w, double h,
                           double r);

/**
 * Draws the stroked outline of a rounded rectangle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 * @param double r The corner radius of the rectangle.
 *
 * **Examples**
 *
 *     cairo_stroke_round_rectangle(cr, 100, 100, 200, 300, 20);
 */
void cairo_stroke_round_rectangle(cairo_t *cr, double x, double y, double w,
                                  double h, double r);

/**
 * Draws a filled rounded rectangle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 * @param double r The corner radius of the rectangle.
 *
 * **Examples**
 *
 *     cairo_fill_round_rectangle(cr, 100, 100, 200, 300, 20);
 */
void cairo_fill_round_rectangle(cairo_t *cr, double x, double y, double w,
                                double h, double r);

/**
 * Creates a circle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the circle.
 * @param double y The y position of the circle.
 * @param double r The radius of the circle.
 *
 * **Examples**
 *
 *     cairo_circle(cr, 100, 100, 50);
 */
void cairo_circle(cairo_t *cr, double x, double y, double r);

/**
 * Draws the stroked outline of a circle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the circle.
 * @param double y The y position of the circle.
 * @param double r The radius of the circle.
 *
 * **Examples**
 *
 *     cairo_stroke_circle(cr, 100, 100, 50);
 */
void cairo_stroke_circle(cairo_t *cr, double x, double y, double r);

/**
 * Draws a filled circle.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the circle.
 * @param double y The y position of the circle.
 * @param double r The radius of the circle.
 *
 * **Examples**
 *
 *     cairo_fill_circle(cr, 100, 100, 50);
 */
void cairo_fill_circle(cairo_t *cr, double x, double y, double r);

/**
 * Creates an ellipse.
 *
 * `x` and `y` will denote the center of the ellipse. The ellipse will be twice
 * as wide as `xr` and twice as tall as `yr`.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the ellipse.
 * @param double y The y position of the ellipse.
 * @param double xr The x radius of the ellipse.
 * @param double yr The y radius of the ellipse.
 *
 * **Examples**
 *
 *     cairo_ellipse(cr, 100, 100, 50, 75);
 */
void cairo_ellipse(cairo_t *cr, double x, double y, double xr, double yr);

/**
 * Draws the stroked outline of an ellipse.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the ellipse.
 * @param double y The y position of the ellipse.
 * @param double xr The x radius of the ellipse.
 * @param double yr The y radius of the ellipse.
 *
 * **Examples**
 *
 *     cairo_stroke_ellipse(cr, 100, 100, 50, 75);
 */
void cairo_stroke_ellipse(cairo_t *cr, double x, double y, double xr,
                          double yr);

/**
 * Draws a filled ellipse.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the ellipse.
 * @param double y The y position of the ellipse.
 * @param double xr The x radius of the ellipse.
 * @param double yr The y radius of the ellipse.
 *
 * **Examples**
 *
 *     cairo_fill_ellipse(cr, 100, 100, 50, 75);
 */
void cairo_fill_ellipse(cairo_t *cr, double x, double y, double xr, double yr);

/**
 * Creates a path by connecting a series of points.
 *
 * Use `bl_make_point_list` to create a list, and `bl_add_point` or
 * `pl_add_point_xy` to add points to the list. Be sure to call
 * `bl_point_list_destroy` when you are done with the list to avoid memory
 * leaks.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_path(cr, path);
 *     cairo_stroke(cr);
 *     bl_point_list_destroy(path);
 *
 */
void cairo_path(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked shape of a path of connected points.
 *
 * Use `bl_make_point_list` to create a list, and `bl_add_point` or
 * `pl_add_point_xy` to add points to the list. Be sure to call
 * `bl_point_list_destroy` when you are done with the list to avoid memory
 * leaks.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 * @param bool close Whether or not to draw a final line back to the start.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_stroke_path(cr, path, true);
 *     bl_point_list_destroy(path);
 */
void cairo_stroke_path(cairo_t *cr, bl_point_list *path, bool close);

/**
 * Draws a filled path of connected points.
 *
 * Use `bl_make_point_list` to create a list, and `bl_add_point` or
 * `pl_add_point_xy` to add points to the list. Be sure to call
 * `bl_point_list_destroy` when you are done with the list to avoid memory
 * leaks.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_fill_path(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_fill_path(cairo_t *cr, bl_point_list *path);

/**
 * Creates a regular polygon with the specified number of sides.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the polygon.
 * @param double y The y position of the polygon.
 * @param double r The radius of the polygon.
 * @param double sides How many sides to the polygon.
 * @param double rotation The rotation of the polygon in radians.
 *
 * **Examples**
 *
 *     cairo_polygon(cr, 100, 100, 50, 5, 0);
 *
 */
void cairo_polygon(cairo_t *cr, double x, double y, double r, int sides,
                   double rotation);

/**
 * Draws the stroked outline of a regular polygon.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the polygon.
 * @param double y The y position of the polygon.
 * @param double r The radius of the polygon.
 * @param double sides How many sides to the polygon.
 * @param double rotation The rotation of the polygon in radians.
 *
 * **Examples**
 *
 *     cairo_stroke_polygon(cr, 100, 100, 50, 5, 0);
 */
void cairo_stroke_polygon(cairo_t *cr, double x, double y, double r, int sides,
                          double rotation);

/**
 * Draws a filled regular polygon.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the polygon.
 * @param double y The y position of the polygon.
 * @param double r The radius of the polygon.
 * @param double sides How many sides to the polygon.
 * @param double rotation The rotation of the polygon in radians.
 *
 * **Examples**
 *
 *     cairo_fill_polygon(cr, 100, 100, 50, 5, 0);
 */
void cairo_fill_polygon(cairo_t *cr, double x, double y, double r, int sides,
                        double rotation);

/**
 * Creates a star shape with the specified number of points.
 *
 * The two radius parameters are somewhat interchangeable. You could call one
 * the inner radius and one the outer radius, but it does not matter which is
 * larger or smaller, though that will affect the orientation of the star.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the star.
 * @param double y The y position of the star.
 * @param double r0 The radius of one set of points of the star.
 * @param double r1 The radius of the other set of points of the star.
 * @param double sides How many points to the star.
 * @param double rotation The rotation of the star in radians.
 *
 * **Examples**
 *
 *     cairo_star(cr, 100, 100, 60, 20, 5, 0);
 */
void cairo_star(cairo_t *cr, double x, double y, double r0, double r1,
                int points, double rotation);

/**
 * Draws the stroked outline of a star.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the star.
 * @param double y The y position of the star.
 * @param double r0 The radius of one set of points of the star.
 * @param double r1 The radius of the other set of points of the star.
 * @param double sides How many points to the star.
 * @param double rotation The rotation of the star in radians.
 *
 * **Examples**
 *
 *     cairo_stroke_star(cr, 100, 100, 60, 20, 5, 0);
 */
void cairo_stroke_star(cairo_t *cr, double x, double y, double r0, double r1,
                       int points, double rotation);

/**
 * Draws a filled star.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the star.
 * @param double y The y position of the star.
 * @param double r0 The radius of one set of points of the star.
 * @param double r1 The radius of the other set of points of the star.
 * @param double sides How many points to the star.
 * @param double rotation The rotation of the star in radians.
 *
 * **Examples**
 *
 *     cairo_fill_star(cr, 100, 100, 60, 20, 5, 0);
 */
void cairo_fill_star(cairo_t *cr, double x, double y, double r0, double r1,
                     int points, double rotation);

/**
 * Draws the stroke of a Bezier curve.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x value of the first control point.
 * @param double y0 The y value of the first control point.
 * @param double x1 The x value of the second control point.
 * @param double y1 The y value of the second control point.
 * @param double x2 The x value of the end point.
 * @param double y2 The y value of the end point.
 *
 * **Examples**
 *
 *     cairo_move_to(cr, 100, 100);
 *     cairo_stroke_curve_to(200, 0, 300, 300, 400, 100);
 *
 */
void cairo_stroke_curve_to(cairo_t *cr, double x0, double y0, double x1,
                           double y1, double x2, double y2);

/**
 * Creates a quadratic curve.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x value of the control point.
 * @param double y0 The y value of the control point.
 * @param double x2 The x value of the end point.
 * @param double y2 The y value of the end point.
 *
 * **Examples**
 *
 *     cairo_move_to(cr, 100, 100);
 *     cairo_quad_curve_to(200, 0, 300, 100);
 *     cairo_stroke();
 */
void cairo_quad_curve_to(cairo_t *cr, double x0, double y0, double x1,
                         double y1);

/**
 * Draws the stroke of a quadratic curve.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x value of the control point.
 * @param double y0 The y value of the control point.
 * @param double x1 The x value of the end point.
 * @param double y1 The y value of the end point.
 *
 * **Examples**
 *
 *     cairo_move_to(cr, 100, 100);
 *     cairo_stroke_quad_curve_to(200, 0, 300, 100);
 */
void cairo_stroke_quad_curve_to(cairo_t *cr, double x0, double y0, double x1,
                                double y1);

/**
 * Draws the specified text with a fill.
 *
 * @param cairo_t *cr The cairo context.
 * @param char *text The text to draw.
 * @param double x The x position of the text.
 * @param double y The y position of the text.
 *
 * **Examples**
 *
 *     cairo_fill_text(cr, "hello world", 100, 100);
 *
 */
void cairo_fill_text(cairo_t *cr, char *text, double x, double y);

/**
 * Draws text using a format string and variables.
 *
 * This function works exactly like `printf`, and in fact uses the same
 * underlying functions, but draws the resultant string to the cairo context.
 *
 * @param cairo_t *cr The cairo context.
 * @param char *text The text to draw.
 * @param double x The x position of the text.
 * @param double y The y position of the text.
 *
 * **Examples**
 *
 *     cairo_printf(cr, 100, 100, "hello %s %d", "world", 2020);
 */
void cairo_printf(cairo_t *cr, double x, double y, char *fmt, ...);

/**
 * Draws the specified text with a stroke.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the text.
 * @param double y The y position of the text.
 * @param char *text The format string to construct the text with.
 * @param ... Additional parameters to fill in the format string with.
 *
 * **Examples**
 *
 *     cairo_stroke_text(cr, "hello world", 100, 100);
 */
void cairo_stroke_text(cairo_t *cr, char *text, double x, double y);

/**
 * Creates a splat shape.
 *
 * This function draws a shape that looks like a drop of ink splashed on a
 * surface. It's like a star with blobs instead of points. If `variation` is 0,
 * it will be a perfect splat and look more like a flower. As `variation`
 * increases, the blobs become more random.
 *
 * @param cairo_t *cr The cairo context.
 * @param char *text The text to draw.
 * @param double x The x position of the splat.
 * @param double y The y position of the splat.
 * @param int num_nodes How many blobs (nodes) in the splat.
 * @param double radius The outer radius of the splat.
 * @param double inner_radius The inner radius of the splat.
 * @param double variation How random the nodes will be.
 *
 * **Examples**
 *
 *     cairo_splat(cr, 200, 200, 6, 100, 20, 0.2);
 */
void cairo_splat(cairo_t *cr, double x, double y, int num_nodes, double radius,
                 double inner_radius, double variation);

/**
 * Draws the stroked outline of a splat shape.
 *
 * @param cairo_t *cr The cairo context.
 * @param char *text The text to draw.
 * @param double x The x position of the splat.
 * @param double y The y position of the splat.
 * @param int num_nodes How many blobs (nodes) in the splat.
 * @param double radius The outer radius of the splat.
 * @param double inner_radius The inner radius of the splat.
 * @param double variation How random the nodes will be.
 *
 * **Examples**
 *
 *
 *     cairo_stroke_splat(cr, 200, 200, 6, 100, 20, 0.2);
 */
void cairo_stroke_splat(cairo_t *cr, double x, double y, int num_nodes,
                        double radius, double inner_radius, double variation);

/**
 * Draws a filled splat shape.
 *
 * @param cairo_t *cr The cairo context.
 * @param char *text The text to draw.
 * @param double x The x position of the splat.
 * @param double y The y position of the splat.
 * @param int num_nodes How many blobs (nodes) in the splat.
 * @param double radius The outer radius of the splat.
 * @param double inner_radius The inner radius of the splat.
 * @param double variation How random the nodes will be.
 *
 * **Examples**
 *
 *     cairo_fill_splat(cr, 200, 200, 6, 100, 20, 0.2);
 */
void cairo_fill_splat(cairo_t *cr, double x, double y, int num_nodes,
                      double radius, double inner_radius, double variation);

/**
 * Creates a smooth, closed curve through a list of points.
 *
 * The curve will not pass through each point. Instead, the points will be used
 * as quadratic Bezier control points for each segment of the curve.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_multi_loop(cr, path);
 *     cairo_stroke(cr);
 *     bl_point_list_destroy(path);
 */
void cairo_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked outline of a smooth closed curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_stroke_multi_loop(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_stroke_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled smooth closed curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_fill_multi_loop(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_fill_multi_loop(cairo_t *cr, bl_point_list *path);

/**
 * Creates an open smooth curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_multi_curve(cr, path);
 *     cairo_stroke(cr);
 *     bl_point_list_destroy(path);
 */
void cairo_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws the stroked path of an open smooth curve through a list of points.
 *
 * The curve will not pass through each point. Instead, the points will be used
 * as quadratic Bezier control points for each segment of the curve.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_stroke_multi_curve(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_stroke_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled, open smooth curve through a list of points.
 *
 * @param cairo_t *cr The cairo context.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_fill_multi_curve(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_fill_multi_curve(cairo_t *cr, bl_point_list *path);

/**
 * Draws a filled circle for each point in a list.
 *
 * @param cairo_t *cr The cairo context.
 * @param bl_point_list *path A linked list of `bl_point` objects.
 * @param double radius The radius of the circles drawn on each point.
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 *     bl_add_point_xy(path, 100, 100);
 *     bl_add_point_xy(path, 110, 200);
 *     // add more points...
 *     cairo_draw_points(cr, path);
 *     bl_point_list_destroy(path);
 */
void cairo_draw_points(cairo_t *cr, bl_point_list *path, double radius);

/**
 * Creates a fractal line between two points.
 *
 * This works by subdividing the initial line segment and offsetting the new
 * point. The result looks like a mountain, coastline or lightning strike.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x value of the first point.
 * @param double y0 The y value of the first point.
 * @param double x0 The x value of the second point.
 * @param double y0 The y value of the second point.
 * @param double roughness How much the points will be offset during iteration.
 * @param int iterations How many iterations to build the line.
 *
 * **Examples**
 *
 *     cairo_fractal_line(cr, 100, 100, 200, 200, 0.4, 5);
 *     cairo_stroke(cr);
 */
void cairo_fractal_line(cairo_t *cr, double x0, double y0, double x1, double y1,
                        double roughness, int iterations);

/**
 * Draws the stroked path of a fractal line between two points.
 *
 *
 * @param cairo_t *cr The cairo context.
 * @param double x0 The x value of the first point.
 * @param double y0 The y value of the first point.
 * @param double x0 The x value of the second point.
 * @param double y0 The y value of the second point.
 * @param double roughness How much the points will be offset during iteration.
 * @param int iterations How many iterations to build the line.
 *
 * **Examples**
 *
 *     cairo_stroke_fractal_line(cr, 100, 100, 200, 200, 0.4, 5);
 */
void cairo_stroke_fractal_line(cairo_t *cr, double x0, double y0, double x1,
                               double y1, double roughness, int iterations);

/**
 * Creates a heart shape.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the heart.
 * @param double y The y position of the heart.
 * @param double w The width of the heart.
 * @param double h The height of the heart.
 * @param double r The rotation of the heart in radians.
 *
 * **Examples**
 *
 *     cairo_heart(cr, 100, 100, 50, 50, 0);
 */
void cairo_heart(cairo_t *cr, double x, double y, double w, double h, double r);

/**
 * Draws the stroked outline of a heart shape.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the heart.
 * @param double y The y position of the heart.
 * @param double w The width of the heart.
 * @param double h The height of the heart.
 * @param double r The rotation of the heart in radians.
 *
 * **Examples**
 *
 *     cairo_stroke_heart(cr, 100, 100, 50, 50, 0);
 */
void cairo_stroke_heart(cairo_t *cr, double x, double y, double w, double h,
                        double r);

/**
 * Draws a filled heart shape.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the heart.
 * @param double y The y position of the heart.
 * @param double w The width of the heart.
 * @param double h The height of the heart.
 * @param double r The rotation of the heart in radians.
 *
 * **Examples**
 *
 *     cairo_fill_heart(cr, 100, 100, 50, 50, 0);
 */
void cairo_fill_heart(cairo_t *cr, double x, double y, double w, double h,
                      double r);

/**
 * Draws a stroked grid.
 *
 * @param cairo_t *cr The cairo context.
 * @param double x The x position of the grid.
 * @param double y The y position of the grid.
 * @param double w The width of the grid.
 * @param double h The height of the grid.
 * @param double xres The space between each line on the x-axis.
 * @param double yres The space between each line on the y-axis.
 *
 * **Examples**
 *
 *     cairo_grid(0, 0, 500, 500, 10, 10);
 *     cairo_stroke(cr);
 */
void cairo_grid(cairo_t *cr, double x, double y, double w, double h,
                double xres, double yres);

#endif
