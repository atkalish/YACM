#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Logger{
private:
    static Logger* logger;
    const string logFile;
    bool printToConsole;

public:
    Logger(const Logger& other) = delete; // should not be cloneable
    static Logger* getInstance();
    static void config(const string& logFile, bool printToConsole);

};

// this should go in the implementation file
Logger* Logger::logger = nullptr;