# PROJECT
APP = petfera

# DEFAULT DIRECTORY TREE
INC_DIR = ./include
SRC_DIR = ./src
# MAKED DIRECTORIES
BIN_DIR = ./bin
OBJ_DIR = ./build
DATA_DIR = ./data
# COMPILING OPTIONS
CC = g++
CFLAGS = -g -Wall -pedantic -ansi -std=c++14 -lm -I$(INC_DIR)
CFILES = main employee animal infra

# RULES AHEAD

define ENDL


endef

.PHONY: all dir clean

$(APP): all
	@echo ":: DEPLOYING:"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(@) $(OBJ_DIR)/*
	@echo "============================================="
	@echo ":: DONE AND READY TO RUN: $(BIN_DIR)/$(@)"
	@echo "============================================="

all: dir
	@echo ":: BUILDING ALL SOURCE FILES:"
	$(foreach file, $(CFILES),\
		$(CC) $(CFLAGS)\
		-c $(SRC_DIR)/$(file).cpp\
		-o $(OBJ_DIR)/$(file).o;\
		$(ENDL)\
	)
	@echo "============================================="

dir: clean
	@echo ":: MAKING DIRECTORIES:"
	mkdir -p $(BIN_DIR) $(OBJ_DIR) $(DATA_DIR)
	@echo "============================================="

clean:
	@echo ":: CLEANING DIRECTORIES:"
	rm -rf $(BIN_DIR) $(OBJ_DIR) $(DATA_DIR)
	@echo "============================================="
