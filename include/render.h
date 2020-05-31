#ifndef _RENDER_H_
#define _RENDER_H_

#include <cairo.h>

/**
 * An enum to specify the type of render (image, gif, video or small video)
 * being done.
 */
enum bl_render_mode { IMAGE, GIF, VIDEO, SMALL_VIDEO };

/**
 * A struct to hold information about the render being done.
 */
typedef struct _bl_render_config {
  double width;
  double height;
  double frames;
  double fps;
} bl_render_config;

/**
 * An interface for a render callback function.
 *
 * Create a function conforming to this interface and pass it to
 * `bl_render_image`, `bl_render_gif` or `bl_render_video`. This function will
 * get called once for an image, or once per frame for a gif or video.
 *
 * For an image, the `percent` value will always be 1. For animations it will
 * interpolate between 0 and 1 for the first through the last frames. Use
 * percent to alter the drawing code on each frame.
 *
 * @param cairo_t *cr The cairo context your render function will draw to.
 * @param double percent The percent of the way through the full animation.
 *
 * **Examples**
 *
 *     void render(cairo_t *cr, double percent) {
 *         // draw to cr here
 *     }
 *     bl_render_gif(config, "out.gif", 4, render);
 */
typedef void (*bl_render_callback)(cairo_t* cr, double percent);

/**
 * Renders multiple frames of an animation and saves them to an animated gif.
 *
 * @param bl_render_config *config The configuration file for the animation.
 * @param char *gif_name The path of the output gif.
 * @param int threads How many threads to use for rendering all the frames.
 * @param bl_render_callback render The callback function that will do the
 * drawing for each frame.
 *
 * **Examples**
 *
 *     bl_render_gif(config, "out.gif", 4, render);
 */
void bl_render_gif(bl_render_config* config, char* gif_name, int threads, bl_render_callback render);

/**
 * Renders multiple frames of an animation and saves them to an mp4 video file.
 *
 * @param bl_render_config *config The configuration file for the animation.
 * @param char *mp4_name The path of the output video.
 * @param int threads How many threads to use for rendering all the frames.
 * @param bl_render_callback render The callback function that will do the
 * drawing for each frame.
 *
 * **Examples**
 *
 *     bl_render_video(config, "out.mp4", 4, render);
 */
void bl_render_video(bl_render_config* config, char* mp4_name, int threads, bl_render_callback render);

/**
 * Renders an image and saves it as a png.
 *
 * @param bl_render_config *config The configuration file for the image.
 * @param char *png_file_name The path of the output png.
 * @param bl_render_callback render The callback function that will draw the
 * image.
 *
 * **Examples**
 *
 *     bl_render_image(config, "out.png", render);
 */
void bl_render_image(double width, double height, char* png_file_name, bl_render_callback render);

#endif
