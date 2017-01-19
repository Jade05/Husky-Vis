include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${Boost_INCLUDE_DIRS})

if(DEP_FOUND)
    include_directories(${ZMQ_INCLUDE_DIR})
endif(DEP_FOUND)

add_library(visualization-server-objs STATIC
    app_constants.cpp
    app_types.cpp
    Something_server.skeleton.cpp
    Something.cpp
)
set_property(TARGET visualization-server-objs PROPERTY CXX_STANDARD 14)
