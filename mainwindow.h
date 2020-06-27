#pragma once

#include <QMainWindow>

#include <QStack>
#include <QDebug>
#include <QScrollBar>
#include <QIntValidator>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    float removeLast();
    void addNumber(float n);

private slots:
    void on_button_0_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_arrow_down_clicked();
    void on_button_arrow_up_clicked();
    void on_button_del_clicked();
    void on_button_division_clicked();
    void on_button_enter_clicked();
    void on_button_multiplication_clicked();
    void on_button_rol_clicked();
    void on_button_subtract_clicked();
    void on_button_sum_clicked();
    void on_button_clear_clicked();

private:
    Ui::MainWindow* ui;
    QStack<float> stack;
};