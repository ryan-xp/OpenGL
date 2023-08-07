#version 330 core		// 3.30版本
in vec3 ourColor;		// 输入(3维)颜色向量
out vec4 FragColor;     // 输出到四个浮点数构成的一个(4维)向量 FragColor
void main()
{
	FragColor = vec4(ourColor, 1.0f);	// 核心函数(颜色信息赋值)
}
