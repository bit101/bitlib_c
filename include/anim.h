#ifndef _ANIM_H_
#define _ANIM_H_

#include "render.h"
#include <cairo.h>

/**
 * Creates animation/image config
 * Creates an instance of `bl_render_config` for creating an animation or image.
 * @param double width The width of the image or animation.
 * @param double height The height of the image or animation.
 * @param double frames The number of frames in the animation.
 * Equal to the fps * seconds of animation.
 * @param double fps Frames per second of the animation.
 * @returns bl_render_config
 */
bl_render_config *bl_make_render_config(double width, double height,
                                        double frames, double fps);

/**
 * Renders each frame of an animation into png files in a folder. Internal use
 * only.
 * @param bl_render_config *config Contains information on how to render the
 * frames.
 * @param char *gif_name The output file name.
 * @param bl_render_callback *render The function that draws each frame.
 * @param char *tmp The file to store the frames in. Usually deleted
 * post-render.
 * @param int num_threads How many threads to use to render this animation.
 */
void _render_frames(bl_render_config *config, char *gif_name,
                    bl_render_callback render, char *tmp, int num_threads);

/**
 * Converts the frames in the temp folder into an animated gif. Internal use
 * only.
 * @param char *frames_dir Where the frames are stored.
 * @param char *file_name The name of the output file.
 * @param double fps. Frames per second for the animation.
 */
void _convert_frames_to_gif(char *frames_dir, char *file_name, double fps);

/**
 * Converts the frames in the temp folder into a video. Internal use only.
 * @param char *frames_dir Where the frames are stored.
 * @param char *file_name The name of the output file.
 * @param double fps. Frames per second for the animation.
 */
void _convert_frames_to_video(bl_render_config *config, char *frames_dir,
                              char *file_name, double fps);

#endif
