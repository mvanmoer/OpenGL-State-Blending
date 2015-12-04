#include "glwidget.h"
#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <cmath>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      blending(false),
      depthtesting(false),
      srcfactor(GL_ONE),
      dstfactor(GL_ZERO),
      separateblending(false),
      separatesrcfactor(GL_ONE),
      separatedstfactor(GL_ZERO),
      blendeq(GL_ADD),
      logicoping(false),
      logicop(GL_COPY),
      premultalpha(false)
{
    clearColor[0] = clearColor[1] = clearColor[2] = clearColor[3] = 0.0f;
    topColor[0] = middleColor[1] = bottomColor[2] = 1.0f;
    topColor[3] = middleColor[3] = bottomColor[3] = 1.0f;
    topColor[1] = topColor[2] = 0.0f;
    middleColor[0] = middleColor[2] = 0.0f;
    bottomColor[0] = bottomColor[1] = 0.0f;
    blendColor[0] = blendColor[1] = blendColor[2] = blendColor[3] = 0.0f;
}

GLWidget::~GLWidget()
{
    cleanup();
}

void GLWidget::cleanup() {
    makeCurrent();
    delete topSprite;
    doneCurrent();
}

GLenum GLWidget::str2enum(const QString& str) {
    if (str == "GL_ZERO")
        return GL_ZERO;
    else if (str == "GL_ONE")
        return GL_ONE;
    else if (str == "GL_SRC_COLOR")
        return GL_SRC_COLOR;
    else if (str == "GL_ONE_MINUS_SRC_COLOR")
        return GL_ONE_MINUS_SRC_COLOR;
    else if (str == "GL_DST_COLOR")
        return GL_DST_COLOR;
    else if (str == "GL_ONE_MINUS_DST_COLOR")
        return GL_ONE_MINUS_DST_COLOR;
    else if (str == "GL_SRC_ALPHA")
        return GL_SRC_ALPHA;
    else if (str == "GL_ONE_MINUS_SRC_ALPHA")
        return GL_ONE_MINUS_SRC_ALPHA;
    else if (str == "GL_DST_ALPHA")
        return GL_DST_ALPHA;
    else if (str == "GL_ONE_MINUS_DST_ALPHA")
        return GL_ONE_MINUS_DST_ALPHA;
    else if (str == "GL_CONSTANT_COLOR")
        return GL_CONSTANT_COLOR;
    else if (str == "GL_ONE_MINUS_CONSTANT_COLOR")
        return GL_ONE_MINUS_CONSTANT_COLOR;
    else if (str == "GL_CONSANT_ALPHA")
        return GL_CONSTANT_ALPHA;
    else if (str == "GL_ONE_MINUS_CONSTANT_ALPHA")
        return GL_ONE_MINUS_CONSTANT_ALPHA;
    else if (str == "GL_SRC_ALPHA_SATURATE")
        return GL_SRC_ALPHA_SATURATE;
    else if (str == "GL_SRC1_COLOR")
        return GL_SRC1_COLOR;
    else if (str == "GL_ONE_MINUS_SRC1_COLOR")
        return GL_ONE_MINUS_SRC1_COLOR;
    else if (str == "GL_SRC1_ALPHA")
        return GL_SRC1_ALPHA;
    else if (str == "GL_ONE_MINUS_SRC1_ALPHA")
        return GL_ONE_MINUS_SRC1_ALPHA;
    else if (str == "GL_FUNC_ADD")
        return GL_FUNC_ADD;
    else if (str == "GL_FUNC_SUBTRACT")
        return GL_FUNC_SUBTRACT;
    else if (str == "GL_FUNC_REVERSE_SUBTRACT")
        return GL_FUNC_REVERSE_SUBTRACT;
    else if (str == "GL_MIN")
        return GL_MIN;
    else if (str == "GL_MAX")
        return GL_MAX;
    else if (str == "GL_CLEAR") return GL_CLEAR;
    else if (str == "GL_COPY") return GL_COPY;
    else if (str == "GL_NOOP") return GL_NOOP;
    else if (str == "GL_SET") return GL_SET;
    else if (str == "GL_COPY_INVERTED") return GL_COPY_INVERTED;
    else if (str == "GL_INVERT") return GL_INVERT;
    else if (str == "GL_AND_REVERSE") return GL_AND_REVERSE;
    else if (str == "GL_OR_REVERSE") return GL_OR_REVERSE;
    else if (str == "GL_AND") return GL_AND;
    else if (str == "GL_OR") return GL_OR;
    else if (str == "GL_NAND") return GL_NAND;
    else if (str == "GL_NOR") return GL_NOR;
    else if (str == "GL_XOR") return GL_XOR;
    else if (str == "GL_EQUIV") return GL_EQUIV;
    else if (str == "GL_AND_INVERTED") return GL_AND_INVERTED;
    else if (str == "GL_OR_INVERTED") return GL_OR_INVERTED;
    else return GL_ZERO;
}

void GLWidget::setEnableBlending(bool state)
{
    blending = state;
    update();
}

void GLWidget::setEnableDepthTest(bool state) {
    depthtesting = state;
    update();
}

void GLWidget::setEnablePreMultiplyAlpha(bool state) {
    premultalpha = state;
    update();
}

void GLWidget::setSrcFactor(const QString& factor) {
    srcfactor = str2enum(factor);
    update();
}

void GLWidget::setDstFactor(const QString& factor) {
    dstfactor = str2enum(factor);
    update();
}

void GLWidget::setEnabledSeparateBlending(bool state) {
    separateblending = state;
    update();
}

