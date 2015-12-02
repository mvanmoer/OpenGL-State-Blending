#version 420

in vec4 vPos;
in vec2 vTexCoord;

uniform vec4 inColor;
uniform mat4 PVM;

out vec4 vColor;
out vec2 fTexCoord;

void main() {
    gl_Position = PVM * vPos;
    vColor = inColor;
    fTexCoord = vTexCoord;
}
