#include "../../include/Utils.h"

#include <iostream>

FileUtils::PathType FileUtils::getPathType(const string& path){
    if(path.find(".json") != string::npos) return FileUtils::PathType::FILE;
    return FileUtils::PathType::DIRECTORY;
}

vector<string> FileUtils::getAllFiles(const string& path){
    fs::path dir = path;
    if(!fs::exists(dir) || !fs::is_directory(dir)) throw runtime_error("directory not found");

    vector<string> filePaths;
    for(const std::filesystem::__cxx11::directory_entry& entry : fs::directory_iterator(path)){
        ostringstream stream;
        stream << entry;
        string subPath = stream.str();
        stream.clear();
        subPath = subPath.substr(1, subPath.length()-2);
        if(FileUtils::getPathType(subPath) == FileUtils::PathType::FILE){
            filePaths.push_back(subPath);
        }else{
            vector<string> subFilePaths = FileUtils::getAllFiles(subPath);
            filePaths.insert(filePaths.end(), subFilePaths.begin(), subFilePaths.end());
        }
    }

    return filePaths;
}