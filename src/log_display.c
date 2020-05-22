#include "log_display.h"
#include "bitlib.h"
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

bl_log_display_data *bl_make_log_display_data(double width, double height) {
  bl_log_display_data *data = malloc(sizeof(bl_log_display_data));
  data->width = width;
  data->height = height;
  data->hits = calloc((int)(width * height), sizeof(double));
  return data;
}

void bl_log_display_add(bl_log_display_data *data, double x, double y) {
  if (x >= 0 && x < data->width && y >= 0 && y < data->height) {
    int index = (int)x + (int)y * (int)data->width;
    data->hits[index] += 1;
    if (data->hits[index] > data->max) {
      data->max = data->hits[index];
    }
  }
}

double bl_log_display_get_value(bl_log_display_data *data, double x, double y) {
  int index = (int)x + (int)y * (int)data->width;
  double val = log10(data->hits[index]) / log10(data->max);
  val = bl_clamp(val, 0, 1);
  return val;
}
