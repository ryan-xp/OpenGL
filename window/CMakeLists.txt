cmake_minimum_required(VERSION 3.0)

project(window)
set(CMAKE_CXX_STANDARD 11)

# 设置头文件目录
include_directories(
    /home/json/zxp/OpenGL/OpenGL/window/include/
    /home/json/zxp/vendor/glew/include/GL/
    /home/json/zxp/vendor/glfw/include/GLFW/
)

# 设置库文件目录
link_directories(
    /home/json/zxp/vendor/glew/lib64/
    /home/json/zxp/vendor/glfw/lib/
)

# 共享的源代码文件
set(SHARED_SRC
    ./src/GlslDealConfig.cpp
)

# 设置需要链接的库
set(LINK_LIBRARIES
    glfw3
    GLEW
    GL
    X11
    pthread
    Xrandr
    Xi
    dl
)

# 定义一个生成可执行文件的函数
function(add_exec target src)
    add_executable(${target} ${src} ${SHARED_SRC})
    target_link_libraries(${target} PRIVATE ${LINK_LIBRARIES})
endfunction()

# 调用函数生成不同的可执行文件
add_exec(rectanger_main ./main/rectanger_main.cpp)
add_exec(window_main ./main/window_main.cpp)
add_exec(trianger_main ./main/triangle_main.cpp)


# 安装可执行文件到指定目录
# install(TARGETS rectanger_main window_main trianger_main
#         RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
#         LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
#         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX})