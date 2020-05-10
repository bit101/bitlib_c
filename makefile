CC := clang
WARN := -Wno-unused-command-line-argument
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`
VERSION := v0.1.1

SRC := src/*.c
INC := include/*.h

test: bin/test
	@echo running test...
	@bin/test
	@eog out.png

bin/test: libs/bitlib.a test/main.c
	@echo compiling test/main.c
	@mkdir -p bin
	@$(CC) $(WARN) $(CFLAGS) test/main.c -Iinclude libs/bitlib.a -o bin/test -lm $(CLIBS)

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
	@rm -rf build
	@rm -rf bin
	@rm -rf libs
	@rm -rf dist
	@rm -f out.png
	@rm -f v*.zip
