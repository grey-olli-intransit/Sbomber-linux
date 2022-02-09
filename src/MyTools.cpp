#include "MyTools.h"

#include <stdint.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>


namespace MyTools {

// тоже можно вынести в класс файлового логгера, но может захочется ещё где время использовать, так что пусть остаётся.
std::string GetCurDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char* buf = ctime(&time);
  return std::string(buf);
}

FileLoggerSingletone & FileLoggerSingletone::getInstance() {
    static FileLoggerSingletone singleInstance;
    return singleInstance;
}

void FileLoggerSingletone::OpenLogFile(const std::string &FileName) {
    logOut.open(FileName, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile() {
    if (logOut.is_open()) {
        logOut.close();
    }
}

void FileLoggerSingletone::WriteToLog(const std::string &str) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

__attribute__((unused)) void FileLoggerSingletone::WriteToLog(const std::string &str, int n) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

__attribute__((unused)) void FileLoggerSingletone::WriteToLog(const std::string &str, double d) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}
    LoggerSingleton & getInstance() {
        static LoggerSingleton singleInstance;
        return singleInstance;
    };
    void OpenLogFile(const std::string &FileName);
    void CloseLogFile();
    void WriteToLog(const std::string &str);

    __attribute__((unused)) void WriteToLog(const std::string &str, int n);
    __attribute__((unused))  void WriteToLog(const std::string &str, double d);

} // namespace MyTools
