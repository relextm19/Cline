#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <filesystem>
#include <map>

//!UPDATE THIS ARRAY TO ADD MORE FILE EXTENSIONS
extern std::string allowed_extensions[30];

extern bool recursive;

extern std::map<std::string, unsigned int> extension_sum;

extern int max_column_width;

struct File_Data{
    std::string file_name;
    unsigned int line_count = 0;
    unsigned int character_count = 0;
    unsigned int whitespace_count = 0; 
};


#endif // COMMON_H