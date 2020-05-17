#ifndef _ANIM_H_
#define _ANIM_H_

#include <cairo.h>

typedef struct _bl_anim {
  double width;
  double height;
  double frames;
  double fps;
} bl_anim;

bl_anim *bl_make_anim(double width, double height, double frames, double fps);

typedef void (*bl_anim_callback)(cairo_t *cr, double percent);

void _render_anim(bl_anim *anim, char *gif_name, bl_anim_callback render,
                  char *tmp, int num_threads);

void _convert_frames_to_gif(char *frames_dir, char *file_name, double fps);
void _convert_frames_to_video(bl_anim *anim, char *frames_dir, char *file_name,
                              double fps);

#endif
