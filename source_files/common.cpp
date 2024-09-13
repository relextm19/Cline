#include "../header_files/common.h"

std::vector<std::string> banned_extensions;
std::vector<std::filesystem::path> banned_directories;


std::map<std::string, unsigned int> extension_sum;

bool recursive = false;
int max_column_width = 0;