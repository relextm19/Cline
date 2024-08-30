#include "../header_files/printing.h"

void print_header(){
    std::cout << std::left << std::setw(max_column_width) << "Extension" 
              << " | " << std::setw(max_column_width) << "Line Count" 
              << " | " << std::setw(max_column_width) << "Character Count" 
              << " | " << std::setw(max_column_width) << "Whitespace Count" 
              << std::endl;
    for(int i = 0; i < max_column_width * 4 + 3; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

void print_data(const std::vector<File_Data>& file_datas){
    for(auto& file_data : file_datas){
        std::cout << std::left << std::setw(max_column_width) << file_data.file_name 
              << " | " << std::setw(max_column_width) << file_data.line_count 
              << " | " << std::setw(max_column_width) << file_data.character_count 
              << " | " << std::setw(max_column_width) << file_data.whitespace_count 
              << std::endl;
    }
}

void print_footer(){
    for(int i = 0; i < max_column_width * 4 + 3; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
    for(auto& [extension, sum] : extension_sum){
        std::cout << std::left << std::setw(max_column_width) << extension 
              << " | " << std::setw(max_column_width) << sum << std::endl;
    }
}
