#version 420

in vec4 vColor;
out vec4 fColor;

void main() {
    vec2 tmp = gl_PointCoord - vec2(0.5);
    float f = dot(tmp, tmp);
    if (f > 0.25)
        discard;
    fColor = vColor;
}
