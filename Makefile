CC = gcc
CFLAGS = -Wall -Wextra -ggdb
LIBS = -lX11 -lXrandr -lGL -lm
SRC_DIR = src
BUILD_DIR = build

.PHONY: all clean

all: timer $(BUILD_DIR)/png2c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

timer: $(SRC_DIR)/timer.c $(SRC_DIR)/digits.h $(SRC_DIR)/penger_walk_sheet.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/timer.c -o $@ $(LIBS)

$(BUILD_DIR)/png2c: $(SRC_DIR)/png2c.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/png2c.c -o $@ $(LIBS)

$(SRC_DIR)/digits.h: $(BUILD_DIR)/png2c assets/digits.png
	$(BUILD_DIR)/png2c assets/digits.png digits > $@

$(SRC_DIR)/penger_walk_sheet.h: $(BUILD_DIR)/png2c assets/penger_walk_sheet.png
	$(BUILD_DIR)/png2c assets/penger_walk_sheet.png penger > $@

clean:
	rm -rfv $(BUILD_DIR) timer $(SRC_DIR)/digits.h $(SRC_DIR)/penger_walk_sheet.h

