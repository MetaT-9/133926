#ifndef CALCULATORFX_H
#define CALCULATORFX_H

#include <QMainWindow>

namespace Ui {
class CalculatorFX;
}

class CalculatorFX : public QMainWindow
{
    Q_OBJECT

private slots:
        void opNormal_restart_clicked();

        void opNormal_continue_clicked();

        void opFunction_clicked();

        void equal_clicked();

        void Ans_clicked();

        void DEL_clicked();

        void AC_clicked();

        void optionCal_toggled();

        void optionTri_toggled();

public:
    explicit CalculatorFX(QWidget *parent = 0);
    ~CalculatorFX();

private:
    Ui::CalculatorFX *ui;
    void connectAllSlots();//连接信号和槽
    QString calPattern_pre;
    QString tri_pre;
    bool cal_complete;



};

#endif // CALCULATORFX_H
