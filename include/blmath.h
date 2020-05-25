#ifndef _MATH_H_
#define _MATH_H_

#include <stdbool.h>

/**
 * Returns the absolute value of the difference between two numbers.
 * @param double a One number.
 * @param double b The other number.
 * @returns double
 *
 * **Example**
 *
 *     bl_difference(1, 3) // returns 2
 *     // |1 - 2| = 2
 *
 */
double bl_difference(double a, double b);

/**
 * Returns the normalized value of a number within a min/max range.
 * @param double value The number to normalize.
 * @param double min. The minimum of the range.
 * @param double max. The maximum of the range.
 * @returns double
 *
 * **Example**
 *
 *     bl_norm(80, 50, 100) // returns 0.6
 *     // 80 is 60% of the way between 50 and 100
 *
 */
double bl_norm(double value, double min, double max);

/**
 * Linear interpolation within a range.
 * @param double t The interpolation value.
 * @param double min The minimum of the range.
 * @param double max The maximum of the range.
 * @returns double
 *
 * **Example**
 *
 *     bl_lerp(0.5, 20, 40) // returns 30
 *     // 30 is 50% of the way between 20 and 40
 */
double bl_lerp(double t, double min, double max);

/**
 * Maps a value within one range to a corresponding value within a different
 * range.
 * @param double src_value The source value within the source range.
 * @param double src_min The minimum of the source range.
 * @param double src_max The maximum of the source range.
 * @param double dst_min The minimum of the destination range.
 * @param double dst_max The maximum of the destination range.
 * @returns double
 *
 * **Example**
 *
 *     bl_map(40, 30, 50, 0, 1000) // returns 500
 *     // 40 is 50% of the way between 30 and 50
 *     // 500 is 50% of the way between 0 and 1000
 */
double bl_map(double src_value, double src_min, double src_max, double dst_min,
              double dst_max);

/**
 * Returns the input value if it is within a range, or wraps it around the range
 * if not.
 * @param double value The input value.
 * @param double min The minimum of the range.
 * @param double max The maximum of the range.
 * @return double
 *
 * **Examples**
 *
 *     bl_wrap(5, 3, 8)  // returns 5 because 5 is within the range.
 *     bl_wrap(10, 3, 8) // returns 4 because 10 is outside the range.
 *     bl_wrap(1, 3, 8)  // returns 7 because 1 is outside of the range.
 */
double bl_wrap(double value, double min, double max);

/**
 *
 */
double bl_clamp(double value, double min, double max);

/**
 *
 */
double bl_round_to(double value, int decimals);

/**
 *
 */
double bl_round_to_nearest(double value, double mult);

/**
 *
 */
double bl_sin_range(double angle, double min, double max);

/**
 *
 */
double bl_cos_range(double angle, double min, double max);

/**
 *
 */
double bl_fract(double value);

/**
 *
 */
double bl_lerp_sin(double value, double min, double max);

/**
 *
 */
bool bl_equalish(double a, double b, double delta);
#endif
