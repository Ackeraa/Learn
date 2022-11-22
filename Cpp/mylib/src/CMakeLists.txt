add_executable(main main.cpp)

target_link_libraries(main
  PUBLIC
  mylib
)

add_executable(template template.cpp)
add_executable(concepts concepts.cpp)
add_executable(allocator allocator.cpp)
add_executable(ranges ranges.cpp)
add_executable(utilities utilities.cpp)
add_executable(concurrency concurrency.cpp)

