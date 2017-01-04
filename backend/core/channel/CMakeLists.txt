include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${Boost_INCLUDE_DIRS})

if(DEP_FOUND)
    include_directories(${ZMQ_INCLUDE_DIR})
endif(DEP_FOUND)

add_library(visualization-channel-objs STATIC
    aggregate_channel.cpp
    chart_type_channel.cpp
    generate_channel.cpp
    statistic_channel.cpp
)
set_property(TARGET visualization-channel-objs PROPERTY CXX_STANDARD 14)
