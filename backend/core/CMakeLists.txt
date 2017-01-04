include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

# add sub directory
add_subdirectory(channel)
add_subdirectory(common)
add_subdirectory(dataloader)

