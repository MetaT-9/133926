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

public:
    explicit CalculatorFX(QWidget *parent = 0);

    ~CalculatorFX();

    QString sysPre(QString sys_current, QString expression);

    void preprocessing(QString expression, QVector<QString>& semi);

    QString calculate(QVector<QString>& semi);

    QString sysConversion(QString sys_current, QString sys_target, QString num);

    QString triConversion(QString tri_target, QString num);

    void sign_pre(QVector<QString>& semi);

    void omittedMul_pre(QVector<QString>& semi);

    void stack_pre(QString expression, QVector<QString>& semi);

    void toPost(QVector<QString>& semi);

    QString calculatePost(QVector<QString>& semi);

private:
    Ui::CalculatorFX *ui;

    void connectAllSlots();//连接信号和槽

    QString calPattern_current;

    QString tri_current;

    bool cal_complete;

    QString Ans;

    QString pi;

    QString e;

    QVector<QString> semi_stack;
};

#endif // CALCULATORFX_H
