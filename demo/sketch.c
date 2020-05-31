#include <cairo.h>
#include <glib.h>
#include "bitlib.h"

double width, height;
enum bl_render_mode mode;

////////////////////////////////////////
// SETUP
////////////////////////////////////////

bl_render_config setup() {
  // IMAGE, GIF, VIDEO, SMALL_VIDEO
  mode = IMAGE;

  // width, height, frames (fps*seconds), fps
  bl_render_config configs[4] = {
      {800, 800, 0, 0},          // IMAGE
      {400, 400, 30 * 2, 30},    // GIF
      {1920, 1080, 30 * 2, 30},  // VIDEO
      {640.0, 360, 30 * 2, 30},  // SMALL_VIDEO
  };
  return configs[mode];
}

////////////////////////////////////////
// RENDER
////////////////////////////////////////

void render(cairo_t* cr, double percent) {
  // percent will be 1.0 when rendering an image
  cairo_clear_rgb(cr, 1, 1, 1);
  cairo_set_line_width(cr, 0.5);

  for (int i = 0; i < 20; i++) {
    cairo_line_to(cr, g_random_double_range(0, width * percent), g_random_double_range(0, height));
  }
  cairo_stroke(cr);

  // where all the magic happens!
}
