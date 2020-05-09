#ifndef _MATH_H_
#define _MATH_H_

#include <stdbool.h>

double bl_difference(double a, double b);

double bl_norm(double value, double min, double max);

double bl_lerp(double t, double min, double max);

double bl_map(double src_value, double src_min, double src_max, double dst_min, double dst_max);

double bl_wrap(double value, double min, double max);

double bl_clamp(double value, double min, double max);

double bl_round_to(double value, int decimals);

double bl_round_to_nearest(double value, double mult);

double bl_sin_range(double angle, double min, double max);

double bl_cos_range(double angle, double min, double max);

double bl_fract(double value);

double bl_lerp_sin(double value, double min, double max);

bool bl_equalish(double a, double b, double delta);
#endif
