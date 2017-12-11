# PROJECT
APP = petfera

# DEFAULT DIRECTORY TREE
INC_DIR = ./include
SRC_DIR = ./src
# MAKED DIRECTORIES
BIN_DIR = ./bin
OBJ_DIR = ./build
# COMPILING OPTIONS
CC = g++
CFLAGS = -Wall -pedantic -ansi -std=c++14 -lm -I$(INC_DIR)
CFILES = main

# RULES

.PHONY: all dir clean

# MAKE THE BINARY EXECUTABLE
$(APP): all
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(@) $(OBJ_DIR)/main.o
	@echo ":: SUCCESSFULLY DEPLOYED: $(BIN_DIR)/$(@)"

# COMPILE ALL DEPENDENCY OBJECTS
all: dir
	$(foreach file, $(CFILES),\
		$(CC) $(CFLAGS)\
		-c $(SRC_DIR)/$(file).cpp\
		-o $(OBJ_DIR)/$(file).o\
	)

# MAKE DIRECTORY TREE
dir: clean
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

# CLEAN A MAKED DIRECTORY TREE
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
