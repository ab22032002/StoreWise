#pragma once
#include "FileScanner.h"
#include <string>
#include <vector>

enum class FileCategory { JUNK, ACTIVE, ARCHIVE };

class FileClassifier {
private:
    std::vector<std::string> junkExtensions = {".tmp", ".log", ".cache"};
    std::vector<std::string> importantExtensions = {".pdf", ".docx", ".txt", ".cpp", ".h", ".xlsx"};
    bool isInVector(const std::string& ext, const std::vector<std::string>& vec);

public:
    FileCategory classify(const FileMeta& file);
};
