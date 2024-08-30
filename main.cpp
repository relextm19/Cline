#include <iostream>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>

char argument_list[] = {
    'p','h', 'r'
};

std::string allowed_extensions[] = {
    ".cpp",".py",".c",".cs",".rs",".js",".java",".html",".css",".php",".sql",".sh",".bat",".ps1",".asm",".go",".rb",".lua",".pl",".swift",".kt",".ts",".json",".xml",".yml",".yaml",".toml",".ini",".cfg",".md"
};

std::map<std::string, unsigned int> extension_sum;

struct File_Data{
    std::string file_name;
    unsigned int line_count = 0;
    unsigned int character_count = 0;
    unsigned int whitespace_count = 0; 
};

bool recursive = false;
int max_column_width = 0;

void parse_args(int argc, char* argv[], std::filesystem::path* path){
    if(path == nullptr) throw std::runtime_error("failed to initalize path");
    //we iterate over args
    for(int i = 1; i < argc; i++){
        if(argv[i][0] != '-') break;

        //if we find a '-' we itterate through the argument list and see if we get a match
        for(int j = 0; j < sizeof(argument_list) / sizeof(argument_list[0]); j++){
            if(argv[i][1] != argument_list[j]) continue;
            int k = 0;
            
            switch(argument_list[j]){
                //if the arg is p we add a string(if it occurs) which follows the argument to the path 
                case 'p':
                    if(i + 1 > argc || argv[i+1][0] == '-') break;
                    path->clear();
                    while(argv[i + 1][k] != '\0'){
                        *path += argv[i + 1][k];
                        k++;
                    } 
                    i++;
                    break;

                case 'h':
                    std::cout << "Usage: " << argv[0] << " -p <path>" << std::endl;
                    break;

                case 'r':
                    recursive = true;
                    break;

                default:
                    break;
            }
        }
    }
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

bool has_allowed_extension(const std::filesystem::path& path){
    for(int i = 0; i < sizeof(allowed_extensions) / sizeof(allowed_extensions[0]); i++){
        if(path.extension() == allowed_extensions[i]){
            return true;
        }
    }
    return false;
}

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

int main(int argc, char* argv[]) {
    std::filesystem::path path = std::filesystem::current_path();
    std::vector<File_Data> file_datas;
    parse_args(argc, argv, &path);
    itterate_files(path, &file_datas);
    print_header();
    print_data(file_datas);
    print_footer();
}
