#version 330 core							// 3.30版本
layout(location = 0) in vec3 position;		// 位置变量的属性位置值为0
void main()
{
	gl_Position = vec4(position, 1.0f);		// 核心函数(位置信息赋值)
} 
