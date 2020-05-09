#include <stdbool.h>
#include "geom.h"


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


// xy in triangle
// rect intersect
