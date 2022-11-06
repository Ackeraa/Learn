add_library(mylib complex.cpp complex.h)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
