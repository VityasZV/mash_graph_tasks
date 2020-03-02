cmake_minimum_required(VERSION 3.10)
project(res)

# get rid of annoying MSVC warnings.
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(CMAKE_CXX_STANDARD 14)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        GL
        GLEW
        glfw
)

find_package(OpenGL REQUIRED)
add_subdirectory(libs/glfw)

add_executable(res src/main.cpp)

target_link_libraries(res ${ALL_LIBS})
