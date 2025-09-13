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

5. Tools and Technology Used
| Category                         | Tool / Technology                     | Purpose / Role                                                    |
| -------------------------------- | ------------------------------------- | ----------------------------------------------------------------- |
| **Programming Language**         | C++17 / C++20                         | Core implementation, high performance, system-level file handling |
| **Build System**                 | CMake                                 | Build and compile project across platforms                        |
| **Compiler**                     | g++ / GCC                             | Compile C++ code                                                  |
| **Filesystem**                   | `<filesystem>` (C++ standard library) | Scan, move, delete, check files and directories                   |
| **File I/O**                     | `<fstream>`                           | Read, write, encrypt, and restore files                                             
| **OS Compatibility**             | Linux (Codespaces) / Cross-platform   | Testing, running, and demo                                        |
| **Command Line Interface (CLI)** | Terminal / shell                      | User interacts with program                                       |
| **Version Control**              | Git / GitHub                          | Store and manage code, track versions                             |
| **IDE / Code Editor**            | GitHub Codespaces                     | Cloud-based coding environment with pre-installed tools           |
| **Optional Future Tools**        | OpenSSL / Crypto++ / zlib / Qt        | Stronger encryption, compression, GUI development                 |

