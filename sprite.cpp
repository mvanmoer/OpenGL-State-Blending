#include "sprite.h"

Sprite::Sprite(float *coords, const char* vshader, const char* fshader)
{
    shaderProgram = new QOpenGLShaderProgram;
    shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vshader);
    shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fshader);
    // if need to bind vertex coord position, do that here
    if (!shaderProgram->link())
        qDebug() << "failed to link shader program\n";
    shaderProgram->bind();
    // grab the uniform locations here
    colorloc = shaderProgram->uniformLocation("inColor");
    pvmloc = shaderProgram->uniformLocation("PVM");

    model.setToIdentity();


    VAO.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&VAO);

    VBO.create();
    VBO.bind();
    //VBO.allocate(coords, sizeof(coords));
    VBO.allocate(coords, sizeof(float) * 12 );

    // setupVertexAttribs() from the examples
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    VBO.release();


    float tcoords[] = {0.0f, 0.0f,
                       0.0f, 1.0f,
                       1.0f, 1.0f,
                       1.0f, 0.0f};
    TBO.create();
    TBO.bind();
    TBO.allocate(tcoords, sizeof(float) * 8);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    TBO.release();

    shaderProgram->release();

}

Sprite::~Sprite() {
    VBO.destroy();
    delete shaderProgram;
    shaderProgram = 0;
    VAO.destroy();
}

void Sprite::Display(float *color, const QMatrix4x4& pv) {
    QOpenGLVertexArrayObject::Binder vaoBinder(&VAO);
    shaderProgram->bind();
    // set uniforms here
    shaderProgram->setUniformValueArray(colorloc, color, 1, 4);
    shaderProgram->setUniformValue(pvmloc, pv * model);
    //glPointSize(4);
    //glDrawArrays(GL_POINTS, 0, 1);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    shaderProgram->release();
}

void Sprite::Display(float r, float g, float b, float a, const QMatrix4x4& pv)
{
    float premultiplied[4];
    premultiplied[0] = r;
    premultiplied[1] = g;
    premultiplied[2] = b;
    premultiplied[3] = a;
    this->Display(premultiplied, pv);
}
