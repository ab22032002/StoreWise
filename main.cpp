#include <iostream>
#include "FileScanner.h"
#include "FileClassifier.h"
#include "VaultManager.h"
#include "Cleaner.h"
#include "ReportGenerator.h"

int main() {
    std::string folder = "/workspaces/StoreWise/Test"; 
    std::string vaultPath = "/workspaces/StoreWise/Test/StoreWiseVault";


    FileScanner scanner;
    FileClassifier classifier;
    VaultManager vault(vaultPath);
    Cleaner cleaner;
    ReportGenerator reporter;

    auto files = scanner.scanFolder(folder);

    for (const auto& f : files) {
        reporter.incrementTotal();
        FileCategory cat = classifier.classify(f);

        if (cat == FileCategory::ARCHIVE) {
            vault.moveToVault(f.path);
            reporter.logArchive(f, f.size/2); // placeholder saved bytes
        } 
        else if (cat == FileCategory::JUNK) {
            cleaner.deleteFile(f);
            reporter.logDeletion(f);
        } 
        else std::cout << "Active file: " << f.name << "\n";
    }

    std::cout << "Vault contains:\n";
    auto vaultFiles = vault.listVaultFiles();
    for (auto vf : vaultFiles) std::cout << " - " << vf << "\n";

    reporter.printReport();
    return 0;
}
