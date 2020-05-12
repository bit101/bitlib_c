#ifndef _RENDER_H_
#define _RENDER_H_

#include <gtk/gtk.h>

void bl_render_anim( double width, double height, double frames, double fps, char *gif_name, void (*render)(cairo_t *cr, double percent));
void bl_render_image(double width, double height, char *png_file_name, void (*render)(cairo_t *cr));
void bl_convert_frames_to_gif(char *frames_dir, char *file_name, double fps, bool optimize);
void bl_view_image(char *file_name);

#endif
