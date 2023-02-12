project(fractal)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory("math")
add_subdirectory("fractal")
add_subdirectory("graphics")

add_executable(visfractal
    "main.cc"
    "mandelbrot_set.cc"
)

target_link_libraries(visfractal
    math
    fractal
    graphics

    sfml-window
    sfml-system
    sfml-graphics
)