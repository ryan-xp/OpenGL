#include <iostream>
#include <string>

#include "glew.h"
#include "glfw3.h"

#include "log.h"
#include "GlslDealConfig.h"


GLfloat vertices_1[] = 
{
	0.0f, 0.5f, 0.0f,		// 上顶点
	-0.5f, -0.5f, 0.0f,		// 左顶点
	0.5f, -0.5f, 0.0f,		// 右顶点
	
};

void glfwErrorCallBack(int error_code, const char* description)
{
    LOGE("error_code: %d , description: %s", error_code,description);
}

int main()
{
    GlslDealConfig mdeal;
    int major = 0, minor = 0, rev = 0;
    glfwGetVersion(&major, &minor, &rev);
    LOGI("glfw version %d - %d - %d", major,minor,rev);

    glfwSetErrorCallback(glfwErrorCallBack);

    if(glfwInit() == GLFW_FALSE)
    {
        LOGE("glfwInit failed");
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(700,700,"Hello OpenGL",NULL,NULL);
    if(window == NULL)
    {
        LOGE("glfwCreateWindow failed");
        return 0;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        LOGE("glew init failed : %s",  reinterpret_cast<const char*>(glewGetErrorString(err)));
        return 0;
    }

    glfwSwapInterval(1);

    std::string FragmentShaderString;
    mdeal.ReadGlslFile("/home/json/zxp/OpenGL/window/glsl/FragmentShader.glsl", FragmentShaderString);
    const char * fragmentShader = FragmentShaderString.c_str();

    //顶点着色器
    GLuint fsshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fsshader,1,&fragmentShader,NULL);
    glCompileShader(fsshader);

    std::string VertextShaderString;
    mdeal.ReadGlslFile("/home/json/zxp/OpenGL/window/glsl/VertexShader.glsl", VertextShaderString);
    const char * vertextShader = VertextShaderString.c_str();

    //片段着色器
    GLuint vsshader =  glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vsshader,1,&vertextShader,NULL);
    glCompileShader(vsshader);

    //创建程序对象
    GLuint pragram = glCreateProgram();

/*

    首先，你会创建顶点着色器对象和片段着色器对象，并把着色器代码加载到它们中。
    然后，使用glAttachShader函数将这些着色器对象附加到一个着色器程序对象上。
    这个过程就像是把小碎片粘贴在一个空白的画布上，准备好开始拼图。

    接下来，你调用glLinkProgram函数，这个函数会将所有附加的着色器对象链接在一起，形成一个可执行的着色器程序。
    这就像把所有的小碎片拼接在一起，形成了一个完整的图案。
    在链接的过程中，OpenGL会执行一些额外的操作，确保着色器之间的交互正确，并生成可以供OpenGL渲染使用的最终程序。

    链接成功后，你就拼好了整个图画，也就是一个完整的着色器程序。之后，你可以使用这个着色器程序来执行图形渲染操作，展示你想要的效果。
*/


    //将着色器附魔到程序对象
    glAttachShader(pragram,fsshader);
    glAttachShader(pragram,vsshader);

    //链接程序对象
    glLinkProgram(pragram);
    
    //删除着色器对象
    glDeleteShader(fsshader);
    glDeleteShader(vsshader);

/*

    顶点数组对象：Vertex Array Object，VAO
    顶点缓冲对象：Vertex Buffer Object，VBO
    元素缓冲对象：Element Buffer Object，EBO 或 索引缓冲对象 Index Buffer Object，IBO

---------------------------------------------------------------------------------

    当我们使用OpenGL绘制图形时，需要将顶点的位置、颜色等信息传递给显卡，让显卡进行绘制。
    VBO（Vertex Buffer Object）是用来存储这些顶点数据的特殊缓冲区，可以将数据保存在显卡中，避免频繁地从CPU传输数据到显卡，提高绘制效率。

    而VAO（Vertex Array Object）则是用来管理这些顶点数据的设置的。
    绘制一个图形通常需要多个顶点属性（比如位置、颜色等），VAO帮助我们预先指定这些属性在VBO中的排列方式，
    避免在每次绘制时重新设置属性，简化绘制代码。

    EBO（Element Buffer Object）是用来存储图元的索引数据的缓冲区，比如三角形的三个顶点索引。
    它可以帮助我们避免重复存储顶点数据，只需存储少量的索引数据就可以描述复杂的图形，提高绘制效率。

    综合来说，VBO、VAO和EBO是帮助我们优化OpenGL绘制图形的工具。

    VBO将顶点数据存储在显卡中，
    VAO管理这些数据的属性设置，
    EBO帮助我们高效描述复杂图形的顶点索引。

    它们的组合可以让我们更高效地绘制图形，让图形的渲染速度更快，性能更好。
*/

    //生成用于管理 顶点数据的---顶点数组对象
    GLuint VAO,VBO;
    glGenVertexArrays(1,&VAO);

    //生成存储这些顶点数据的特殊缓冲区 --顶点缓冲对象
    glGenBuffers(1,&VBO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);  //用于绑定缓冲区对象的函数。它的作用是将一个缓冲区对象绑定到指定的缓冲区目标上
                                        //以便在后续的OpenGL渲染调用中使用。
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
                                        //在指定的缓冲区对象中分配一块内存，并将初始数据写入该内存

	/* 第六步：设置链接顶点属性 */

    //绑定到顶点数组
    glBindVertexArray(VAO);	

    //中用于定义顶点属性的函数。它告诉OpenGL如何解释顶点数据，并将顶点数据与顶点着色器中的顶点属性关联起来。
    //  index: 指定要配置的顶点属性的索引，与顶点着色器中的in关键字声明的变量位置相对应。
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);

    //中用于启用顶点属性的函数。它告诉OpenGL在顶点着色器中启用指定索引的顶点属性。
    //启用顶点属性后，OpenGL将根据设置的顶点属性索引自动获取顶点数据，并传递给顶点着色器。

    //  index：指定要启用的顶点属性的索引。这个索引对应于顶点着色器中in关键字声明的变量位置。
	glEnableVertexAttribArray(0);


	// draw loop 画图循环
	while (!glfwWindowShouldClose(window))
	{
		glViewport(0, 0, 500, 500);  //用于设置OpenGL的视口，即指定渲染结果在屏幕上显示的区域。通过设置视口，可以控制OpenGL渲染的输出在屏幕上的位置和大小。
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		/*  第九步：绘制三角形 */
		glUseProgram(pragram);		// 渲染调用着色器程序
		glBindVertexArray(VAO);				// 绑定 VAO
		glDrawArrays(GL_TRIANGLES, 0, 3);	// 画三角形  从第0个顶点开始 一共画3次
		glBindVertexArray(0);				// 解绑定

		glfwSwapBuffers(window);
        glfwPollEvents();
	}
    // glBindVertexArray(0);	
	glDeleteVertexArrays(1, &VAO);		
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(pragram);

	glfwTerminate();
	return 0;


    return 0;
}