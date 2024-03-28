cmake_minimum_required(VERSION 3.26)
project(CandyPane)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB HEADER_FILES  "include/**/*.hpp"
        "include/*.hpp")
file(GLOB SOURCE_FILES  "src/**/*.cpp"
        "src/*.cpp")

add_library(CandyPane STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(CandyPane)
