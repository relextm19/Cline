#include "../header_files/common.h"

std::string allowed_extensions[] = {
    ".cpp", ".py", ".c", ".cs", ".rs", ".js", ".java", ".html", ".css", ".php", ".sql", ".sh", ".bat", ".ps1", ".asm", ".go", ".rb", ".lua", ".pl", ".swift", ".kt", ".ts", ".json", ".xml", ".yml", ".yaml", ".toml", ".ini", ".cfg", ".md"
};

std::map<std::string, unsigned int> extension_sum;

bool recursive = false;
int max_column_width = 0;