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

## Make

Run `make` in project dir to see the demo and make sure things are set up correctly.

Run `make dist` to generate the `bitlib.a` library file into `libs`.

Run `make clean` to remove artifacts, including `libs`.

## Scripts

Copy or update the dist files to another project using the `copy_dist.sh` script, passing the path of the other project.

Create a new project based on the `demo/main.c` file using the `new_project.sh` script, passing the new project path.

## Use of template

In the new project, edit `main.c` to draw different stuff. The `setup()` function lets you specify the output as image, gif or video. You can set render config values (size, frames, fps) for each of those. Custom drawing code goes in the `render` function. The rest is boilerplate.


