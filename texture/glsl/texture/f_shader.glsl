#version 330 core				// 3.30版本
in vec3 ourColor;
in vec2 ourTextureCoords;		// 将纹理坐标引入(从顶点着色器过来的)
out vec4 FragColor;				// 输出是四个浮点数构成的一个向量 RGB+aerfa
uniform sampler2D ourTexture;	// 纹理对象引入(从主函数过来的)
void main()
{
	// FragColor = vec4(ourColor, 1.0f);
	FragColor = texture(ourTexture, ourTextureCoords);	// 采样获得纹理坐标
}