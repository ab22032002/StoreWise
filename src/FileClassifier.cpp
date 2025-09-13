#include "FileClassifier.h"
#include <ctime>

bool FileClassifier::isInVector(const std::string& ext, const std::vector<std::string>& vec) {
    for (const auto& e : vec) if (ext == e) return true;
    return false;
}

FileCategory FileClassifier::classify(const FileMeta& file) {
    if (isInVector(file.extension, junkExtensions))
        return FileCategory::JUNK;

    if (isInVector(file.extension, importantExtensions)) {
        time_t now = time(nullptr);
        // Classifying it as archive when the files are older than a year; (int terms of seconds: 365*24*3600)
        if (difftime(now, file.lastModified) > 365*24*3600)
            return FileCategory::ARCHIVE;
        else
            return FileCategory::ACTIVE;
    }

    return FileCategory::ACTIVE;
}
