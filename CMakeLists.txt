cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# compiler flag
add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE cxx_std_11)

add_executable(baguetteplusplus baguetteplusplus.cpp)

add_subdirectory(utils) 
add_subdirectory(tools)
add_subdirectory(parser)
add_subdirectory(lexer)

target_link_libraries(baguetteplusplus PUBLIC 
    ListUtils
    StringTool
    MainParser
    MainLexer)

target_include_directories(baguetteplusplus PRIVATE 
    ${SOURCE_DIR}/utils
    ${SOURCE_DIR}/tools
    ${SOURCE_DIR}/parser
    ${SOURCE_DIR}/lexer)

target_include_directories(baguetteplusplus PUBLIC ${BINARY_DIR})