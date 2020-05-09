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
  struct Point *head;
} point_list;

point_list* make_point_list();
point* make_point(double x, double y);
void add_point(point_list *list, point *p);
void add_point_xy(point_list *list, double x, double y);
double point_distance(point *p0, point *p1);


point* lerp_point(double t, point *p0, point *p1);
point* random_point(double x, double y, double w, double h);
point* random_polar_point(double x, double y, double r);
point* point_from_polar(double angle, double radius);

double point_distance(point *p0, point *p1);
double point_magnitude(point *p);
double point_angle(point *p);

void point_translate(point *p, double x, double y);
void point_scale(point *p, double sx, double sy);
void point_rotate(point *p, double angle);

#endif
