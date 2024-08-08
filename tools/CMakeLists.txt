add_library(Tools 
    src/StringTool.c
    src/ListUtils.c
    src/TreeUtils.c
    src/FileUtils.c)

target_include_directories(Tools PRIVATE 
                          ${CMAKE_CURRENT_SOURCE_DIR}/include)


  target_link_libraries(Tools INTERFACE bpp_compiler_flag)

  if(TESTING)
  enable_testing()
    add_executable(tools_test
    test/main.c
    src/StringTool.c
    src/ListUtils.c
    src/TreeUtils.c
    src/FileUtils.c)

    target_include_directories(tools_test PRIVATE
        include/)

    target_include_directories(tools_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

    # function to simplify stringUtilsTest
    function(testStringUtils myname functionName target typeTest input element result)
        add_test(NAME ${myname} COMMAND ${target} ${typeTest} ${input} ${element} ${result})
        set_tests_properties(${myname}
            PROPERTIES PASS_REGULAR_EXPRESSION "test ${functionName} : SUCCES"
        )
    endfunction()

    testStringUtils( TestCountInChar countChar tools_test  0x0011 superstrings s 3)
    testStringUtils( TestIsCharExistInArray isCharExistInArray tools_test  0x0012 superstrings t 1)
    testStringUtils( TestConcatenateString concatanateString tools_test  0x0013 super strings superstrings)
    testStringUtils( TestConcatenateChar concatanateChar tools_test  0x0014 tot o toto)
    testStringUtils( TestCopyString copyString tools_test  0x0015 toto 0 toto)
    testStringUtils( TestIsIdenticalString isIdenticalStr tools_test  0x0016 toto 0 toto)
    
    add_test(NAME testList COMMAND tools_test 0x0020 toto to tot)
    set_tests_properties(testList
        PROPERTIES PASS_REGULAR_EXPRESSION "test initList : SUCCES" 
        "test find List : SUCCES SUCCES" 
        "test ValueList : SUCCES" 
        "test removeList: SUCCES"
        "test clearList: SUCCES"
    )
    add_test(NAME testTree COMMAND tools_test 0x0020 toto to tot tata ta tat)
    set_tests_properties(testTree
        PROPERTIES PASS_REGULAR_EXPRESSION "test initList : SUCCES" 
        "test find List : SUCCES SUCCES" 
        "test removeList: SUCCES"
        "test removeList: SUCCES"
        "test clearList: SUCCES"
    )
endif()
