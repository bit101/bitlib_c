#ifndef _GEOM_H_
#define _GEOM_H_

#include <math.h>

double bl_distance_xy(double x0, double y0, double x1, double y1);
bool bl_xy_in_rect(double x, double y, double rx, double ry, double rw, double rh);
bool bl_xy_in_circle(double x, double y, double cx, double cy, double cr);
double bl_xy_magnitude(double x, double y);
bool bl_circle_intersect(double cx0, double cy0, double cr0, double cx1, double cy1, double cr1);



#endif

