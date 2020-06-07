#include "render.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "anim.h"
#include "bitlib.h"

char* frames_dir = "bitlib_c_frames";
void _create_frame_dir();
void _remove_frame_dir();

void bl_render_gif(bl_render_config config, char* gif_name, int threads, bl_render_callback render) {
  _create_frame_dir();
  _render_frames(config, gif_name, render, frames_dir, threads);
  _convert_frames_to_gif(frames_dir, gif_name, config.fps);
  _remove_frame_dir();
}

void bl_render_video(bl_render_config config, char* mp4_name, int threads, bl_render_callback render) {
  _create_frame_dir();
  _render_frames(config, mp4_name, render, frames_dir, threads);
  _convert_frames_to_video(config, frames_dir, mp4_name, config.fps);
  _remove_frame_dir();
}

void bl_render_image(double width, double height, char* png_file_name, bl_render_callback render) {
  cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t* cr = cairo_create(surface);
  render(cr, 1);
  cairo_surface_write_to_png(surface, png_file_name);
}

void _create_frame_dir() {
  char command[255];
  sprintf(command, "rm -f %s/*", frames_dir);
  // in case the dir and files are there from an aborted run
  system(command);
  mkdir(frames_dir, S_IRWXU | S_IRWXG | S_IRWXO);
}

void _remove_frame_dir() {
  char* bl_save_frames = getenv("BL_SAVE_FRAMES");
  if (bl_save_frames == NULL || strcmp(bl_save_frames, "1")) {
    char command[255];
    sprintf(command, "rm -f %s/*", frames_dir);
    system(command);
    rmdir(frames_dir);
  }
}
