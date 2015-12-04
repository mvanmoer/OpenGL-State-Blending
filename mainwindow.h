#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *);

private slots:

    void on_top_alpha_slider_valueChanged(int value);

    void on_blend_checkbox_toggled(bool checked);

    void on_depth_test_checkbox_toggled(bool checked);

    void on_srcFactorOpts_activated(const QString &arg1);

    void on_dstFactorOps_activated(const QString &arg1);

    void on_sepSrcFactorOps_activated(const QString &arg1);

    void on_blendEqOps_activated(const QString &arg1);

    void on_logicOpOps_activated(const QString &arg1);

    void on_glClearColorButton_clicked();

    void on_topColorButton_clicked();

    void on_middleColorButton_clicked();

    void on_bottomColorButton_clicked();

    void on_blendColorButton_clicked();

    void on_clear_color_alpha_slider_valueChanged(int value);

    void on_sepDstFactorOps_activated(const QString &arg1);

    void on_const_color_alpha_slider_valueChanged(int value);

    void on_colorLogic_checkbox_toggled(bool checked);

    void on_middle_alpha_slider_valueChanged(int value);

    void on_bottom_alpha_slider_valueChanged(int value);

    void on_separate_checkbox_toggled(bool checked);

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
