# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/artamonovoleg/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/artamonovoleg/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/artamonovoleg/CLionProjects/TestTask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestTask.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TestTask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestTask.dir/flags.make

CMakeFiles/TestTask.dir/main.cpp.o: CMakeFiles/TestTask.dir/flags.make
CMakeFiles/TestTask.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestTask.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestTask.dir/main.cpp.o -c /Users/artamonovoleg/CLionProjects/TestTask/main.cpp

CMakeFiles/TestTask.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestTask.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/artamonovoleg/CLionProjects/TestTask/main.cpp > CMakeFiles/TestTask.dir/main.cpp.i

CMakeFiles/TestTask.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestTask.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/artamonovoleg/CLionProjects/TestTask/main.cpp -o CMakeFiles/TestTask.dir/main.cpp.s

# Object files for target TestTask
TestTask_OBJECTS = \
"CMakeFiles/TestTask.dir/main.cpp.o"

# External object files for target TestTask
TestTask_EXTERNAL_OBJECTS =

TestTask: CMakeFiles/TestTask.dir/main.cpp.o
TestTask: CMakeFiles/TestTask.dir/build.make
TestTask: CMakeFiles/TestTask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestTask"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestTask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestTask.dir/build: TestTask
.PHONY : CMakeFiles/TestTask.dir/build

CMakeFiles/TestTask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestTask.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestTask.dir/clean

CMakeFiles/TestTask.dir/depend:
	cd /Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/artamonovoleg/CLionProjects/TestTask /Users/artamonovoleg/CLionProjects/TestTask /Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug /Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug /Users/artamonovoleg/CLionProjects/TestTask/cmake-build-debug/CMakeFiles/TestTask.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestTask.dir/depend
