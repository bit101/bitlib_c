default: build build/bitlib.a
	@gcc `pkg-config --cflags gtk+-3.0` main.c build/bitlib.a -o test_one -lm `pkg-config --libs gtk+-3.0`
	@./test_one
	@eog out.png


build/drawing.o: src/drawing.c
	@gcc `pkg-config --cflags gtk+-3.0` -c src/drawing.c -o build/drawing.o -lm `pkg-config --libs gtk+-3.0`

build/point.o: src/point.c
	@gcc `pkg-config --cflags gtk+-3.0` -c src/point.c -o build/point.o -lm `pkg-config --libs gtk+-3.0`

build/perlin.o: src/perlin.c
	@gcc `pkg-config --cflags gtk+-3.0` -c src/perlin.c -o build/perlin.o -lm `pkg-config --libs gtk+-3.0`

build/bitlib.a: build/drawing.o build/point.o build/perlin.o
	@ld -r build/drawing.o build/point.o build/perlin.o -o build/bitlib.a

build:
	@mkdir build

clean:
	@rm *.a
	@rm *.o
	@rm out.png
