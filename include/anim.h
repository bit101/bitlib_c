#ifndef _ANIM_H_
#define _ANIM_H_

#include "render.h"
#include <cairo.h>

bl_render_config *bl_make_render_config(double width, double height,
                                        double frames, double fps);

void _render_frames(bl_render_config *config, char *gif_name,
                    bl_render_callback render, char *tmp, int num_threads);

void _convert_frames_to_gif(char *frames_dir, char *file_name, double fps);
void _convert_frames_to_video(bl_render_config *config, char *frames_dir,
                              char *file_name, double fps);

#endif
