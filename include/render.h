#ifndef _RENDER_H_
#define _RENDER_H_

#include <cairo.h>

enum bl_render_mode { IMAGE, GIF, VIDEO, SMALL_VIDEO };

typedef struct _bl_render_config {
  double width;
  double height;
  double frames;
  double fps;
} bl_render_config;

typedef void (*bl_render_callback)(cairo_t *cr, double percent);

void bl_render_gif(bl_render_config *config, char *gif_name, int threads,
                   bl_render_callback render);
void bl_render_video(bl_render_config *config, char *mp4_name, int threads,
                     bl_render_callback render);
void bl_render_image(double width, double height, char *png_file_name,
                     bl_render_callback render);

#endif
