project(TomsAdventure)
cmake_minimum_required(VERSION 2.8)
# The version number.

aux_source_directory(code DIR_SRCS)


aux_source_directory(code/include DIR_SRCS_INCLUDE)

add_definitions(-std=c++11)


# add the executable
add_executable(TomsAdventure ${DIR_SRCS} ${DIR_SRCS_INCLUDE})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "-g -Wall")

target_link_libraries(TomsAdventure ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

