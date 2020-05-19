#include "bitlib.h"
#include <cairo.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

enum render_mode { IMAGE, GIF, VIDEO, SMALL_VIDEO } mode;
double width, height;

////////////////////////////////////////
// SETUP
////////////////////////////////////////

bl_render_config setup() {
  // IMAGE, GIF, VIDEO, SMALL_VIDEO
  mode = GIF;

  // width, height, frames, fps
  bl_render_config configs[4] = {
      {800, 800, 0, 0},     // IMAGE
      {400, 400, 60, 30},   // GIF
      {1920, 1080, 60, 30}, // VIDEO
      {640, 360, 60, 30},   // SMALL_VIDEO
  };
  return configs[mode];
}

////////////////////////////////////////
// RENDER
////////////////////////////////////////

void render(cairo_t *cr, double percent) {
  // percent will be 1.0 when rendering an image
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_set_line_width(cr, 0.5);

  for (int i = 0; i < 20; i++) {
    cairo_line_to(cr, g_random_double_range(0, width * percent),
                  g_random_double_range(0, height));
  }
  cairo_stroke(cr);

  // where all the magic happens!
}

////////////////////////////////////////
// MAIN
////////////////////////////////////////
int main(int argc, char **argv) {
  char *out_name;
  bl_render_config config = setup();
  width = config.width;
  height = config.height;

  switch (mode) {
  case IMAGE:
    out_name = "out.png";
    bl_render_image(width, height, out_name, render);
    bl_view_image(out_name);
    break;

  case GIF:
    out_name = "out.gif";
    bl_render_gif(&config, out_name, 4, render);
    bl_view_image(out_name);
    break;

  case VIDEO:
  case SMALL_VIDEO:
    out_name = "out.mp4";
    bl_render_video(&config, out_name, 4, render);
    bl_view_video(out_name);
    break;

  default:
    // noop
    break;
  }
}
