# bitlib_c

bitlib graphics library ported to c (gtk/cairo).

Mainly tested on Linux machines. Some testing has been done on Macos and it should compile and run. See notes below.

## Requirements

- `gtk3` dev libraries: `cairo`, `glib`, some others. Best just to install `gtk3`.

  - Debian / Ubuntu: `libgtk-3-dev`.
  
  - Arch: `gtk`

  - Manjaro: already has `gtk` installed.

- `gcc` but works fine with `clang` as well.

- `pkg-config` 

- `imagemagick` for gif creation

- `ffmpeg` for video creation

- `eog` for image viewing

- `vlc` for video viewing

## Make

Run `make dist`:

  - generates the `bitlib.a` and `libbitlib.so` library files into `libs` folder.

  - copies `libs` and `include` into `dist` folder.

  - zips dist into a ditribution zip file based on the verion defined in `makefile`

Run `make clean`:

  - removes all build artifacts, including `libs`.

## Install

To install the library system-wide, run the `install.sh` script.

This script does three things: 

1. First it runs `make dist` to generate a fresh copy of the library files.

2. Then it copies the files in `dist/include` to `/usr/include/bitlib/`.

3. Then it copies `libbitlib.so` to `/user/lib64/`.

If your system is set up differently than the above, you'll have to figure out where to put those files so that your compiler will find them.

You'll only have to do the install once. Then any projects you create will have access to the library.

Include any bitlib headers in your files by using the following statment:

    #include <bitlib/bitlib.h>

Add the library to your compile by using the following in your gcc or clang call:

    -lbitlib

The older method of copying the `include` folder and `bitlib.a` file to a project will still work, but is no longer the recommended way to create a project. The demo project depends on the library being installed system-wide.

## Uninstall

To remove the library files from your `/usr` directory, you can either just delete `/usr/include/bitlib` and `/usr/lib64/libbitlib.so` or run the `uninstall.sh` script which does just that.

## Project Template and Script

Generate a new project with `new_project.sh`. The project in `demo` itself is incomplete and will not run by itself. Use the `new_project.sh` script to generate a runnable project elsewhere. Pass the path of the new project to the script. Example:

    ./new_project.sh ../test
    cd ../test
    make

## Use of template

In the new project, edit `sketch.c` to create your image or animation.

The `setup()` function lets you specify the output as image, gif or video.  You can set render config values (size, frames, fps) for each of those.

Custom drawing code goes in the `render` function.

You can create multiple sketch files. To run a different one, open `makefile` and change the value of `SKETCH_C` at the top to point to the location of the sketch you want to compile.

There's usually no need to touch the `main.c` file or the rest of `makefile`, but there are a couple of configuration items possible.

- The renderer will use 4 threads by default when rendering animation frames. You can change `num_threads` in `main.c` to increase or decrease that number at your own risk.

- The renderer will spit out some console logs before, during and after the rendering process. This can interfere with any logging you might be doing in your own sketch files. You can set the environmental variable `BL_QUIET` to `1` to squelch this output. This can be set in the `makefile`.

## API Docs

[bitlib_c documentation](https://bit101.github.io/bitlib_c/index.html)


## Compiling on Macos

I'm explicitly NOT supporting this library on anything but Linux based operating systems.

That said, I have gotten it compiling and working on Macos. You'll have to fiddle with some settings system-wide and figure out how to handle various warnings and errors. I'll list some of what I've found here. But this should only be taken as advice, not any kind of statement of support for that platform.

You might wind up with various warnings about text-based stub files being out of sync.

See: stackoverflow.com/questions/51314888/ld-warning-text-based-stub-file-are-out-of-sync-falling-back-to-library-file/55344565

Steps to resolve:

1. Run xcrun --show-sdk-path

2. Copy the path that this outputs.

3. Then: `export SDKROOT="<output path from step 1>`

The `bl_view_image` and `bl_view_video` functions are hardcoded to run `eog` and `vlc`. This won't work if you don't have those installed. You can set up your own view functions by using `system`. Example:

`system("open out.png");`

