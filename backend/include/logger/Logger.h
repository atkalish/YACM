#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <sstream>
#include <source_location>
#include <fstream>

using namespace std;

class Logger{
private:
    static Logger* logger;
    inline static const string LOG_FILE_DIR = "logs/";
    ofstream outfile;
    bool _debug;
    bool _info;
    bool _warning;
    bool _error;
    Logger();
public:
    Logger(const Logger& other) = delete; // should not be cloneable
    ~Logger();
    static Logger* getInstance();
    void config(bool debug, bool info, bool warning, bool error);
    void log(const string& message, const source_location location = source_location::current());
    void debug(const string& message, const source_location location = source_location::current());
    void warning(const string& message, const source_location location = source_location::current());
    void error(const string& mwessage, const source_location location = source_location::current());

private:
    string getLogString(const string& severity, const string& message, source_location location);
};