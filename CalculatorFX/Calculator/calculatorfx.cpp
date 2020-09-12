#include "calculatorfx.h"
#include "ui_calculatorfx.h"
//#include <QToolButton>
//#include <QPushButton>
#include <QDebug>
CalculatorFX::CalculatorFX(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorFX)
{
    ui->setupUi(this);
//给函数toolButton添加菜单
    QMenu *menu_function=new QMenu();
    QAction *action1 = menu_function -> addAction("                      1                      ");
    QAction *action2 = menu_function -> addAction("                      2                      ");
    ui -> tBtn_function -> setMenu(menu_function);
    calPattern_pre="科学计算";
    tri_pre="角度制";
    cal_complete=false;
    connectAllSlots();
}

CalculatorFX::~CalculatorFX()
{
    delete ui;
}

void CalculatorFX::connectAllSlots(){
    QPushButton *opNormal_restart[22]={
        ui->pBtn_0,     ui->pBtn_1,         ui->pBtn_2,         ui->pBtn_3,         ui->pBtn_4,
        ui->pBtn_5,     ui->pBtn_6,         ui->pBtn_7,         ui->pBtn_8,         ui->pBtn_9,
        ui->pBtn_A,     ui->pBtn_B,         ui->pBtn_C,         ui->pBtn_D,         ui->pBtn_E,
        ui->pBtn_F,     ui->pBtn_pi,        ui->pBtn_e,         ui->pBtn_lBracket,  ui->pBtn_rbracket,
        ui->pBtn_dot,   ui->pBtn_not
    };

    QPushButton *opNormal_continue[13]={
        ui->pBtn_Add,   ui->pBtn_sub,       ui->pBtn_mul,       ui->pBtn_div,       ui->pBtn_mod,
        ui->pBtn_power, ui->pBtn_square,    ui->pBtn_percent,   ui->pBtn_and,       ui->pBtn_or,
        ui->pBtn_xor,   ui->pBtn_sll,       ui->pBtn_sra
    };

    QPushButton *opFunction[11]={
        ui->pBtn_sin,       ui->pBtn_cos,   ui->pBtn_tan,   ui->pBtn_arcsin,    ui->pBtn_arccos,
        ui->pBtn_arctan,    ui->pBtn_log,   ui->pBtn_lg,    ui->pBtn_ln,        ui->pBtn_sqrt,
        ui->pBtn_abs
    };

    QRadioButton *optionCal[5]={
        ui->rBtn_sciCal,    ui->rBtn_bin,   ui->rBtn_oct,   ui->rBtn_hex,   ui->rBtn_mix
    };

    QRadioButton *optionTri[2]={
        ui->rBtn_angle,     ui->rBtn_radian
    };

    for(auto btn : opNormal_restart){
        connect(btn, &QPushButton::clicked, this, &CalculatorFX::opNormal_restart_clicked);
    }

    for(auto btn : opNormal_continue){
        connect(btn, &QPushButton::clicked, this, &CalculatorFX::opNormal_continue_clicked);
    }

    for(auto btn : opFunction){
        connect(btn, &QPushButton::clicked, this, &CalculatorFX::opFunction_clicked);
    }

    connect(ui->pBtn_equal, &QPushButton::clicked, this, &CalculatorFX::equal_clicked);

    connect(ui->pBtn_Ans, &QPushButton::clicked, this, &CalculatorFX::Ans_clicked);

    connect(ui->pBtn_DEL, &QPushButton::clicked, this, &CalculatorFX::DEL_clicked);

    connect(ui->pBtn_AC, &QPushButton::clicked, this, &CalculatorFX::AC_clicked);

    for(auto btn : optionCal){
        connect(btn, &QRadioButton::toggled, this, &CalculatorFX::optionCal_toggled);
    }

    for(auto btn : optionTri){
        connect(btn, &QRadioButton::toggled, this, &CalculatorFX::optionTri_toggled);
    }
}

void CalculatorFX::opNormal_restart_clicked(){
    ;
}

void CalculatorFX::opNormal_continue_clicked(){
    ;
}

void CalculatorFX::opFunction_clicked(){
    ;
}

void CalculatorFX::equal_clicked(){
    ;
}

void CalculatorFX::Ans_clicked(){
    ;
}

void CalculatorFX::DEL_clicked(){
    ;
}

void CalculatorFX::AC_clicked(){
    ;
}

void CalculatorFX::optionCal_toggled(){
    QRadioButton* rBtn = qobject_cast<QRadioButton*>(sender());
    if(rBtn->isChecked()){
        ;

    }
    calPattern_pre=rBtn->text();
}

void CalculatorFX::optionTri_toggled(){
    QRadioButton* rBtn = qobject_cast<QRadioButton*>(sender());
    if(rBtn->isChecked()){
        ;

    }
    tri_pre=rBtn->text();
}



