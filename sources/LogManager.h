//
// Created by Елена on 12.12.2021.
//

#ifndef FRONT_END_RVM_COMPILER_LOGMANAGER_H
#define FRONT_END_RVM_COMPILER_LOGMANAGER_H


#include <iostream>
#include <string>

using LogFileNameType = std::string;
using LogDirectoryType = std::string;
using LogString = std::string;

class LogManager {
    LogFileNameType logFileName;
    LogDirectoryType logDirectory;

public:
    LogManager();
    LogManager(std::string logFileName, LogDirectoryType logDirectory = "logs");

    ~LogManager() = default;

    void setLogFileName(LogFileNameType fileName);
    LogFileNameType getLogFileName();

    void setLogDirectory(LogDirectoryType directory);
    LogDirectoryType getLogDirectory();

    void makeLog(LogString logString);

    void deleteLogs();
};

#endif //FRONT_END_RVM_COMPILER_LOGMANAGER_H
