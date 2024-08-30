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

###Requirements
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
   ./cline -p <path> -r
   ```
   Or just use it without any to use it on the directory you are located in(You must add the compiled program to the path first):
   ```sh
   ./cline
   ```

### Example Command
```sh
./cline -p /your/directory/path -r
```

This will analyze all supported files in the specified directory and its subdirectories, providing a detailed report.

