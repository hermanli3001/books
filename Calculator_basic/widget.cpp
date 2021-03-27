#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

static long long bufferNum = 0;
static long long symbol = 0;
// 0 is default
// 1 is +
// 2 is -
// 3 is *
// 4 is /

void Widget::on_btnClear_clicked()
{
    ui->lineEdit->setText("0");
    bufferNum = 0;
    symbol = 0;
}

void Widget::on_btnNum0_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum1_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 1;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum2_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 2;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum3_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 3;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum4_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 4;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum5_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 5;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum6_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 6;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum7_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 7;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum8_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 8;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnNum9_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    currNum *= 10;
    currNum = currNum + 9;
    QString tempStr = QString::number(currNum);
    ui->lineEdit->setText(tempStr);
}

void Widget::on_btnPlus_clicked()
{
    bufferNum = ui->lineEdit->text().toInt();
    if (symbol != 0)
        ui->lineEdit->setText("0");
    symbol = 1;
    ui->lineEdit->setText("0");
}

void Widget::on_btnSub_clicked()
{
    bufferNum = ui->lineEdit->text().toInt();
    if (symbol != 0)
        ui->lineEdit->setText("0");
    symbol = 2;
    ui->lineEdit->setText("0");
}

void Widget::on_btnMul_clicked()
{
    bufferNum = ui->lineEdit->text().toInt();
    if (symbol != 0)
        ui->lineEdit->setText("0");
    symbol = 3;
    ui->lineEdit->setText("0");
}

void Widget::on_btnDiv_clicked()
{
    bufferNum = ui->lineEdit->text().toInt();
    if (symbol != 0)
        ui->lineEdit->setText("0");
    symbol = 4;
    ui->lineEdit->setText("0");
}

void Widget::on_btnEqual_clicked()
{
    long long currNum = ui->lineEdit->text().toInt();
    if (symbol == 0)
        bufferNum += 0;
    else if (symbol == 1)
        bufferNum += currNum;
    else if (symbol == 2)
        bufferNum -= currNum;
    else if (symbol == 3)
        bufferNum *= currNum;
    else if (symbol == 4)
        bufferNum /= currNum;
    else {
        ui->lineEdit->setText("Symbol Error");
    }
    QString tempStr = QString::number(bufferNum);
    ui->lineEdit->setText(tempStr);
}
