cmake_minimum_required(VERSION 3.10)
project(github-activity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(github-activity
    src/main.cpp
    src/cli.cpp
    src/github_api.cpp
    src/http_client.cpp
    src/json_parser.cpp
)

target_include_directories(github-activity PRIVATE include)
