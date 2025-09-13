#include "ReportGenerator.h"
#include <iostream>

void ReportGenerator::logDeletion(const FileMeta& file) {
    deletedFiles++;
    spaceSaved += file.size;
}

void ReportGenerator::logArchive(const FileMeta& file, size_t savedBytes) {
    archivedFiles++;
    spaceSaved += savedBytes;
}

void ReportGenerator::printReport() {
    std::cout << "\n===== StoreWise Report =====\n";
    std::cout << "Total files scanned: " << totalFiles << "\n";
    std::cout << "Junk files deleted: " << deletedFiles << "\n";
    std::cout << "Archived files: " << archivedFiles << "\n";
    std::cout << "Total space saved: " << spaceSaved / (1024.0*1024.0) << " MB\n";

    double energySavedKWh = (spaceSaved / (1024.0*1024.0*1024.0)) * 0.3; // 1GB ~ 0.3 kWh
    std::cout << "Estimated energy saved: " << energySavedKWh << " kWh\n";
    std::cout << "============================\n";
}
