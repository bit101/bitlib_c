default: bitlib.a
	@gcc `pkg-config --cflags gtk+-3.0` main.c drawing.o point.o -o test_one -lm `pkg-config --libs gtk+-3.0`
	@./test_one
	@eog out.png


drawing.o: drawing.c
	@gcc `pkg-config --cflags gtk+-3.0` -c drawing.c -o drawing.o -lm `pkg-config --libs gtk+-3.0`

point.o: point.c
	@gcc `pkg-config --cflags gtk+-3.0` -c point.c -o point.o -lm `pkg-config --libs gtk+-3.0`

bitlib.a: drawing.o point.o
	@ld -r drawing.o point.o -o bitlib.a
