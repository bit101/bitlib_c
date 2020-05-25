#ifndef _NOISE_H_
#define _NOISE_H_

/**
 * Gets a one-dimensional Perlin noise value.
 *
 * @param double x The value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_perlin_1(0.3);
 */
double bl_perlin_1(double x);

/**
 * Gets a two-dimensional Perlin noise value.
 *
 * @param double x The x value to get noise for.
 * @param double y The y value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_perlin_2(0.3, 0.8);
 */
double bl_perlin_2(double x, double y);

/**
 * Gets a three-dimensional Perlin noise value.
 *
 * @param double x The x value to get noise for.
 * @param double y The y value to get noise for.
 * @param double z The z value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_perlin_3(0.3, 0.8, 0.1);
 */
double bl_perlin_3(double x, double y, double z);

/**
 * Gets a one-dimensional simplex noise value.
 *
 * @param double x The value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_simplex_1(0.3);
 */
double bl_simplex_1(double x);

/**
 * Gets a two-dimensional simplex noise value.
 *
 * @param double x The x value to get noise for.
 * @param double y The y value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_simplex_2(0.3, 0.8);
 */
double bl_simplex_2(double x, double y);

/**
 * Gets a three-dimensional simplex noise value.
 *
 * @param double x The x value to get noise for.
 * @param double y The y value to get noise for.
 * @param double z The z value to get noise for.
 * @returns double
 *
 * **Examples**
 *
 *     double value = bl_simplex_3(0.3, 0.8, 0.1);
 */
double bl_simplex_3(double x, double y, double z);

#endif
