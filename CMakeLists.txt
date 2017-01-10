cmake_minimum_required (VERSION 2.6)

project (MeshViewer)
add_subdirectory (lib)

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})
else()
    message(ERROR " OPENGL not found!")
endif()

find_package(GLUT REQUIRED)
if(GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS})
else()
    message(ERROR " GLUT not found!")
endif()

FIND_PACKAGE(GLEW REQUIRED)
if(GLEW_FOUND)
    include_directories( ${GLEW_INCLUDE_PATH})
else()
    message("GLEW not found!")
  endif()

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
#FIND_PACKAGE(GTK2 REQUIRED )
if(GTK3_FOUND)
    include_directories( ${GTK3_INCLUDE_PATH})
else()
    message("GTK not found!")
endif()

set (CMAKE_CXX_STANDARD 11)

FILE(
  GLOB_RECURSE
  src_mesh
  src/*
  )

set(ALL_LIBS
  ${OPENGL_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARY}
  ${GLUT_LIBRARY}
  ${GTK3_LIBRARIES}
  # gtk-3
  # gdk-3
  # pangocairo-1.0
  # pango-1.0
  # atk-1.0
  # cairo-gobject
  # cairo
  # gdk_pixbuf-2.0
  # gio-2.0
  # gobject-2.0
  # glib-2.0
  nfd
)

include_directories(
  ${GTK_INCLUDE_DIR}
  lib/glm/
  lib/nfd/include/
  lib/tchar/
  .
)



add_executable(Mesh.bin ${src_mesh})

target_link_libraries(Mesh.bin 
	${ALL_LIBS}
)
