add_library(Tools 
    src/StringTool.c
    src/ListUtils.c
    src/ArrayUtils.c)

target_include_directories(Tools PRIVATE 
                          ${CMAKE_CURRENT_SOURCE_DIR}/include)


  target_link_libraries(Tools INTERFACE bpp_compiler_flag)
