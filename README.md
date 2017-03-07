# Husky-Vis

Build

Download the source code with submodule Husky.

git clone --recursive https://github.com/Gyingguo/Husky-Vis.git
Go to the project root and do an out-of-source build using CMake:

Build Server

cd backend
mkdir debug
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make help               # List all build target
make Server             # Build Server 
make -j                 # Build all applications with all threads

Configuration
...


Run
...
