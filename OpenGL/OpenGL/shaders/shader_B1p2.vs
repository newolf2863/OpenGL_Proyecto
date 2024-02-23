#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor;
uniform float time;

void main()
{
    gl_Position = vec4(aPos, 1.0);
	vertexColor = aColor + vec3(sin(time), cos(time), 0.5f);
}
