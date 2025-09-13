# StoreWise

**Tagline:** Privacy-preserving, automated file lifecycle manager in C++ for efficient storage and environmental impact reporting.

---

## **Overview**

StoreWise is a C++ CLI tool that helps manage your files efficiently by:

- Scanning a folder for all files.
- Classifying files as **ARCHIVE**, **JUNK**, or **ACTIVE**.
- Deleting unnecessary junk files.
- Moving old important files to a **Vault**.
- Generating a report summarizing space saved, files processed, and eco-impact.

The tool is designed for **privacy**, **performance**, and **environmental awareness**.

---

## **Features**

1. **Automatic File Management**
   - Scans folder recursively.
   - Classifies files based on type and age.
   - Moves ARCHIVE files to a secure vault.
   - Deletes JUNK files automatically.

2. **Privacy-Preserving Vault**
   - Vault files are encrypted (XOR encryption placeholder, future AES possible).
   - Active files remain untouched.
   - Secure storage prevents accidental privacy leaks.

3. **Report Generation**
   - Shows total files scanned.
   - Files archived and deleted.
   - Estimated disk space and energy saved.

4. **Efficient & Fast**
   - Implemented in C++ for fast file I/O and low memory usage.
   - CLI-based → lightweight, cross-platform compatible (Linux / Codespaces).

---

## **Modules**

| Module           | Responsibility                                 | C++ Concepts                  |
|-----------------|-----------------------------------------------|-------------------------------|
| `FileScanner`     | Recursively scans folders & gathers metadata | Classes, std::filesystem      |
| `FileClassifier`  | Categorizes files (ARCHIVE/JUNK/ACTIVE)     | Classes, encapsulation        |
| `VaultManager`    | Encrypts, moves to vault, restores files    | Classes, encapsulation, file I/O |
| `Cleaner`         | Deletes junk files                           | Classes, file I/O             |
| `ReportGenerator` | Maintains stats & prints report              | Classes, encapsulation        |

> **OOP Principles:** Encapsulation, Modularity, Abstraction

---

## **Usage**

1. Create a test folder:

```bash
mkdir -p /workspaces/StoreWise/Test
```
2. Build StoreWise:
```bash
cd /workspaces/StoreWise/build
cmake ..
cmake --build .
```
3. Run StoreWise:
```bash
./StoreWise
```
4. Observe:
- Junk files deleted
- Old important files moved to StoreWiseVault
- Report printed in terminal
- Vault files can be restored separately
