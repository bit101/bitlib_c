#include "view.h"
#include <stdio.h>
#include <stdlib.h>

void bl_view_image(char* file_name) {
  char command[255];
  sprintf(command, "eog %s", file_name);
  system(command);
}

void bl_view_video(char* file_name) {
  char command[255];
  sprintf(command, "vlc --verbose 0 %s", file_name);
  system(command);
}
