CXX = g++
CPPFLAGS = -Wall -pthread
INCLUDE_DIR = include
SRC_DIR = src
TARGET = main

ifdef DEBUG
CPPFLAGS += -g -DDEBUG
endif

# Add all C source files in the src directory to the SOURCES variable
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Replace .c extensions with .o extensions for each source file
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=%.o)

# Add include directory to the compiler's include path
CPPFLAGS += -I$(INCLUDE_DIR)

# Default target: build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $@ $(OBJECTS)

# Build object files from C source files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(TARGET) $(OBJECTS)
