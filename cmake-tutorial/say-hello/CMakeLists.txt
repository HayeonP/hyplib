add_library(say-hello# SHARED STATIC(default)
    src/say-hello/hello.hpp
    src/say-hello/hello.cpp
)

target_include_directories(say-hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/say-hello) # INTERFACE / PUBLIC / PRIVATE
target_compile_definitions(say-hello PUBLIC VERSION=3)