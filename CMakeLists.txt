cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# compiler flag
add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE cxx_std_11)

configure_file(constante.h.in constante.h)

add_executable(baguetteplusplus 
    baguetteplusplus.cpp
    mainLexer.cpp
    mainParser.cpp)

add_subdirectory(utils) 
add_subdirectory(tools)

target_link_libraries(baguetteplusplus PUBLIC 
    ListUtils
    StringTool)

target_include_directories(baguetteplusplus PRIVATE 
    ${SOURCE_DIR}/utils
    ${SOURCE_DIR}/tools)

target_include_directories(baguetteplusplus PUBLIC ${BINARY_DIR})