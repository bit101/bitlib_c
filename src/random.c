#include "random.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool _rand_inited = false;
long _seed = 0;
long _a = 1664525;
long _c = 1013904223;
long _m = (long)pow(2, 32);

double rand_seed(long seed) {
  _seed = seed;
}

double rand_seed_rand() {
  _seed = time(NULL);
}

long rand_int() {
  if (!_rand_inited) {
    rand_seed_rand();
    _rand_inited = true;
  }
  _seed = (_seed * _a + _c) % _m;
  return _seed;
}

double rand_double() {
  return (double)rand_int() / _m;
}

bool rand_weighted_bool(double percent) {
  return rand_double() < percent;
}

bool rand_bool() {
  return rand_weighted_bool(0.5);
}

double rand_double_range(double min, double max) {
  return min + rand_double() * (max - min);
}

long rand_int_range(long min, long max) {
  return (long)floor(rand_double_range(min, max));
}

double rand_power(double min, double max, double power) {
  return min + pow(rand_double(), power) * (max - min);
}

double rand_gauss(double min, double max, int gauss) {
  double total = 0;
  for (int i = 0; i < gauss; i++) {
    total += rand_double_range(min, max);
  }
  return total / gauss;
}
