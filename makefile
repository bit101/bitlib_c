CC := clang
SRC := src
BUILD := build
LIBS := libs
TARGET := test/main.c
BIN := bin
DIST := dist
EXE := $(BIN)/test
INCLUDE := include
WARN := -Wno-unused-command-line-argument
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`

default: $(EXE)
	@$(EXE)
	@eog out.png

dist: $(LIBS)/bitlib.a
	@mkdir -p $(DIST)
	@cp -r $(LIBS) $(DIST)
	@cp -r $(INCLUDE) $(DIST)

$(EXE): $(LIBS)/bitlib.a $(TARGET)
	@echo compiling $(TARGET) ...
	@mkdir -p $(BIN)
	@$(CC) $(WARN) $(CFLAGS)  $(TARGET) -I$(INCLUDE) $(LIBS)/bitlib.a -o $(EXE) -lm $(CLIBS)


$(LIBS)/bitlib.a: $(BUILD) $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/blmath.o $(BUILD)/color.o
	@echo compiling bitlib.a ...
	@mkdir -p $(LIBS)
	@ld -r $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/color.o $(BUILD)/blmath.o -o $(LIBS)/bitlib.a

$(BUILD)/drawing.o: $(SRC)/drawing.c
	@echo compiling drawing.o ...
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC)/drawing.c -I$(INCLUDE) -o $(BUILD)/drawing.o -lm $(CLIBS)

$(BUILD)/point.o: $(SRC)/point.c
	@echo compiling point.o ...
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC)/point.c   -I$(INCLUDE) -o $(BUILD)/point.o   -lm $(CLIBS)

$(BUILD)/perlin.o: $(SRC)/perlin.c
	@echo compiling perlin.o ...
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC)/perlin.c  -I$(INCLUDE) -o $(BUILD)/perlin.o  -lm $(CLIBS)

$(BUILD)/color.o: $(SRC)/color.c
	@echo compiling color.o ...
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC)/color.c  -I$(INCLUDE) -o $(BUILD)/color.o  -lm $(CLIBS)

$(BUILD)/blmath.o: $(SRC)/blmath.c
	@echo compiling blmath.o ...
	@$(CC) $(WARN) $(CFLAGS) -c $(SRC)/blmath.c  -I$(INCLUDE) -o $(BUILD)/blmath.o  -lm $(CLIBS)

$(BUILD):
	@mkdir $(BUILD)

clean:
	@rm -rf $(BUILD)
	@rm -rf $(BIN)
	@rm -rf $(LIBS)
	@rm -rf $(DIST)
	@rm -f out.png
