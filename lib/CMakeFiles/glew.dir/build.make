# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ruhtra/Downloads/test/meshviewer-clean

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruhtra/Downloads/test/meshviewer-clean

# Include any dependencies generated for this target.
include lib/CMakeFiles/glew.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/glew.dir/flags.make

lib/CMakeFiles/glew.dir/glew/src/glew.c.o: lib/CMakeFiles/glew.dir/flags.make
lib/CMakeFiles/glew.dir/glew/src/glew.c.o: lib/glew/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/glew.dir/glew/src/glew.c.o"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew.dir/glew/src/glew.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c

lib/CMakeFiles/glew.dir/glew/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/glew/src/glew.c.i"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c > CMakeFiles/glew.dir/glew/src/glew.c.i

lib/CMakeFiles/glew.dir/glew/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/glew/src/glew.c.s"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c -o CMakeFiles/glew.dir/glew/src/glew.c.s

lib/CMakeFiles/glew.dir/glew/src/glew.c.o.requires:

.PHONY : lib/CMakeFiles/glew.dir/glew/src/glew.c.o.requires

lib/CMakeFiles/glew.dir/glew/src/glew.c.o.provides: lib/CMakeFiles/glew.dir/glew/src/glew.c.o.requires
	$(MAKE) -f lib/CMakeFiles/glew.dir/build.make lib/CMakeFiles/glew.dir/glew/src/glew.c.o.provides.build
.PHONY : lib/CMakeFiles/glew.dir/glew/src/glew.c.o.provides

lib/CMakeFiles/glew.dir/glew/src/glew.c.o.provides.build: lib/CMakeFiles/glew.dir/glew/src/glew.c.o


# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/glew/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

lib/libglew.a: lib/CMakeFiles/glew.dir/glew/src/glew.c.o
lib/libglew.a: lib/CMakeFiles/glew.dir/build.make
lib/libglew.a: lib/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglew.a"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean_target.cmake
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/glew.dir/build: lib/libglew.a

.PHONY : lib/CMakeFiles/glew.dir/build

lib/CMakeFiles/glew.dir/requires: lib/CMakeFiles/glew.dir/glew/src/glew.c.o.requires

.PHONY : lib/CMakeFiles/glew.dir/requires

lib/CMakeFiles/glew.dir/clean:
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/glew.dir/clean

lib/CMakeFiles/glew.dir/depend:
	cd /home/ruhtra/Downloads/test/meshviewer-clean && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib /home/ruhtra/Downloads/test/meshviewer-clean/lib/CMakeFiles/glew.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/glew.dir/depend
