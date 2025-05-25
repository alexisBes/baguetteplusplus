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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parser_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parser_math.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/generateur_main.c
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

file( GLOB SOURCE_FILE_TEST
   ${CMAKE_CURRENT_SOURCE_DIR}/test/unitaire/src/*.c
)

###
### Ajout d'un binaire de test unitaire
###

add_executable(baguettetest 
    test/lexer/src/main.c
    ${SOURCE_LIST}
    ${SOURCE_FILE_TEST})

target_link_libraries(baguettetest 
    PRIVATE Tools)

target_include_directories(baguettetest PRIVATE
    include/
    utils/include/)

target_include_directories(baguettetest PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()
 add_test(NAME "Test_Lexer" COMMAND baguettetest ${CMAKE_CURRENT_SOURCE_DIR}/test/lexer/KEYWORD_test.txt ${CMAKE_CURRENT_SOURCE_DIR}/test/lexer/KEYWORD_test_expected.txt ${CMAKE_CTEST_ARGUMENTS})