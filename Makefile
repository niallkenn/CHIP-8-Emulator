CC = gcc

CC_FLAGS = -Wall -Wextra -I./src
LD_FLAGS = -lX11

SRC_DIR = src
BUILD_DIR = src/build

C_SRCS := $(shell find $(SRC_DIR) -type f -name '*.c');

MAIN = $(BUILD_DIR)/main

.PHONY: all clean run

all: $(MAIN)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(MAIN): $(C_SRCS) | $(BUILD_DIR)
	@$(CC) $(CC_FLAGS) $(C_SRCS) -o $(MAIN) $(LD_FLAGS)

clean:
	@rm -rf $(BUILD_DIR)

run: $(MAIN)
	@$(MAIN)