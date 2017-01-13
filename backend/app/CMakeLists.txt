include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

# Visualization
add_executable(Visualization visualization.cpp)
target_link_libraries(Visualization visualization-common-objs)
target_link_libraries(Visualization visualization-dataloader-objs)
target_link_libraries(Visualization visualization-channel-objs)
target_link_libraries(Visualization husky)
target_link_libraries(Visualization ${HUSKY_EXTERNAL_LIB})
set_property(TARGET Visualization PROPERTY CXX_STANDARD 14)
