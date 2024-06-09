# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -lm -ggdb

# Define the source and build directories
SRC_DIR = src
BUILD_DIR = build

# Define the target executable
TARGET = $(BUILD_DIR)/draw_cube

# List all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate object files list
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean

