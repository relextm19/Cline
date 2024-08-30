#include "../header_files/args.h"
#include "../header_files/common.h"

char argument_list[] = {
    'p','h', 'r'
};

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
