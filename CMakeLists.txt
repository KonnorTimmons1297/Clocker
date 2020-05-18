cmake_minimum_required ( VERSION 3.17 )
project( Clocker )

# Find the GLFW binaries
#find_package( PkgConfig REQUIRED )
#pkg_search_module( GLFW REQUIRED glfw3 )
 
# Bring the headers, such as glad.h and shaderutils.h into the project
include_directories( include )
#include_directories( ${GLFW_INCLUDE_DIRS} )
 
#Can manually add the sources using the set command
#set( DEFAULT_DEPS src/glad.c src/shaderutils.c )
set( CLOCKER_SOURCES src/clocker.cpp )
#set( TWO_TRIANGLE_SOURCES ${DEFAULT_DEPS} src/two_triangles.c )
#set( COLORFUL_SOURCES ${DEFAULT_DEPS} src/colorful_triangle.c )
#set( SLIDING_SOURCES ${DEFAULT_DEPS} src/sliding_triangle.c )

# Setting up the executables
add_executable( clocker ${CLOCKER_SOURCES} )
#target_link_libraries( plain ${GLFW_STATIC_LIBRARIES} )
 
#add_executable( two ${TWO_TRIANGLE_SOURCES} )
#target_link_libraries( two ${GLFW_STATIC_LIBRARIES} )

#add_executable( colorful ${COLORFUL_SOURCES} )
#target_link_libraries( colorful ${GLFW_STATIC_LIBRARIES} )

#add_executable( sliding ${SLIDING_SOURCES} )
#target_link_libraries( sliding ${GLFW_STATIC_LIBRARIES} )
