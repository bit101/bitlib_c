#ifndef _POINT_H_
#define _POINT_H_

typedef struct Point {
  double x;
  double y;
  struct Point *next;
} bl_point;

typedef struct Point_List {
  struct Point *head;
} bl_point_list;

bl_point_list* bl_make_point_list();
void bl_add_point_xy(bl_point_list *list, double x, double y);
void bl_add_point(bl_point_list *list, bl_point *p);

bl_point* bl_make_point(double x, double y);
bl_point* bl_lerp_point(double t, bl_point *p0, bl_point *p1);
bl_point* bl_random_point(double x, double y, double w, double h);
bl_point* bl_random_point_in_circle(double x, double y, double r);
bl_point* bl_point_from_polar(double angle, double radius);

double bl_point_distance(bl_point *p0, bl_point *p1);
double bl_point_magnitude(bl_point *p);
double bl_point_angle(bl_point *p);

void bl_point_translate(bl_point *p, double x, double y);
void bl_point_scale(bl_point *p, double sx, double sy);
void bl_point_rotate(bl_point *p, double angle);

#endif
