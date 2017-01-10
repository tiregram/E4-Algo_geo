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
CMAKE_SOURCE_DIR = /home/ruhtra/Downloads/test/meshviewer-clean

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruhtra/Downloads/test/meshviewer-clean

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles /home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ruhtra/Downloads/test/meshviewer-clean/CMakeFiles 0
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
# Target rules for targets named uninstall

# Build rule for target.
uninstall: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uninstall
.PHONY : uninstall

# fast build rule for target.
uninstall/fast:
	$(MAKE) -f lib/glfw/CMakeFiles/uninstall.dir/build.make lib/glfw/CMakeFiles/uninstall.dir/build
.PHONY : uninstall/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) -f lib/glfw/src/CMakeFiles/glfw.dir/build.make lib/glfw/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

#=============================================================================
# Target rules for targets named heightmap

# Build rule for target.
heightmap: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 heightmap
.PHONY : heightmap

# fast build rule for target.
heightmap/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/heightmap.dir/build.make lib/glfw/examples/CMakeFiles/heightmap.dir/build
.PHONY : heightmap/fast

#=============================================================================
# Target rules for targets named gears

# Build rule for target.
gears: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gears
.PHONY : gears

# fast build rule for target.
gears/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/gears.dir/build.make lib/glfw/examples/CMakeFiles/gears.dir/build
.PHONY : gears/fast

#=============================================================================
# Target rules for targets named particles

# Build rule for target.
particles: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 particles
.PHONY : particles

# fast build rule for target.
particles/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/particles.dir/build.make lib/glfw/examples/CMakeFiles/particles.dir/build
.PHONY : particles/fast

#=============================================================================
# Target rules for targets named wave

# Build rule for target.
wave: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 wave
.PHONY : wave

# fast build rule for target.
wave/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/wave.dir/build.make lib/glfw/examples/CMakeFiles/wave.dir/build
.PHONY : wave/fast

#=============================================================================
# Target rules for targets named boing

# Build rule for target.
boing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 boing
.PHONY : boing

# fast build rule for target.
boing/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/boing.dir/build.make lib/glfw/examples/CMakeFiles/boing.dir/build
.PHONY : boing/fast

#=============================================================================
# Target rules for targets named simple

# Build rule for target.
simple: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 simple
.PHONY : simple

# fast build rule for target.
simple/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/simple.dir/build.make lib/glfw/examples/CMakeFiles/simple.dir/build
.PHONY : simple/fast

#=============================================================================
# Target rules for targets named splitview

# Build rule for target.
splitview: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 splitview
.PHONY : splitview

# fast build rule for target.
splitview/fast:
	$(MAKE) -f lib/glfw/examples/CMakeFiles/splitview.dir/build.make lib/glfw/examples/CMakeFiles/splitview.dir/build
.PHONY : splitview/fast

#=============================================================================
# Target rules for targets named windows

# Build rule for target.
windows: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 windows
.PHONY : windows

# fast build rule for target.
windows/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/windows.dir/build.make lib/glfw/tests/CMakeFiles/windows.dir/build
.PHONY : windows/fast

#=============================================================================
# Target rules for targets named sharing

# Build rule for target.
sharing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sharing
.PHONY : sharing

# fast build rule for target.
sharing/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/sharing.dir/build.make lib/glfw/tests/CMakeFiles/sharing.dir/build
.PHONY : sharing/fast

#=============================================================================
# Target rules for targets named title

# Build rule for target.
title: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 title
.PHONY : title

# fast build rule for target.
title/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/title.dir/build.make lib/glfw/tests/CMakeFiles/title.dir/build
.PHONY : title/fast

#=============================================================================
# Target rules for targets named threads

# Build rule for target.
threads: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 threads
.PHONY : threads

# fast build rule for target.
threads/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/threads.dir/build.make lib/glfw/tests/CMakeFiles/threads.dir/build
.PHONY : threads/fast

#=============================================================================
# Target rules for targets named empty

# Build rule for target.
empty: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 empty
.PHONY : empty

# fast build rule for target.
empty/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/empty.dir/build.make lib/glfw/tests/CMakeFiles/empty.dir/build
.PHONY : empty/fast

#=============================================================================
# Target rules for targets named msaa

# Build rule for target.
msaa: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 msaa
.PHONY : msaa

# fast build rule for target.
msaa/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/msaa.dir/build.make lib/glfw/tests/CMakeFiles/msaa.dir/build
.PHONY : msaa/fast

