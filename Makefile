# Top-level Makefile - recursive approach with static lib
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin
INCLUDE = include
CC = gcc
AR = ar
RANLIB = ranlib
CFLAGS = -Wall -Wextra -std=c99 -I$(INCLUDE) -g

.PHONY: all clean src lib build_static

all: src lib build_static

# Build object files in src/
src:
	$(MAKE) -C $(SRC_DIR) all

# Create static library lib/libmyutils.a from the utility object files
lib: src
	@mkdir -p $(LIB_DIR)
	# create archive from object files (string & file modules only)
	$(AR) rcs $(LIB_DIR)/libmyutils.a $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o
	# ranlib is optional on some systems but harmless
	$(RANLIB) $(LIB_DIR)/libmyutils.a
	@echo "Created static library: $(LIB_DIR)/libmyutils.a"

# Link the static client against the static library
build_static: lib
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/main_static.o -L$(LIB_DIR) -lmyutils -o $(BIN_DIR)/client_static
	@echo "Built $(BIN_DIR)/client_static"

clean:
	$(MAKE) -C $(SRC_DIR) clean
	-rm -rf $(BIN_DIR)
	-rm -rf $(LIB_DIR)
