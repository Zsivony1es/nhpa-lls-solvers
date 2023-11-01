# Compiler and compiler flags
CC = g++
CXX = g++
CFLAGS = -std=c++20 -O3
CXXFLAGS = -std=c++20 -O3

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
APP_DIR = apps
TEST_DIR = tests
TEST_APP_DIR = apps/tests

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Header files
INCS = -I$(INCLUDE_DIR)

# Executable names
EXECUTABLE = main
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_APP_DIR)/%,$(TEST_SRCS:.cpp=))

# Libraries
LIBS = -I/opt/homebrew/opt/openblas/include -L/opt/homebrew/opt/openblas/lib -lopenblas

# Makefile targets
all: $(EXECUTABLE) $(TEST_EXECUTABLES)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) main.cpp $(OBJS) $(LIBS) $(INCS) -o apps/$@
	$(CC) $(CFLAGS) generate_test_matrices.cpp $(OBJS) $(LIBS) $(INCS) -o apps/generate_test_matrices

$(TEST_EXECUTABLES): $(OBJS)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(OBJS) $(LIBS) $(INCS) -o apps/$@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(LIBS) $(INCS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(APP_DIR)
	mkdir $(APP_DIR)
	mkdir $(TEST_APP_DIR)

run:
	./apps/$(EXECUTABLE)

matrix_gen:
	rm -rf res/*
	make all
	./apps/generate_test_matrices

test: $(TEST_EXECUTABLES)
	./$(APP_DIR)/$(TEST_EXECUTABLES)

.PHONY: all clean run test matrix_gen
