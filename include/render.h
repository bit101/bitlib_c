#ifndef _RENDER_H_
#define _RENDER_H_

#include "anim.h"

typedef void (*bl_image_callback)(cairo_t *cr);

void bl_render_gif(bl_anim *anim, char *gif_name, int threads,
                   bl_anim_callback render);
void bl_render_video(bl_anim *anim, char *mp4_name, int threads,
                     bl_anim_callback render);
void bl_render_image(double width, double height, char *png_file_name,
                     bl_image_callback render);

#endif