void GLWidget::setSeparateSrcFactor(const QString& factor) {
    separatesrcfactor = str2enum(factor);
    update();
}

void GLWidget::setSeparateDstFactor(const QString& factor) {
    separatedstfactor = str2enum(factor);
    update();
}

void GLWidget::setBlendEquation(const QString& eq) {
    blendeq = str2enum(eq);
    update();
}

void GLWidget::setSeparateBlendEquation(const QString& eq) {
    sepeq = str2enum(eq);
    update();
}

void GLWidget::setEnableColorLogicOp(bool state) {
    logicoping = state;
    update();
}

void GLWidget::setLogicOp(const QString& op) {
    logicop = str2enum(op);
    update();
}

void GLWidget::setClearColor(QColor c) {
    clearColor[0] = c.redF();
    clearColor[1] = c.greenF();
    clearColor[2] = c.blueF();
    update();
}

void GLWidget::setClearAlpha(float a) {
    clearColor[3] = a;
    update();
}

void GLWidget::setTopColor(QColor c) {
    topColor[0] = c.redF();
    topColor[1] = c.greenF();
    topColor[2] = c.blueF();
    update();
}

void GLWidget::setTopAlpha(float a) {
    topColor[3] = a;
    update();
}

void GLWidget::setMiddleColor(QColor c) {
    middleColor[0] = c.redF();
    middleColor[1] = c.greenF();
    middleColor[2] = c.blueF();
    update();
}

void GLWidget::setMiddleAlpha(float a) {
    middleColor[3] = a;
    update();
}

void GLWidget::setBottomColor(QColor c) {
    bottomColor[0] = c.redF();
    bottomColor[1] = c.greenF();
    bottomColor[2] = c.blueF();
    update();
}

void GLWidget::setBottomAlpha(float a) {
    bottomColor[3] = a;
    update();
}

void GLWidget::setBlendColor(QColor c) {
    blendColor[0] = c.redF();
    blendColor[1] = c.greenF();
    blendColor[2] = c.blueF();
    update();
}

void GLWidget::setBlendAlpha(float a) {
    blendColor[3] = a;
    update();
}

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_MULTISAMPLE);
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
    glBlendColor(blendColor[0], blendColor[1], blendColor[2], blendColor[3]);

    persp.setToIdentity();
    persp.ortho(-10, 10, -10, 10, 1, 100);

    cam.setToIdentity();
    cam.translate(0, 0, -1);
    cam.scale(1.5);

    // Might move this inside the billboard and have a generic set of coords that
    // the application can move around.
    float s3 = 2.0*sqrt(3.0);
    float fan[] = { -s3, -s3, 0.0f,
                    -s3,  s3, 0.0f,
                     s3,  s3, 0.0f,
                     s3, -s3, 0.0f};

    topSprite = new Sprite(fan, ":/shaders/billboard.vert", ":/shaders/billboard.frag");
    topSprite->getModelMtx()->translate(-sqrt(3.0), 2.0, -1.0);
    middleSprite = new Sprite(fan, ":/shaders/billboard.vert", ":shaders/billboard.frag");
    middleSprite->getModelMtx()->translate(sqrt(3.0), 0.0, -2.0);
    bottomSprite = new Sprite(fan, ":/shaders/billboard.vert", ":/shaders/billboard.frag");
    bottomSprite->getModelMtx()->translate(-sqrt(3.0), -2.0, -3.0);

}


void GLWidget::paintGL()
{
    // ~ display callback in freeglut

    if (premultalpha) {
        glClearColor(clearColor[0]*clearColor[3], clearColor[1]*clearColor[3], clearColor[2]*clearColor[3], clearColor[3]);
    }
    else {
        glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (blending) {
        glEnable(GL_BLEND);
        if (premultalpha) {
            glBlendColor(blendColor[0] * blendColor[3], blendColor[1] * blendColor[3], blendColor[2] * blendColor[3], blendColor[3]);
        }
        else {
            glBlendColor(blendColor[0], blendColor[1], blendColor[2], blendColor[3]);
        }
        if (!separateblending) {
            glBlendFunc(srcfactor, dstfactor);
            glBlendEquation(blendeq);
        }
        else {
            glBlendFuncSeparate(srcfactor, dstfactor, separatesrcfactor, separatedstfactor);
            glBlendEquationSeparate(blendeq, sepeq);
        }
    }
    else {
        glDisable(GL_BLEND);
    }

    if (depthtesting) {
        glEnable(GL_DEPTH_TEST);
    }
    else {
        glDisable(GL_DEPTH_TEST);
    }

    if (logicoping) {
        glEnable(GL_COLOR_LOGIC_OP);
        glLogicOp(logicop);
    }
    else {
        glDisable(GL_COLOR_LOGIC_OP);
    }

    if (premultalpha) {
        topSprite->Display(topColor[0]*topColor[3], topColor[1]*topColor[3], topColor[2]*topColor[3], topColor[3], persp*cam);
        middleSprite->Display(middleColor[0]*middleColor[3], middleColor[1]*middleColor[3], middleColor[2]*middleColor[3], middleColor[3], persp*cam);
        bottomSprite->Display(bottomColor[0]*bottomColor[3], bottomColor[1]*bottomColor[3], bottomColor[2]*bottomColor[3], bottomColor[3], persp*cam);
    }
    else {
        topSprite->Display(topColor, persp * cam);
        middleSprite->Display(middleColor, persp * cam);
        bottomSprite->Display(bottomColor, persp * cam);
    }
}




































