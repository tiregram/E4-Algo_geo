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
include lib/glfw/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include lib/glfw/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw/tests/CMakeFiles/windows.dir/flags.make

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o: lib/glfw/tests/CMakeFiles/windows.dir/flags.make
lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o: lib/glfw/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/windows.c

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/windows.c > CMakeFiles/windows.dir/windows.c.i

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/windows.c -o CMakeFiles/windows.dir/windows.c.s

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.requires:

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.requires

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.provides: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.requires
	$(MAKE) -f lib/glfw/tests/CMakeFiles/windows.dir/build.make lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.provides

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.provides.build: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o


# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

lib/glfw/tests/windows: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o
lib/glfw/tests/windows: lib/glfw/tests/CMakeFiles/windows.dir/build.make
lib/glfw/tests/windows: lib/glfw/src/libglfw3.a
lib/glfw/tests/windows: /usr/lib64/librt.so
lib/glfw/tests/windows: /usr/lib64/libm.so
lib/glfw/tests/windows: /usr/lib64/libX11.so
lib/glfw/tests/windows: /usr/lib64/libXrandr.so
lib/glfw/tests/windows: /usr/lib64/libXinerama.so
lib/glfw/tests/windows: /usr/lib64/libXi.so
lib/glfw/tests/windows: /usr/lib64/libXxf86vm.so
lib/glfw/tests/windows: /usr/lib64/libXcursor.so
lib/glfw/tests/windows: /usr/lib64/libGL.so
lib/glfw/tests/windows: lib/glfw/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable windows"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw/tests/CMakeFiles/windows.dir/build: lib/glfw/tests/windows

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/build

lib/glfw/tests/CMakeFiles/windows.dir/requires: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.o.requires

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/requires

lib/glfw/tests/CMakeFiles/windows.dir/clean:
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/clean

lib/glfw/tests/CMakeFiles/windows.dir/depend:
	cd /home/ruhtra/Downloads/test/meshviewer-clean && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/depend
