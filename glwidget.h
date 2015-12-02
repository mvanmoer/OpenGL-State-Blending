// Don't forget to promote the widget in the designer to be of
// this class!
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QMatrix4x4>
#include <QColor>
#include "sprite.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

public slots:
    void setEnableBlending(bool);
    void setEnableDepthTest(bool);
    void setSrcFactor(const QString&);
    void setDstFactor(const QString&);
    void setEnabledSeparateBlending(bool);
    void setSeparateSrcFactor(const QString&);
    void setSeparateDstFactor(const QString&);
    void setClearColor(QColor);
    void setClearAlpha(float);
    void setTopColor(QColor);
    void setTopAlpha(float);
    void setMiddleColor(QColor);
    void setMiddleAlpha(float);
    void setBottomColor(QColor);
    void setBottomAlpha(float);
    void setBlendColor(QColor);
    void setBlendAlpha(float);
    void setBlendEquation(const QString&);
    void setSeparateBlendEquation(const QString&);
    void setEnableColorLogicOp(bool);
    void setLogicOp(const QString&);
    void cleanup();

signals:
   // signals are for mouse events etc inside the widget.

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

private:
    // Qt centric
    bool core;

    // OpenGL centric
    void setupVertexAttribs();

    // These are state which can be set in paintGL()
    bool blending;
    bool depthtesting;
    GLenum srcfactor;
    GLenum dstfactor;
    bool separateblending;
    GLenum separatesrcfactor;
    GLenum separatedstfactor;
    GLenum blendeq;
    GLenum sepeq;
    bool logicoping;
    GLenum logicop;

    float clearColor[4];
    float blendColor[4];

    // for setting uniforms
    float topColor[4];
    float middleColor[4];
    float bottomColor[4];

    // for converting combobox QStrings to GLenums
    GLenum str2enum(const QString&);

    Sprite *topSprite;
    Sprite *middleSprite;
    Sprite *bottomSprite;

    QMatrix4x4 persp;
    QMatrix4x4 cam;

};

#endif // GLWIDGET_H
