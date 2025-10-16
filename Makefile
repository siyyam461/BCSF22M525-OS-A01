# Top-level Makefile - recursive approach
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE = include

.PHONY: all clean src build

all: src build

# Recursive call to src/Makefile to produce .o files in ../obj
src:
	$(MAKE) -C $(SRC_DIR) all

# Link objects into binary
build:
	@mkdir -p $(BIN_DIR)
	$(CC) -Wall -Wextra -std=c99 -I$(INCLUDE) $(OBJ_DIR)/*.o -o $(BIN_DIR)/client

clean:
	$(MAKE) -C $(SRC_DIR) clean
	-rm -rf $(BIN_DIR)

