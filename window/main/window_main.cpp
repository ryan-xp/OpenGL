#include <iostream>
#include "glew.h"
#include "glfw3.h"


/*

glfwinit失败   export DISPLAY=:0
glewinit失败   检查glfwWindowHint版本号设置


*/


void init(GLFWwindow* window)
{

}

void display(GLFWwindow* window,double deltaTime)
{
    glClearColor(0.5f,0.5f,0.0f,0.5f);
    glClear(GL_COLOR_BUFFER_BIT);
}



void GetGlfwRunError(int error_code, const char* description)
{
    std::cout<<"error_code: "<<error_code<<std::endl;
    std::cout<<"description: "<<description<<std::endl;
}

int main()
{
    int major = 0, minor = 0, rev = 0;
    glfwGetVersion(&major, &minor, &rev);
    std::cout << "major: " << major << " minor : " << minor << " rev " << rev << std::endl;

    //捕获glfw错误的回调函数
    glfwSetErrorCallback(GetGlfwRunError);

    if(glfwInit() == GLFW_FALSE)
    {
        std::cout << " GLFW initialization failed" << std::endl;

    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* windows = glfwCreateWindow(800,800,"Hello OpenGL",NULL,NULL);
    if(windows == NULL)
    {
        std::cout << "create window failed" << std::endl;
        return 0;
    }
    //绑定上下文
    glfwMakeContextCurrent(windows);

    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout<<"glfwInit() failed "<< glewGetErrorString(err) << std::endl;
    }
/*
    glfwSwapInterval是GLFW库中的一个函数，用于设置交换缓冲区的间隔，也就是设置垂直同步（Vertical Sync，通常简称为Vsync）。

    在OpenGL中，绘制的图像通常会首先渲染到一个后缓冲区（back buffer），然后通过交换缓冲区（swap buffer）的方式将后缓冲区的内容显示到屏幕上。交换缓冲区的过程是由操作系统或GPU控制的。如果不设置垂直同步，可能会导致屏幕撕裂（tearing）现象，即画面中出现不同部分的帧同时显示在屏幕上的现象。

    glfwSwapInterval函数用于设置交换缓冲区的间隔，控制渲染时机。它接受一个整数参数，表示帧间隔的数量，通常设置为0或1：

    0：表示禁用垂直同步，渲染帧将立即交换到前缓冲区，可能会导致屏幕撕裂。
    1：表示启用垂直同步，渲染帧将等待垂直同步信号，直到下一次屏幕刷新时再交换到前缓冲区，避免屏幕撕裂。
    在一些情况下，可能会使用更高的交换间隔，例如2或更高，以限制帧率。这可能对于节能或性能测试有用，但可能会导致输入延迟。
*/
    glfwSwapInterval(1);

    init(windows);

    while(!glfwWindowShouldClose(windows))
    {
        if(glfwGetKey(windows, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(windows, true);
        display(windows,glfwGetTime());
/*
        在OpenGL中，绘制的图像通常会首先渲染到一个后缓冲区（back buffer）。
        渲染完成后，调用glfwSwapBuffers函数会将后缓冲区的内容交换到前缓冲区（front buffer），
        从而在屏幕上显示绘制的图像。这样可以避免在渲染过程中产生闪烁或可见的图像渲染过程。
*/
        glfwSwapBuffers(windows);

        //处理窗口事件
        glfwPollEvents();
    }

    glfwDestroyWindow(windows);
    glfwTerminate();
    return 0;


    return 0;
}