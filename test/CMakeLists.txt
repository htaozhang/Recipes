
aux_source_directory(./ sources)
add_executable(unittest ${sources})
target_link_libraries(unittest gtest)
target_link_libraries(unittest gtest_main)
