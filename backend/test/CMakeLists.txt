include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/husky ${HUSKY_EXTERNAL_INCLUDE})

# AggregateChannelTest
add_executable(AggregateChannelTest aggregate_channel_test.cpp)
target_link_libraries(AggregateChannelTest visualization-channel-objs)
target_link_libraries(AggregateChannelTest visualization-common-objs)
target_link_libraries(AggregateChannelTest husky)
target_link_libraries(AggregateChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET AggregateChannelTest PROPERTY CXX_STANDARD 14)


# ChartTypeChannelTest 
add_executable(ChartTypeChannelTest chart_type_channel_test.cpp)
target_link_libraries(ChartTypeChannelTest visualization-channel-objs)
target_link_libraries(ChartTypeChannelTest visualization-common-objs)
target_link_libraries(ChartTypeChannelTest husky)
target_link_libraries(ChartTypeChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET ChartTypeChannelTest PROPERTY CXX_STANDARD 14)


# ConstantTest 
add_executable(ConstantTest constant_test.cpp)
target_link_libraries(ConstantTest visualization-channel-objs)
target_link_libraries(ConstantTest visualization-common-objs)
target_link_libraries(ConstantTest husky)
target_link_libraries(ConstantTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET ConstantTest PROPERTY CXX_STANDARD 14)

# DataloaderTest 
add_executable(DataloaderTest dataloader_test.cpp)
target_link_libraries(DataloaderTest visualization-dataloader-objs)
target_link_libraries(DataloaderTest visualization-common-objs)
target_link_libraries(DataloaderTest husky)
target_link_libraries(DataloaderTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET DataloaderTest PROPERTY CXX_STANDARD 14)

# GenerateChannelTest 
add_executable(GenerateChannelTest generate_channel_test.cpp)
target_link_libraries(GenerateChannelTest visualization-channel-objs)
target_link_libraries(GenerateChannelTest visualization-common-objs)
target_link_libraries(GenerateChannelTest husky)
target_link_libraries(GenerateChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET GenerateChannelTest PROPERTY CXX_STANDARD 14)

# StatisticChannelTest 
add_executable(StatisticChannelTest statistic_channel_test.cpp)
target_link_libraries(StatisticChannelTest visualization-channel-objs)
target_link_libraries(StatisticChannelTest visualization-common-objs)
target_link_libraries(StatisticChannelTest husky)
target_link_libraries(StatisticChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET StatisticChannelTest PROPERTY CXX_STANDARD 14)

# RawDataChannelTest 
add_executable(RawDataChannelTest process_rawdata_channel_test.cpp)
target_link_libraries(RawDataChannelTest visualization-channel-objs)
target_link_libraries(RawDataChannelTest visualization-common-objs)
target_link_libraries(RawDataChannelTest visualization-dataloader-objs)
target_link_libraries(RawDataChannelTest husky)
target_link_libraries(RawDataChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET RawDataChannelTest PROPERTY CXX_STANDARD 14)

# AggregateDataChannelTest 
add_executable(AggregateDataChannelTest process_aggregatedata_channel_test.cpp)
target_link_libraries(AggregateDataChannelTest visualization-channel-objs)
target_link_libraries(AggregateDataChannelTest visualization-common-objs)
target_link_libraries(AggregateDataChannelTest visualization-dataloader-objs)
target_link_libraries(AggregateDataChannelTest husky)
target_link_libraries(AggregateDataChannelTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET AggregateDataChannelTest PROPERTY CXX_STANDARD 14)

# UtilsTest 
add_executable(UtilsTest utils_test.cpp)
target_link_libraries(UtilsTest husky)
target_link_libraries(UtilsTest visualization-common-objs)
target_link_libraries(UtilsTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET UtilsTest PROPERTY CXX_STANDARD 14)

# PreprocessTest
add_executable(PreprocessTest preprocess_test.cpp)
target_link_libraries(PreprocessTest husky)
target_link_libraries(PreprocessTest visualization-dataloader-objs)
target_link_libraries(PreprocessTest ${HUSKY_EXTERNAL_LIB})
set_property(TARGET PreprocessTest PROPERTY CXX_STANDARD 14)
