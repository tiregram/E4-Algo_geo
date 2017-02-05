# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles /home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ruhtra/Downloads/test/E4-Algo_geo/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Mesh.bin

# Build rule for target.
Mesh.bin: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Mesh.bin
.PHONY : Mesh.bin

# fast build rule for target.
Mesh.bin/fast:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/build
.PHONY : Mesh.bin/fast

#=============================================================================
# Target rules for targets named nfd

# Build rule for target.
nfd: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 nfd
.PHONY : nfd

# fast build rule for target.
nfd/fast:
	$(MAKE) -f lib/nfd/CMakeFiles/nfd.dir/build.make lib/nfd/CMakeFiles/nfd.dir/build
.PHONY : nfd/fast

src/Globalvar.o: src/Globalvar.cpp.o

.PHONY : src/Globalvar.o

# target to build an object file
src/Globalvar.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/Globalvar.cpp.o
.PHONY : src/Globalvar.cpp.o

src/Globalvar.i: src/Globalvar.cpp.i

.PHONY : src/Globalvar.i

# target to preprocess a source file
src/Globalvar.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/Globalvar.cpp.i
.PHONY : src/Globalvar.cpp.i

src/Globalvar.s: src/Globalvar.cpp.s

.PHONY : src/Globalvar.s

# target to generate assembly for a file
src/Globalvar.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/Globalvar.cpp.s
.PHONY : src/Globalvar.cpp.s

src/helperFunctions.o: src/helperFunctions.cpp.o

.PHONY : src/helperFunctions.o

# target to build an object file
src/helperFunctions.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/helperFunctions.cpp.o
.PHONY : src/helperFunctions.cpp.o

src/helperFunctions.i: src/helperFunctions.cpp.i

.PHONY : src/helperFunctions.i

# target to preprocess a source file
src/helperFunctions.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/helperFunctions.cpp.i
.PHONY : src/helperFunctions.cpp.i

src/helperFunctions.s: src/helperFunctions.cpp.s

.PHONY : src/helperFunctions.s

# target to generate assembly for a file
src/helperFunctions.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/helperFunctions.cpp.s
.PHONY : src/helperFunctions.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/matrix.o: src/matrix.cpp.o

.PHONY : src/matrix.o

# target to build an object file
src/matrix.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/matrix.cpp.o
.PHONY : src/matrix.cpp.o

src/matrix.i: src/matrix.cpp.i

.PHONY : src/matrix.i

# target to preprocess a source file
src/matrix.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/matrix.cpp.i
.PHONY : src/matrix.cpp.i

src/matrix.s: src/matrix.cpp.s

.PHONY : src/matrix.s

# target to generate assembly for a file
src/matrix.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/matrix.cpp.s
.PHONY : src/matrix.cpp.s

src/myFace.o: src/myFace.cpp.o

.PHONY : src/myFace.o

# target to build an object file
src/myFace.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myFace.cpp.o
.PHONY : src/myFace.cpp.o

src/myFace.i: src/myFace.cpp.i

.PHONY : src/myFace.i

# target to preprocess a source file
src/myFace.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myFace.cpp.i
.PHONY : src/myFace.cpp.i

src/myFace.s: src/myFace.cpp.s

.PHONY : src/myFace.s

# target to generate assembly for a file
src/myFace.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myFace.cpp.s
.PHONY : src/myFace.cpp.s

src/myHalfedge.o: src/myHalfedge.cpp.o

.PHONY : src/myHalfedge.o

# target to build an object file
src/myHalfedge.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myHalfedge.cpp.o
.PHONY : src/myHalfedge.cpp.o

src/myHalfedge.i: src/myHalfedge.cpp.i

.PHONY : src/myHalfedge.i

# target to preprocess a source file
src/myHalfedge.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myHalfedge.cpp.i
.PHONY : src/myHalfedge.cpp.i

src/myHalfedge.s: src/myHalfedge.cpp.s

.PHONY : src/myHalfedge.s

# target to generate assembly for a file
src/myHalfedge.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myHalfedge.cpp.s
.PHONY : src/myHalfedge.cpp.s

