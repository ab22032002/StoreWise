cmake_minimum_required(VERSION 3.10)
project(StoreWise)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(StoreWise
    main.cpp
    src/FileScanner.cpp
    src/FileClassifier.cpp
    src/VaultManager.cpp
    src/Cleaner.cpp          
    src/ReportGenerator.cpp  
)
