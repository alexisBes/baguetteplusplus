add_library(ListUtils ListUtils.cpp)

target_include_directories(ListUtils INTERFACE 
                          ${CMAKE_CURRENT_SOURCE_DIR})


  target_link_libraries(ListUtils INTERFACE bpp_compiler_flag)