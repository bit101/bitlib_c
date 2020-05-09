#include <gtk/gtk.h>
#include <math.h>
#include "blmath.h"

double bl_difference(double a, double b)
{
  return fabs(a - b);
}

double bl_norm(double value, double min, double max)
{
  return (value - min) / (max - min);
}

double bl_lerp(double t, double min, double max)
{
  return min + (max - min) * t;
}

double bl_map(double src_value, double src_min, double src_max, double dst_min, double dst_max)
{
  double norm = bl_norm(src_value, src_min, src_max);
  return bl_lerp(norm, dst_min, dst_max);
}

double bl_wrap(double value, double min, double max)
{
  double range = max - min;
  return min + fmod((fmod(value - min, range) + range), range);
}

double bl_clamp(double value, double min, double max)
{
  // let min and max be reversed and still work.
  double real_min = min;
  double real_max = max;
  double result = value;

  if (min > max)
  {
    real_min = max;
    real_max = min;
  }
  if (value < real_min)
  {
    result = real_min;
  }
  if (value > real_max)
  {
    result = real_max;
  }
  return result;
}

double bl_round_to(double value, int decimals)
{
  double mult = pow(10.0, (double)decimals);
  return round(value * mult) / mult;
}

double bl_round_to_nearest(double value, double mult)
{
  return round(value / mult) * mult;
}

double bl_sin_range(double angle, double min, double max)
{
  return bl_map(sin(angle), -1, 1, min, max);
}

double bl_cos_range(double angle, double min, double max)
{
  return bl_map(cos(angle), -1, 1, min, max);
}

double bl_fract(double value)
{
  return value - floor(value);
}

double bl_lerp_sin(double value, double min, double max)
{
  return bl_sin_range(value * G_PI * 2, min, max);
}

int bl_equalish(double a, double b, double delta)
{
  return bl_difference(a, b) <= delta;
}
