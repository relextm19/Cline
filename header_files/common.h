#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <filesystem>
#include <map>
#include <vector>
#include <string>
#include <thread>
#include <iomanip>
#include <fstream>
#include <time.h>
#include "thread_pool.h"


extern std::vector<std::string> banned_extensions;
extern std::vector<std::filesystem::path> banned_directories;


extern bool recursive;

extern std::map<std::string, unsigned int> extension_sum;

extern int max_column_width;

struct File_Data{
    std::string file_name;
    unsigned int line_count = 0;
    unsigned int character_count = 0;
    unsigned int whitespace_count = 0; 
};


#endif //COMMON_H