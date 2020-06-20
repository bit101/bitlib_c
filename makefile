CC := gcc
WARN := -Wno-unused-command-line-argument
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`
VERSION := v0.2.4
SRC := src/*.c
INC := include/*.h

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
	@rm build/*

	@echo compiling libbitlib.so ...
	@$(CC) $(WARN) $(CFLAGS) -fPIC -c $(SRC) -Iinclude  -lm $(CLIBS)
	@mv *.o build/
	@gcc build/*.o -shared -o libs/libbitlib.so

docs: $(INC)
	@doxygen Doxyfile

clean:
	@echo cleaning...
	@rm -rf build
	@rm -rf libs
	@rm -rf dist
	@rm -f v*.zip
