add_executable(cmake_tutorial main.cpp)

target_link_libraries(cmake_tutorial PUBLIC say-hello) # PRIVATE PUBLIC