cmake_minimum_required(VERSION 2.6)

project (nfd)

find_package(GTK REQUIRED)


add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)


include_directories(
  ${GTK_INCLUDE_DIR}
  /usr/include/gtk-3.0/
  /usr/include/glib-2.0/
  /usr/lib/glib-2.0/include/
  /usr/include/pango-1.0/
  /usr/include/cairo/
  /usr/include/gdk-pixbuf-2.0/
  /usr/include/atk-1.0/
  )


set(
  NFD_SOURCE
  src/nfd_gtk.c
  src/nfd_common.c
  )


add_library(nfd STATIC
	${NFD_SOURCE}
#	${GLEW_INCLUDE}
  )
