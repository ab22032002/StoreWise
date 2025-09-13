#pragma once
#include "FileScanner.h"
#include <string>

class ReportGenerator {
private:
    size_t totalFiles = 0;
    size_t deletedFiles = 0;
    size_t archivedFiles = 0;
    size_t spaceSaved = 0; // bytes
public:
    void logDeletion(const FileMeta& file);
    void logArchive(const FileMeta& file, size_t savedBytes);
    void incrementTotal() { totalFiles++; }
    void printReport();
};
