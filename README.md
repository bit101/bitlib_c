# bitlib_c

bitlib graphics library ported to c (gtk/cairo).

So far only tested on Linux machines. 

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

  - generates the `bitlib.a` library file into `libs` folder.

  - copies `libs` and `include` into `dist` folder.

  - zips dist into a ditribution zip file based on the verion defined in `makefile`

Run `make clean`:

  - removes all build artifacts, including `libs`.

## Scripts

Add or update the dist files to another project using the `copy_dist.sh` script, passing the path of the other project. Example:

    ./copy_dist.sh ../existing_project

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
