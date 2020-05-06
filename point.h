#ifndef _POINT_H_
#define _POINT_H_

typedef struct Point {
  double x;
  double y;
  struct Point *next;
} point;

point* make_point(double x, double y);
void add_point(point *head, double x, double y);

#endif
