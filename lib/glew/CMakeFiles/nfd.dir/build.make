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
CMAKE_SOURCE_DIR = /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew

# Include any dependencies generated for this target.
include CMakeFiles/nfd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nfd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nfd.dir/flags.make

CMakeFiles/nfd.dir/src/glew.c.o: CMakeFiles/nfd.dir/flags.make
CMakeFiles/nfd.dir/src/glew.c.o: src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nfd.dir/src/glew.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nfd.dir/src/glew.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c

CMakeFiles/nfd.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nfd.dir/src/glew.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c > CMakeFiles/nfd.dir/src/glew.c.i

CMakeFiles/nfd.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nfd.dir/src/glew.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glew.c -o CMakeFiles/nfd.dir/src/glew.c.s

CMakeFiles/nfd.dir/src/glew.c.o.requires:

.PHONY : CMakeFiles/nfd.dir/src/glew.c.o.requires

CMakeFiles/nfd.dir/src/glew.c.o.provides: CMakeFiles/nfd.dir/src/glew.c.o.requires
	$(MAKE) -f CMakeFiles/nfd.dir/build.make CMakeFiles/nfd.dir/src/glew.c.o.provides.build
.PHONY : CMakeFiles/nfd.dir/src/glew.c.o.provides

CMakeFiles/nfd.dir/src/glew.c.o.provides.build: CMakeFiles/nfd.dir/src/glew.c.o


CMakeFiles/nfd.dir/src/glewinfo.c.o: CMakeFiles/nfd.dir/flags.make
CMakeFiles/nfd.dir/src/glewinfo.c.o: src/glewinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nfd.dir/src/glewinfo.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nfd.dir/src/glewinfo.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glewinfo.c

CMakeFiles/nfd.dir/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nfd.dir/src/glewinfo.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glewinfo.c > CMakeFiles/nfd.dir/src/glewinfo.c.i

CMakeFiles/nfd.dir/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nfd.dir/src/glewinfo.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/glewinfo.c -o CMakeFiles/nfd.dir/src/glewinfo.c.s

CMakeFiles/nfd.dir/src/glewinfo.c.o.requires:

.PHONY : CMakeFiles/nfd.dir/src/glewinfo.c.o.requires

CMakeFiles/nfd.dir/src/glewinfo.c.o.provides: CMakeFiles/nfd.dir/src/glewinfo.c.o.requires
	$(MAKE) -f CMakeFiles/nfd.dir/build.make CMakeFiles/nfd.dir/src/glewinfo.c.o.provides.build
.PHONY : CMakeFiles/nfd.dir/src/glewinfo.c.o.provides

CMakeFiles/nfd.dir/src/glewinfo.c.o.provides.build: CMakeFiles/nfd.dir/src/glewinfo.c.o


CMakeFiles/nfd.dir/src/visualinfo.c.o: CMakeFiles/nfd.dir/flags.make
CMakeFiles/nfd.dir/src/visualinfo.c.o: src/visualinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/nfd.dir/src/visualinfo.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nfd.dir/src/visualinfo.c.o   -c /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/visualinfo.c

CMakeFiles/nfd.dir/src/visualinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nfd.dir/src/visualinfo.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/visualinfo.c > CMakeFiles/nfd.dir/src/visualinfo.c.i

CMakeFiles/nfd.dir/src/visualinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nfd.dir/src/visualinfo.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/src/visualinfo.c -o CMakeFiles/nfd.dir/src/visualinfo.c.s

CMakeFiles/nfd.dir/src/visualinfo.c.o.requires:

.PHONY : CMakeFiles/nfd.dir/src/visualinfo.c.o.requires

CMakeFiles/nfd.dir/src/visualinfo.c.o.provides: CMakeFiles/nfd.dir/src/visualinfo.c.o.requires
	$(MAKE) -f CMakeFiles/nfd.dir/build.make CMakeFiles/nfd.dir/src/visualinfo.c.o.provides.build
.PHONY : CMakeFiles/nfd.dir/src/visualinfo.c.o.provides

CMakeFiles/nfd.dir/src/visualinfo.c.o.provides.build: CMakeFiles/nfd.dir/src/visualinfo.c.o


# Object files for target nfd
nfd_OBJECTS = \
"CMakeFiles/nfd.dir/src/glew.c.o" \
"CMakeFiles/nfd.dir/src/glewinfo.c.o" \
"CMakeFiles/nfd.dir/src/visualinfo.c.o"

# External object files for target nfd
nfd_EXTERNAL_OBJECTS =

libnfd.a: CMakeFiles/nfd.dir/src/glew.c.o
libnfd.a: CMakeFiles/nfd.dir/src/glewinfo.c.o
libnfd.a: CMakeFiles/nfd.dir/src/visualinfo.c.o
libnfd.a: CMakeFiles/nfd.dir/build.make
libnfd.a: CMakeFiles/nfd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libnfd.a"
	$(CMAKE_COMMAND) -P CMakeFiles/nfd.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nfd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nfd.dir/build: libnfd.a

.PHONY : CMakeFiles/nfd.dir/build

CMakeFiles/nfd.dir/requires: CMakeFiles/nfd.dir/src/glew.c.o.requires
CMakeFiles/nfd.dir/requires: CMakeFiles/nfd.dir/src/glewinfo.c.o.requires
CMakeFiles/nfd.dir/requires: CMakeFiles/nfd.dir/src/visualinfo.c.o.requires

.PHONY : CMakeFiles/nfd.dir/requires

CMakeFiles/nfd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nfd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nfd.dir/clean

CMakeFiles/nfd.dir/depend:
	cd /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew /home/ruhtra/Downloads/test/meshviewer-clean/lib/glew/CMakeFiles/nfd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nfd.dir/depend
