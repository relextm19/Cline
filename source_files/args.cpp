#include "../header_files/args.h"
#include "../header_files/common.h"

void parse_args(int argc, char* argv[], std::filesystem::path* path){
    if(path == nullptr) throw std::runtime_error("failed to initalize path");
    //we iterate over args
    for(int i = 1; i < argc; i++){
        if(argv[i][0] != '-') break;

        //if we find a '-' we itterate through the argument list and see if we get a match
        for(int j = 0; j < sizeof(argument_list) / sizeof(argument_list[0]); j++){
            switch(argument_list[j]){
                //TODO
                case 'h':
                    break;

                case 'r':
                    recursive = true;
                    break;

                case 'e':
                    if(i + 1 > argc || argv[i+1][0] == '-') break;

                    banned_extensions.push_back(argv[i + 1]);
                    break;

                case 'd':
                    if(i + 1 > argc || argv[i+1][0] == '-') break;

                    banned_directories.push_back(argv[i + 1]);
                    break;

                default:
                    break;
            }
        }
    }
}
