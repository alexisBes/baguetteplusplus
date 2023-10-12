add_library(MainParser mainParser.cpp)

target_include_directories(MainParser INTERFACE 
                          ${CMAKE_CURRENT_SOURCE_DIR})


  target_link_libraries(MainParser INTERFACE bpp_compiler_flag)