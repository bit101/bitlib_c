#ifndef _POINT_H_
#define _POINT_H_

#include <stdbool.h>

/**
 * A struct for holding a single point in a linked list.
 */
typedef struct Point {
  double x;
  double y;
  struct Point* next;
} bl_point;

/**
 * A struct holding the head and tail of a linked list.
 */
typedef struct Point_List {
  struct Point* head;
  struct Point* tail;
} bl_point_list;

/**
 * Creates a linked list of point objects.
 *
 * @returns bl_point_list*
 *
 * **Examples**
 *
 *     bl_point_list *path = bl_make_point_list();
 */
bl_point_list* bl_make_point_list();

/**
 * Adds an x, y point to a point list.
 *
 * @param bl_point_list *list The list to add to.
 * @param double x The x value of the point to add.
 * @param double y The y value of the point to add.
 *
 * **Examples**
 *
 *     bl_add_point_xy(path, 100, 100);
 */
void bl_add_point_xy(bl_point_list* list, double x, double y);

/**
 * Adds a point to a point list.
 *
 * @param bl_point_list *list The list to add to.
 * @param bl_point *point The point to add.
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(100, 100);
 *     bl_add_point(path, p);
 */
void bl_add_point(bl_point_list* list, bl_point* p);

/**
 * Returns the number of points in a point list.
 *
 * @param bl_point_list *list The list to get a count for.
 * @returns int
 *
 * **Examples**
 *
 *     int count = bl_point_list_count(path);
 */
int bl_point_list_count(bl_point_list* list);

/**
 * Frees the memory for each point in a point list and for the list itself.
 *
 * @param bl_point_list *list The list to destroy.
 *
 * **Examples**
 *
 *     bl_point_list_destroy(path);
 */
void bl_point_list_destroy(bl_point_list* list);

/**
 * Creates a new point.
 *
 * @param double x The x value of the point.
 * @param double y The y value of the point.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(100, 100);
 */
bl_point* bl_make_point(double x, double y);

/**
 * Returns a new point interpolated between two other points.
 *
 * @param double t The interpolation value. Usually 0 to 1.
 * @param bl_point *p0 The first point.
 * @param bl_point *p1 The second point.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 500);
 *     bl_point *p2 = bl_lerp_point(0.35, p0, p1);
 */
bl_point* bl_lerp_point(double t, bl_point* p0, bl_point* p1);

/**
 * Returns a random point withint a defined rectangle.
 *
 * @param double x The x position of the rectangle.
 * @param double y The y position of the rectangle.
 * @param double w The width of the rectangle.
 * @param double h The height of the rectangle.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p = bl_random_point(0, 0, 500, 500);
 */
bl_point* bl_random_point(double x, double y, double w, double h);

/**
 * Returns a random point within a defined circle.
 *
 * @param double x The x position of the circle.
 * @param double y The y position of the circle.
 * @param double r The radius of the circle.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p = bl_random_point_in_circle(100, 100, 50);
 */
bl_point* bl_random_point_in_circle(double x, double y, double r);

/**
 * Returns a random point that will be within a triangle defined by three
 * points.
 *
 * @param bl_point *p0 The first point of the triangle.
 * @param bl_point *p1 The second point of the triangle.
 * @param bl_point *p2 The third point of the triangle.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(140, 300);
 *     bl_point *p3 = bl_random_point_in_triangle(p0, p1, p2);
 */
bl_point* bl_random_point_in_triangle(bl_point* p0, bl_point* p1, bl_point* p2);

/**
 * Returns a new point based on an angle and radius.
 *
 * @param double angle The angle from the origin.
 * @param double radius The distance from the origin.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p = bl_point_from_polar(PI / 4, 100);
 */
bl_point* bl_point_from_polar(double angle, double radius);

/**
 * Returns the distance between two points.
 *
 * @param bl_point *p0 The first point.
 * @param bl_point *p1 The second point.
 * @returns double
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(200, 150);
 *     bl_point *p1 = bl_make_point(140, 300);
 *     double dist = bl_point_distance(p0, p1);
 */
double bl_point_distance(bl_point* p0, bl_point* p1);

/**
 * Returns the magnitude (distance from origin) of a point.
 *
 * @param bl_point *p The point.
 * @returns double
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(200, 150);
 *     double mag = bl_point_magnitude(p);
 */
double bl_point_magnitude(bl_point* p);

/**
 * Returns the angle from the origin to a point.
 *
 * @param bl_point *p The point.
 * @returns double
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(200, 150);
 *     double angle = bl_point_angle(p);
 */
double bl_point_angle(bl_point* p);

/**
 * Translates a point.
 *
 * @param bl_point *p The point.
 * @param double x How much to translate on the x-axis.
 * @param double y How much to translate on the y-axis.
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(200, 150);
 *     bl_point_translate(p, 100, 50);
 */
