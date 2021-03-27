#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnClear_clicked();

    void on_btnNum0_clicked();

    void on_btnNum1_clicked();

    void on_btnNum2_clicked();

    void on_btnNum3_clicked();

    void on_btnNum4_clicked();

    void on_btnNum5_clicked();

    void on_btnNum6_clicked();

    void on_btnNum7_clicked();

    void on_btnNum8_clicked();

    void on_btnNum9_clicked();

    void on_btnPlus_clicked();

    void on_btnSub_clicked();

    void on_btnMul_clicked();

    void on_btnDiv_clicked();

    void on_btnEqual_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
