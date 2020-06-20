# set the sketch file you want to render here.
SKETCH_C := sketch.c

# don't change any of this unless you know what you are doing.
CC := gcc
WARN := -Wno-unused-command-line-argument
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`
BITLIB := -lbitlib
SKETCH_O := $(SKETCH_C:.c=.o)

# to hide the command line progress while rendering, set BL_QUIET to 1
# to save the intermediate frames created when rendering a gif or video set BL_SAVE_FRAMES to 1
default: main
	@BL_QUIET=0 BL_SAVE_FRAMES=0 bash -c "./main"

main: main.c $(SKETCH_O)
	@$(CC) $(WARN) $(CFLAGS) -Iinclude main.c $(SKETCH_O) $(BITLIB) -o main -lm $(CLIBS)

$(SKETCH_O): $(SKETCH_C)
	@$(CC) $(WARN) $(CFLAGS) -Iinclude -c $(SKETCH_C) -lm $(CLIBS)

clean:
	@rm -f main
	@rm -f out.gif
	@rm -f out.mp4
	@rm -f out.png
	@rm -rf bitlib_c_frames