void bl_point_translate(bl_point* p, double x, double y);

/**
 * Scales a point from the origin.
 *
 * @param bl_point *p The point.
 * @param double sx How much to scale on the x-axis.
 * @param double sy How much to scale on the y-axis.
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(200, 150);
 *     bl_point_scale(p, 2, 3);
 */
void bl_point_scale(bl_point* p, double sx, double sy);

/**
 * Rotates a point around the origin.
 *
 * @param bl_point *p The point.
 * @param double angle The angle to rotate by.
 *
 * **Examples**
 *
 *     bl_point *p = bl_make_point(200, 150);
 *     bl_point_rotate(p, PI / 4);
 */
void bl_point_rotate(bl_point* p, double angle);

/**
 * Returns the dot product of two angles formed by four points.
 *
 * @param bl_point *p0 The first point of the first line.
 * @param bl_point *p1 The second point of the first line.
 * @param bl_point *p2 The first point of the second line.
 * @param bl_point *p4 The second point of the second line.
 * @returns double
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(100, 100);
 *     bl_point *p3 = bl_make_point(140, 300);
 *     double dp = bl_dot_product(p0, p1, p2, p3);
 */
double bl_dot_product(bl_point* p0, bl_point* p1, bl_point* p2, bl_point* p3);

/**
 * Returns the angle between two lines defined by four points.
 *
 * @param bl_point *p0 The first point of the first line.
 * @param bl_point *p1 The second point of the first line.
 * @param bl_point *p2 The first point of the second line.
 * @param bl_point *p4 The second point of the second line.
 * @returns double
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(100, 100);
 *     bl_point *p3 = bl_make_point(140, 300);
 *     double angle = bl_angle_between(p0, p1, p2, p3);
 */
double bl_angle_between(bl_point* p0, bl_point* p1, bl_point* p2, bl_point* p3);

/**
 * Returns a point on a Bezier curve.
 *
 * The `t` parameter is in the range of 0 to 1. 0 will return the first point. 1
 * will return the final point. A value between 0 and 1 will return a point
 * along the Bezier path formed by the four points.
 *
 * @param bl_point *p0 The first point.
 * @param bl_point *p1 The second point.
 * @param bl_point *p2 The third point.
 * @param bl_point *p3 The fourth point.
 * @param double t The interpolation value.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(300, 100);
 *     bl_point *p3 = bl_make_point(400, 300);
 *     bl_point *p4 = bl_bezier_point(p0, p1, p2, p3, 0.2);
 */
bl_point* bl_bezier_point(bl_point* p0, bl_point* p1, bl_point* p2, bl_point* p3, double t);

/**
 * Returns a point on a quadratic Bezier curve.
 *
 * The `t` parameter is in the range of 0 to 1. 0 will return the first point. 1
 * will return the final point. A value between 0 and 1 will return a point
 * along the quadratic Bezier path formed by the three points.
 *
 * @param bl_point *p0 The first point.
 * @param bl_point *p1 The second point.
 * @param bl_point *p2 The third point.
 * @param double t The interpolation value.
 * @returns bl_point*
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(300, 100);
 *     bl_point *p4 = bl_quadratic_point(p0, p1, p2, p3, 0.2);
 */
bl_point* bl_quadratic_point(bl_point* p0, bl_point* p1, bl_point* p2, double t);

/**
 * Returns whether or not too line segments intersect.
 *
 * @param bl_point *p0 The first point of the first line.
 * @param bl_point *p1 The second point of the first line.
 * @param bl_point *p2 The first point of the second line.
 * @param bl_point *p4 The second point of the second line.
 * @returns bool
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *p1 = bl_make_point(200, 150);
 *     bl_point *p2 = bl_make_point(300, 100);
 *     bl_point *p3 = bl_make_point(400, 300);
 *     bool intersect = bl_segment_intersect(p0, p1, p2, p3);
 */
bl_point* bl_segment_intersect(bl_point* p0, bl_point* p1, bl_point* p2, bl_point* p3);

/**
 * Given the specified point and circle, finds another point on the circle that
 * will form a line tangent to the circle.
 *
 * @param bl_point *p The initial point.
 * @param double x The x position of the circle.
 * @param double y The y position of the circle.
 * @param double r The radius of the circle.
 * @param bool anticlockwise Which side of the circle to find the tangent point
 * on.
 *
 * **Examples**
 *
 *     bl_point *p0 = bl_make_point(100, 100);
 *     bl_point *tangent = bl_tangent_point_to_circle(p, 200, 100, 50, false);
 */
bl_point* bl_tangent_point_to_circle(bl_point* p, double x, double y, double r, bool anticlockwise);

#endif
