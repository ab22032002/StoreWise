#pragma once
#include <string>
#include <vector>
#include <ctime>

struct FileMeta {
    std::string path;
    std::string name;
    size_t size;
    time_t lastModified;
    std::string extension;
};

class FileScanner {
public:
    std::vector<FileMeta> scanFolder(const std::string& folderPath);
};
