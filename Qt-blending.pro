#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T10:06:38
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt-blending
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    sprite.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    sprite.h

FORMS    += mainwindow.ui

RESOURCES += \
    shaders.qrc

DISTFILES +=
