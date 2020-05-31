#ifndef _VIEW_H_
#define _VIEW_H_

/**
 * Displays an image.
 *
 * This implementation uses eog (Eye of Gnome) image viewer on Linux.
 *
 * @param char *file_name The path of the image to display.
 *
 * **Examples**
 *
 *     bl_view_image("out.png");
 */
void bl_view_image(char* file_name);

/**
 * Displays a video.
 *
 * This implementation uses vlc video player.
 *
 * @param char *file_name The path of the video to display.
 *
 * **Examples**
 *
 *     bl_view_video("out.mp4");
 */
void bl_view_video(char* file_name);

#endif
