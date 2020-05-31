#include "bitlib.h"

extern double width, height;
extern enum bl_render_mode mode;

extern bl_render_config setup();
extern void render(cairo_t* cr, double percent);

////////////////////////////////////////
// MAIN
////////////////////////////////////////
int main(int argc, char** argv) {
  char* out_name;
  bl_render_config config = setup();
  int num_threads = 4;
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
      bl_render_gif(&config, out_name, num_threads, render);
      bl_view_image(out_name);
      break;

    case VIDEO:
    case SMALL_VIDEO:
      out_name = "out.mp4";
      bl_render_video(&config, out_name, num_threads, render);
      bl_view_video(out_name);
      break;

    default:
      // noop
      break;
  }
}
