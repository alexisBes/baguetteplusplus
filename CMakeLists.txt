cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED true)
# compiler flag
add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE cxx_std_11)

configure_file(constante.h.in constante.h)

add_executable(baguetteplusplus 
    main.c
    mainLexer.c
    mainParser.c)

add_subdirectory(tools)

target_link_libraries(baguetteplusplus PUBLIC 
    Tools)

target_include_directories(baguetteplusplus PRIVATE
    ${SOURCE_DIR}/tools)

target_include_directories(baguetteplusplus PUBLIC ${BINARY_DIR})

