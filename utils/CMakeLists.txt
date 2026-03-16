
  ###
  ### Ce project contien une librairie avec des fonction utile 
  ###
add_library(Tools 
    src/tools_string.c
    src/tools_tree.c
    src/tools_stack.c)

target_include_directories(Tools PRIVATE 
                          ${CMAKE_CURRENT_SOURCE_DIR}/include)


  target_link_libraries(Tools INTERFACE bpp_compiler_flag)

  ###
  ### executable pour test unitaire de la lib
  ###
    add_executable(tools_test
    test/src/main.c
    test/src/suite_toolsString.c
    test/src/suite_toolsTree.c
    test/src/suite_toolsStack.c
    src/tools_string.c
    src/tools_tree.c
    src/tools_stack.c)
    

    target_include_directories(tools_test PRIVATE
        test/  
        include/)

    target_link_libraries(tools_test 
        cunit)

