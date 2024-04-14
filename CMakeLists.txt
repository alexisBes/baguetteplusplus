cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)


configure_file(constante.in.h constante.h)
set(TESTING OFF CACHE BOOL "Lanch unit test")

add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE cxx_std_11)


set (SOURCE_LIST
    src/mainLexer.c
    src/mainParser.c
    src/Logger.c
    src/instructionParser.c
    src/bppFile.c
)

add_executable(baguetteplusplus 
    src/main.c
    ${SOURCE_LIST})

add_subdirectory(tools)

target_link_libraries(baguetteplusplus 
    PRIVATE Tools)

target_include_directories(baguetteplusplus PRIVATE
    include/
    tools/include/)

target_include_directories(baguetteplusplus PUBLIC ${CMAKE_CURRENT_BINARY_DIR})


if(TESTING)
enable_testing()

endif()

