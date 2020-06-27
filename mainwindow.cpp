#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator());
    ui->textEdit->setReadOnly(true);
    setWindowTitle("Reverse Polish Notation");
}

MainWindow::~MainWindow() { delete ui; }

/******************************** DIGITS ********************************/

void MainWindow::on_button_0_clicked() { ui->lineEdit->insert("0"); }

void MainWindow::on_button_1_clicked() { ui->lineEdit->insert("1"); }

void MainWindow::on_button_2_clicked() { ui->lineEdit->insert("2"); }

void MainWindow::on_button_3_clicked() { ui->lineEdit->insert("3"); }

void MainWindow::on_button_4_clicked() { ui->lineEdit->insert("4"); }

void MainWindow::on_button_5_clicked() { ui->lineEdit->insert("5"); }

void MainWindow::on_button_6_clicked() { ui->lineEdit->insert("6"); }

void MainWindow::on_button_7_clicked() { ui->lineEdit->insert("7"); }

void MainWindow::on_button_8_clicked() { ui->lineEdit->insert("8"); }

void MainWindow::on_button_9_clicked() { ui->lineEdit->insert("9"); }

/******************************** OPERATIONS ********************************/

void MainWindow::on_button_sum_clicked()
{
    if (stack.length() < 2)                                  //stack must have at least two elements for an operation
        return;

    float a = removeLast();
    float b = removeLast();

    addNumber(b + a);                                         //inserts operation result into stack and updates TextEdit
}

void MainWindow::on_button_subtract_clicked()
{
    if (stack.length() < 2)
        return;

    float a = removeLast();
    float b = removeLast();

    addNumber(b - a);
}

void MainWindow::on_button_multiplication_clicked()
{
    if (stack.length() < 2)
        return;

    float a = removeLast();
    float b = removeLast();

    addNumber(b * a);
}

void MainWindow::on_button_division_clicked()
{
    if (stack.length() < 2)
        return;

    if (stack.top() == 0)                                    //avoids division by zero
        return;

    float a = removeLast();
    float b = removeLast();

    addNumber(b / a);
}

void MainWindow::on_button_arrow_down_clicked()
{
    ui->textEdit->verticalScrollBar()->triggerAction(QScrollBar::SliderSingleStepAdd);
}

void MainWindow::on_button_arrow_up_clicked()
{
    ui->textEdit->verticalScrollBar()->triggerAction(QScrollBar::SliderSingleStepSub);
}

void MainWindow::on_button_del_clicked()
{
    if (stack.isEmpty())                                     //checks is stack is empty
        return;

    removeLast();
}

void MainWindow::on_button_enter_clicked()
{
    if (ui->lineEdit->text() == "")                          //checks if LineEdit's field is empty
        return;

    float next = ui->lineEdit->text().toFloat();            //gets content and converts it from text to float

    ui->lineEdit->clear();                                  //clears LineEdit's content
    addNumber(next);                                        //inserts into stack and updates TextEdit
}

void MainWindow::on_button_rol_clicked()
{
    if (stack.length() < 2)
        return;

    float a = removeLast();
    float b = removeLast();

    addNumber(a);
    addNumber(b);
}

void MainWindow::on_button_clear_clicked() { ui->lineEdit->clear(); }

/******************************** UTILS ********************************/

float MainWindow::removeLast()
{
    float last = stack.pop();                                               //removes last element

    ui->textEdit->clear();                                                  //clears TextEdit

    foreach(float i, stack)                                                 //iterates through stack elements
    {
        ui->textEdit->insertPlainText(QString::number(i) + "\n");           //for each element, inserts line break and itself into TextEdit
    }

    return last;                                                            //returns removed element
}

void MainWindow::addNumber(float n)
{
    ui->textEdit->insertPlainText(QString::number(n) + "\n");               //inserts line break, converts number to text and inserts it
    stack.push(n);                                                          //adds parsed element to stack
}
