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
include lib/glfw/tests/CMakeFiles/monitors.dir/depend.make

# Include the progress variables for this target.
include lib/glfw/tests/CMakeFiles/monitors.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw/tests/CMakeFiles/monitors.dir/flags.make

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o: lib/glfw/tests/CMakeFiles/monitors.dir/flags.make
lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o: lib/glfw/tests/monitors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/monitors.dir/monitors.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/monitors.c

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/monitors.c.i"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/monitors.c > CMakeFiles/monitors.dir/monitors.c.i

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/monitors.c.s"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/monitors.c -o CMakeFiles/monitors.dir/monitors.c.s

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.requires:

.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.requires

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.provides: lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.requires
	$(MAKE) -f lib/glfw/tests/CMakeFiles/monitors.dir/build.make lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.provides

lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.provides.build: lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o


lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o: lib/glfw/tests/CMakeFiles/monitors.dir/flags.make
lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o: lib/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/monitors.dir/__/deps/getopt.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/deps/getopt.c

lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/monitors.dir/__/deps/getopt.c.i"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/deps/getopt.c > CMakeFiles/monitors.dir/__/deps/getopt.c.i

lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/monitors.dir/__/deps/getopt.c.s"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/deps/getopt.c -o CMakeFiles/monitors.dir/__/deps/getopt.c.s

lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.requires:

.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.requires

lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.provides: lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f lib/glfw/tests/CMakeFiles/monitors.dir/build.make lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.provides

lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.provides.build: lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o


# Object files for target monitors
monitors_OBJECTS = \
"CMakeFiles/monitors.dir/monitors.c.o" \
"CMakeFiles/monitors.dir/__/deps/getopt.c.o"

# External object files for target monitors
monitors_EXTERNAL_OBJECTS =

lib/glfw/tests/monitors: lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o
lib/glfw/tests/monitors: lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o
lib/glfw/tests/monitors: lib/glfw/tests/CMakeFiles/monitors.dir/build.make
lib/glfw/tests/monitors: lib/glfw/src/libglfw3.a
lib/glfw/tests/monitors: /usr/lib64/librt.so
lib/glfw/tests/monitors: /usr/lib64/libm.so
lib/glfw/tests/monitors: /usr/lib64/libX11.so
lib/glfw/tests/monitors: /usr/lib64/libXrandr.so
lib/glfw/tests/monitors: /usr/lib64/libXinerama.so
lib/glfw/tests/monitors: /usr/lib64/libXi.so
lib/glfw/tests/monitors: /usr/lib64/libXxf86vm.so
lib/glfw/tests/monitors: /usr/lib64/libXcursor.so
lib/glfw/tests/monitors: /usr/lib64/libGL.so
lib/glfw/tests/monitors: lib/glfw/tests/CMakeFiles/monitors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable monitors"
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monitors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw/tests/CMakeFiles/monitors.dir/build: lib/glfw/tests/monitors

.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/build

lib/glfw/tests/CMakeFiles/monitors.dir/requires: lib/glfw/tests/CMakeFiles/monitors.dir/monitors.c.o.requires
lib/glfw/tests/CMakeFiles/monitors.dir/requires: lib/glfw/tests/CMakeFiles/monitors.dir/__/deps/getopt.c.o.requires

.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/requires

lib/glfw/tests/CMakeFiles/monitors.dir/clean:
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/monitors.dir/cmake_clean.cmake
.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/clean

lib/glfw/tests/CMakeFiles/monitors.dir/depend:
	cd /home/ruhtra/Downloads/test/meshviewer-clean && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests /home/ruhtra/Downloads/test/meshviewer-clean /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests /home/ruhtra/Downloads/test/meshviewer-clean/lib/glfw/tests/CMakeFiles/monitors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/tests/CMakeFiles/monitors.dir/depend
