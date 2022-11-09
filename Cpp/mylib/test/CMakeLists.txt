find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests
  test_mycomplex.cpp
  test_mystring.cpp
  test_myvector.cpp
  test_mymatrix.cpp
  )

target_link_libraries(unit_tests
  PUBLIC
  mylib
  gtest_main
  ${GTEST_LIBRARIES} pthread
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
  LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
  240
  )

