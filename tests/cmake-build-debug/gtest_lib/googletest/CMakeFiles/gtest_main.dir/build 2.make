# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/parallels/Downloads/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/parallels/Downloads/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug"

# Include any dependencies generated for this target.
include gtest_lib/googletest/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include gtest_lib/googletest/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include gtest_lib/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include gtest_lib/googletest/CMakeFiles/gtest_main.dir/flags.make

gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: gtest_lib/googletest/CMakeFiles/gtest_main.dir/flags.make
gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /home/parallels/Desktop/Parallels\ Shared\ Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/gtest_lib/googletest/src/gtest_main.cc
gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: gtest_lib/googletest/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/gtest_lib/googletest/src/gtest_main.cc"

gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/gtest_lib/googletest/src/gtest_main.cc" > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/gtest_lib/googletest/src/gtest_main.cc" -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_main.a: gtest_lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/libgtest_main.a: gtest_lib/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_main.a: gtest_lib/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgtest_main.a"
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest_lib/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_main.a
.PHONY : gtest_lib/googletest/CMakeFiles/gtest_main.dir/build

gtest_lib/googletest/CMakeFiles/gtest_main.dir/clean:
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : gtest_lib/googletest/CMakeFiles/gtest_main.dir/clean

gtest_lib/googletest/CMakeFiles/gtest_main.dir/depend:
	cd "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests" "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/gtest_lib/googletest" "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug" "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest" "/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Universidad/Algo2/tps/tp3/TP-Grupal-AYP2-2C2023/tests/cmake-build-debug/gtest_lib/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : gtest_lib/googletest/CMakeFiles/gtest_main.dir/depend
