#include <fstream>

#include "../header_files/file_actions.h"

bool has_allowed_extension(const std::filesystem::path& path){
    for(int i = 0; i < sizeof(allowed_extensions) / sizeof(allowed_extensions[0]); i++){
        if(path.extension() == allowed_extensions[i]){
            return true;
        }
    }
    return false;
}

File_Data count_lines(const std::filesystem::path& path){
    std::ifstream file(path);
    File_Data file_data;
    char c;
    unsigned int current_line_char_count = 0;
    while(file.get(c)){
        file_data.character_count++;
        current_line_char_count++;
        if(c == '\n'){
            file_data.line_count++;
            if(current_line_char_count == 1) file_data.whitespace_count++;
            current_line_char_count = 0;
        } 
    }
    return file_data; 
}

File_Data get_file_data(const std::filesystem::directory_entry& entry){
    //we get the data from the file
    File_Data file_data;
    file_data = count_lines(entry.path());
    file_data.file_name = entry.path().filename().string();
    if(file_data.file_name.size() > max_column_width) max_column_width = file_data.file_name.size();
    //add the data to the total sum of data for the file extension
    extension_sum[entry.path().extension().string()] += file_data.line_count;
    return file_data;
}

void itterate_files(const std::filesystem::path& path, std::vector<File_Data>* file_datas){
    if(std::filesystem::exists(path) && std::filesystem::is_directory(path)){
        if(recursive){
            for(auto& entry : std::filesystem::recursive_directory_iterator(path)){
                if(has_allowed_extension(entry.path()))
                file_datas->push_back(get_file_data(entry));
            }
        } else{
            for(auto& entry : std::filesystem::directory_iterator(path)){
                if(has_allowed_extension(entry.path()))
                file_datas->push_back(get_file_data(entry));
            }
        }
    }
}
