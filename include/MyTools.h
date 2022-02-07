#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

namespace MyTools {

std::string GetCurDateTime();

class FileLoggerSingletone {
    static std::ofstream logOut;

    static bool loggerInUse;
    const std::string FileName;
    FileLoggerSingletone();

    FileLoggerSingletone(const std::string &FN);

public:
    //FileLoggerSingletone(const FileLoggerSingletone & root) = delete;
    static FileLoggerSingletone getInstance();
    static void OpenLogFile(const std::string &FileName);
    static void CloseLogFile();
    static void WriteToLog(const std::string &str);
    static void WriteToLog(const std::string &str, int n);
    __attribute__((unused)) static void WriteToLog(const std::string &str, double d);
};

}; // namespace MyTools
