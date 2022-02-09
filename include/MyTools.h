#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

namespace MyTools {

std::string GetCurDateTime();

class FileLoggerSingletone {
    std::ofstream logOut;

    const std::string FileName;
    FileLoggerSingletone() = default;
    ~FileLoggerSingletone() = default;

public:
    // нет копирования
    FileLoggerSingletone(const FileLoggerSingletone & root) = delete;
    FileLoggerSingletone & operator=(const FileLoggerSingletone &) = delete;
    // нет перемещения
    FileLoggerSingletone(const FileLoggerSingletone && root) = delete;
    FileLoggerSingletone & operator=(const FileLoggerSingletone &&) = delete;

    static FileLoggerSingletone & getInstance();
    void OpenLogFile(const std::string &FileName);
    void CloseLogFile();
    void WriteToLog(const std::string &str);

    __attribute__((unused)) void WriteToLog(const std::string &str, int n);
    __attribute__((unused))  void WriteToLog(const std::string &str, double d);
};

// proxy for FileLoggerSingletone
class LoggerSingleton {
    FileLoggerSingletone & fls = MyTools::FileLoggerSingletone::getInstance();

    static unsigned int logCounter;

    LoggerSingleton() = default;
    ~LoggerSingleton() = default;
public:
    // нет копирования
    LoggerSingleton(const LoggerSingleton & root) = delete;
    LoggerSingleton & operator=(const LoggerSingleton &) = delete;
    // нет перемещения
    LoggerSingleton(const LoggerSingleton && root) = delete;
    LoggerSingleton & operator=(const LoggerSingleton &&) = delete;

    static LoggerSingleton & getInstance();
    void OpenLogFile(const std::string &FileName);
    void CloseLogFile();
    void WriteToLog(const std::string &str);

    __attribute__((unused)) void WriteToLog(const std::string &str, int n);
    __attribute__((unused))  void WriteToLog(const std::string &str, double d);

};


}; // namespace MyTools
