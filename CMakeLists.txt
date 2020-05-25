cmake_minimum_required ( VERSION 3.13 )

set (CMAKE_CXX_STANDARD 17)

project( Clocker )

include_directories( include )

file(GLOB SOURCES "src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable( clocker ${SOURCES} )
target_compile_options(clocker PRIVATE -Wall -Wextra -pedantic)
