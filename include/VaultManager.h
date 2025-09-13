#pragma once
#include <string>
#include <vector>
#include "FileScanner.h"

class VaultManager {
private:
    std::string vaultPath;
    std::string simpleEncrypt(const std::string& data, char key = 'K');

public:
    VaultManager(const std::string& path);
    void moveToVault(const std::string& filePath);
    void restoreFromVault(const std::string& vaultFile, const std::string& outputDir);
    std::vector<std::string> listVaultFiles();
};
