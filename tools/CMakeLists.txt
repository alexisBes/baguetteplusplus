add_library(Tools 
    stringTool.c
    ListUtils.c)

target_include_directories(Tools INTERFACE 
                          ${CMAKE_CURRENT_SOURCE_DIR})


  target_link_libraries(Tools INTERFACE bpp_compiler_flag)