#include <iostream>
#include <cmath>
#include "glew.h"
#include "glfw3.h"
#include "log.h"
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
    mdel.ReadGlslFile("/home/json/zxp/OpenGL/OpenGL/window/glsl/rectangle/rectangle_v.glsl", VertextShaderString);
    const char * vertextShader = VertextShaderString.c_str();

    std::string FragmentShaderString;
    mdel.ReadGlslFile("/home/json/zxp/OpenGL/OpenGL/window/glsl/rectangle/rectangle_f.glsl", FragmentShaderString);
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


    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

/* 设置索引缓冲对象	*/
	GLuint EBO;
	glGenBuffers(1, &EBO);		
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_1), indices_1, GL_STATIC_DRAW); 


    while(!glfwWindowShouldClose(window))
    {
        //glViewport(0,0,300,300);
        glClearColor(0.0f,0.5f,0.5f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        /*  绘制图形 */
		float time = glfwGetTime();						// 获取时间
		float redValue = sin(time) / 2.0f + 0.5f;		// 红色数值计算，范围[0,1]
		float greenValue = 1 - redValue;				// 绿色数值计算，范围[0.1]。且满足 “redValue + greenValue = 1”
		int vertexColorLocation = glGetUniformLocation(program, "time");
		glUniform4f(vertexColorLocation, redValue, greenValue, 0.0f, 1.0f );

		glBindVertexArray(VAO);									// 绑定 VAO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);				// 绑定 EBO
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);	// 画两个三角形 从第0个顶点开始 一共画6次
		glBindVertexArray(0);									// 解绑定 VAO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);				// 解绑定 EBO


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
