default: drawing.o
	@gcc `pkg-config --cflags gtk+-3.0` main.c drawing.o -o test_one -lm `pkg-config --libs gtk+-3.0`
	@./test_one
	@eog out.png


drawing.o: drawing.c
	@gcc `pkg-config --cflags gtk+-3.0` -c drawing.c -o drawing.o -lm `pkg-config --libs gtk+-3.0`
