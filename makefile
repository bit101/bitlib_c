CC := gcc
SRC := src
BUILD := build
LIBS := libs
TARGET := test/main.c
BIN := bin
DIST := dist
EXE := $(BIN)/test
INCLUDE := include
CFLAGS := `pkg-config --cflags gtk+-3.0`
CLIBS := `pkg-config --libs gtk+-3.0`

default: $(EXE)
	@$(EXE)
	@eog out.png

dist: $(LIBS) $(LIBS)/bitlib.a
	@mkdir -p $(DIST)
	@cp -r $(LIBS) $(DIST)
	@cp -r $(INCLUDE) $(DIST)

$(EXE): $(BIN) $(LIBS) $(LIBS)/bitlib.a $(TARGET)
	@$(CC) $(CFLAGS)  $(TARGET) -I$(INCLUDE) $(LIBS)/bitlib.a -o $(EXE) -lm $(CLIBS)


$(LIBS)/bitlib.a: $(BUILD) $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/color.o
	@ld -r $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/color.o -o $(LIBS)/bitlib.a

$(BUILD)/drawing.o: $(SRC)/drawing.c
	@$(CC) $(CFLAGS) -c $(SRC)/drawing.c -I$(INCLUDE) -o $(BUILD)/drawing.o -lm $(CLIBS)

$(BUILD)/point.o: $(SRC)/point.c
	@$(CC) $(CFLAGS) -c $(SRC)/point.c   -I$(INCLUDE) -o $(BUILD)/point.o   -lm $(CLIBS)

$(BUILD)/perlin.o: $(SRC)/perlin.c
	@$(CC) $(CFLAGS) -c $(SRC)/perlin.c  -I$(INCLUDE) -o $(BUILD)/perlin.o  -lm $(CLIBS)

$(BUILD)/color.o: $(SRC)/color.c
	@$(CC) $(CFLAGS) -c $(SRC)/color.c  -I$(INCLUDE) -o $(BUILD)/color.o  -lm $(CLIBS)

$(BUILD):
	@mkdir $(BUILD)

$(LIBS):
	@mkdir $(LIBS)

$(BIN):
	@mkdir $(BIN)

clean:
	@rm -rf $(BUILD)
	@rm -rf $(BIN)
	@rm -rf $(LIBS)
	@rm -rf $(DIST)
	@rm -f out.png
