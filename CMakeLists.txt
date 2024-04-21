cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)


configure_file(constante.in.h constante.h)
set(TESTING OFF CACHE BOOL "Lanch unit test")

add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE c_std_11)


set (SOURCE_LIST
   ${CMAKE_CURRENT_SOURCE_DIR}/src/mainLexer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainParser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/instructionParser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bppFile.c
)


if(TESTING)
enable_testing()
add_definitions( -DTESTING)
endif()

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


