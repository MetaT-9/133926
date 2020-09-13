#ifndef CALCULATORFX_H
#define CALCULATORFX_H

#include <QMainWindow>

namespace Ui {
class CalculatorFX;
}

class CalculatorFX : public QMainWindow
{
    Q_OBJECT
public slots:
    bool eventFilter(QObject *watched, QEvent *event);

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

        QString sysConversion(QString sys_current,QString sys_target,QString num);

        QString triConversion(QString tri_target,QString num);

public:
    explicit CalculatorFX(QWidget *parent = 0);
    ~CalculatorFX();

private:
    Ui::CalculatorFX *ui;
    void connectAllSlots();//连接信号和槽
    QString calPattern_current;
    QString tri_current;
    bool cal_complete;
    QString Ans;



};

#endif // CALCULATORFX_H
