# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hypark/DL_opt/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hypark/DL_opt/cmake/build

# Include any dependencies generated for this target.
include hello-exe/CMakeFiles/cmake_tutorial.dir/depend.make

# Include the progress variables for this target.
include hello-exe/CMakeFiles/cmake_tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include hello-exe/CMakeFiles/cmake_tutorial.dir/flags.make

hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.o: hello-exe/CMakeFiles/cmake_tutorial.dir/flags.make
hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.o: ../hello-exe/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hypark/DL_opt/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.o"
	cd /home/hypark/DL_opt/cmake/build/hello-exe && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmake_tutorial.dir/main.cpp.o -c /home/hypark/DL_opt/cmake/hello-exe/main.cpp

hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_tutorial.dir/main.cpp.i"
	cd /home/hypark/DL_opt/cmake/build/hello-exe && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hypark/DL_opt/cmake/hello-exe/main.cpp > CMakeFiles/cmake_tutorial.dir/main.cpp.i

hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_tutorial.dir/main.cpp.s"
	cd /home/hypark/DL_opt/cmake/build/hello-exe && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hypark/DL_opt/cmake/hello-exe/main.cpp -o CMakeFiles/cmake_tutorial.dir/main.cpp.s

# Object files for target cmake_tutorial
cmake_tutorial_OBJECTS = \
"CMakeFiles/cmake_tutorial.dir/main.cpp.o"

# External object files for target cmake_tutorial
cmake_tutorial_EXTERNAL_OBJECTS =

hello-exe/cmake_tutorial: hello-exe/CMakeFiles/cmake_tutorial.dir/main.cpp.o
hello-exe/cmake_tutorial: hello-exe/CMakeFiles/cmake_tutorial.dir/build.make
hello-exe/cmake_tutorial: say-hello/libsay-hello.a
hello-exe/cmake_tutorial: hello-exe/CMakeFiles/cmake_tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hypark/DL_opt/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmake_tutorial"
	cd /home/hypark/DL_opt/cmake/build/hello-exe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake_tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hello-exe/CMakeFiles/cmake_tutorial.dir/build: hello-exe/cmake_tutorial

.PHONY : hello-exe/CMakeFiles/cmake_tutorial.dir/build

hello-exe/CMakeFiles/cmake_tutorial.dir/clean:
	cd /home/hypark/DL_opt/cmake/build/hello-exe && $(CMAKE_COMMAND) -P CMakeFiles/cmake_tutorial.dir/cmake_clean.cmake
.PHONY : hello-exe/CMakeFiles/cmake_tutorial.dir/clean

hello-exe/CMakeFiles/cmake_tutorial.dir/depend:
	cd /home/hypark/DL_opt/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hypark/DL_opt/cmake /home/hypark/DL_opt/cmake/hello-exe /home/hypark/DL_opt/cmake/build /home/hypark/DL_opt/cmake/build/hello-exe /home/hypark/DL_opt/cmake/build/hello-exe/CMakeFiles/cmake_tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hello-exe/CMakeFiles/cmake_tutorial.dir/depend

