cmake_minimum_required(VERSION 3.26)
project(CandyPane)

set(CMAKE_CXX_STANDARD 23)

set(GTEST_ROOT "D:/googletest")
set(GTEST_LIBS gtest gtest_main)
include_directories(${GTEST_ROOT})
link_directories(${GTEST_ROOT}/build/lib)

include_directories(include)  # candypane core

file(GLOB HEADER_FILES  "include/**/*.hpp"
        "include/*.hpp")
file(GLOB SOURCE_FILES  "src/**/*.cpp"
        "src/*.cpp")

add_library(CandyPane STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(CandyPane gtest ${GTEST_LIBS})
