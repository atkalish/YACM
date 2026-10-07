#include "../../include/logger/Logger.h"

Logger* Logger::logger = nullptr;

Logger* Logger::getInstance(){
    if(logger == nullptr){
        logger = new Logger();
        error_code ec;
        filesystem::create_directories(LOG_FILE_DIR, ec);
        std::chrono::_V2::system_clock::time_point now = std::chrono::system_clock::now();
        ostringstream stream;
        stream << std::chrono::current_zone()->to_local(now);
        string filename = LOG_FILE_DIR + stream.str() + ".txt";
        filename[filename.find(' ')] = '_';
        logger->outfile.open(filename);
    }
    return logger;
}

void Logger::config( bool debug, bool info, bool warning, bool error){
    this->_debug = debug;
    this->_info = info;
    this->_warning = warning;
    this->_error = error;
}

void Logger::log(const string &message, const source_location location){
    if(!this->_info) return;
    string logStr = getLogString("INFO", message, location);
    cerr << logStr << endl;
    outfile << logStr << endl;
}

void Logger::debug(const string &message, const source_location location){
    if(!this->_debug) return;
    string logStr = getLogString("DEBUG", message, location);
    cerr << logStr << endl;
    outfile << logStr << endl;
}

void Logger::warning(const string &message, const source_location location){
    if(!this->_warning) return;
    string logStr = getLogString("WARNING", message, location);
    cerr << logStr << endl;
    outfile << logStr << endl;
}

void Logger::error(const string &message, const source_location location){
    if(!this->_error) return;
    string logStr = getLogString("ERROR", message, location);
    cerr << logStr << endl;
    outfile << logStr << endl;
}

string Logger::getLogString(const string &severity, const string &message, source_location location){
    ostringstream stream;
    std::chrono::_V2::system_clock::time_point now = std::chrono::system_clock::now();
    stream << "[" << severity << "] ";

    if(severity == "INFO") stream << "   ";
    if(severity == "DEBUG") stream << "  ";
    if(severity == "WARNING") stream << "";
    if(severity == "ERROR") stream << "  ";

    stream << std::chrono::current_zone()->to_local(now) << " ";
    stream << "[" << location.file_name() << ":" << location.line() << "] ";
    stream << message;
    return stream.str();
}

// all logging is enabled by default
Logger::Logger(){
    this->config(true, true, true, true);
}

Logger::~Logger(){
    this->outfile.close();
}