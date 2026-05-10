###
### Projet principal
### 
cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)
set (CMAKE_C_STANDARD 11)

configure_file(constante.in.h constante.h)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE c_std_11)
target_compile_options(bpp_compiler_flag INTERFACE
    "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)

set (SOURCE_LIST
   ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer_main.c
   ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer_ident.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parser_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parser_math.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/semer_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/symbo_table_main.c
)


add_executable(baguetteplusplus 
    src/main.c
    ${SOURCE_LIST})

add_subdirectory(utils)

target_link_libraries(baguetteplusplus 
    PRIVATE Tools)

target_include_directories(baguetteplusplus PRIVATE
    include/
    utils/include/)

target_include_directories(baguetteplusplus PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

###
### Ajout d'un binaire de test unitaire
###
file( GLOB SOURCE_FILE_TEST
   ${CMAKE_CURRENT_SOURCE_DIR}/test/src/*.c
)

add_executable(baguettetest 
    ${SOURCE_FILE_TEST}
    ${SOURCE_LIST}
    )

target_link_libraries(baguettetest 
    PRIVATE Tools
    cunit)

target_include_directories(baguettetest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/test/)

target_include_directories(baguettetest PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
