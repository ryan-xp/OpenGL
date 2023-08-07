#include <iostream>

#include "glew.h"
#include "glfw3.h"
#include "log.h"
#include "GlslDealConfig.h"

/* 编写各顶点位置与颜色 */
GLfloat vertices_1[] = 
{	// position				// color
	0.0f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		// 上顶点(红色)
	-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		// 左顶点(绿色)
	0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f		// 右顶点(蓝色)
};

/* 四个顶点的连接信息给出来 */
GLuint indices_1[] =
{
	0, 1, 3,		// 序号为 0、1、3 的顶点组合成一个三角形
	1, 2, 3			// 序号为 1、2、3 的顶点组合成一个三角形
};

void GLFWerrorFunc(int error_code, const char *description)
{
    LOGE("GLFW error: %d", error_code);
    LOGE("GLFW description: %s", description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

    glViewport(0, 0, width, height);
}

int main()
{
    GlslDealConfig mdel;
    std::string version = glfwGetVersionString();
    LOGI("Version: %s", version.c_str());

    glfwSetErrorCallback(GLFWerrorFunc);

    if (glfwInit() != GLFW_TRUE)
    {
        LOGE("GLFW initialization failed");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600,600,"Draw OpenGL",NULL,NULL);
    
    if(window == NULL)
    {
        LOGE("Failed to create window");
        return 0;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        LOGE("glew init failed %s", glewGetErrorString(err));
        return 0;
    }
    glfwSwapInterval(1);


    std::string VertextShaderString;
    mdel.ReadGlslFile("/home/json/zxp/OpenGL/window/glsl/VertexShader.glsl", VertextShaderString);
    const char * vertextShader = VertextShaderString.c_str();

    std::string FragmentShaderString;
    mdel.ReadGlslFile("/home/json/zxp/OpenGL/window/glsl/FragmentShader.glsl", FragmentShaderString);
    const char * fragmentShader = FragmentShaderString.c_str();

    GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
    GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(v_shader,1,&vertextShader,NULL);
    glShaderSource(f_shader,1,&fragmentShader,NULL);

    glCompileShader(v_shader);
    glCompileShader(f_shader);

    GLuint program = glCreateProgram();

    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);

    glLinkProgram(program);

    glDeleteShader(v_shader);
    glDeleteShader(f_shader);

    GLuint VAO,VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1,&VBO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices_1),vertices_1,GL_STATIC_DRAW);

    glBindVertexArray(VAO);

/*

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)0)：这一行代码配置顶点属性指针。
        具体参数解释如下：

        0：表示要配置的顶点属性的索引，对应顶点着色器中的layout(location = 0)。
        3：表示顶点属性的分量数量，即每个顶点的位置属性由3个分量组成（x、y、z坐标）。
        GL_FLOAT：表示顶点属性的数据类型为单精度浮点数。
        GL_FALSE：表示是否对数据进行归一化，对位置属性而言不需要归一化。
        6*sizeof(GLfloat)：指定连续顶点属性之间的偏移量，这里表示每个顶点数据之间的大小为6个GLfloat。
        (GLvoid*)0：表示从缓冲的开头位置开始读取数据。
        glEnableVertexAttribArray(0)：启用顶点属性索引为0的顶点属性数组

*/

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

/*

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)))：
        这一行代码配置第二个顶点属性指针。具体参数解释如下：

        1：表示要配置的顶点属性的索引，对应顶点着色器中的layout(location = 1)。
        3：表示顶点属性的分量数量，即每个顶点的颜色属性由3个分量组成（R、G、B颜色分量）。
        GL_FLOAT：表示顶点属性的数据类型为单精度浮点数。
        GL_FALSE：表示是否对数据进行归一化，对颜色属性而言不需要归一化。
        6*sizeof(GLfloat)：指定连续顶点属性之间的偏移量，这里表示每个顶点数据之间的大小为6个GLfloat。
        (GLvoid*)(3*sizeof(GLfloat))：表示从缓冲的一半位置（偏移3个GLfloat）开始读取数据。
        glEnableVertexAttribArray(1)：启用顶点属性索引为1的顶点属性数组。

*/
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);	// 通道 1 打开


    while(!glfwWindowShouldClose(window))
    {
        //glViewport(0,0,300,300);
        glClearColor(0.0f,0.5f,0.5f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
