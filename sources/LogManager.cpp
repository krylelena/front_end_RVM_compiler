//
// Created by Елена on 12.12.2021.
//

#include <fstream>

#include "LogManager.h"

LogManager::LogManager() {
    logFileName = "program.log";
    logDirectory = "logs";
}
LogManager::LogManager(std::string logFileName, LogDirectoryType logDirectory) {
    this->logFileName = logFileName;
    this->logDirectory = logDirectory;
}

void LogManager::setLogFileName(LogFileNameType fileName) {
    logFileName = fileName;
}

LogFileNameType LogManager::getLogFileName() {
    return logFileName;
}

void LogManager::setLogDirectory(LogDirectoryType directory) {
    logDirectory = directory;
}

LogDirectoryType LogManager::getLogDirectory() {
    return logDirectory;
}

void LogManager::makeLog(LogString logString) {
    std::string fullFilePath =  "../"+logFileName;
    std::ofstream logFile(fullFilePath, std::ios_base::app);

    if (!logFile.is_open()) {
        std::cout << "lof file " << fullFilePath << " is not exists" << std::endl;
    }

    logFile << logString << std::endl;

    logFile.close();

}

void LogManager::deleteLogs() {
    std::string fullFilePath =  "../"+logFileName;
    std::ofstream logFile(fullFilePath, std::ios_base::out);

    if (!logFile.is_open()) {
        std::cout << "lof file " << fullFilePath << " is not exists" << std::endl;
    }

    logFile << "";

    logFile.close();
}