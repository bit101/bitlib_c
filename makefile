CC := gcc
SRC := src
BUILD := build
TARGET := test/main.c
BIN := bin
EXE := $(BIN)/test
INCLUDE := include
CFLAGS := `pkg-config --cflags gtk+-3.0`
LIBS := `pkg-config --libs gtk+-3.0`

default: $(EXE)
	@$(EXE)
	@eog out.png

$(EXE): $(BIN) $(BUILD) $(BUILD)/bitlib.a $(TARGET)
	@$(CC) $(CFLAGS)  $(TARGET) -I$(INCLUDE) $(BUILD)/bitlib.a -o $(EXE) -lm $(LIBS)


$(BUILD)/bitlib.a: $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/color.o
	@ld -r $(BUILD)/drawing.o $(BUILD)/point.o $(BUILD)/perlin.o $(BUILD)/color.o -o $(BUILD)/bitlib.a

$(BUILD)/drawing.o: $(SRC)/drawing.c
	@$(CC) $(CFLAGS) -c $(SRC)/drawing.c -I$(INCLUDE) -o $(BUILD)/drawing.o -lm $(LIBS)

$(BUILD)/point.o: $(SRC)/point.c
	@$(CC) $(CFLAGS) -c $(SRC)/point.c   -I$(INCLUDE) -o $(BUILD)/point.o   -lm $(LIBS)

$(BUILD)/perlin.o: $(SRC)/perlin.c
	@$(CC) $(CFLAGS) -c $(SRC)/perlin.c  -I$(INCLUDE) -o $(BUILD)/perlin.o  -lm $(LIBS)

$(BUILD)/color.o: $(SRC)/color.c
	@$(CC) $(CFLAGS) -c $(SRC)/color.c  -I$(INCLUDE) -o $(BUILD)/color.o  -lm $(LIBS)

$(BUILD):
	@mkdir $(BUILD)

bin:
	@mkdir $(BIN)

clean:
	@rm -rf $(BUILD)
	@rm -rf $(BIN)
	@rm out.png
