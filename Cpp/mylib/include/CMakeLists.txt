add_library(mylib
  mycomplex.h
  mystring.h
  myvector.h
  mymatrix.h
  mytuple.h
  matrix2.h
  )
set_target_properties(mylib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
