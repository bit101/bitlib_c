#ifndef _RENDER_H_
#define _RENDER_H_

#include <cairo.h>
typedef struct _anim {
  double width;
  double height;
  double frames;
  double fps;
} bl_anim;

typedef void (*bl_anim_callback)(cairo_t *cr, double percent);
typedef void (*bl_image_callback)(cairo_t *cr);

bl_anim *bl_make_anim(double width, double height, double frames, double fps);
void bl_render_gif(bl_anim *anim, char *gif_name, bl_anim_callback render);
void bl_render_video(bl_anim *anim, char *mp4_name, bl_anim_callback render);
void bl_render_image(double width, double height, char *png_file_name,
                     bl_image_callback render);
void bl_convert_frames_to_gif(char *frames_dir, char *file_name, double fps);
void bl_convert_frames_to_video(bl_anim *anim, char *frames_dir,
                                char *file_name, double fps);
void bl_view_image(char *file_name);
void bl_vlc(char *file_name);

#endif
