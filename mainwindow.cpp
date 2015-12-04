#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1011, 611);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

// Alpha sliders
void MainWindow::on_clear_color_alpha_slider_valueChanged(int value)
{
    ui->myGLCanvas->setClearAlpha(float(value)/100.0f);
}

void MainWindow::on_top_alpha_slider_valueChanged(int value)
{
    ui->myGLCanvas->setTopAlpha(float(value)/100.0f);
}

void MainWindow::on_const_color_alpha_slider_valueChanged(int value)
{
    ui->myGLCanvas->setBlendAlpha(float(value)/100.0f);
}

void MainWindow::on_middle_alpha_slider_valueChanged(int value)
{
    ui->myGLCanvas->setMiddleAlpha(float(value)/100.0f);
}

void MainWindow::on_bottom_alpha_slider_valueChanged(int value)
{
    ui->myGLCanvas->setBottomAlpha(float(value)/100.0f);
}

// checkboxes
void MainWindow::on_blend_checkbox_toggled(bool checked)
{
    ui->myGLCanvas->setEnableBlending(checked);
}

void MainWindow::on_depth_test_checkbox_toggled(bool checked)
{
    ui->myGLCanvas->setEnableDepthTest(checked);
}

void MainWindow::on_colorLogic_checkbox_toggled(bool checked)
{
    ui->myGLCanvas->setEnableColorLogicOp(checked);
}

void MainWindow::on_separate_checkbox_toggled(bool checked)
{
    ui->myGLCanvas->setEnabledSeparateBlending(checked);
}

// Dropdown menus
void MainWindow::on_srcFactorOpts_activated(const QString &arg1)
{
   ui->myGLCanvas->setSrcFactor(arg1);
}

void MainWindow::on_dstFactorOps_activated(const QString &arg1)
{
    ui->myGLCanvas->setDstFactor(arg1);
}

void MainWindow::on_sepSrcFactorOps_activated(const QString &arg1)
{
    ui->myGLCanvas->setSeparateSrcFactor(arg1);
}

void MainWindow::on_blendEqOps_activated(const QString &arg1)
{
    ui->myGLCanvas->setBlendEquation(arg1);
}

void MainWindow::on_logicOpOps_activated(const QString &arg1)
{
    ui->myGLCanvas->setLogicOp(arg1);
}

void MainWindow::on_sepDstFactorOps_activated(const QString &arg1)
{
    ui->myGLCanvas->setSeparateDstFactor(arg1);
}

// Color dialogs
void MainWindow::on_glClearColorButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white,this,"glClearColor");
    ui->myGLCanvas->setClearColor(selectedColor);
}

void MainWindow::on_topColorButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white, this, "top sprite color");
    ui->myGLCanvas->setTopColor(selectedColor);
}

void MainWindow::on_middleColorButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white, this, "middle sprite color");
    ui->myGLCanvas->setMiddleColor(selectedColor);
}

void MainWindow::on_bottomColorButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white, this, "bottom sprite color");
    ui->myGLCanvas->setBottomColor(selectedColor);
}

void MainWindow::on_blendColorButton_clicked()
{
    QColor selectedColor = QColorDialog::getColor(Qt::white, this, "glBlendColor");
    ui->myGLCanvas->setBlendColor(selectedColor);
}











void MainWindow::on_actionExit_triggered()
{
    close();
}
