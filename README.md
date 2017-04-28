# Husky-Vis

The project is divied into three parts: 
1. backend: recommendation engine, implemented by c++;
2. backend-express-es6: http webserver, connected with recommendation engine by thrift RPC to fetch data;
3. frontend-vue: frontend part

# Build

Download the source code with submodule Husky.

git clone --recursive https://github.com/Gyingguo/Husky-Vis.git

Go to the project root and do an out-of-source build using CMake:

# Build backend

cd backend
mkdir debug
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make help               # List all build target
make Server             # Build Server 
make -j                 # Build all applications with all threads

Configuration
master_host=master
master_port=10086
comm_port=14279
hdfs_namenode=master
hdfs_namenode_port=9000
serve=1

// data is provided directly
data=test_data.json
data_schema=test_schema.json
// suggestion is distributed by suggestions or data
distribute=suggestions
// distribute=data
// data is provided by mongodb
mongo_server=XXX
mongo_db=XXX
mongo_collection=XXX
// return topk suggestions
topk=10
// configuable constant data
constant=constant.json

// list your own parameters here:

[worker]
info=master:1


# Run backend
./debug/Server -C ./conf/single.conf

# backend-express-es6
gulp watch
npm run server

# frontend-vue
npm run dev
