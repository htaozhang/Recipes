include_directories(BEFORE SYSTEM ${gtest_SOURCE_DIR}/include)

aux_source_directory(./ sources)

add_executable(unittest ${sources})

target_link_libraries(unittest gtest gtest_main)
