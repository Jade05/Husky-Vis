include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

# Visualization
add_executable(Visualization visualization.cpp)
target_link_libraries(Visualization visualization-common-objs)
target_link_libraries(Visualization visualization-dataloader-objs)
target_link_libraries(Visualization visualization-channel-objs)
target_link_libraries(Visualization husky)
target_link_libraries(Visualization ${HUSKY_EXTERNAL_LIB})
set_property(TARGET Visualization PROPERTY CXX_STANDARD 14)

# Server
add_executable(Server server.cpp)
target_link_libraries(Server visualization-server-objs)
target_link_libraries(Server husky)
target_link_libraries(Server ${HUSKY_EXTERNAL_LIB})
set_property(TARGET Server PROPERTY CXX_STANDARD 14)
