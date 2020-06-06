#include "random.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void rand_seed(int seed) {
  srand(seed);
}

void rand_seed_rand() {
  srand(time(NULL) % clock());
}

int rand_int() {
  return rand();
}

double rand_double() {
  return (double)rand() / RAND_MAX;
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

int rand_int_range(int min, int max) {
  return min + rand() % (max - min);
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

char* rand_string(int length) {
  char* str = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    str[i] = (char)rand_int_range(33, 127);
  }
  str[length] = '\0';
  return str;
}

char* rand_string_lower(int length) {
  char* str = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    str[i] = (char)rand_int_range(97, 123);
  }
  str[length] = '\0';
  return str;
}

char* rand_string_upper(int length) {
  char* str = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    str[i] = (char)rand_int_range(65, 91);
  }
  str[length] = '\0';
  return str;
}

char* rand_string_alpha(int length) {
  char* str = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    char c = (char)rand_int_range(65, 117);
    if (c > 90) {
      c += 6;
    }
    str[i] = c;
  }
  str[length] = '\0';
  return str;
}
