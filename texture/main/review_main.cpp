#include <iostream>
#include <string>
#include <cmath>
#include "glew.h"
#include "glfw3.h"
#include "GlslDealConfig.h"

/* 编写各顶点位置 */
GLfloat vertices_1[] =
{
	//position					
	0.5f, 0.5f, 0.0f,			// top right		0
	0.5f, -0.5f, 0.0f,			// bottom right		1
	-0.5f, -0.5f, 0.0f,			// bottom left		2
	-0.5f, 0.5f, 0.0f,			// top left			3
};

/* 四个顶点的连接信息给出来 */
GLuint indices_1[] =
{
	0, 1, 3,		// 序号为 0、1、3 的顶点组合成一个三角形
	1, 2, 3			// 序号为 1、2、3 的顶点组合成一个三角形
};


void GlfwErrorFunc(int error_code, const char* description)
{
    LOGE("GLFW error: %d", error_code);
    LOGE("description: %s", description);
}

void ViewCallBack(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{

    GlslDealConfig Config;

    std::string val = glfwGetVersionString();
    LOGI("GLFW version : %s", val.c_str());

    glfwSetErrorCallback(GlfwErrorFunc);

    if(glfwInit() != GLFW_TRUE)
    {
        LOGE("GLFW initialization failed");
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* windw = glfwCreateWindow(800,800,"rectangle",NULL,NULL);
    if(windw == NULL)
    {
        LOGE("GLFW window create failed");
        return 0;
    }

    glfwMakeContextCurrent(windw);
    glfwSetFramebufferSizeCallback(windw,ViewCallBack);

    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        LOGE("GLEW initialization failed : %s", glewGetErrorString(err));
        return 0;
    }
    glfwSwapInterval(1);

    std::string f_str,v_str;
    Config.ReadGlslFile("/home/json/zxp/OpenGL/OpenGL/texture/glsl/VertexShader.glsl", v_str);
    Config.ReadGlslFile("/home/json/zxp/OpenGL/OpenGL/texture/glsl/FragmentShader.glsl",f_str);

    const char * f_glsl = f_str.c_str();
    const char * v_glsl = v_str.c_str();

    GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
    GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(v_shader,1,&v_glsl,NULL);
    glShaderSource(f_shader,1,&f_glsl,NULL);

    glCompileShader(v_shader);
    glCompileShader(f_shader);

    GLuint prom = glCreateProgram();
    glAttachShader(prom, v_shader);
    glAttachShader(prom, f_shader);
    glLinkProgram(prom);

    glDeleteShader(v_shader);
    glDeleteShader(f_shader);

    GLuint VAO,VBO,EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices_1),vertices_1,GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT,GL_TRUE,3*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    //EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices_1),indices_1,GL_STATIC_DRAW);

    while(!glfwWindowShouldClose(windw))
    {
        
        glClearColor(0.5f,0.0f,0.1f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(prom);

        /*  绘制图形 */
		float time = glfwGetTime();						// 获取时间
		float redValue = sin(time) / 2.0f + 0.5f;		// 红色数值计算，范围[0,1]
		float greenValue = 1 - redValue;				// 绿色数值计算，范围[0.1]。且满足 “redValue + greenValue = 1”
		int vertexColorLocation = glGetUniformLocation(prom, "time");
		glUniform4f(vertexColorLocation, redValue, greenValue, 0.0f, 1.0f );

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);	// 画两个三角形 从第0个顶点开始 一共画6次
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

        glfwSwapBuffers(windw);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(prom);
    glfwTerminate();
    return 0;
}
