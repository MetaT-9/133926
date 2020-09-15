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

    void cmp_triggered();

    void comDiv_triggered();

    void lowComMul_triggered();

    void equ11_triggered();

    void equ12_triggered();

    void equInverse_triggered();

    void equExp_triggered();

    void equLog_triggered();

public:
    explicit CalculatorFX(QWidget *parent = 0);

    ~CalculatorFX();

    QString sysPre(QString sys_current, QString expression);

    void preprocessing(QString expression, QVector<QString>& semi);

    QString calculate(QVector<QString>& semi, QString sysCurrent, QString triCurrent);

    QString sysConversion(QString sys_current, QString sys_target, QString num);

    QString triConversion(QString tri_target, QString num);

    void sign_pre(QVector<QString>& semi);

    void omittedMul_pre(QVector<QString>& semi);

    void stack_pre(QString expression, QVector<QString>& semi);

    void toPost(QVector<QString>& semi, QVector<QString>& postExp);

    QString calculatePost(QVector<QString>& postExp, QString sysCurrent, QString triCurrent);

    void fun_cmp(QString expression);

    void fun_comDiv(QString expression);

    void fun_lowComMul(QString expression);

    void fun_equ11(QString expression);

    void fun_equ12(QString expression);

    void fun_equInverse(QString expression);

    void fun_equExp(QString expression);

    void fun_equLog(QString expression);

private:
    Ui::CalculatorFX *ui;

    QAction *action_cmp;

    QAction *action_comDiv;

    QAction *action_lowComMul;

    QAction *action_equ11;

    QAction *action_equ12;

    QAction *action_equInverse;

    QAction *action_equExp;

    QAction *action_equLog;

    void connectAllSlots();//连接信号和槽

    QString calPattern_current;

    QString tri_current;

    bool cal_complete;

    QString Ans;

    QString pi;

    QString e;

    bool flag_arc;

    int functionFlag;

    QVector<QString> semi_stack;
};

#endif // CALCULATORFX_H
