#include "Cleaner.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void Cleaner::deleteFile(const FileMeta& file) {
    if (!fs::exists(file.path)) {
        std::cout << "File does not exist: " << file.name << "\n";
        return;
    }

    try {
        // Simple delete (for secure deletion, overwrite logic can be added)
        fs::remove(file.path);
        std::cout << "Deleted Junk File: " << file.name << "\n";
    } catch (std::exception& e) {
        std::cout << "Error deleting file: " << e.what() << "\n";
    }
}
