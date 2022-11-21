add_executable(main main.cpp)

target_link_libraries(main
  PUBLIC
  mylib
)

add_executable(template template.cpp)
add_executable(concepts concepts.cpp)

