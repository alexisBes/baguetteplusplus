cmake_minimum_required(VERSION 3.10)

project("baguette plus plus" VERSION 0.0)

set(TESTING OFF CACHE BOOL "Lanch unit test")

add_library(bpp_compiler_flag INTERFACE)
target_compile_features(bpp_compiler_flag INTERFACE cxx_std_11)

configure_file(constante.h.in constante.h)
set (SOURCE_LIST
    src/mainLexer.c
    src/mainParser.c
)

add_executable(baguetteplusplus 
    src/main.c
    ${SOURCE_LIST})

add_subdirectory(tools)

target_link_libraries(baguetteplusplus PRIVATE 
    Tools)

target_include_directories(baguetteplusplus PRIVATE
    include/
    tools/include/)

target_include_directories(baguetteplusplus PUBLIC ${BINARY_DIR})



if(TESTING)
    enable_testing()
    add_executable(baguetteplusplus_test
    test/main.c
    ${SOURCE_LIST})
    target_link_libraries(baguetteplusplus_test PRIVATE 
        Tools)

    target_include_directories(baguetteplusplus_test PRIVATE
        include/
        tools/include/)
    target_include_directories(baguetteplusplus_test PUBLIC ${BINARY_DIR})

    # define a function to simplify adding tests
function(do_test myname target typeTest input element result)
        add_test(NAME ${myname} COMMAND ${target} ${typeTest} ${input} ${element} ${result})
        set_tests_properties(${myname}
            PROPERTIES PASS_REGULAR_EXPRESSION "SUCCES"
        )
endfunction()

    do_test( TestCountInChar baguetteplusplus_test  2 superstrings s 3)
    do_test( TestIsCharExistInArray baguetteplusplus_test  4 superstrings t 1)
    do_test( concatenateString baguetteplusplus_test  6 super strings superstrings)
    do_test( concatenateChar baguetteplusplus_test  8 tot o toto)
endif()