add_library(MainLexer mainLexer.cpp)

target_include_directories(MainLexer INTERFACE 
                          ${CMAKE_CURRENT_SOURCE_DIR})


  target_link_libraries(MainLexer INTERFACE bpp_compiler_flag)