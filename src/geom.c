#include "geom.h"
#include <stdbool.h>

double bl_distance_xy(double x0, double y0, double x1, double y1) {
  double dx = x0 - x1;
  double dy = y0 - y1;
  return sqrt(dx * dx + dy * dy);
}

bool bl_xy_in_rect(double x, double y, double rx, double ry, double rw, double rh) {
  return x >= rx && x <= rx + rw && y >= ry && y <= ry + rh;
}

bool bl_xy_in_circle(double x, double y, double cx, double cy, double cr) {
  double dx = x - cx;
  double dy = y - cy;
  return sqrt(dx * dx + dy * dy) <= cr;
}

double bl_xy_magnitude(double x, double y) {
  return sqrt(x * x + y * y);
}

bool bl_circle_intersect(double cx0, double cy0, double cr0, double cx1, double cy1, double cr1) {
  double dx = cx0 - cx1;
  double dy = cy0 - cy1;
  return sqrt(dx * dx + dy * dy) <= cr0 + cr1;
}

double bl_bezier(double x0, double x1, double x2, double x3, double t) {
  double one_minus_t = 1.0 - t;
  double m0 = one_minus_t * one_minus_t * one_minus_t;
  double m1 = 3.0 * one_minus_t * one_minus_t * t;
  double m2 = 3.0 * one_minus_t * t * t;
  double m3 = t * t * t;
  return m0 * x0 + m1 * x1 + m2 * x2 + m3 * x3;
}

double bl_quadratic_bezier(double x0, double x1, double x2, double t) {
  double one_minus_t = 1.0 - t;
  double m0 = one_minus_t * one_minus_t;
  double m1 = 2.0 * one_minus_t * t;
  double m2 = t * t;
  return m0 * x0 + m1 * x1 + m2 * x2;
}
// xy in triangle
// rect intersect
