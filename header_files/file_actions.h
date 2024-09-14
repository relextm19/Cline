#ifndef FILE_ACTIONS_H
#define FILE_ACTIONS_H


#include "common.h"

bool has_allowed_extension(const std::filesystem::path& path);
File_Data get_file_data(const std::filesystem::directory_entry& entry);
void itterate_files(const std::filesystem::path& path, std::vector<File_Data>* file_datas, ThreadPool& thread_pool);

#endif // FILE_ACTIONS_H