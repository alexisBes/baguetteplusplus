add_library(StringTool stringTool.cpp)

target_include_directories(StringTool INTERFACE 
                          ${CMAKE_CURRENT_SOURCE_DIR})


  target_link_libraries(StringTool INTERFACE bpp_compiler_flag)