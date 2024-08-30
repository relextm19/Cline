# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iheader_files -std=c++17

# Directories
SRC_DIR = source_files
OBJ_DIR = build

# Source files
SRCS = main.cpp common.cpp args.cpp file_actions.cpp printing.cpp

# Object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/common.o $(OBJ_DIR)/args.o $(OBJ_DIR)/file_actions.o $(OBJ_DIR)/printing.o

# Executable name
EXEC = cline

# Default target
all: $(EXEC)

# Create object files directory if it doesn't exist
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

# Link the object files to create the executable
$(EXEC): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files into object files
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/common.o: $(SRC_DIR)/common.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/common.cpp -o $(OBJ_DIR)/common.o

$(OBJ_DIR)/args.o: $(SRC_DIR)/args.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/args.cpp -o $(OBJ_DIR)/args.o

$(OBJ_DIR)/file_actions.o: $(SRC_DIR)/file_actions.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/file_actions.cpp -o $(OBJ_DIR)/file_actions.o

$(OBJ_DIR)/printing.o: $(SRC_DIR)/printing.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/printing.cpp -o $(OBJ_DIR)/printing.o

# Clean up build files
clean:
	cmd /C del $(OBJ_DIR)\*.o $(EXEC)
	@rmdir $(OBJ_DIR) 2>nul || true
