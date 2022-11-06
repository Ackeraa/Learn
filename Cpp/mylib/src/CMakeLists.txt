add_library(mylib complex1.cpp complex1.h)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp)
