# Top-level Makefile - builds static and shared libraries and clients
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin
INCLUDE = include
CC = gcc
AR = ar
RANLIB = ranlib
CFLAGS = -Wall -Wextra -std=c99 -I$(INCLUDE) -g
PICFLAGS = -fPIC

.PHONY: all clean src lib_static lib_shared build_static build_dynamic

all: src lib_static lib_shared build_static build_dynamic

# Build object files in src/
src:
	$(MAKE) -C $(SRC_DIR) all

# Static library (as before)
lib_static: src
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $(LIB_DIR)/libmyutils.a $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o
	$(RANLIB) $(LIB_DIR)/libmyutils.a
	@echo "Created $(LIB_DIR)/libmyutils.a"

# Shared library: use PIC objects (the .pic.o produced by src/Makefile)
lib_shared: src
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -o $(LIB_DIR)/libmyutils.so $(OBJ_DIR)/mystrfunctions.pic.o $(OBJ_DIR)/myfilefunctions.pic.o
	@echo "Created $(LIB_DIR)/libmyutils.so"

# Build static client (LINK DIRECTLY to the static archive)
build_static: lib_static
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/main_static.o $(LIB_DIR)/libmyutils.a -o $(BIN_DIR)/client_static
	@echo "Built $(BIN_DIR)/client_static (statically linked to libmyutils.a)"

# Build dynamic client (links against shared lib)
build_dynamic: lib_shared
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/main_dynamic.o -L$(LIB_DIR) -lmyutils -o $(BIN_DIR)/client_dynamic
	@echo "Built $(BIN_DIR)/client_dynamic (dynamically linked to libmyutils.so)"

clean:
	$(MAKE) -C $(SRC_DIR) clean
	-rm -rf $(BIN_DIR)
	-rm -rf $(LIB_DIR)
	-rm -rf $(OBJ_DIR)
