#include "FileScanner.h"
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

std::vector<FileMeta> FileScanner::scanFolder(const std::string& folderPath) {
    std::vector<FileMeta> files;

    for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (fs::is_regular_file(entry.path())) {
            FileMeta meta;
            meta.path = entry.path().string();
            meta.name = entry.path().filename().string();
            meta.size = fs::file_size(entry.path());

            auto ftime = fs::last_write_time(entry.path());
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                            ftime - fs::file_time_type::clock::now()
                            + std::chrono::system_clock::now());
            meta.lastModified = std::chrono::system_clock::to_time_t(sctp);

            meta.extension = entry.path().extension().string();

            files.push_back(meta);
        }
    }

    return files;
}