#=============================================================================
# Target rules for targets named tearing

# Build rule for target.
tearing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tearing
.PHONY : tearing

# fast build rule for target.
tearing/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/tearing.dir/build.make lib/glfw/tests/CMakeFiles/tearing.dir/build
.PHONY : tearing/fast

#=============================================================================
# Target rules for targets named events

# Build rule for target.
events: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 events
.PHONY : events

# fast build rule for target.
events/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/events.dir/build.make lib/glfw/tests/CMakeFiles/events.dir/build
.PHONY : events/fast

#=============================================================================
# Target rules for targets named gamma

# Build rule for target.
gamma: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gamma
.PHONY : gamma

# fast build rule for target.
gamma/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/gamma.dir/build.make lib/glfw/tests/CMakeFiles/gamma.dir/build
.PHONY : gamma/fast

#=============================================================================
# Target rules for targets named glfwinfo

# Build rule for target.
glfwinfo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfwinfo
.PHONY : glfwinfo

# fast build rule for target.
glfwinfo/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/glfwinfo.dir/build.make lib/glfw/tests/CMakeFiles/glfwinfo.dir/build
.PHONY : glfwinfo/fast

#=============================================================================
# Target rules for targets named iconify

# Build rule for target.
iconify: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 iconify
.PHONY : iconify

# fast build rule for target.
iconify/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/iconify.dir/build.make lib/glfw/tests/CMakeFiles/iconify.dir/build
.PHONY : iconify/fast

#=============================================================================
# Target rules for targets named monitors

# Build rule for target.
monitors: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 monitors
.PHONY : monitors

# fast build rule for target.
monitors/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/monitors.dir/build.make lib/glfw/tests/CMakeFiles/monitors.dir/build
.PHONY : monitors/fast

#=============================================================================
# Target rules for targets named cursor

# Build rule for target.
cursor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cursor
.PHONY : cursor

# fast build rule for target.
cursor/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/cursor.dir/build.make lib/glfw/tests/CMakeFiles/cursor.dir/build
.PHONY : cursor/fast

#=============================================================================
# Target rules for targets named joysticks

# Build rule for target.
joysticks: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 joysticks
.PHONY : joysticks

# fast build rule for target.
joysticks/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/joysticks.dir/build.make lib/glfw/tests/CMakeFiles/joysticks.dir/build
.PHONY : joysticks/fast

#=============================================================================
# Target rules for targets named clipboard

# Build rule for target.
clipboard: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 clipboard
.PHONY : clipboard

# fast build rule for target.
clipboard/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/clipboard.dir/build.make lib/glfw/tests/CMakeFiles/clipboard.dir/build
.PHONY : clipboard/fast

#=============================================================================
# Target rules for targets named reopen

# Build rule for target.
reopen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 reopen
.PHONY : reopen

# fast build rule for target.
reopen/fast:
	$(MAKE) -f lib/glfw/tests/CMakeFiles/reopen.dir/build.make lib/glfw/tests/CMakeFiles/reopen.dir/build
.PHONY : reopen/fast

#=============================================================================
# Target rules for targets named docs

# Build rule for target.
docs: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 docs
.PHONY : docs

# fast build rule for target.
docs/fast:
	$(MAKE) -f lib/glfw/docs/CMakeFiles/docs.dir/build.make lib/glfw/docs/CMakeFiles/docs.dir/build
.PHONY : docs/fast

#=============================================================================
# Target rules for targets named glew

# Build rule for target.
glew: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glew
.PHONY : glew

# fast build rule for target.
glew/fast:
	$(MAKE) -f lib/glew/CMakeFiles/glew.dir/build.make lib/glew/CMakeFiles/glew.dir/build
.PHONY : glew/fast

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
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... Mesh.bin"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... uninstall"
	@echo "... glfw"
	@echo "... heightmap"
	@echo "... gears"
	@echo "... particles"
	@echo "... wave"
	@echo "... boing"
	@echo "... simple"
	@echo "... splitview"
	@echo "... windows"
	@echo "... sharing"
	@echo "... title"
	@echo "... threads"
	@echo "... empty"
	@echo "... msaa"
	@echo "... tearing"
	@echo "... events"
	@echo "... gamma"
	@echo "... glfwinfo"
	@echo "... iconify"
	@echo "... monitors"
	@echo "... cursor"
	@echo "... joysticks"
	@echo "... clipboard"
	@echo "... reopen"
	@echo "... docs"
	@echo "... glew"
	@echo "... nfd"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
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
