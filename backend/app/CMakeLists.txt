include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

add_subdirectory(gen-cpp)

# Server
add_executable(Server server.cpp)
target_link_libraries(Server visualization-server-objs)
target_link_libraries(Server visualization-common-objs)
target_link_libraries(Server visualization-dataloader-objs)
target_link_libraries(Server visualization-channel-objs)
target_link_libraries(Server husky)
target_link_libraries(Server ${HUSKY_EXTERNAL_LIB})
set_property(TARGET Server PROPERTY CXX_STANDARD 14)
