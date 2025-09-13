#include "VaultManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

VaultManager::VaultManager(const std::string& path) {
    vaultPath = path;
    if (!fs::exists(vaultPath)) fs::create_directory(vaultPath);
}

std::string VaultManager::simpleEncrypt(const std::string& data, char key) {
    std::string result = data;
    for (char &c : result) c ^= key;
    return result;
}

void VaultManager::moveToVault(const std::string& filePath) {
    if (!fs::exists(filePath)) { std::cout << "File not found: " << filePath << "\n"; return; }

    std::ifstream in(filePath, std::ios::binary);
    std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::string encrypted = simpleEncrypt(content); // placeholder encryption

    std::string fileName = fs::path(filePath).filename().string() + ".swenc";
    std::string vaultFile = fs::path(vaultPath) / fileName;

    std::ofstream out(vaultFile, std::ios::binary);
    out << encrypted;
    out.close();

    fs::remove(filePath);
    std::cout << "Moved to Vault: " << vaultFile << "\n";
}

void VaultManager::restoreFromVault(const std::string& vaultFile, const std::string& outputDir) {
    std::string vaultFilePath = fs::path(vaultPath) / vaultFile;
    if (!fs::exists(vaultFilePath)) { std::cout << "Vault file not found\n"; return; }

    std::ifstream in(vaultFilePath, std::ios::binary);
    std::string encrypted((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::string decrypted = simpleEncrypt(encrypted); // XOR decrypt placeholder

    std::string restoredFile = fs::path(outputDir) / fs::path(vaultFile).stem();
    std::ofstream out(restoredFile, std::ios::binary);
    out << decrypted;
    out.close();

    std::cout << "Restored file: " << restoredFile << "\n";
}

std::vector<std::string> VaultManager::listVaultFiles() {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(vaultPath)) {
        if (fs::is_regular_file(entry.path()))
            files.push_back(entry.path().filename().string());
    }
    return files;
}
