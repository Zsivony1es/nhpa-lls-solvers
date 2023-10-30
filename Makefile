# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -O3

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

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXECUTABLE) apps/*

run:
	./apps/$(EXECUTABLE)

.PHONY: all clean
