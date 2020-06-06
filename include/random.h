#ifndef _RANDOM_H_
#define _RANDOM_H_
#include <stdbool.h>

/**
 * Sets the seed used for generating random values.
 *
 * Calling the same series of rand functions after setting the seed to the same value
 * will result in the same series of random results.
 *
 * @param int seed The seed value.
 *
 * **Examples**
 *
 *     rand_seed(0);
 *     double a = rand_double();
 *     int b = rand_int();
 *     
 *     rand_seed(0);
 *     double c = rand_double(); // c will equal a
 *     int d = rand_int(); // d will equal b
 *
 */
void rand_seed(int seed);

/**
 * Sets the seed used for generating random values.
 *
 * This actually sets the seed using a couple of different time functions designed to give a fairly decent random seed.
 *
 * **Examples**
 *
 *     rand_seed_rand();
 *     int b = rand_int(); // who knows what b will equal?
 *
 */
void rand_seed_rand();
/**
 * Returns a random boolean. Allows you to weight the odds of getting true or false.
 *
 * @param double percent The odds of getting true. 0 it 0%. 0.5 is 50%. 1.0 is 100%.
 * @return double
 *
 * **Examples**
 *
 *     bool b = rand_weighted_bool(0.2); // b has a 20% chance of being true.
 *
 */
bool rand_weighted_bool(double percent);

/**
 * Returns a random boolean.
 *
 * @return double
 *
 * **Examples**
 *
 *     bool b = rand_bool(); // b has a 50% chance of being true.
 *
 */
bool rand_bool();

/**
 * Returns a random integer from 0 to MAX_RAND.
 *
 * @return int
 *
 * **Examples**
 *
 *     int n = rand_int();
 *
 */
int rand_int();

/**
 * Returns a random double from 0 to 1.
 *
 * @return double
 *
 * **Examples**
 *
 *     double n = rand_double();
 *
 */
double rand_double();

/**
 * Returns a double between a min and max value.
 *
 * @param double min The minimum value of the range.
 * @param double max The maximum value of the range.
 * @return double
 *
 * **Examples**
 *
 *     double n = rand_double_range(50, 100);
 *
 */
double rand_double_range(double min, double max);

/**
 * Returns a int between a min and max value.
 *
 * @param int min The minimum value of the range.
 * @param int max The maximum value of the range.
 * @return int
 *
 * **Examples**
 *
 *     int n = rand_int_range(50, 100);
 *
 */
int rand_int_range(int min, int max);

/**
 * Returns a double within a range, weighted exponentially towards one end of the range.
 *
 * The power parameter affects where the return value will end up. A power value of one makes this function work exactly
 * like rand_double_range. As the power value decreases towards zero, the return values will tend towards maximum, and
 * as power increases above 1, the return values will tend towards minimum.
 *
 * @param double min The minimum value of the range.
 * @param double max The maximum value of the range.
 * @param double power The power of the exponent that affects the result.
 * @return double
 *
 * **Examples**
 *
 *     double n = rand_power(0, 100, 2); // n will be more likely to be closer to 0.
 *     double m = rand_power(0, 100, 0.2); // m will be more likely to be closer to 100.
 *
 */
double rand_power(double min, double max, double power);

/**
 * Returns a double within a range, weighted with a bell curve towards the center of the range.
 *
 * The gauss parameter affects the strength of the bell curve. The higher gauss is set, the more likely the return
 * values will tend towards the center of the range. A gauss of 1 makes this function work exactly like
 * rand_double_range.
 *
 * @param double min The minimum value of the range.
 * @param double max The maximum value of the range.
 * @param double gauss The strength of the bell curve.
 * @return double
 *
 * **Examples**
 *
 *     double n = rand_gauss(0, 100, 2); // n will be more somewhat more likely to be closer to 50 than a random range.
 *     double m = rand_gauss(0, 100, 10); // m will be very much more likely to be closer to 50.
 *
 */
double rand_gauss(double min, double max, int gauss);

/**
 * Returns a random string which may contain upper and lower case characters, digits and other ascii symbols.
 *
 * This function allocates memory that should be freed when you are complete with it.
 *
 * @param int length The length of the string returned.
 * @return char*
 *
 * **Examples**
 *
 *     char *str = rand_string(10);
 *     printf("str: %s\n", str);
 *     free(str);
 *
 */
char* rand_string(int length);

/**
 * Returns a random string of lower case letters.
 *
 * This function allocates memory that should be freed when you are complete with it.
 *
 * @param int length The length of the string returned.
 * @return char*
 *
 * **Examples**
 *
 *     char *str = rand_string_lower(10);
 *     printf("str: %s\n", str);
 *     free(str);
 *
 */
char* rand_string_lower(int length);

/**
 * Returns a random string of upper case letters.
 *
 * This function allocates memory that should be freed when you are complete with it.
 *
 * @param int length The length of the string returned.
 * @return char*
 *
 * **Examples**
 *
 *     char *str = rand_string_upper(10);
 *     printf("str: %s\n", str);
 *     free(str);
 *
 */
char* rand_string_upper(int length);

/**
 * Returns a random string of upper and lower case letters.
 *
 * This function allocates memory that should be freed when you are complete with it.
 *
 * @param int length The length of the string returned.
 * @return char*
 *
 * **Examples**
 *
 *     char *str = rand_string_alpha(10);
 *     printf("str: %s\n", str);
 *     free(str);
 *
 */
char* rand_string_alpha(int length);

#endif
