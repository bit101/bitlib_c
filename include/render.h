#ifndef _RENDER_H_
#define _RENDER_H_

#include <cairo.h>
typedef void (*bl_anim_callback)(cairo_t *cr, double percent);
typedef void (*bl_image_callback)(cairo_t *cr);

void bl_render_gif( double width, double height, double frames, double fps, char *gif_name, bl_anim_callback render);
void bl_render_video( double width, double height, double frames, double fps, char *mp4_name, bl_anim_callback render);
void bl_render_image(double width, double height, char *png_file_name, bl_image_callback render);
void bl_convert_frames_to_gif(char *frames_dir, char *file_name, double fps);
void bl_convert_frames_to_video(char *frames_dir, char *file_name, double fps);
void bl_view_image(char *file_name);
void bl_vlc(char *file_name);

#endif
