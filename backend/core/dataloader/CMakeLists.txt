include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${Boost_INCLUDE_DIRS})

if(DEP_FOUND)
    include_directories(${ZMQ_INCLUDE_DIR})
endif(DEP_FOUND)

add_library(visualization-dataloader-objs STATIC
    dataloader.cpp
)
set_property(TARGET visualization-dataloader-objs PROPERTY CXX_STANDARD 14)
