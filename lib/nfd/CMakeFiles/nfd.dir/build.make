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
CMAKE_SOURCE_DIR = /home/ruhtra/Downloads/test/E4-Algo_geo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruhtra/Downloads/test/E4-Algo_geo

# Include any dependencies generated for this target.
include lib/nfd/CMakeFiles/nfd.dir/depend.make

# Include the progress variables for this target.
include lib/nfd/CMakeFiles/nfd.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nfd/CMakeFiles/nfd.dir/flags.make

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o: lib/nfd/CMakeFiles/nfd.dir/flags.make
lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o: lib/nfd/src/nfd_gtk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nfd.dir/src/nfd_gtk.c.o   -c /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_gtk.c

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nfd.dir/src/nfd_gtk.c.i"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_gtk.c > CMakeFiles/nfd.dir/src/nfd_gtk.c.i

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nfd.dir/src/nfd_gtk.c.s"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_gtk.c -o CMakeFiles/nfd.dir/src/nfd_gtk.c.s

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.requires:

.PHONY : lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.requires

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.provides: lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.requires
	$(MAKE) -f lib/nfd/CMakeFiles/nfd.dir/build.make lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.provides.build
.PHONY : lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.provides

lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.provides.build: lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o


lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o: lib/nfd/CMakeFiles/nfd.dir/flags.make
lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o: lib/nfd/src/nfd_common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nfd.dir/src/nfd_common.c.o   -c /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_common.c

lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nfd.dir/src/nfd_common.c.i"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_common.c > CMakeFiles/nfd.dir/src/nfd_common.c.i

lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nfd.dir/src/nfd_common.c.s"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/src/nfd_common.c -o CMakeFiles/nfd.dir/src/nfd_common.c.s

lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.requires:

.PHONY : lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.requires

lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.provides: lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.requires
	$(MAKE) -f lib/nfd/CMakeFiles/nfd.dir/build.make lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.provides.build
.PHONY : lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.provides

lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.provides.build: lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o


# Object files for target nfd
nfd_OBJECTS = \
"CMakeFiles/nfd.dir/src/nfd_gtk.c.o" \
"CMakeFiles/nfd.dir/src/nfd_common.c.o"

# External object files for target nfd
nfd_EXTERNAL_OBJECTS =

lib/nfd/libnfd.a: lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o
lib/nfd/libnfd.a: lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o
lib/nfd/libnfd.a: lib/nfd/CMakeFiles/nfd.dir/build.make
lib/nfd/libnfd.a: lib/nfd/CMakeFiles/nfd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libnfd.a"
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && $(CMAKE_COMMAND) -P CMakeFiles/nfd.dir/cmake_clean_target.cmake
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nfd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nfd/CMakeFiles/nfd.dir/build: lib/nfd/libnfd.a

.PHONY : lib/nfd/CMakeFiles/nfd.dir/build

lib/nfd/CMakeFiles/nfd.dir/requires: lib/nfd/CMakeFiles/nfd.dir/src/nfd_gtk.c.o.requires
lib/nfd/CMakeFiles/nfd.dir/requires: lib/nfd/CMakeFiles/nfd.dir/src/nfd_common.c.o.requires

.PHONY : lib/nfd/CMakeFiles/nfd.dir/requires

lib/nfd/CMakeFiles/nfd.dir/clean:
	cd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd && $(CMAKE_COMMAND) -P CMakeFiles/nfd.dir/cmake_clean.cmake
.PHONY : lib/nfd/CMakeFiles/nfd.dir/clean

lib/nfd/CMakeFiles/nfd.dir/depend:
	cd /home/ruhtra/Downloads/test/E4-Algo_geo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruhtra/Downloads/test/E4-Algo_geo /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd /home/ruhtra/Downloads/test/E4-Algo_geo /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd /home/ruhtra/Downloads/test/E4-Algo_geo/lib/nfd/CMakeFiles/nfd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nfd/CMakeFiles/nfd.dir/depend

