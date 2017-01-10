cmake_minimum_required(VERSION 2.6)

project (glew)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)


include_directories()


FILE(
  GLOB_RECURSE
  GLEW_SOURCE
  src/*.c
  )


add_library(glew STATIC
	${GLEW_SOURCE}
  )
