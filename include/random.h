#ifndef _RANDOM_H_
#define _RANDOM_H_
#include <stdbool.h>

bool rand_weighted_bool(double percent);
bool rand_bool();
double rand_seed(long seed);
double rand_seed_rand();
long rand_int();
double rand_double();
double rand_double_range(double min, double max);
long rand_int_range(long min, long max);
double rand_power(double min, double max, double power);
double rand_gauss(double min, double max, int gauss);
#endif
