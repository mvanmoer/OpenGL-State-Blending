#version 420

in vec4 vPos;

uniform vec4 inColor;
uniform mat4 PVM;

out vec4 vColor;

void main() {
    gl_PointSize = 256.0;
    gl_Position = PVM * vPos;
    vColor = inColor;
}
