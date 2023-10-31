# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++20 -O3

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
APP_DIR = apps

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Header files
INCS = -I$(INCLUDE_DIR)

# Executable name
EXECUTABLE = my_program

# Libraries
LIBS = -I/opt/homebrew/opt/openblas/include -L/opt/homebrew/opt/openblas/lib -lopenblas

# Makefile targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) main.cpp $(OBJS) $(LIBS) -o apps/$@
	$(CC) $(CFLAGS) generate_test_matrices.cpp $(OBJS) $(LIBS) -o apps/generate_test_matrices

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(LIBS) $(INCS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXECUTABLE) apps/*

run:
	./apps/$(EXECUTABLE)

matrix_gen:
	rm -rf res/*
	make all
	./apps/generate_test_matrices

.PHONY: all clean
