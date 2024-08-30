#ifndef PRINTING_H
#define PRINTING_H

#include <vector>
#include <iomanip>

#include "common.h"

void print_footer();
void print_data(const std::vector<File_Data>& file_datas);
void print_header();

#endif // PRINTING_H