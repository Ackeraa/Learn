# My Cpp Learning Program
##  Build with cmake
```shell
cmake -S. -Bbuild
cmake --build build
cd build
ctest
```

## Install gtest
```shell
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```
