# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/85/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/85/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mhamdan03/Application-Security

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mhamdan03/Application-Security/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Application_Security.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Application_Security.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Application_Security.dir/flags.make

CMakeFiles/Application_Security.dir/main.c.o: CMakeFiles/Application_Security.dir/flags.make
CMakeFiles/Application_Security.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mhamdan03/Application-Security/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Application_Security.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Application_Security.dir/main.c.o   -c /home/mhamdan03/Application-Security/main.c

CMakeFiles/Application_Security.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Application_Security.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mhamdan03/Application-Security/main.c > CMakeFiles/Application_Security.dir/main.c.i

CMakeFiles/Application_Security.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Application_Security.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mhamdan03/Application-Security/main.c -o CMakeFiles/Application_Security.dir/main.c.s

# Object files for target Application_Security
Application_Security_OBJECTS = \
"CMakeFiles/Application_Security.dir/main.c.o"

# External object files for target Application_Security
Application_Security_EXTERNAL_OBJECTS =

Application_Security: CMakeFiles/Application_Security.dir/main.c.o
Application_Security: CMakeFiles/Application_Security.dir/build.make
Application_Security: CMakeFiles/Application_Security.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mhamdan03/Application-Security/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Application_Security"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Application_Security.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Application_Security.dir/build: Application_Security

.PHONY : CMakeFiles/Application_Security.dir/build

CMakeFiles/Application_Security.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Application_Security.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Application_Security.dir/clean

CMakeFiles/Application_Security.dir/depend:
	cd /home/mhamdan03/Application-Security/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mhamdan03/Application-Security /home/mhamdan03/Application-Security /home/mhamdan03/Application-Security/cmake-build-debug /home/mhamdan03/Application-Security/cmake-build-debug /home/mhamdan03/Application-Security/cmake-build-debug/CMakeFiles/Application_Security.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Application_Security.dir/depend

