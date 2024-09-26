## Cline

**Cline** is a command-line tool that counts the number of lines, characters, and whitespace in files, displaying the results in a neatly formatted table sorted by file extension.

### Features
- **Line, Character, and Whitespace Counting**: Analyzes files to provide a breakdown of lines, characters, and whitespace.
- **File Extension and Directory Banning**: 
- **Recursive Mode**: 

### Modes
- **-r**: Enable recursive analysis of subdirectories.
- **-h**: Display help information.
- **-e**: Ban file extensions
- **-d**: Ban directories

### Requirements
A C++ compiler such as g++, clang, or similar.
C++ version 17 or higher.
Make utility installed on your system to use the provided Makefile.

### Usage

1. **Compile the Code**:  
   Compile code with make using
   ```sh
   make
   ```

3. **Run the Program**:  
   Run the compiled executable, specifying any desired options:
   ```sh
   ./cline -r
   ```
   Or just use it without any to use it on the directory you are located in(You must add the compiled program to the path first):
   ```sh
   ./cline
   ```

### Example Command
```sh
./cline -r -e '.exe'
```

This will analyze all supported files in the specified directory and its subdirectories, providing a detailed report.

