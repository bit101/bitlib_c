#ifndef _MATH_H_
#define _MATH_H_

#define PI 3.1415926535897932384626433832795028841971693993751
#define PI_2 1.5707963267948966192313216916397514420985846996876
#define SQRT2 1.4142135623730950488016887242096980785696718753769

#include <stdbool.h>

/**
 * Returns the absolute value of the difference between two numbers.
 *
 * Subtracting two different numbers may give you a negative number. This just
 * takes the absolute value of that result.
 *
 * @param double a One number.
 * @param double b The other number.
 * @returns double
 *
 * **Examples**
 *
 *     bl_difference(1, 3) // returns 2
 *     // |1 - 2| = 2
 *
 */
double bl_difference(double a, double b);

/**
 * Returns the normalized value of a number within a min/max range.
 *
 * If the input value is the same as the minimum, `bl_norm` will return 0. If it
 * is the same as the maximum value, it will return 1. If it is between `min`
 * and `max`, it will return a number between 0 and 1.
 *
 * This also supports input values below `min` (will return a negative number)
 * and above `max` (will return a number greater than 1).
 *
 * @param double value The number to normalize.
 * @param double min. The minimum of the range.
 * @param double max. The maximum of the range.
 * @returns double
 *
 * **Examples**
 *
 *     bl_norm(80, 50, 100) // returns 0.6
 *     // 80 is 60% of the way between 50 and 100
 *
 */
double bl_norm(double value, double min, double max);

/**
 * Linear interpolation within a range.
 *
 * If the interpolation value (`t`) is 0, `bl_lerp` will return `min`. If `t` is
 * 1, it will return `max`. For `t` values between 0 and 1, `bl_lerp` will
 * interpolate between `min` and `max`.
 *
 * This also suppots `t` values below 0 and above 1, in which case the return
 * will be outside the `min`/`max` range.
 *
 * @param double t The interpolation value.
 * @param double min The minimum of the range.
 * @param double max The maximum of the range.
 * @returns double
 *
 * **Examples**
 *
 *     bl_lerp(0.5, 20, 40) // returns 30
 *     // 30 is 50% of the way between 20 and 40
 */
double bl_lerp(double t, double min, double max);

/**
 * Maps a value within one range to a corresponding value within a different
 * range.
 *
 * Essentialy, the applies a norm function on `src_value`, `src_min`, and
 * `src_max`. Then uses the result of that as an input to a lerp function with
 * `dst_min` and `dst_max`.
 *
 * @param double src_value The source value within the source range.
 * @param double src_min The minimum of the source range.
 * @param double src_max The maximum of the source range.
 * @param double dst_min The minimum of the destination range.
 * @param double dst_max The maximum of the destination range.
 * @returns double
 *
 * **Examples**
 *
 *     bl_map(40, 30, 50, 0, 1000) // returns 500
 *     // 40 is 50% of the way between 30 and 50
 *     // 500 is 50% of the way between 0 and 1000
 */
double bl_map(double src_value, double src_min, double src_max, double dst_min, double dst_max);

/**
 * Returns the input value if it is within a range, or wraps it around the range
 * if not.
 *
 * If the input value goes to or beyond the `max` value, it will wrap around and
 * start counting from `min`. If the input value is less than `min`, it will
 * wrap around and start counting backwards from `max`.
 *
 * Note that this is basically an advanced form of modulo. If the input value is
 * exactly equal to `max`, wrap will return `min`. Calling wrap with 0 as `min`
 * acts exactly the same as module.
 *
 * An instance where you might use this is in constraining hues to a particular
 * range of the spectrum. Or animating an object that you want to leave one side
 * of the screen and return on the opposite side.
 *
 * @param double value The input value.
 * @param double min The minimum of the range.
 * @param double max The maximum of the range.
 * @return double
 *
 * **Examples**
 *
 *     bl_wrap(5, 3, 8) // returns 5. 5 is within the range.
 *
 *     bl_wrap(8, 3, 8) // returns 3. 8 has hit the max and wraps.
 *
 *     bl_wrap(10, 3, 8) // returns 5. 10 is 2 beyond max, so it returns min + 2
 *
 *     bl_wrap(1, 3, 8)  // returns 6. 1 is 2 less than min, it returns max - 2
 */
double bl_wrap(double value, double min, double max);

