#version 330

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoord;

uniform mat4 uTransformationMatrix;

void main(){
	gl_Position = uTransformationMatrix * vec4(pos.xy, 0.0, 1.0);
}