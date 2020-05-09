CC := gcc
WARN := -Wno-unused-command-line-argument
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`

test: bin/test
	@echo running test...
	@bin/test
	@eog out.png

bin/test: libs/bitlib.a test/main.c
	@echo compiling test/main.c
	@mkdir -p bin
	@$(CC) $(WARN) $(CFLAGS) test/main.c -Iinclude libs/bitlib.a -o bin/test -lm $(CLIBS)

dist: libs/bitlib.a
	@echo assembling distribution package ...
	@mkdir -p dist
	@cp -r libs dist
	@cp -r include dist

libs/bitlib.a: build build/drawing.o build/point.o build/noise.o build/blmath.o build/geom.o build/color.o
	@echo compiling bitlib.a ...
	@mkdir -p libs
	@ld -r build/drawing.o build/point.o build/noise.o build/color.o build/blmath.o build/geom.o -o libs/bitlib.a

build/drawing.o: src/drawing.c include/drawing.h
	@echo compiling drawing.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/drawing.c -Iinclude -o build/drawing.o -lm $(CLIBS)

build/point.o: src/point.c include/point.h
	@echo compiling point.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/point.c -Iinclude -o build/point.o -lm $(CLIBS)

build/noise.o: src/noise.c include/noise.h
	@echo compiling noise.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/noise.c -Iinclude -o build/noise.o -lm $(CLIBS)

build/color.o: src/color.c include/color.h
	@echo compiling color.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/color.c -Iinclude -o build/color.o -lm $(CLIBS)

build/blmath.o: src/blmath.c include/blmath.h
	@echo compiling blmath.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/blmath.c -Iinclude -o build/blmath.o -lm $(CLIBS)

build/geom.o: src/geom.c include/geom.h
	@echo compiling geom.o ...
	@$(CC) $(WARN) $(CFLAGS) -c src/geom.c -Iinclude -o build/geom.o -lm $(CLIBS)

build:
	@mkdir build

clean:
	@rm -rf build
	@rm -rf bin
	@rm -rf libs
	@rm -rf dist
	@rm -f out.png
