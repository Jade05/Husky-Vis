include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

# AggregateChannel
add_executable(AggregateChannel aggregate_channel.cpp)
target_link_libraries(AggregateChannel visualization-channel-objs)
target_link_libraries(AggregateChannel visualization-common-objs)
target_link_libraries(AggregateChannel husky)
target_link_libraries(AggregateChannel ${HUSKY_EXTERNAL_LIB})
set_property(TARGET AggregateChannel PROPERTY CXX_STANDARD 14)

