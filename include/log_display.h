#ifndef _LOG_DISPLAY_H_
#define _LOG_DISPLAY_H_

typedef struct _bl_bl_log_display_data {
  double *hits;
  double width;
  double height;
  double max;
} bl_log_display_data;

bl_log_display_data *bl_make_log_display_data(double width, double height);
void bl_log_display_add(bl_log_display_data *data, double x, double y);
double bl_log_display_get_value(bl_log_display_data *data, double x, double y);

#endif
