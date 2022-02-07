#include "MyTools.h"

#include <stdint.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>


namespace MyTools {

//void OpenLogFile(const std::string &FN) { logOut.open(FN, std::ios_base::out); }

//void CloseLogFile() {
//  if (logOut.is_open()) {
//    logOut.close();
//  }
//}

std::string GetCurDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char* buf = ctime(&time);
  return std::string(buf);
}


bool FileLoggerSingletone::FileLoggerSingletone::loggerInUse= true;
std::ofstream FileLoggerSingletone::FileLoggerSingletone::logOut;

FileLoggerSingletone::FileLoggerSingletone(){
}


FileLoggerSingletone::FileLoggerSingletone(const std::string &FN) : FileName(FN)  {
            if(loggerInUse) { // fixme: refactor - remove this block later and change to if(!loggerInUse)
                std::cerr << "Singletone already initialised. Doing nothing.";
            } else {
                FileLoggerSingletone();
                OpenLogFile(FileName);
            }
}

FileLoggerSingletone FileLoggerSingletone::getInstance() {
    static FileLoggerSingletone singleInstance;
    return singleInstance;
}

void FileLoggerSingletone::OpenLogFile(const std::string &FileName) {
    logOut.open(FileName, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile() {
    if (MyTools::FileLoggerSingletone::logOut.is_open()) {
        MyTools::FileLoggerSingletone::logOut.close();
    }
}

void FileLoggerSingletone::WriteToLog(const std::string &str) {
    if (MyTools::FileLoggerSingletone::logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

void FileLoggerSingletone::WriteToLog(const std::string &str, int n) {
    if (MyTools::FileLoggerSingletone::logOut.is_open()) {
        MyTools::FileLoggerSingletone::logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

__attribute__((unused)) void FileLoggerSingletone::WriteToLog(const std::string &str, double d) {
    if (MyTools::FileLoggerSingletone::logOut.is_open()) {
        MyTools::FileLoggerSingletone::logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}


//class FileLoggerSingletone {
//        static std::ofstream logOut;
//
//        static bool loggerInUse;
//        const std::string FileName;
//        FileLoggerSingletone() {
//            loggerInUse = true;
//        }
//
//        FileLoggerSingletone(const std::string &FN) : FileName(FN)  {
//            if(loggerInUse) { // fixme: refactor - remove this block later and change to if(!loggerInUse)
//                std::cerr << "Singletone already initialised. Doing nothing.";
//            } else {
//                FileLoggerSingletone();
//                OpenLogFile(FileName);
//            }
//        }
//    public:
//        //FileLoggerSingletone(const FileLoggerSingletone & root) = delete;
//        static FileLoggerSingletone getInstance() {
//            static FileLoggerSingletone singleInstance;
//            return singleInstance;
//        }
//        static void OpenLogFile(const std::string &FileName) { logOut.open(FileName, std::ios_base::out); }
//        static void CloseLogFile() {
//            if (MyTools::FileLoggerSingletone::logOut.is_open()) {
//                MyTools::FileLoggerSingletone::logOut.close();
//            }
//        }
//        static void WriteToLog(const std::string &str) {
//            if (MyTools::FileLoggerSingletone::logOut.is_open()) {
//                logOut << GetCurDateTime() << " - " << str << std::endl;
//            }
//        }
//
//        static void WriteToLog(const std::string &str, int n) {
//            if (MyTools::FileLoggerSingletone::logOut.is_open()) {
//                MyTools::FileLoggerSingletone::logOut << GetCurDateTime() << " - " << str << n << std::endl;
//            }
//        }
//
//        __attribute__((unused)) void WriteToLog(const std::string &str, double d) {
//            if (MyTools::FileLoggerSingletone::logOut.is_open()) {
//                MyTools::FileLoggerSingletone::logOut << GetCurDateTime() << " - " << str << d << std::endl;
//            }
//        }
//
//
//    };



} // namespace MyTools
