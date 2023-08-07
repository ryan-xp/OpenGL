cmake_minimum_required(VERSION 3.0)

project(window)
set(CMAKE_CXX_STANDARD 11)
include_directories(
    /home/json/zxp/OpenGL/window/include/
    /home/json/zxp/vendor/glew/include/GL/
    /home/json/zxp/vendor/glfw/include/GLFW/
)

link_directories(
    /home/json/zxp/vendor/glew/lib64/
    /home/json/zxp/vendor/glfw/lib/
)

set(GLOB_SRC

    ./main/zmain.cpp
    ./src/GlslDealConfig.cpp

)

add_executable(window ${GLOB_SRC})

target_link_libraries(window PRIVATE
    glfw3
    GLEW
    GL
    X11
    pthread
    Xrandr
    Xi
    dl
)
