cmake -S . -B build 
cmake --build build
cd build && ctest
make
./bin/main
