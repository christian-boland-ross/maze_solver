CC = gcc

CFLAGS = -Wall -Wextra -g

SRC_DIR = source
GRAPHICS_DIR = graphics

SOURCES = $(wildcard $(SRC_DIR)/*.c) $(GRAPHICS_DIR)/graphics.c

TARGET = maze

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -I$(GRAPHICS_DIR) -I$(SRC_DIR) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) | java -jar $(GRAPHICS_DIR)/drawapp-5.0.jar

clean:
	rm -f $(TARGET)