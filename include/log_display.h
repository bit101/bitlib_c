#ifndef _LOG_DISPLAY_H_
#define _LOG_DISPLAY_H_

/**
 * A structure to hold information about quantitative draws to a bitmap.
 *
 * Rather than directly drawing each pixel, you mark it as hit in this data
 * struct. When you are done markeing pixels, you can get the value for each
 * pixel which will be calculated on a logarithmic scale based on the pixel that
 * got the most hits.
 */
typedef struct _bl_bl_log_display_data {
  double *hits;
  double width;
  double height;
  double max;
} bl_log_display_data;

/**
 * Creates an instance of `bl_log_display_data`.
 *
 * Be sure to `free` the instance when you are done.
 *
 * @param double width The width of the bitmap you will be drawing to.
 * @param double height The height of the bitmap you will be drawing to.
 * @returns bl_log_display_data*
 *
 * **Examples**
 *
 *     bl_log_display_data *data = bl_make_log_display_data(400, 400);
 */
bl_log_display_data *bl_make_log_display_data(double width, double height);

/**
 * Marks a pixel as hit in a `bl_log_display_data` instance.
 *
 * Hits are cumulative and will later be scaled logarithmically.
 *
 * @param bl_log_display_data *data The `bl_log_display_data` to add to.
 * @param double x The x value of the pixel to add.
 * @param double y The y value of the pixel to add.
 *
 * **Examples**
 *
 *     bl_log_display_add(data, 100, 100);
 */
void bl_log_display_add(bl_log_display_data *data, double x, double y);

/**
 * Gets the logarithmically scaled value for a pixel.
 *
 * @param bl_log_display_data *data The `bl_log_display_data` to retrieve a
 * value from.
 * @param double x The x value of the pixel.
 * @param double y The y value of the pixel.
 * returns double
 *
 * **Examples**
 *
 * double value = bl_log_display_get_value(data, 100, 100);
 */
double bl_log_display_get_value(bl_log_display_data *data, double x, double y);

#endif
