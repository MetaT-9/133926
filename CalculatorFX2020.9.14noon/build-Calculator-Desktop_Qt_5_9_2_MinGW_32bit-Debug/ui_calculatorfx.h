/********************************************************************************
** Form generated from reading UI file 'calculatorfx.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORFX_H
#define UI_CALCULATORFX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorFX
{
public:
    QAction *instruction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pBtn_comma;
    QPushButton *pBtn_0b;
    QPushButton *pBtn_0x;
    QPushButton *pBtn_Ans;
    QPushButton *pBtn_DEL;
    QPushButton *pBtn_pi;
    QPushButton *pBtn_and;
    QPushButton *pBtn_arcsin;
    QPushButton *pBtn_sin;
    QPushButton *pBtn_A;
    QPushButton *pBtn_B;
    QPushButton *pBtn_C;
    QPushButton *pBtn_D;
    QPushButton *pBtn_E;
    QPushButton *pBtn_F;
    QPushButton *pBtn_e;
    QPushButton *pBtn_or;
    QPushButton *pBtn_arccos;
    QPushButton *pBtn_cos;
    QPushButton *pBtn_7;
    QPushButton *pBtn_8;
    QPushButton *pBtn_9;
    QPushButton *pBtn_div;
    QPushButton *pBtn_mod;
    QPushButton *pBtn_power;
    QPushButton *pBtn_abs;
    QPushButton *pBtn_xor;
    QPushButton *pBtn_arctan;
    QPushButton *pBtn_tan;
    QPushButton *pBtn_4;
    QPushButton *pBtn_5;
    QPushButton *pBtn_6;
    QPushButton *pBtn_mul;
    QPushButton *pBtn_lBracket;
    QPushButton *pBtn_rbracket;
    QPushButton *pBtn_square;
    QPushButton *pBtn_not;
    QPushButton *pBtn_log;
    QPushButton *pBtn_lg;
    QPushButton *pBtn_1;
    QPushButton *pBtn_2;
    QPushButton *pBtn_3;
    QPushButton *pBtn_sub;
    QPushButton *pBtn_sqrt;
    QPushButton *pBtn_sll;
    QPushButton *pBtn_sra;
    QPushButton *pBtn_ln;
    QPushButton *pBtn_0;
    QPushButton *pBtn_dot;
    QPushButton *pBtn_percent;
    QPushButton *pBtn_Add;
    QToolButton *tBtn_function;
    QPushButton *pBtn_AC;
    QPushButton *pBtn_equal;
    QFrame *frame_screen;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Input;
    QLineEdit *lineEdit_Result;
    QWidget *widget_options;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QFrame *frame_calPattern;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rBtn_sciCal;
    QRadioButton *rBtn_bin;
    QRadioButton *rBtn_oct;
    QRadioButton *rBtn_hex;
    QRadioButton *rBtn_mix;
    QFrame *frame_tri;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rBtn_angle;
    QRadioButton *rBtn_radian;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *CalculatorFX)
    {
        if (CalculatorFX->objectName().isEmpty())
            CalculatorFX->setObjectName(QStringLiteral("CalculatorFX"));
        CalculatorFX->resize(800, 750);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalculatorFX->sizePolicy().hasHeightForWidth());
        CalculatorFX->setSizePolicy(sizePolicy);
        CalculatorFX->setMinimumSize(QSize(800, 750));
        instruction = new QAction(CalculatorFX);
        instruction->setObjectName(QStringLiteral("instruction"));
        centralWidget = new QWidget(CalculatorFX);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pBtn_comma = new QPushButton(centralWidget);
        pBtn_comma->setObjectName(QStringLiteral("pBtn_comma"));
        sizePolicy.setHeightForWidth(pBtn_comma->sizePolicy().hasHeightForWidth());
        pBtn_comma->setSizePolicy(sizePolicy);
        pBtn_comma->setMinimumSize(QSize(35, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        pBtn_comma->setFont(font);

        gridLayout->addWidget(pBtn_comma, 2, 3, 1, 1);

        pBtn_0b = new QPushButton(centralWidget);
        pBtn_0b->setObjectName(QStringLiteral("pBtn_0b"));
        sizePolicy.setHeightForWidth(pBtn_0b->sizePolicy().hasHeightForWidth());
        pBtn_0b->setSizePolicy(sizePolicy);
        pBtn_0b->setMinimumSize(QSize(35, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        pBtn_0b->setFont(font1);

        gridLayout->addWidget(pBtn_0b, 2, 4, 1, 1);

        pBtn_0x = new QPushButton(centralWidget);
        pBtn_0x->setObjectName(QStringLiteral("pBtn_0x"));
        sizePolicy.setHeightForWidth(pBtn_0x->sizePolicy().hasHeightForWidth());
        pBtn_0x->setSizePolicy(sizePolicy);
        pBtn_0x->setMinimumSize(QSize(35, 25));
        pBtn_0x->setFont(font1);

        gridLayout->addWidget(pBtn_0x, 2, 5, 1, 1);

        pBtn_Ans = new QPushButton(centralWidget);
        pBtn_Ans->setObjectName(QStringLiteral("pBtn_Ans"));
        sizePolicy.setHeightForWidth(pBtn_Ans->sizePolicy().hasHeightForWidth());
        pBtn_Ans->setSizePolicy(sizePolicy);
        pBtn_Ans->setMinimumSize(QSize(70, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        pBtn_Ans->setFont(font2);

        gridLayout->addWidget(pBtn_Ans, 2, 6, 1, 1);

        pBtn_DEL = new QPushButton(centralWidget);
        pBtn_DEL->setObjectName(QStringLiteral("pBtn_DEL"));
        sizePolicy.setHeightForWidth(pBtn_DEL->sizePolicy().hasHeightForWidth());
        pBtn_DEL->setSizePolicy(sizePolicy);
        pBtn_DEL->setMinimumSize(QSize(70, 25));
        pBtn_DEL->setFont(font2);

        gridLayout->addWidget(pBtn_DEL, 2, 7, 1, 1);

        pBtn_pi = new QPushButton(centralWidget);
        pBtn_pi->setObjectName(QStringLiteral("pBtn_pi"));
        sizePolicy.setHeightForWidth(pBtn_pi->sizePolicy().hasHeightForWidth());
        pBtn_pi->setSizePolicy(sizePolicy);
        pBtn_pi->setMinimumSize(QSize(35, 25));
        pBtn_pi->setFont(font1);

        gridLayout->addWidget(pBtn_pi, 3, 0, 1, 1);

        pBtn_and = new QPushButton(centralWidget);
        pBtn_and->setObjectName(QStringLiteral("pBtn_and"));
        sizePolicy.setHeightForWidth(pBtn_and->sizePolicy().hasHeightForWidth());
        pBtn_and->setSizePolicy(sizePolicy);
        pBtn_and->setMinimumSize(QSize(35, 25));
        pBtn_and->setFont(font1);

        gridLayout->addWidget(pBtn_and, 3, 1, 1, 1);

        pBtn_arcsin = new QPushButton(centralWidget);
        pBtn_arcsin->setObjectName(QStringLiteral("pBtn_arcsin"));
        sizePolicy.setHeightForWidth(pBtn_arcsin->sizePolicy().hasHeightForWidth());
        pBtn_arcsin->setSizePolicy(sizePolicy);
        pBtn_arcsin->setMinimumSize(QSize(35, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        pBtn_arcsin->setFont(font3);

        gridLayout->addWidget(pBtn_arcsin, 3, 2, 1, 1);

        pBtn_sin = new QPushButton(centralWidget);
        pBtn_sin->setObjectName(QStringLiteral("pBtn_sin"));
        sizePolicy.setHeightForWidth(pBtn_sin->sizePolicy().hasHeightForWidth());
        pBtn_sin->setSizePolicy(sizePolicy);
        pBtn_sin->setMinimumSize(QSize(35, 25));
        pBtn_sin->setFont(font1);

        gridLayout->addWidget(pBtn_sin, 3, 3, 1, 1);

        pBtn_A = new QPushButton(centralWidget);
        pBtn_A->setObjectName(QStringLiteral("pBtn_A"));
        sizePolicy.setHeightForWidth(pBtn_A->sizePolicy().hasHeightForWidth());
        pBtn_A->setSizePolicy(sizePolicy);
        pBtn_A->setMinimumSize(QSize(35, 25));
        pBtn_A->setFont(font1);

        gridLayout->addWidget(pBtn_A, 3, 4, 1, 1);

        pBtn_B = new QPushButton(centralWidget);
        pBtn_B->setObjectName(QStringLiteral("pBtn_B"));
        sizePolicy.setHeightForWidth(pBtn_B->sizePolicy().hasHeightForWidth());
        pBtn_B->setSizePolicy(sizePolicy);
        pBtn_B->setMinimumSize(QSize(35, 25));
        pBtn_B->setFont(font1);

        gridLayout->addWidget(pBtn_B, 3, 5, 1, 1);

        pBtn_C = new QPushButton(centralWidget);
        pBtn_C->setObjectName(QStringLiteral("pBtn_C"));
        sizePolicy.setHeightForWidth(pBtn_C->sizePolicy().hasHeightForWidth());
        pBtn_C->setSizePolicy(sizePolicy);
        pBtn_C->setMinimumSize(QSize(35, 25));
        pBtn_C->setFont(font1);

        gridLayout->addWidget(pBtn_C, 3, 6, 1, 1);

        pBtn_D = new QPushButton(centralWidget);
        pBtn_D->setObjectName(QStringLiteral("pBtn_D"));
        sizePolicy.setHeightForWidth(pBtn_D->sizePolicy().hasHeightForWidth());
        pBtn_D->setSizePolicy(sizePolicy);
        pBtn_D->setMinimumSize(QSize(35, 25));
        pBtn_D->setFont(font1);

        gridLayout->addWidget(pBtn_D, 3, 7, 1, 1);

        pBtn_E = new QPushButton(centralWidget);
        pBtn_E->setObjectName(QStringLiteral("pBtn_E"));
        sizePolicy.setHeightForWidth(pBtn_E->sizePolicy().hasHeightForWidth());
        pBtn_E->setSizePolicy(sizePolicy);
        pBtn_E->setMinimumSize(QSize(35, 25));
        pBtn_E->setFont(font1);

        gridLayout->addWidget(pBtn_E, 3, 8, 1, 1);

        pBtn_F = new QPushButton(centralWidget);
        pBtn_F->setObjectName(QStringLiteral("pBtn_F"));
        sizePolicy.setHeightForWidth(pBtn_F->sizePolicy().hasHeightForWidth());
        pBtn_F->setSizePolicy(sizePolicy);
        pBtn_F->setMinimumSize(QSize(35, 25));
        pBtn_F->setFont(font1);

        gridLayout->addWidget(pBtn_F, 3, 9, 1, 1);

        pBtn_e = new QPushButton(centralWidget);
        pBtn_e->setObjectName(QStringLiteral("pBtn_e"));
        sizePolicy.setHeightForWidth(pBtn_e->sizePolicy().hasHeightForWidth());
        pBtn_e->setSizePolicy(sizePolicy);
        pBtn_e->setMinimumSize(QSize(35, 25));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        font4.setItalic(false);
        pBtn_e->setFont(font4);

        gridLayout->addWidget(pBtn_e, 4, 0, 1, 1);

        pBtn_or = new QPushButton(centralWidget);
        pBtn_or->setObjectName(QStringLiteral("pBtn_or"));
        sizePolicy.setHeightForWidth(pBtn_or->sizePolicy().hasHeightForWidth());
        pBtn_or->setSizePolicy(sizePolicy);
        pBtn_or->setMinimumSize(QSize(35, 25));
        pBtn_or->setFont(font1);

        gridLayout->addWidget(pBtn_or, 4, 1, 1, 1);

        pBtn_arccos = new QPushButton(centralWidget);
        pBtn_arccos->setObjectName(QStringLiteral("pBtn_arccos"));
        sizePolicy.setHeightForWidth(pBtn_arccos->sizePolicy().hasHeightForWidth());
        pBtn_arccos->setSizePolicy(sizePolicy);
        pBtn_arccos->setMinimumSize(QSize(35, 25));
        pBtn_arccos->setFont(font3);

        gridLayout->addWidget(pBtn_arccos, 4, 2, 1, 1);

        pBtn_cos = new QPushButton(centralWidget);
        pBtn_cos->setObjectName(QStringLiteral("pBtn_cos"));
        sizePolicy.setHeightForWidth(pBtn_cos->sizePolicy().hasHeightForWidth());
        pBtn_cos->setSizePolicy(sizePolicy);
        pBtn_cos->setMinimumSize(QSize(35, 25));
        pBtn_cos->setFont(font1);

        gridLayout->addWidget(pBtn_cos, 4, 3, 1, 1);

        pBtn_7 = new QPushButton(centralWidget);
        pBtn_7->setObjectName(QStringLiteral("pBtn_7"));
        sizePolicy.setHeightForWidth(pBtn_7->sizePolicy().hasHeightForWidth());
        pBtn_7->setSizePolicy(sizePolicy);
        pBtn_7->setMinimumSize(QSize(35, 25));
        pBtn_7->setFont(font1);

        gridLayout->addWidget(pBtn_7, 4, 4, 1, 1);

        pBtn_8 = new QPushButton(centralWidget);
        pBtn_8->setObjectName(QStringLiteral("pBtn_8"));
        sizePolicy.setHeightForWidth(pBtn_8->sizePolicy().hasHeightForWidth());
        pBtn_8->setSizePolicy(sizePolicy);
        pBtn_8->setMinimumSize(QSize(35, 25));
        pBtn_8->setFont(font1);

        gridLayout->addWidget(pBtn_8, 4, 5, 1, 1);

        pBtn_9 = new QPushButton(centralWidget);
        pBtn_9->setObjectName(QStringLiteral("pBtn_9"));
        sizePolicy.setHeightForWidth(pBtn_9->sizePolicy().hasHeightForWidth());
        pBtn_9->setSizePolicy(sizePolicy);
        pBtn_9->setMinimumSize(QSize(35, 25));
        pBtn_9->setFont(font1);

        gridLayout->addWidget(pBtn_9, 4, 6, 1, 1);

        pBtn_div = new QPushButton(centralWidget);
        pBtn_div->setObjectName(QStringLiteral("pBtn_div"));
        sizePolicy.setHeightForWidth(pBtn_div->sizePolicy().hasHeightForWidth());
        pBtn_div->setSizePolicy(sizePolicy);
        pBtn_div->setMinimumSize(QSize(35, 25));
        pBtn_div->setFont(font1);

        gridLayout->addWidget(pBtn_div, 4, 7, 1, 1);

        pBtn_mod = new QPushButton(centralWidget);
        pBtn_mod->setObjectName(QStringLiteral("pBtn_mod"));
        sizePolicy.setHeightForWidth(pBtn_mod->sizePolicy().hasHeightForWidth());
        pBtn_mod->setSizePolicy(sizePolicy);
        pBtn_mod->setMinimumSize(QSize(35, 25));
        pBtn_mod->setFont(font1);

        gridLayout->addWidget(pBtn_mod, 4, 8, 1, 1);

        pBtn_power = new QPushButton(centralWidget);
        pBtn_power->setObjectName(QStringLiteral("pBtn_power"));
        sizePolicy.setHeightForWidth(pBtn_power->sizePolicy().hasHeightForWidth());
        pBtn_power->setSizePolicy(sizePolicy);
        pBtn_power->setMinimumSize(QSize(35, 25));
        pBtn_power->setFont(font1);

        gridLayout->addWidget(pBtn_power, 4, 9, 1, 1);

        pBtn_abs = new QPushButton(centralWidget);
        pBtn_abs->setObjectName(QStringLiteral("pBtn_abs"));
        sizePolicy.setHeightForWidth(pBtn_abs->sizePolicy().hasHeightForWidth());
        pBtn_abs->setSizePolicy(sizePolicy);
        pBtn_abs->setMinimumSize(QSize(35, 25));
        pBtn_abs->setFont(font1);

        gridLayout->addWidget(pBtn_abs, 5, 0, 1, 1);

        pBtn_xor = new QPushButton(centralWidget);
        pBtn_xor->setObjectName(QStringLiteral("pBtn_xor"));
        sizePolicy.setHeightForWidth(pBtn_xor->sizePolicy().hasHeightForWidth());
        pBtn_xor->setSizePolicy(sizePolicy);
        pBtn_xor->setMinimumSize(QSize(35, 25));
        pBtn_xor->setFont(font1);

        gridLayout->addWidget(pBtn_xor, 5, 1, 1, 1);

        pBtn_arctan = new QPushButton(centralWidget);
        pBtn_arctan->setObjectName(QStringLiteral("pBtn_arctan"));
        sizePolicy.setHeightForWidth(pBtn_arctan->sizePolicy().hasHeightForWidth());
        pBtn_arctan->setSizePolicy(sizePolicy);
        pBtn_arctan->setMinimumSize(QSize(35, 25));
        pBtn_arctan->setFont(font3);

        gridLayout->addWidget(pBtn_arctan, 5, 2, 1, 1);

        pBtn_tan = new QPushButton(centralWidget);
        pBtn_tan->setObjectName(QStringLiteral("pBtn_tan"));
        sizePolicy.setHeightForWidth(pBtn_tan->sizePolicy().hasHeightForWidth());
        pBtn_tan->setSizePolicy(sizePolicy);
        pBtn_tan->setMinimumSize(QSize(35, 25));
        pBtn_tan->setFont(font1);

        gridLayout->addWidget(pBtn_tan, 5, 3, 1, 1);

        pBtn_4 = new QPushButton(centralWidget);
        pBtn_4->setObjectName(QStringLiteral("pBtn_4"));
        sizePolicy.setHeightForWidth(pBtn_4->sizePolicy().hasHeightForWidth());
        pBtn_4->setSizePolicy(sizePolicy);
        pBtn_4->setMinimumSize(QSize(35, 25));
        pBtn_4->setFont(font1);

        gridLayout->addWidget(pBtn_4, 5, 4, 1, 1);

        pBtn_5 = new QPushButton(centralWidget);
        pBtn_5->setObjectName(QStringLiteral("pBtn_5"));
        sizePolicy.setHeightForWidth(pBtn_5->sizePolicy().hasHeightForWidth());
        pBtn_5->setSizePolicy(sizePolicy);
        pBtn_5->setMinimumSize(QSize(35, 25));
        pBtn_5->setFont(font1);

        gridLayout->addWidget(pBtn_5, 5, 5, 1, 1);

        pBtn_6 = new QPushButton(centralWidget);
        pBtn_6->setObjectName(QStringLiteral("pBtn_6"));
        sizePolicy.setHeightForWidth(pBtn_6->sizePolicy().hasHeightForWidth());
        pBtn_6->setSizePolicy(sizePolicy);
        pBtn_6->setMinimumSize(QSize(35, 25));
        pBtn_6->setFont(font1);

        gridLayout->addWidget(pBtn_6, 5, 6, 1, 1);

        pBtn_mul = new QPushButton(centralWidget);
        pBtn_mul->setObjectName(QStringLiteral("pBtn_mul"));
        sizePolicy.setHeightForWidth(pBtn_mul->sizePolicy().hasHeightForWidth());
        pBtn_mul->setSizePolicy(sizePolicy);
        pBtn_mul->setMinimumSize(QSize(35, 25));
        pBtn_mul->setFont(font1);

        gridLayout->addWidget(pBtn_mul, 5, 7, 1, 1);

        pBtn_lBracket = new QPushButton(centralWidget);
        pBtn_lBracket->setObjectName(QStringLiteral("pBtn_lBracket"));
        sizePolicy.setHeightForWidth(pBtn_lBracket->sizePolicy().hasHeightForWidth());
        pBtn_lBracket->setSizePolicy(sizePolicy);
        pBtn_lBracket->setMinimumSize(QSize(35, 25));
        pBtn_lBracket->setFont(font1);

        gridLayout->addWidget(pBtn_lBracket, 5, 8, 1, 1);

        pBtn_rbracket = new QPushButton(centralWidget);
        pBtn_rbracket->setObjectName(QStringLiteral("pBtn_rbracket"));
        sizePolicy.setHeightForWidth(pBtn_rbracket->sizePolicy().hasHeightForWidth());
        pBtn_rbracket->setSizePolicy(sizePolicy);
        pBtn_rbracket->setMinimumSize(QSize(35, 25));
        pBtn_rbracket->setFont(font1);

        gridLayout->addWidget(pBtn_rbracket, 5, 9, 1, 1);

        pBtn_square = new QPushButton(centralWidget);
        pBtn_square->setObjectName(QStringLiteral("pBtn_square"));
        sizePolicy.setHeightForWidth(pBtn_square->sizePolicy().hasHeightForWidth());
        pBtn_square->setSizePolicy(sizePolicy);
        pBtn_square->setMinimumSize(QSize(35, 25));
        pBtn_square->setFont(font1);

        gridLayout->addWidget(pBtn_square, 6, 0, 1, 1);

        pBtn_not = new QPushButton(centralWidget);
        pBtn_not->setObjectName(QStringLiteral("pBtn_not"));
        sizePolicy.setHeightForWidth(pBtn_not->sizePolicy().hasHeightForWidth());
        pBtn_not->setSizePolicy(sizePolicy);
        pBtn_not->setMinimumSize(QSize(35, 25));
        pBtn_not->setFont(font1);

        gridLayout->addWidget(pBtn_not, 6, 1, 1, 1);

        pBtn_log = new QPushButton(centralWidget);
        pBtn_log->setObjectName(QStringLiteral("pBtn_log"));
        sizePolicy.setHeightForWidth(pBtn_log->sizePolicy().hasHeightForWidth());
        pBtn_log->setSizePolicy(sizePolicy);
        pBtn_log->setMinimumSize(QSize(35, 25));
        pBtn_log->setFont(font1);

        gridLayout->addWidget(pBtn_log, 6, 2, 1, 1);

        pBtn_lg = new QPushButton(centralWidget);
        pBtn_lg->setObjectName(QStringLiteral("pBtn_lg"));
        sizePolicy.setHeightForWidth(pBtn_lg->sizePolicy().hasHeightForWidth());
        pBtn_lg->setSizePolicy(sizePolicy);
        pBtn_lg->setMinimumSize(QSize(35, 25));
        pBtn_lg->setFont(font1);

        gridLayout->addWidget(pBtn_lg, 6, 3, 1, 1);

        pBtn_1 = new QPushButton(centralWidget);
        pBtn_1->setObjectName(QStringLiteral("pBtn_1"));
        sizePolicy.setHeightForWidth(pBtn_1->sizePolicy().hasHeightForWidth());
        pBtn_1->setSizePolicy(sizePolicy);
        pBtn_1->setMinimumSize(QSize(35, 25));
        pBtn_1->setFont(font1);

        gridLayout->addWidget(pBtn_1, 6, 4, 1, 1);

        pBtn_2 = new QPushButton(centralWidget);
        pBtn_2->setObjectName(QStringLiteral("pBtn_2"));
        sizePolicy.setHeightForWidth(pBtn_2->sizePolicy().hasHeightForWidth());
        pBtn_2->setSizePolicy(sizePolicy);
        pBtn_2->setMinimumSize(QSize(35, 25));
        pBtn_2->setFont(font1);

        gridLayout->addWidget(pBtn_2, 6, 5, 1, 1);

        pBtn_3 = new QPushButton(centralWidget);
        pBtn_3->setObjectName(QStringLiteral("pBtn_3"));
        sizePolicy.setHeightForWidth(pBtn_3->sizePolicy().hasHeightForWidth());
        pBtn_3->setSizePolicy(sizePolicy);
        pBtn_3->setMinimumSize(QSize(35, 25));
        pBtn_3->setFont(font1);

        gridLayout->addWidget(pBtn_3, 6, 6, 1, 1);

        pBtn_sub = new QPushButton(centralWidget);
        pBtn_sub->setObjectName(QStringLiteral("pBtn_sub"));
        sizePolicy.setHeightForWidth(pBtn_sub->sizePolicy().hasHeightForWidth());
        pBtn_sub->setSizePolicy(sizePolicy);
        pBtn_sub->setMinimumSize(QSize(35, 25));
        pBtn_sub->setFont(font1);

        gridLayout->addWidget(pBtn_sub, 6, 7, 1, 1);

        pBtn_sqrt = new QPushButton(centralWidget);
        pBtn_sqrt->setObjectName(QStringLiteral("pBtn_sqrt"));
        sizePolicy.setHeightForWidth(pBtn_sqrt->sizePolicy().hasHeightForWidth());
        pBtn_sqrt->setSizePolicy(sizePolicy);
        pBtn_sqrt->setMinimumSize(QSize(35, 25));
        pBtn_sqrt->setFont(font3);

        gridLayout->addWidget(pBtn_sqrt, 7, 0, 1, 1);

        pBtn_sll = new QPushButton(centralWidget);
        pBtn_sll->setObjectName(QStringLiteral("pBtn_sll"));
        sizePolicy.setHeightForWidth(pBtn_sll->sizePolicy().hasHeightForWidth());
        pBtn_sll->setSizePolicy(sizePolicy);
        pBtn_sll->setMinimumSize(QSize(35, 25));
        pBtn_sll->setFont(font1);

        gridLayout->addWidget(pBtn_sll, 7, 1, 1, 1);

        pBtn_sra = new QPushButton(centralWidget);
        pBtn_sra->setObjectName(QStringLiteral("pBtn_sra"));
        sizePolicy.setHeightForWidth(pBtn_sra->sizePolicy().hasHeightForWidth());
        pBtn_sra->setSizePolicy(sizePolicy);
        pBtn_sra->setMinimumSize(QSize(35, 25));
        pBtn_sra->setFont(font1);

        gridLayout->addWidget(pBtn_sra, 7, 2, 1, 1);

        pBtn_ln = new QPushButton(centralWidget);
        pBtn_ln->setObjectName(QStringLiteral("pBtn_ln"));
        sizePolicy.setHeightForWidth(pBtn_ln->sizePolicy().hasHeightForWidth());
        pBtn_ln->setSizePolicy(sizePolicy);
        pBtn_ln->setMinimumSize(QSize(35, 25));
        pBtn_ln->setFont(font1);

        gridLayout->addWidget(pBtn_ln, 7, 3, 1, 1);

        pBtn_0 = new QPushButton(centralWidget);
        pBtn_0->setObjectName(QStringLiteral("pBtn_0"));
        sizePolicy.setHeightForWidth(pBtn_0->sizePolicy().hasHeightForWidth());
        pBtn_0->setSizePolicy(sizePolicy);
        pBtn_0->setMinimumSize(QSize(35, 25));
        pBtn_0->setFont(font1);

        gridLayout->addWidget(pBtn_0, 7, 4, 1, 1);

        pBtn_dot = new QPushButton(centralWidget);
        pBtn_dot->setObjectName(QStringLiteral("pBtn_dot"));
        sizePolicy.setHeightForWidth(pBtn_dot->sizePolicy().hasHeightForWidth());
        pBtn_dot->setSizePolicy(sizePolicy);
        pBtn_dot->setMinimumSize(QSize(35, 25));
        pBtn_dot->setFont(font);

        gridLayout->addWidget(pBtn_dot, 7, 5, 1, 1);

        pBtn_percent = new QPushButton(centralWidget);
        pBtn_percent->setObjectName(QStringLiteral("pBtn_percent"));
        sizePolicy.setHeightForWidth(pBtn_percent->sizePolicy().hasHeightForWidth());
        pBtn_percent->setSizePolicy(sizePolicy);
        pBtn_percent->setMinimumSize(QSize(35, 25));
        pBtn_percent->setFont(font1);

        gridLayout->addWidget(pBtn_percent, 7, 6, 1, 1);

        pBtn_Add = new QPushButton(centralWidget);
        pBtn_Add->setObjectName(QStringLiteral("pBtn_Add"));
        sizePolicy.setHeightForWidth(pBtn_Add->sizePolicy().hasHeightForWidth());
        pBtn_Add->setSizePolicy(sizePolicy);
        pBtn_Add->setMinimumSize(QSize(35, 25));
        pBtn_Add->setFont(font1);

        gridLayout->addWidget(pBtn_Add, 7, 7, 1, 1);

        tBtn_function = new QToolButton(centralWidget);
        tBtn_function->setObjectName(QStringLiteral("tBtn_function"));
        sizePolicy.setHeightForWidth(tBtn_function->sizePolicy().hasHeightForWidth());
        tBtn_function->setSizePolicy(sizePolicy);
        tBtn_function->setMinimumSize(QSize(105, 25));
        tBtn_function->setFont(font1);
        tBtn_function->setPopupMode(QToolButton::InstantPopup);
        tBtn_function->setToolButtonStyle(Qt::ToolButtonTextOnly);
        tBtn_function->setAutoRaise(false);
        tBtn_function->setArrowType(Qt::DownArrow);

        gridLayout->addWidget(tBtn_function, 2, 0, 1, 3);

        pBtn_AC = new QPushButton(centralWidget);
        pBtn_AC->setObjectName(QStringLiteral("pBtn_AC"));
        sizePolicy.setHeightForWidth(pBtn_AC->sizePolicy().hasHeightForWidth());
        pBtn_AC->setSizePolicy(sizePolicy);
        pBtn_AC->setMinimumSize(QSize(70, 25));
        pBtn_AC->setFont(font2);

        gridLayout->addWidget(pBtn_AC, 2, 8, 1, 2);

        pBtn_equal = new QPushButton(centralWidget);
        pBtn_equal->setObjectName(QStringLiteral("pBtn_equal"));
        sizePolicy.setHeightForWidth(pBtn_equal->sizePolicy().hasHeightForWidth());
        pBtn_equal->setSizePolicy(sizePolicy);
        pBtn_equal->setMinimumSize(QSize(35, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(36);
        pBtn_equal->setFont(font5);

        gridLayout->addWidget(pBtn_equal, 6, 8, 2, 2);

        frame_screen = new QFrame(centralWidget);
        frame_screen->setObjectName(QStringLiteral("frame_screen"));
        sizePolicy.setHeightForWidth(frame_screen->sizePolicy().hasHeightForWidth());
        frame_screen->setSizePolicy(sizePolicy);
        frame_screen->setMinimumSize(QSize(0, 160));
        frame_screen->setFrameShape(QFrame::Box);
        frame_screen->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_screen);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Input = new QLineEdit(frame_screen);
        lineEdit_Input->setObjectName(QStringLiteral("lineEdit_Input"));
        sizePolicy.setHeightForWidth(lineEdit_Input->sizePolicy().hasHeightForWidth());
        lineEdit_Input->setSizePolicy(sizePolicy);
        lineEdit_Input->setFont(font2);
        lineEdit_Input->setAutoFillBackground(false);
        lineEdit_Input->setFrame(false);

        verticalLayout->addWidget(lineEdit_Input);

        lineEdit_Result = new QLineEdit(frame_screen);
        lineEdit_Result->setObjectName(QStringLiteral("lineEdit_Result"));
        sizePolicy.setHeightForWidth(lineEdit_Result->sizePolicy().hasHeightForWidth());
        lineEdit_Result->setSizePolicy(sizePolicy);
        lineEdit_Result->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_Result->setFont(font2);
        lineEdit_Result->setLayoutDirection(Qt::LeftToRight);
        lineEdit_Result->setFrame(false);
        lineEdit_Result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_Result->setReadOnly(true);
        lineEdit_Result->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEdit_Result);


        gridLayout->addWidget(frame_screen, 0, 0, 1, 10);

        widget_options = new QWidget(centralWidget);
        widget_options->setObjectName(QStringLiteral("widget_options"));
        horizontalLayout_3 = new QHBoxLayout(widget_options);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(widget_options);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        frame_calPattern = new QFrame(splitter);
        frame_calPattern->setObjectName(QStringLiteral("frame_calPattern"));
        sizePolicy.setHeightForWidth(frame_calPattern->sizePolicy().hasHeightForWidth());
        frame_calPattern->setSizePolicy(sizePolicy);
        frame_calPattern->setFrameShape(QFrame::Box);
        frame_calPattern->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_calPattern);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rBtn_sciCal = new QRadioButton(frame_calPattern);
        rBtn_sciCal->setObjectName(QStringLiteral("rBtn_sciCal"));
        sizePolicy.setHeightForWidth(rBtn_sciCal->sizePolicy().hasHeightForWidth());
        rBtn_sciCal->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(8);
        rBtn_sciCal->setFont(font6);
        rBtn_sciCal->setChecked(true);
        rBtn_sciCal->setAutoRepeat(false);
        rBtn_sciCal->setAutoExclusive(true);

        horizontalLayout->addWidget(rBtn_sciCal);

        rBtn_bin = new QRadioButton(frame_calPattern);
        rBtn_bin->setObjectName(QStringLiteral("rBtn_bin"));
        sizePolicy.setHeightForWidth(rBtn_bin->sizePolicy().hasHeightForWidth());
        rBtn_bin->setSizePolicy(sizePolicy);
        rBtn_bin->setFont(font6);

        horizontalLayout->addWidget(rBtn_bin);

        rBtn_oct = new QRadioButton(frame_calPattern);
        rBtn_oct->setObjectName(QStringLiteral("rBtn_oct"));
        sizePolicy.setHeightForWidth(rBtn_oct->sizePolicy().hasHeightForWidth());
        rBtn_oct->setSizePolicy(sizePolicy);
        rBtn_oct->setFont(font6);

        horizontalLayout->addWidget(rBtn_oct);

        rBtn_hex = new QRadioButton(frame_calPattern);
        rBtn_hex->setObjectName(QStringLiteral("rBtn_hex"));
        sizePolicy.setHeightForWidth(rBtn_hex->sizePolicy().hasHeightForWidth());
        rBtn_hex->setSizePolicy(sizePolicy);
        rBtn_hex->setFont(font6);

        horizontalLayout->addWidget(rBtn_hex);

        rBtn_mix = new QRadioButton(frame_calPattern);
        rBtn_mix->setObjectName(QStringLiteral("rBtn_mix"));
        sizePolicy.setHeightForWidth(rBtn_mix->sizePolicy().hasHeightForWidth());
        rBtn_mix->setSizePolicy(sizePolicy);
        rBtn_mix->setFont(font6);

        horizontalLayout->addWidget(rBtn_mix);

        splitter->addWidget(frame_calPattern);
        frame_tri = new QFrame(splitter);
        frame_tri->setObjectName(QStringLiteral("frame_tri"));
        sizePolicy.setHeightForWidth(frame_tri->sizePolicy().hasHeightForWidth());
        frame_tri->setSizePolicy(sizePolicy);
        frame_tri->setFrameShape(QFrame::Box);
        frame_tri->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_tri);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rBtn_angle = new QRadioButton(frame_tri);
        rBtn_angle->setObjectName(QStringLiteral("rBtn_angle"));
        sizePolicy.setHeightForWidth(rBtn_angle->sizePolicy().hasHeightForWidth());
        rBtn_angle->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(11);
        rBtn_angle->setFont(font7);
        rBtn_angle->setChecked(true);

        horizontalLayout_2->addWidget(rBtn_angle);

        rBtn_radian = new QRadioButton(frame_tri);
        rBtn_radian->setObjectName(QStringLiteral("rBtn_radian"));
        sizePolicy.setHeightForWidth(rBtn_radian->sizePolicy().hasHeightForWidth());
        rBtn_radian->setSizePolicy(sizePolicy);
        rBtn_radian->setFont(font7);

        horizontalLayout_2->addWidget(rBtn_radian);

        splitter->addWidget(frame_tri);

        horizontalLayout_3->addWidget(splitter);


        gridLayout->addWidget(widget_options, 1, 0, 1, 10);

        CalculatorFX->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalculatorFX);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        CalculatorFX->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(instruction);

        retranslateUi(CalculatorFX);

        QMetaObject::connectSlotsByName(CalculatorFX);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorFX)
    {
        CalculatorFX->setWindowTitle(QApplication::translate("CalculatorFX", "CalculatorFX", Q_NULLPTR));
        instruction->setText(QApplication::translate("CalculatorFX", "\346\237\245\347\234\213\350\257\264\346\230\216", Q_NULLPTR));
        pBtn_comma->setText(QApplication::translate("CalculatorFX", ",", Q_NULLPTR));
        pBtn_0b->setText(QApplication::translate("CalculatorFX", "0b", Q_NULLPTR));
        pBtn_0x->setText(QApplication::translate("CalculatorFX", "0x", Q_NULLPTR));
        pBtn_Ans->setText(QApplication::translate("CalculatorFX", "Ans", Q_NULLPTR));
        pBtn_DEL->setText(QApplication::translate("CalculatorFX", "DEL", Q_NULLPTR));
        pBtn_pi->setText(QApplication::translate("CalculatorFX", "\317\200", Q_NULLPTR));
        pBtn_and->setText(QApplication::translate("CalculatorFX", "and", Q_NULLPTR));
        pBtn_arcsin->setText(QApplication::translate("CalculatorFX", "arcsin", Q_NULLPTR));
        pBtn_sin->setText(QApplication::translate("CalculatorFX", "sin", Q_NULLPTR));
        pBtn_A->setText(QApplication::translate("CalculatorFX", "A", Q_NULLPTR));
        pBtn_B->setText(QApplication::translate("CalculatorFX", "B", Q_NULLPTR));
        pBtn_C->setText(QApplication::translate("CalculatorFX", "C", Q_NULLPTR));
        pBtn_D->setText(QApplication::translate("CalculatorFX", "D", Q_NULLPTR));
        pBtn_E->setText(QApplication::translate("CalculatorFX", "E", Q_NULLPTR));
        pBtn_F->setText(QApplication::translate("CalculatorFX", "F", Q_NULLPTR));
        pBtn_e->setText(QApplication::translate("CalculatorFX", "e", Q_NULLPTR));
        pBtn_or->setText(QApplication::translate("CalculatorFX", "or", Q_NULLPTR));
        pBtn_arccos->setText(QApplication::translate("CalculatorFX", "arccos", Q_NULLPTR));
        pBtn_cos->setText(QApplication::translate("CalculatorFX", "cos", Q_NULLPTR));
        pBtn_7->setText(QApplication::translate("CalculatorFX", "7", Q_NULLPTR));
        pBtn_8->setText(QApplication::translate("CalculatorFX", "8", Q_NULLPTR));
        pBtn_9->setText(QApplication::translate("CalculatorFX", "9", Q_NULLPTR));
        pBtn_div->setText(QApplication::translate("CalculatorFX", "/", Q_NULLPTR));
        pBtn_mod->setText(QApplication::translate("CalculatorFX", "mod", Q_NULLPTR));
        pBtn_power->setText(QApplication::translate("CalculatorFX", "^", Q_NULLPTR));
        pBtn_abs->setText(QApplication::translate("CalculatorFX", "abs", Q_NULLPTR));
        pBtn_xor->setText(QApplication::translate("CalculatorFX", "xor", Q_NULLPTR));
        pBtn_arctan->setText(QApplication::translate("CalculatorFX", "arctan", Q_NULLPTR));
        pBtn_tan->setText(QApplication::translate("CalculatorFX", "tan", Q_NULLPTR));
        pBtn_4->setText(QApplication::translate("CalculatorFX", "4", Q_NULLPTR));
        pBtn_5->setText(QApplication::translate("CalculatorFX", "5", Q_NULLPTR));
        pBtn_6->setText(QApplication::translate("CalculatorFX", "6", Q_NULLPTR));
        pBtn_mul->setText(QApplication::translate("CalculatorFX", "*", Q_NULLPTR));
        pBtn_lBracket->setText(QApplication::translate("CalculatorFX", "(", Q_NULLPTR));
        pBtn_rbracket->setText(QApplication::translate("CalculatorFX", ")", Q_NULLPTR));
        pBtn_square->setText(QApplication::translate("CalculatorFX", "^2", Q_NULLPTR));
        pBtn_not->setText(QApplication::translate("CalculatorFX", "not", Q_NULLPTR));
        pBtn_log->setText(QApplication::translate("CalculatorFX", "log", Q_NULLPTR));
        pBtn_lg->setText(QApplication::translate("CalculatorFX", "lg", Q_NULLPTR));
        pBtn_1->setText(QApplication::translate("CalculatorFX", "1", Q_NULLPTR));
        pBtn_2->setText(QApplication::translate("CalculatorFX", "2", Q_NULLPTR));
        pBtn_3->setText(QApplication::translate("CalculatorFX", "3", Q_NULLPTR));
        pBtn_sub->setText(QApplication::translate("CalculatorFX", "-", Q_NULLPTR));
        pBtn_sqrt->setText(QApplication::translate("CalculatorFX", "sqrt", Q_NULLPTR));
        pBtn_sll->setText(QApplication::translate("CalculatorFX", "<<", Q_NULLPTR));
        pBtn_sra->setText(QApplication::translate("CalculatorFX", ">>", Q_NULLPTR));
        pBtn_ln->setText(QApplication::translate("CalculatorFX", "ln", Q_NULLPTR));
        pBtn_0->setText(QApplication::translate("CalculatorFX", "0", Q_NULLPTR));
        pBtn_dot->setText(QApplication::translate("CalculatorFX", ".", Q_NULLPTR));
        pBtn_percent->setText(QApplication::translate("CalculatorFX", "%", Q_NULLPTR));
        pBtn_Add->setText(QApplication::translate("CalculatorFX", "+", Q_NULLPTR));
        tBtn_function->setText(QApplication::translate("CalculatorFX", "\346\226\271\347\250\213\344\270\216\347\211\271\346\256\212\345\207\275\346\225\260", Q_NULLPTR));
        pBtn_AC->setText(QApplication::translate("CalculatorFX", "AC", Q_NULLPTR));
        pBtn_equal->setText(QApplication::translate("CalculatorFX", "=", Q_NULLPTR));
        rBtn_sciCal->setText(QApplication::translate("CalculatorFX", "\347\247\221\345\255\246\350\256\241\347\256\227", Q_NULLPTR));
        rBtn_bin->setText(QApplication::translate("CalculatorFX", "\344\272\214\350\277\233\345\210\266", Q_NULLPTR));
        rBtn_oct->setText(QApplication::translate("CalculatorFX", "\345\205\253\350\277\233\345\210\266", Q_NULLPTR));
        rBtn_hex->setText(QApplication::translate("CalculatorFX", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR));
        rBtn_mix->setText(QApplication::translate("CalculatorFX", "\346\267\267\345\220\210\350\277\233\345\210\266", Q_NULLPTR));
        rBtn_angle->setText(QApplication::translate("CalculatorFX", "\350\247\222\345\272\246\345\210\266", Q_NULLPTR));
        rBtn_radian->setText(QApplication::translate("CalculatorFX", "\345\274\247\345\272\246\345\210\266", Q_NULLPTR));
        menu->setTitle(QApplication::translate("CalculatorFX", "\344\275\277\347\224\250\350\257\264\346\230\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalculatorFX: public Ui_CalculatorFX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORFX_H
