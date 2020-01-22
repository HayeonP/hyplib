cmake_minimum_required(VERSION 3.16)
project(cpp_test VERSION 1.0.0)

add_executable(CsvLoggerCppTest
    CsvLogger.hpp
    CsvLogger.cpp
    main_cpp.cpp
)
target_link_libraries(CsvLoggerCppTest
    -pthread
)

add_executable(CsvLoggerCTest
    CsvLogger.h
    CsvLogger.c
    main_c.c
)

set_target_properties(CsvLoggerCppTest PROPERTIES LINKER_LANGUAGE CXX)


