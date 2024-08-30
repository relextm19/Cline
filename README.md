## Cline

**Cline** is a command-line tool that counts the number of lines, characters, and whitespace in files, displaying the results in a neatly formatted table sorted by file extension.

### Features
- **Line, Character, and Whitespace Counting**: Analyzes files to provide a breakdown of lines, characters, and whitespace.
- **File Extension Support**: Supports multiple file extensions including `.cpp`, `.py`, `.c`, `.java`, `.html`, `.css`, and more.
- **Recursive Mode**: Optionally analyze files in subdirectories with the `-r` flag.

### Modes
- **-p**: Specify the path to the directory you want to analyze.
- **-r**: Enable recursive analysis of subdirectories.
- **-h**: Display help information.

### Requirements
- A C++ compiler such as `g++`, `clang`, or similar.
- C++ version 17 or higher.

### Usage

1. **Compile the Code**:  
   Use your preferred C++ compiler to compile the code. For example, using `g++`:
   ```sh
   g++ -std=c++17 main.cpp -o cline
   ```

2. **Run the Program**:  
   Run the compiled executable, specifying any desired options:
   ```sh
   ./cline -p <path> -r
   ```

### Example Command
```sh
./cline -p /your/directory/path -r
```

This will analyze all supported files in the specified directory and its subdirectories, providing a detailed report.

