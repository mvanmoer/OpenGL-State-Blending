#version 420

in vec4 vColor;
in vec2 fTexCoord;

out vec4 fColor;


void main() {

    vec2 tmp = fTexCoord - vec2(0.5);
    float f = dot(tmp, tmp);
    if (f > 0.25)
        discard;
    else
        fColor = vColor;
}
