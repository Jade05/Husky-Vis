# Husky-Vis 

The project is divied into three parts:  </br>
1. backend: recommendation engine, implemented by c++;  </br>
2. backend-express-es6: http webserver, connected with recommendation engine by thrift RPC to fetch data; </br>
3. frontend-vue: frontend part

# Build

Download the source code with submodule Husky. </br>

git clone --recursive https://github.com/Gyingguo/Husky-Vis.git </br>

Go to the project root and do an out-of-source build using CMake: </br>

# Build backend

cd backend </br>
mkdir debug </br>
cd debug </br>
cmake -DCMAKE_BUILD_TYPE=Debug .. </br>
make help               # List all build target </br>
make Server             # Build Server </br>
make -j                 # Build all applications with all threads </br>

Configuration </br>

master_host=master </br>
master_port=10086 </br>
comm_port=14279 </br>
hdfs_namenode=master </br>
hdfs_namenode_port=9000 </br>
serve=1 </br>

#data is provided directly </br>
data=test_data.json </br>
data_schema=test_schema.json </br>
#suggestion is distributed by suggestions or data </br>
distribute=suggestions </br>
#distribute=data </br>
#data is provided by mongodb </br>
mongo_server=XXX </br>
mongo_db=XXX </br>
mongo_collection=XXX </br>
#return topk suggestions </br>
topk=10 </br>
#configuable constant data </br>
constant=constant.json </br>

#list your own parameters here: </br>

[worker] </br>
info=master:1 </br>


# Run backend </br>
./debug/Server -C ./conf/single.conf </br>

# backend-express-es6 </br>
gulp watch </br>
npm run server </br>

# frontend-vue </br>
npm run dev </br>
