#ifndef _POINT_H_
#define _POINT_H_

typedef struct Point
{
  double x;
  double y;
  struct Point *next;
} point;

typedef struct Point_List
{
  struct Point *next;
} point_list;

point_list* make_point_list();
point* make_point(double x, double y);
void add_point(point_list *head, double x, double y);

#endif
