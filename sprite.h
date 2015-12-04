#ifndef SPRITE_H
#define SPRITE_H

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QMatrix4x4>

class Sprite
{
private:
    float color[4];
    QOpenGLVertexArrayObject VAO;
    QOpenGLBuffer VBO;
    QOpenGLBuffer TBO;
    QOpenGLShaderProgram *shaderProgram;
    GLuint colorloc;
    QMatrix4x4 model;
    GLuint pvmloc;
public:
    Sprite(float*, const char*, const char*);
    ~Sprite();
    QOpenGLShaderProgram* getShaderProgram() const { return shaderProgram; }
    void Display(float *, const QMatrix4x4&);
    void Display(float, float, float, float, const QMatrix4x4&);
    QMatrix4x4* getModelMtx() { return &model; }
};

#endif // SPRITE_H
