cmake -S . -B build 
cmake --build build
cd build && make
./bin/$1