/**
 * Clamps a value within a range.
 *
 * If the value is lower then the minimum value of the range, `bl_clamp` will
 * return the minimum value. If the value is higher than the maximum, it will
 * return the maximum.
 *
 * @param double value The input value.
 * @param double min The minimum of the range.
 * @param double max The maximum of the range.
 * @return double.
 */
double bl_clamp(double value, double min, double max);

/**
 * Rounds a value to a power of 10 (positive or negative).
 *
 * If the `decimals` value is 0, this acts the same as a simple round. If
 * `decimals` is positive, it will round to the nearest multiple of 10, 100,
 * 1000, etc. If `decimals` is negative, it will round to the nearest 0.1, 0.01,
 * 0.001, etc.
 *
 * @param double value The input value.
 * @param double value How many decimals to round to.
 * @returns double
 *
 * **Examples**
 *
 *     bl_round_to(1234, 2) // returns 1200
 *     bl_round_to(1234.5678, -2) // returns 1234.57
 */
double bl_round_to(double value, int decimals);

/**
 * Returns a value rounded to the nearest multiple of another number.
 *
 * Setting `mult` to 10 has the same effect as `bl_round_to`.
 *
 * You can set `mult` to a fraction to round to the nearest multiple of that
 * fraction.
 *
 * @param double value The input value.
 * @param mult The multiple to round to.
 * @return double
 *
 * **Examples**
 *
 *     bl_round_to_nearest(23, 8) // returns 24
 *     bl_round_to_nearest(5.7123, 0.25) // returns 5.75
 */
double bl_round_to_nearest(double value, double mult);

/**
 * Given an angle, returns a number between min and max.
 *
 * Given a series of angles from 0 to 2PI, `bl_sin_range` will return values
 * conforming a sine wave, starting at `(max+min)/2`, rising to `max`, going
 * back to `min`, and back to the average of the two.
 *
 * @param double angle The input angle.
 * @param double min The minumum of the sine wave.
 * @param double max The maximum of the sine wave.
 * @returns double
 *
 * **Examples**
 *
 *     bl_sin_range(0, -10, 10) // returns 0 (-10 + 10) / 2
 *     bl_sin_range(PI / 2, -10, 10) // returns 10 (max)
 *     bl_sin_range(PI * 2 / 3, -10, 10) // returns -10 (min)
 */
double bl_sin_range(double angle, double min, double max);

/**
 * Given an angle, returns a number between min and max.
 *
 * Given a series of angles from 0 to 2PI, `bl_cos_range` will return values
 * conforming a cosine wave, starting at `max`, going down to `(max+min)/2`,
 * then to `min`, back to the average of the two and then `max`.
 *
 * @param double angle The input angle.
 * @param double min The minumum of the sine wave.
 * @param double max The maximum of the sine wave.
 * @returns double
 *
 * **Examples**
 *
 *     bl_cos_range(0, -10, 10) // returns 10 (max)
 *     bl_cos_range(PI / 2, -10, 10) // returns 0 (min+max) / 2
 *     bl_cos_range(PI, -10, 10) // returns -10 (min)
 */
double bl_cos_range(double angle, double min, double max);

/**
 * Returns the fractional part of a floating point number.
 *
 * You could use the built-in `double modf(double x, double *integer)` function
 * if you want both the fractional and integer part of a number.
 *
 * @param double value The input value.
 * @returns double
 *
 * **Examples**
 *
 *     bl_fract(1.23) // returns 0.23
 */
double bl_fract(double value);

/**
 * Interpolates a normalized input value (0 to 1) to a sine wave extending from
 * min to max.
 *
 * This function is equivalent to calling `bl_sin_range(value * PI * 2, min,
 * max)`. If you have an input value which can be treated as an angle, use
 * `bl_sin_range`. If you have a normalized value, use this.
 *
 * @param double value The input value.
 * @param double min The minimum of the sine wave.
 * @param double max The maximum of the sine wave.
 * @returns double
 *
 * **Examples**
 *
 *     bl_lerp_sin(0.25, -10, 10) // returns 10 (max)
 */
double bl_lerp_sin(double value, double min, double max);

/**
 * Returns a bool representing whether or not two double values are equal to
 * within a certain range.
 *
 * @param double a One number.
 * @param double b Another number.
 * @param double delta How close the numbers should be to be considered equal.
 *
 * **Examples**
 *
 *     bl_equalish(1, 1.0001, 0.001)   // returns true
 *     bl_equalish(1, 1.0001, 0.00001) // returns false
 */
bool bl_equalish(double a, double b, double delta);
#endif
