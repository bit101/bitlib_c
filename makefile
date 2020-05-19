CC := gcc
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`
VERSION := v0.2.0
SRC := src/*.c
INC := include/*.h

default: bin/main
	@echo running main...
	@./bin/main

bin/main: libs/bitlib.a demo/main.c
	@echo compiling main...
	@mkdir -p bin
	@$(CC) $(WARN) $(CFLAGS) demo/main.c -Iinclude libs/bitlib.a -o bin/main -lm $(CLIBS)

dist: libs/bitlib.a
	@echo assembling distribution package for version $(VERSION) ...
	@mkdir -p dist
	@cp -r libs dist
	@cp -r include dist
	@echo $(VERSION) > dist/version.txt
	@zip -rq $(VERSION).zip ./dist

libs/bitlib.a: $(SRC) $(INC)
	@echo compiling bitlib.a ...
	@mkdir -p build
	@mkdir -p libs
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC) -Iinclude  -lm $(CLIBS)
	@mv *.o build/
	@ld -r build/*.o -o libs/bitlib.a

clean:
	@echo cleaning...
	@rm -rf build
	@rm -rf bin
	@rm -rf libs
	@rm -rf dist
	@rm -f *.png
	@rm -f *.gif
	@rm -f *.mp4
	@rm -f v*.zip