src/myMesh.o: src/myMesh.cpp.o

.PHONY : src/myMesh.o

# target to build an object file
src/myMesh.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myMesh.cpp.o
.PHONY : src/myMesh.cpp.o

src/myMesh.i: src/myMesh.cpp.i

.PHONY : src/myMesh.i

# target to preprocess a source file
src/myMesh.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myMesh.cpp.i
.PHONY : src/myMesh.cpp.i

src/myMesh.s: src/myMesh.cpp.s

.PHONY : src/myMesh.s

# target to generate assembly for a file
src/myMesh.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myMesh.cpp.s
.PHONY : src/myMesh.cpp.s

src/myPoint3D.o: src/myPoint3D.cpp.o

.PHONY : src/myPoint3D.o

# target to build an object file
src/myPoint3D.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myPoint3D.cpp.o
.PHONY : src/myPoint3D.cpp.o

src/myPoint3D.i: src/myPoint3D.cpp.i

.PHONY : src/myPoint3D.i

# target to preprocess a source file
src/myPoint3D.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myPoint3D.cpp.i
.PHONY : src/myPoint3D.cpp.i

src/myPoint3D.s: src/myPoint3D.cpp.s

.PHONY : src/myPoint3D.s

# target to generate assembly for a file
src/myPoint3D.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myPoint3D.cpp.s
.PHONY : src/myPoint3D.cpp.s

src/myVector3D.o: src/myVector3D.cpp.o

.PHONY : src/myVector3D.o

# target to build an object file
src/myVector3D.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVector3D.cpp.o
.PHONY : src/myVector3D.cpp.o

src/myVector3D.i: src/myVector3D.cpp.i

.PHONY : src/myVector3D.i

# target to preprocess a source file
src/myVector3D.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVector3D.cpp.i
.PHONY : src/myVector3D.cpp.i

src/myVector3D.s: src/myVector3D.cpp.s

.PHONY : src/myVector3D.s

# target to generate assembly for a file
src/myVector3D.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVector3D.cpp.s
.PHONY : src/myVector3D.cpp.s

src/myVertex.o: src/myVertex.cpp.o

.PHONY : src/myVertex.o

# target to build an object file
src/myVertex.cpp.o:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVertex.cpp.o
.PHONY : src/myVertex.cpp.o

src/myVertex.i: src/myVertex.cpp.i

.PHONY : src/myVertex.i

# target to preprocess a source file
src/myVertex.cpp.i:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVertex.cpp.i
.PHONY : src/myVertex.cpp.i

src/myVertex.s: src/myVertex.cpp.s

.PHONY : src/myVertex.s

# target to generate assembly for a file
src/myVertex.cpp.s:
	$(MAKE) -f CMakeFiles/Mesh.bin.dir/build.make CMakeFiles/Mesh.bin.dir/src/myVertex.cpp.s
.PHONY : src/myVertex.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Mesh.bin"
	@echo "... nfd"
	@echo "... src/Globalvar.o"
	@echo "... src/Globalvar.i"
	@echo "... src/Globalvar.s"
	@echo "... src/helperFunctions.o"
	@echo "... src/helperFunctions.i"
	@echo "... src/helperFunctions.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/matrix.o"
	@echo "... src/matrix.i"
	@echo "... src/matrix.s"
	@echo "... src/myFace.o"
	@echo "... src/myFace.i"
	@echo "... src/myFace.s"
	@echo "... src/myHalfedge.o"
	@echo "... src/myHalfedge.i"
	@echo "... src/myHalfedge.s"
	@echo "... src/myMesh.o"
	@echo "... src/myMesh.i"
	@echo "... src/myMesh.s"
	@echo "... src/myPoint3D.o"
	@echo "... src/myPoint3D.i"
	@echo "... src/myPoint3D.s"
	@echo "... src/myVector3D.o"
	@echo "... src/myVector3D.i"
	@echo "... src/myVector3D.s"
	@echo "... src/myVertex.o"
	@echo "... src/myVertex.i"
	@echo "... src/myVertex.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

