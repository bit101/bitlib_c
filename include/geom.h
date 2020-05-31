#ifndef _GEOM_H_
#define _GEOM_H_

#include <math.h>
#include <stdbool.h>

/**
 * Returns the distance between two x, y points.
 *
 * @param double x0 The x value of the first point.
 * @param double y0 The y value of the first point.
 * @param double x1 The x value of the second point.
 * @param double y1 The y value of the second point.
 * @returns double
 *
 * **Examples**
 *
 *     double dist = bl_distance_xy(100, 100, 200, 200);
 */
double bl_distance_xy(double x0, double y0, double x1, double y1);

/**
 * Returns whether or not an x, y point is within a rectangle.
 *
 * @param double x The x value of the point.
 * @param double y The y value of the point.
 * @param double rx The x position of the rectangle.
 * @param double ry The y position of the rectangle.
 * @param double rw The width of the rectangle.
 * @param double rh The height of the rectangle.
 * @returns double
 *
 * **Examples**
 *
 *     bool in_rect = bl_xy_in_rect(100, 100, 50, 50, 200, 300);
 */
bool bl_xy_in_rect(double x, double y, double rx, double ry, double rw, double rh);
/**
 * Returns whether or not an x, y point is within a circle.
 *
 * @param double x The x value of the point.
 * @param double y The y value of the point.
 * @param double cx The x position of the circle.
 * @param double cy The y position of the circle.
 * @param double cr The radius of the circle.
 * @returns bool
 *
 * **Examples**
 *
 *     bool in_circle = bl_xy_in_circle(100, 100, 150, 150, 100);
 */
bool bl_xy_in_circle(double x, double y, double cx, double cy, double cr);

/**
 * Returns the magnitude (distance from origin) of an x, y point.
 *
 * @param double x The x value of the point.
 * @param double y The y value of the point.
 * @returns double
 *
 * **Examples**
 *
 *     double mag = bl_xy_magnitude(100, 200);
 */
double bl_xy_magnitude(double x, double y);

/**
 * Returns whether or not two circles are intersecting.
 *
 * @param double cx0 The x position of the first circle.
 * @param double cy0 The y position of the first circle.
 * @param double cr0 The radius of the first circle.
 * @param double cx1 The x position of the second circle.
 * @param double cy1 The y position of the second circle.
 * @param double cr1 The radius of the second circle.
 * @returns double
 *
 * **Examples**
 *
 * bool collision = bl_circle_intersect(100, 100, 50, 150, 150, 100);
 */
bool bl_circle_intersect(double cx0, double cy0, double cr0, double cx1, double cy1, double cr1);

#endif
