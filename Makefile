# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude -g
LDFLAGS = -lm

# Directories
SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
CORE_DIR = $(SRC_DIR)/core
INCLUDE_DIR = include
BUILD_DIR = build
DATA_DIR = data

# Output binary
TARGET = $(BUILD_DIR)/calculator

# Source and object files
APP_SRCS = $(wildcard $(APP_DIR)/*.c)
CORE_SRCS = $(wildcard $(CORE_DIR)/*.c)
SRCS = $(APP_SRCS) $(CORE_SRCS)
APP_OBJS = $(patsubst $(APP_DIR)/%.c, $(BUILD_DIR)/%.o, $(APP_SRCS))
CORE_OBJS = $(patsubst $(CORE_DIR)/%.c, $(BUILD_DIR)/%.o, $(CORE_SRCS))
OBJS = $(APP_OBJS) $(CORE_OBJS)

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Build object files for app
$(BUILD_DIR)/%.o: $(APP_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build object files for core
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Reset history data
reset-history:
	rm -f $(DATA_DIR)/history.csv

.PHONY: all clean run reset-history