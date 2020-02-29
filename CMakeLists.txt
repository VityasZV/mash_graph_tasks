cmake_minimum_required (VERSION 3.8)
project (rt)

# find_package(OpenGL REQUIRED) -doesnt work

include_directories(
    libs/glfw/include/
    .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
)

# get rid of annoying MSVC warnings.
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set (CMAKE_CXX_STANDARD 17)

add_executable(rt src/main.cpp src/Bitmap/Bitmap.cpp)


target_link_libraries(rt ${ALL_LIBS} )

