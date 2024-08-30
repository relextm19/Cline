#include "../header_files/common.h"
#include "../header_files/printing.h"
#include "../header_files/args.h"
#include "../header_files/file_actions.h"



int main(int argc, char* argv[]) {
    std::filesystem::path path = std::filesystem::current_path();
    std::vector<File_Data> file_datas;
    parse_args(argc, argv, &path);
    itterate_files(path, &file_datas);
    print_header();
    print_data(file_datas);
    print_footer();
}
