#version 330 core		// 3.30版本 
layout(location = 0) in vec3 position;			// 位置变量的顶点属性位置值为 0
layout(location = 1) in vec3 color;				// 颜色变量的顶点属性位置值为 1
layout(location = 2) in vec2 textureCoords;		// 纹理坐标只有两个浮点数 (s,t), 属性位置值为 2 
out vec3 ourColor;								
out vec2 ourTextureCoords;						// 将纹理坐标传到片元着色器
void main()
{
	gl_Position = vec4(position, 1.0f);			// 核心函数(位置信息赋值)
	// ourColor = color;
	ourTextureCoords = vec2(textureCoords.x, 1-textureCoords.y);
}