cmake_minimum_required(VERSION 3.16)
project(cpp_test VERSION 1.0.0)

add_executable(CsvLoggerTest
    CsvLogger.h
	CsvLogger.cpp
    main.cpp
)
target_link_libraries(CsvLoggerTest
    -pthread
)
set_target_properties(CsvLoggerTest PROPERTIES LINKER_LANGUAGE CXX)


