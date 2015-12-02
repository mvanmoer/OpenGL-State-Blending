#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QOpenGLContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // This stuff is the analogue of glutInit*
    // I'm assuming some things based on my particular workstation driver
    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    fmt.setSamples(32);
    fmt.setVersion(4,2);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(fmt);

    MainWindow w;
    w.show();

    return a.exec();
}
