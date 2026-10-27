cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 26)
project(YACM VERSION 1.0 LANGUAGES CXX)
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(yacm ${SRC_FILES})
target_include_directories(yacm PRIVATE include)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)
target_link_libraries(yacm PRIVATE nlohmann_json::nlohmann_json)
