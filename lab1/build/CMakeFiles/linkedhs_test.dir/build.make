# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mihanizzm/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mihanizzm/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mihanizzm/cpp-labs-2022/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mihanizzm/cpp-labs-2022/lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/linkedhs_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linkedhs_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linkedhs_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linkedhs_test.dir/flags.make

CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o: CMakeFiles/linkedhs_test.dir/flags.make
CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o: /home/mihanizzm/cpp-labs-2022/lab1/LinkedHashSet.cpp
CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o: CMakeFiles/linkedhs_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mihanizzm/cpp-labs-2022/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o -MF CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o.d -o CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o -c /home/mihanizzm/cpp-labs-2022/lab1/LinkedHashSet.cpp

CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mihanizzm/cpp-labs-2022/lab1/LinkedHashSet.cpp > CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.i

CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mihanizzm/cpp-labs-2022/lab1/LinkedHashSet.cpp -o CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.s

CMakeFiles/linkedhs_test.dir/Tests.cpp.o: CMakeFiles/linkedhs_test.dir/flags.make
CMakeFiles/linkedhs_test.dir/Tests.cpp.o: /home/mihanizzm/cpp-labs-2022/lab1/Tests.cpp
CMakeFiles/linkedhs_test.dir/Tests.cpp.o: CMakeFiles/linkedhs_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mihanizzm/cpp-labs-2022/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linkedhs_test.dir/Tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linkedhs_test.dir/Tests.cpp.o -MF CMakeFiles/linkedhs_test.dir/Tests.cpp.o.d -o CMakeFiles/linkedhs_test.dir/Tests.cpp.o -c /home/mihanizzm/cpp-labs-2022/lab1/Tests.cpp

CMakeFiles/linkedhs_test.dir/Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linkedhs_test.dir/Tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mihanizzm/cpp-labs-2022/lab1/Tests.cpp > CMakeFiles/linkedhs_test.dir/Tests.cpp.i

CMakeFiles/linkedhs_test.dir/Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linkedhs_test.dir/Tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mihanizzm/cpp-labs-2022/lab1/Tests.cpp -o CMakeFiles/linkedhs_test.dir/Tests.cpp.s

# Object files for target linkedhs_test
linkedhs_test_OBJECTS = \
"CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o" \
"CMakeFiles/linkedhs_test.dir/Tests.cpp.o"

# External object files for target linkedhs_test
linkedhs_test_EXTERNAL_OBJECTS =

linkedhs_test: CMakeFiles/linkedhs_test.dir/LinkedHashSet.cpp.o
linkedhs_test: CMakeFiles/linkedhs_test.dir/Tests.cpp.o
linkedhs_test: CMakeFiles/linkedhs_test.dir/build.make
linkedhs_test: lib/libgtest_main.a
linkedhs_test: lib/libgtest.a
linkedhs_test: CMakeFiles/linkedhs_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mihanizzm/cpp-labs-2022/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable linkedhs_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linkedhs_test.dir/link.txt --verbose=$(VERBOSE)
	/home/mihanizzm/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -D TEST_TARGET=linkedhs_test -D TEST_EXECUTABLE=/home/mihanizzm/cpp-labs-2022/lab1/build/linkedhs_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/mihanizzm/cpp-labs-2022/lab1/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=linkedhs_test_TESTS -D CTEST_FILE=/home/mihanizzm/cpp-labs-2022/lab1/build/linkedhs_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /home/mihanizzm/.local/lib/python3.8/site-packages/cmake/data/share/cmake-3.24/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/linkedhs_test.dir/build: linkedhs_test
.PHONY : CMakeFiles/linkedhs_test.dir/build

CMakeFiles/linkedhs_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linkedhs_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linkedhs_test.dir/clean

CMakeFiles/linkedhs_test.dir/depend:
	cd /home/mihanizzm/cpp-labs-2022/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mihanizzm/cpp-labs-2022/lab1 /home/mihanizzm/cpp-labs-2022/lab1 /home/mihanizzm/cpp-labs-2022/lab1/build /home/mihanizzm/cpp-labs-2022/lab1/build /home/mihanizzm/cpp-labs-2022/lab1/build/CMakeFiles/linkedhs_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linkedhs_test.dir/depend

