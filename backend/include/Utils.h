#pragma once

#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

namespace FileUtils{
    enum PathType{FILE, DIRECTORY};

    PathType getPathType(const string& path);
    vector<string> getAllFiles(const string& directory);
};