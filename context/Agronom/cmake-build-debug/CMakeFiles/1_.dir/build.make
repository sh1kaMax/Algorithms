# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Максим/Dropbox/algos/context/Agronom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1_.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_.dir/flags.make

CMakeFiles/1_.dir/main.cpp.o: CMakeFiles/1_.dir/flags.make
CMakeFiles/1_.dir/main.cpp.o: /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/main.cpp
CMakeFiles/1_.dir/main.cpp.o: CMakeFiles/1_.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1_.dir/main.cpp.o -MF CMakeFiles/1_.dir/main.cpp.o.d -o CMakeFiles/1_.dir/main.cpp.o -c /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/main.cpp

CMakeFiles/1_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/main.cpp > CMakeFiles/1_.dir/main.cpp.i

CMakeFiles/1_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/main.cpp -o CMakeFiles/1_.dir/main.cpp.s

# Object files for target 1_
1__OBJECTS = \
"CMakeFiles/1_.dir/main.cpp.o"

# External object files for target 1_
1__EXTERNAL_OBJECTS =

1_: CMakeFiles/1_.dir/main.cpp.o
1_: CMakeFiles/1_.dir/build.make
1_: CMakeFiles/1_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_.dir/build: 1_
.PHONY : CMakeFiles/1_.dir/build

CMakeFiles/1_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_.dir/clean

CMakeFiles/1_.dir/depend:
	cd /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Максим/Dropbox/algos/context/Agronom /mnt/c/Users/Максим/Dropbox/algos/context/Agronom /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug /mnt/c/Users/Максим/Dropbox/algos/context/Agronom/cmake-build-debug/CMakeFiles/1_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1_.dir/depend

