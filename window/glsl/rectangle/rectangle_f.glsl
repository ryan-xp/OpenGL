#version 330 core 		// 3.30版本
out vec4 FragColor;     // 输出是四个浮点数构成的一个向量 RGB+aerfa
uniform vec4 time;		// 在OpenGL程序代码中设定这个变量(uniform：实时地变量表示)
void main()
{
	FragColor = time;	// 颜色随时间变化
}
