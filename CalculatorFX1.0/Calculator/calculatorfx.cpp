#include "calculatorfx.h"
#include "ui_calculatorfx.h"
//#include <QToolButton>
//#include <QPushButton>
#include <QMenu>
#include <QDebug>
#include <QMessageBox>
#include <QtMath>
#include <QMap>
#include <cmath>
CalculatorFX::CalculatorFX(QWidget *parent) ://科学计数法，ans
    QMainWindow(parent),
    ui(new Ui::CalculatorFX)
{
    ui->setupUi(this);
    ui->lineEdit_Input->installEventFilter(this);
//给函数toolButton添加菜单
    QMenu *menu_function=new QMenu();
    CalculatorFX::action_cmp = menu_function->addAction("对任意两个进制数字作比较");//to be improved
    CalculatorFX::action_comDiv = menu_function->addAction("求公约数");
    CalculatorFX::action_lowComMul = menu_function->addAction("求最小公倍数");
    CalculatorFX::action_equ11 = menu_function->addAction("一元一次方程求解");
    CalculatorFX::action_equ12 = menu_function->addAction("一元二次方程求解");
    CalculatorFX::action_equInverse = menu_function->addAction("反比例函数方程求解");
    CalculatorFX::action_equExp = menu_function->addAction("指数函数方程求解");
    CalculatorFX::action_equLog = menu_function->addAction("对数函数方程求解");
    ui->tBtn_function->setMenu(menu_function);
    ui->lineEdit_Input->setFocus();
    calPattern_current="科学计算";
    tri_current="角度制";
    cal_complete=false;
    Ans="@";
    flag_arc=false;
    functionFlag=0;
    errorFlag=0;
    pi.setNum(qAcos(-1), 'G', 11);
    e.setNum(qExp(1), 'G', 11);
    connectAllSlots();
}

CalculatorFX::~CalculatorFX()
{
    delete ui;
}
//点击清空
bool CalculatorFX::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->lineEdit_Input)
    {
        if(event->type()==QEvent::MouseButtonRelease&&cal_complete)
        {
            ui->lineEdit_Result->clear();
            cal_complete=false;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void CalculatorFX::connectAllSlots(){
    QPushButton *opNormal_restart[25]={
        ui->pBtn_0,     ui->pBtn_1,         ui->pBtn_2,         ui->pBtn_3,         ui->pBtn_4,
        ui->pBtn_5,     ui->pBtn_6,         ui->pBtn_7,         ui->pBtn_8,         ui->pBtn_9,
        ui->pBtn_A,     ui->pBtn_B,         ui->pBtn_C,         ui->pBtn_D,         ui->pBtn_E,
        ui->pBtn_F,     ui->pBtn_pi,        ui->pBtn_e,         ui->pBtn_lBracket,  ui->pBtn_rbracket,
        ui->pBtn_dot,   ui->pBtn_not,       ui->pBtn_comma,     ui->pBtn_0b,        ui->pBtn_0x
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

    connect(CalculatorFX::action_cmp, &QAction::triggered, this, &CalculatorFX::cmp_triggered);

    connect(CalculatorFX::action_comDiv, &QAction::triggered, this, &CalculatorFX::comDiv_triggered);

    connect(CalculatorFX::action_lowComMul, &QAction::triggered, this, &CalculatorFX::lowComMul_triggered);

    connect(CalculatorFX::action_equ11, &QAction::triggered, this, &CalculatorFX::equ11_triggered);

    connect(CalculatorFX::action_equ12, &QAction::triggered, this, &CalculatorFX::equ12_triggered);

    connect(CalculatorFX::action_equInverse, &QAction::triggered, this, &CalculatorFX::equInverse_triggered);

    connect(CalculatorFX::action_equExp, &QAction::triggered, this, &CalculatorFX::equExp_triggered);

    connect(CalculatorFX::action_equLog, &QAction::triggered, this, &CalculatorFX::equLog_triggered);
}

void CalculatorFX::opNormal_restart_clicked(){
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    int temp_position=ui->lineEdit_Input->cursorPosition();
    QString temp=ui->lineEdit_Input->text().insert(temp_position,pBtn->text());
    ui->lineEdit_Input->setText(temp);
    ui->lineEdit_Input->setCursorPosition(temp_position+pBtn->text().size());
    ui->lineEdit_Input->setFocus();
    cal_complete=false;
}

void CalculatorFX::opNormal_continue_clicked(){
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
    if(cal_complete==true){
        ui->lineEdit_Input->setText("Ans");
        ui->lineEdit_Result->clear();
    }
    int temp_position=ui->lineEdit_Input->cursorPosition();
    QString temp=ui->lineEdit_Input->text().insert(temp_position,pBtn->text());
    ui->lineEdit_Input->setText(temp);
    ui->lineEdit_Input->setCursorPosition(temp_position+pBtn->text().size());
    ui->lineEdit_Input->setFocus();
    cal_complete=false;
}

void CalculatorFX::opFunction_clicked(){
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    int temp_position=ui->lineEdit_Input->cursorPosition();
    QString addition=pBtn->text()+"(";
    QString temp=ui->lineEdit_Input->text().insert(temp_position,addition);
    ui->lineEdit_Input->setText(temp);
    ui->lineEdit_Input->setCursorPosition(temp_position+addition.size());
    ui->lineEdit_Input->setFocus();
    cal_complete=false;
}

void CalculatorFX::equal_clicked(){
    if(CalculatorFX::functionFlag==1){
        fun_cmp(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==2){
        fun_comDiv(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==3){
        fun_lowComMul(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==4){
        fun_equ11(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==5){
        fun_equ12(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==6){
        fun_equInverse(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==7){
        fun_equExp(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    if(CalculatorFX::functionFlag==8){
        fun_equLog(ui->lineEdit_Input->text());
        if(errorFlag==1){
            errorFlag=0;
            QMessageBox::warning(this,"warning","语法错误");
            return;
        }
        if(errorFlag==2){
            errorFlag=0;
            QMessageBox::warning(this,"warning","数学错误");
            return;
        }
        cal_complete=true;
        return;
    }
    CalculatorFX::functionFlag=0;
    semi_stack.clear();
    QString sys_temp=CalculatorFX::sysPre(calPattern_current,ui->lineEdit_Input->text());
    if(errorFlag==1){
        errorFlag=0;
        QMessageBox::warning(this,"warning","语法错误");
        return;
    }
    if(errorFlag==2){
        errorFlag=0;
        QMessageBox::warning(this,"warning","数学错误");
        return;
    }
    CalculatorFX::preprocessing(sys_temp,semi_stack);
    if(errorFlag==1){
        errorFlag=0;
        QMessageBox::warning(this,"warning","语法错误");
        return;
    }
    if(errorFlag==2){
        errorFlag=0;
        QMessageBox::warning(this,"warning","数学错误");
        return;
    }
    QString result_dec=CalculatorFX::calculate(semi_stack, calPattern_current, tri_current);
    if(errorFlag==1){
        errorFlag=0;
        QMessageBox::warning(this,"warning","语法错误");
        return;
    }
    if(errorFlag==2){
        errorFlag=0;
        QMessageBox::warning(this,"warning","数学错误");
        return;
    }
    QString result_done=CalculatorFX::sysConversion("科学计算", calPattern_current, result_dec);
    if(errorFlag==1){
        errorFlag=0;
        QMessageBox::warning(this,"warning","语法错误");
        return;
    }
    if(errorFlag==2){
        errorFlag=0;
        QMessageBox::warning(this,"warning","数学错误");
        return;
    }
    ui->lineEdit_Result->setText(result_done);
    Ans=result_dec;
    cal_complete=true;
}
//warning,continue
void CalculatorFX::Ans_clicked(){
    if(Ans=="@"){
        QMessageBox::warning(this,"warning","暂无Ans");
        return;
    }
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    int temp_position=ui->lineEdit_Input->cursorPosition();
    QString temp=ui->lineEdit_Input->text().insert(temp_position,ui->pBtn_Ans->text());
    ui->lineEdit_Input->setText(temp);
    ui->lineEdit_Input->setCursorPosition(temp_position+ui->pBtn_Ans->text().size());
    ui->lineEdit_Input->setFocus();
    cal_complete=false;
}

void CalculatorFX::DEL_clicked(){
    if(cal_complete==true){
        return;
    }
    ui->lineEdit_Input->backspace();
    ui->lineEdit_Input->setFocus();
}

void CalculatorFX::AC_clicked(){
    ui->lineEdit_Input->clear();
    ui->lineEdit_Result->clear();
    ui->lineEdit_Input->setFocus();
    cal_complete=false;
}
//to be improved//toggled
void CalculatorFX::optionCal_toggled(){
    QRadioButton* rBtn = qobject_cast<QRadioButton*>(sender());
    if(rBtn->isChecked()){
        if(cal_complete){
            ui->lineEdit_Result->setText(CalculatorFX::sysConversion(calPattern_current,rBtn->text(),ui->lineEdit_Result->text()));
        }
        else{
            ui->lineEdit_Input->setFocus();
        }
        calPattern_current=rBtn->text();
    }   
}

void CalculatorFX::optionTri_toggled(){
    QRadioButton* rBtn = qobject_cast<QRadioButton*>(sender());
    if(rBtn->isChecked()){
        if(!cal_complete){
            ui->lineEdit_Input->setFocus();
        }
        tri_current=rBtn->text();
    }   
}

QString CalculatorFX::sysConversion(QString sys_current,QString sys_target,QString num){
    if(sys_current==sys_target)
        return num;
    int temp;
    bool ok;
    QString newNum;
    if(sys_current=="科学计算")
        temp=num.toInt(&ok,10);
    if(sys_current=="二进制")
        temp=num.toInt(&ok,2);
    if(sys_current=="八进制")
        temp=num.toInt(&ok,8);
    if(sys_current=="十六进制")
        temp=num.toInt(&ok,16);
    if(sys_current=="混合进制"){
        if(num.startsWith("0b")){
            num.remove(0, 2);
            temp=num.toInt(&ok,2);
        }
        else
            temp=num.toInt(&ok,0);
    }
    if(ok==false){
        errorFlag=1;
        return "error1";
    }
    if(sys_target=="科学计算")
        return newNum.setNum(temp,10);
    if(sys_target=="二进制")
        return newNum.setNum(temp,2);
    if(sys_target=="八进制")
        return newNum.setNum(temp,8);
    if(sys_target=="十六进制")
        return newNum.setNum(temp,16);
    if(sys_target=="混合进制"){
        if(sys_current=="科学计算")
            return num;
        if(sys_current=="二进制")
            return "0b"+num;
        if(sys_current=="八进制")
            return "0"+num;
        if(sys_current=="十六进制")
            return "0x"+num;
    }
    errorFlag=1;
    return "error1";
}

QString CalculatorFX::triConversion(QString tri_target,QString num){
    bool ok;
    double temp=num.toDouble(&ok);
    if(ok==false)
        return "error";
    if(tri_target=="角度制")
        temp=qRadiansToDegrees(temp);
    if(tri_target=="弧度制")
        temp=qDegreesToRadians(temp);
    QString newNum;
    return newNum.setNum(temp, 'G', 11);
}
//支持E
QString CalculatorFX::sysPre(QString sys_current,QString expression){
    if(sys_current=="科学计算")
        return expression;
    expression.replace("Ans", "ans");
    expression.replace("xor", "Xor");
    for(int i=0;expression[i]!='\0';){
        int i1=i+1;
        if(expression[i].isDigit()||(expression[i]>='A'&&expression[i]<='F')||expression[i]=='b'||expression[i]=='x'){
            for(i1=i+1;expression[i1].isDigit()||(expression[i1]>='A'&&expression[i1]<='F')||expression[i1]=='b'||expression[i1]=='x';++i1);
            QString exp_temp=expression.mid(i,i1-i);
            exp_temp=CalculatorFX::sysConversion(sys_current, "科学计算", exp_temp);
            if(errorFlag==1){
                return "error1";
            }
            if(errorFlag==2){
                return "error1";
            }
            expression.replace(i,i1-i,exp_temp);
            i=i+exp_temp.length()+1;
        }
        else{
            ++i;
        }
    }
    expression.replace("ans", "Ans");
    expression.replace("Xor", "xor");
    return expression;
}

void CalculatorFX::preprocessing(QString expression, QVector<QString>& semi){
    for(int i=0;expression[i]!='\0';){
        if(expression[i]=='E'){
            int i1=0,i2=0;
            for(i1=i-1;i1>=0&&(expression[i1].isDigit()||expression[i1]=='.');--i1);
            if(expression[i+1]=='+'||expression[i+1]=='-'||expression[i+1].isDigit())
                for(i2=i+2;expression[i2].isDigit();++i2);
            QString temp1=expression.mid(i1+1,i2-i1-1);
            if(temp1.isEmpty()){
                errorFlag=1;
                return;
            }
            bool ok;
            double temp_num=temp1.toDouble(&ok);
            if(ok==false){
                errorFlag=1;
                return;
            }
            temp1.setNum(temp_num, 'f', 11);
            expression.replace(i1+1,i2-i1-1,temp1);
            i=0;
        }
        else
            ++i;
    }
    while(expression.contains("-+")||expression.contains("+-")||expression.contains("++")||expression.contains("--")){
        expression.replace("+-","-");
        expression.replace("-+","-");
        expression.replace("++","+");
        expression.replace("--","+");
    }
    CalculatorFX::stack_pre(expression, semi);
    if(errorFlag==1){
        return ;
    }
    if(errorFlag==2){
        return ;
    }
    CalculatorFX::sign_pre(semi);
    if(errorFlag==1){
        return ;
    }
    if(errorFlag==2){
        return ;
    }
    CalculatorFX::omittedMul_pre(semi);
    if(errorFlag==1){
        return ;
    }
    if(errorFlag==2){
        return ;
    }
    for(int i=0;i<semi.length();++i){
        if(semi[i]=="Ans"){
            double temp=Ans.toDouble();
            QString temp_str;
            temp_str.setNum(temp, 'f', 11);
            semi[i]=temp_str;
        }
        if(semi[i]=="e"){
            semi[i]=e;
        }
        if(semi[i]=="π"){
            semi[i]=pi;
        }
    }
}
//精度 G 11
QString CalculatorFX::calculate(QVector<QString>& semi, QString sysCurrent, QString triCurrent){
    QVector<QString> postExp;
    CalculatorFX::toPost(semi, postExp);
    if(errorFlag==1){
        return "error1";
    }
    if(errorFlag==2){
        return "error2";
    }
    QString result=CalculatorFX::calculatePost(postExp, sysCurrent, triCurrent);
    if(errorFlag==1){
        return "error1";
    }
    if(errorFlag==2){
        return "error2";
    }
    return result;
}

void CalculatorFX::sign_pre(QVector<QString>& semi){
    QVector<QString> opNotice;
    opNotice<<"+"<<"-"<<"*"<<"/"<<"mod"<<"^"<<"<<"<<">>"<<"("<<"and"<<"or"<<"not"<<"xor";
    if(semi[0]=="+"||semi[0]=="-"){
        semi.push_front("0");
        semi.push_front("(");
        semi.insert(4,")");
    }
    for(int i=1;i<semi.length();++i){
        if(semi[i]=="+"||semi[i]=="-"){
            if(opNotice.contains(semi[i-1])){
                semi.insert(i,"0");
                semi.insert(i,"(");
                semi.insert(i+4,")");
                i=i+4;
            }
        }
    }
}

void CalculatorFX::omittedMul_pre(QVector<QString>& semi){
    QVector<QString> opNotice;
    opNotice<<"("<<"sin"<<"cos"<<"tan"<<"arcsin"<<"arccos"<<"arctan"<<"e"<<"π"<<"Ans"<<"log"<<"ln"<<"lg"<<"abs"<<"sqrt"<<"not";
    for(int i=0;i<semi.length()-1;++i){
        if(semi[i][0].isDigit()){
            if(opNotice.contains(semi[i+1])){
                semi.insert(i+1,"*");
                i=i+1;
            }
        }
    }
}

void CalculatorFX::stack_pre(QString expression, QVector<QString>& semi){
    QVector<QString> opSTD1, opSTD2, opSTD3, opSTD4, opSTD6;//27op
    opSTD1<<"+"<<"-"<<"*"<<"/"<<"^"<<"%"<<"("<<")"<<","<<"e"<<"π";
    opSTD2<<"or"<<"lg"<<"ln"<<"<<"<<">>";
    opSTD3<<"mod"<<"log"<<"abs"<<"and"<<"xor"<<"not"<<"sin"<<"cos"<<"tan"<<"Ans";
    opSTD4<<"sqrt";
    opSTD6<<"arcsin"<<"arccos"<<"arctan";
    for(int i=0;expression[i]!='\0';){
        if(expression[i].isDigit()){
            int i1;
            for(i1=i+1;expression[i1].isDigit()||expression[i1]=='.';++i1);
            semi.push_back(expression.mid(i,i1-i));
            i=i1;
        }
        else if(opSTD1.contains(expression.mid(i,1))){
            semi.push_back(expression.mid(i,1));
            ++i;
        }
        else if(opSTD2.contains(expression.mid(i,2))){
            semi.push_back(expression.mid(i,2));
            i=i+2;
        }
        else if(opSTD3.contains(expression.mid(i,3))){
            semi.push_back(expression.mid(i,3));
            i=i+3;
        }
        else if(opSTD4.contains(expression.mid(i,4))){
            semi.push_back(expression.mid(i,4));
            i=i+4;
        }
        else if(opSTD6.contains(expression.mid(i,6))){
            semi.push_back(expression.mid(i,6));
            i=i+6;
        }
        else{
            errorFlag=1;
            return;
        }
    }
}

void CalculatorFX::toPost(QVector<QString>& semi, QVector<QString>& postExp){
    QMap<QString, int> priority;
    priority["or"]=1;
    priority["xor"]=2;
    priority["and"]=3;
    priority[">>"]=4;
    priority["<<"]=4;
    priority["+"]=5;
    priority["-"]=5;
    priority["*"]=6;
    priority["/"]=6;
    priority["mod"]=6;
    priority["^"]=7;
    priority["not"]=8;//按位求反码
    priority["%"]=9;
    priority["sin"]=10;
    priority["cos"]=10;
    priority["tan"]=10;
    priority["arcsin"]=10;
    priority["arccos"]=10;
    priority["arctan"]=10;
    priority["log"]=10;
    priority["ln"]=10;
    priority["lg"]=10;
    priority["sqrt"]=10;
    priority["abs"]=10;
    priority["("]=10;
    QVector<QString> op_stack;
    for(int i=0;i<semi.length();++i){
        if(semi[i][0].isDigit())
            postExp.push_back(semi[i]);
        else if(semi[i]=="(")
            op_stack.push_back(semi[i]);
        else if(semi[i]==")"){
            while(op_stack.last()!="("){
                postExp.push_back(op_stack.last());
                op_stack.removeLast();
            }
            op_stack.removeLast();
        }
        else if(semi[i]==","){
            while(op_stack.last()!="("){
                postExp.push_back(op_stack.last());
                op_stack.removeLast();
            }
        }
        else{
            while(1){
                if(op_stack.isEmpty()||op_stack.last()=="("||priority[semi[i]]>priority[op_stack.last()]){
                    op_stack.push_back(semi[i]);
                    break;
                }
                postExp.push_back(op_stack.last());
                op_stack.removeLast();
            }
        }
    }
    while(!op_stack.isEmpty()){
        postExp.push_back(op_stack.last());
        op_stack.removeLast();
    }
}

QString CalculatorFX::calculatePost(QVector<QString>& postExp, QString sysCurrent, QString triCurrent){
    QVector<QString> resultExp;
    bool ok=true;
    if(sysCurrent=="科学计算"){
        for(int i=0;i<postExp.length();++i){
            if(postExp[i][0].isDigit())
                resultExp.push_back(postExp[i]);
            else{
                if(postExp[i]=="+"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2+temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="-"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2-temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="*"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);qDebug()<<"ok";
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2*temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="/"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1==0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2/temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="mod"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1==0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(fmod(temp2,temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="^"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qPow(temp2,temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="%"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp1/100, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="sin"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(triCurrent=="角度制")
                        temp1=qDegreesToRadians(temp1);
                    QString result1;
                    result1.setNum(qSin(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="cos"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(triCurrent=="角度制")
                        temp1=qDegreesToRadians(temp1);
                    QString result1;
                    result1.setNum(qCos(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="tan"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(triCurrent=="角度制")
                        temp1=qDegreesToRadians(temp1);
                    QString result1;
                    result1.setNum(qTan(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="arcsin"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1>1||temp1<-1){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    temp1=qAsin(temp1);
                    if(triCurrent=="角度制")
                        temp1=qRadiansToDegrees(temp1);
                    QString result1;
                    result1.setNum(temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="arccos"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1>1||temp1<-1){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    temp1=qAcos(temp1);
                    if(triCurrent=="角度制")
                        temp1=qRadiansToDegrees(temp1);
                    QString result1;
                    result1.setNum(temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="arctan"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    temp1=qAtan(temp1);
                    if(triCurrent=="角度制")
                        temp1=qRadiansToDegrees(temp1);
                    QString result1;
                    result1.setNum(temp1, 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="abs"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qFabs(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="sqrt"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1<0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qSqrt(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="ln"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1<=0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qLn(temp1), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="lg"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1<=0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qLn(temp1)/qLn(10), 'G', 11);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="log"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp1=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1<=0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    double temp2=resultExp.last().toDouble(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp2<=0||temp2==1){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qLn(temp1)/qLn(temp2), 'G', 11);
                    resultExp.push_back(result1);
                }
                else{
                    errorFlag=1;
                    return"error1";
                }
            }
        }
        double tempr=resultExp[0].toDouble();
        QString resultFinal;
        resultFinal.setNum(tempr, 'G', 11);
        if(qFabs(tempr)<0.0000000001)
            resultFinal="0";
        return resultFinal;
    }
    else{
        for(int i=0;i<postExp.length();++i){
            if(postExp[i][0].isDigit())
                resultExp.push_back(postExp[i]);
            else{
                if(postExp[i]=="+"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2+temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="-"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2-temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="*"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2*temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="/"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1==0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2/temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="mod"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    if(temp1==0){
                        errorFlag=2;
                        return "error2";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2%temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="abs"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(qFabs(temp1));
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="and"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2&temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="or"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2|temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="xor"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2^temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="not"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(~temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]==">>"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2>>temp1);
                    resultExp.push_back(result1);
                }
                else if(postExp[i]=="<<"){
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp1=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    if(resultExp.isEmpty()){
                        errorFlag=1;
                        return "error1";
                    }
                    int temp2=resultExp.last().toInt(&ok);
                    if(ok==false){
                        errorFlag=1;
                        return "error1";
                    }
                    resultExp.removeLast();
                    QString result1;
                    result1.setNum(temp2<<temp1);
                    resultExp.push_back(result1);
                }
                else{
                    errorFlag=1;
                    return"error";
                }
            }
        }
        return resultExp[0];
    }
}

void CalculatorFX::cmp_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("请输入有序数对(s1,a,s2,b)s1,s2分别为a,b的进制:(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=1;
    cal_complete=false;
}

void CalculatorFX::comDiv_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=2;
    cal_complete=false;
}

void CalculatorFX::lowComMul_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=3;
    cal_complete=false;
}

void CalculatorFX::equ11_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("对方程ax+b=0,请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=4;
    cal_complete=false;
}

void CalculatorFX::equ12_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("对方程ax^2+bx+c=0,请输入有序数对(a,b,c):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=5;
    cal_complete=false;
}

void CalculatorFX::equInverse_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("对方程a/x+b=0,请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=6;
    cal_complete=false;
}

void CalculatorFX::equExp_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("对方程a^x+b=0,请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=7;
    cal_complete=false;
}

void CalculatorFX::equLog_triggered(){
    if(cal_complete==true){
        ui->lineEdit_Input->clear();
        ui->lineEdit_Result->clear();
    }
    ui->lineEdit_Input->setText("对方程log(a,x)+b=0,请输入有序数对(a,b):(");
    ui->lineEdit_Input->setFocus();
    CalculatorFX::functionFlag=8;
    cal_complete=false;
}

void CalculatorFX::fun_cmp(QString expression){
    QString couple=expression.mid(34,expression.length()-35);
    if(couple.count(",")!=3){
        errorFlag=1;
        return;
    }
    QString sys1=couple.section(",", 0, 0);
    QString num1=couple.section(",", 1, 1);
    QString sys2=couple.section(",", 2, 2);
    QString num2=couple.section(",", 3, 3);
    bool ok;
    int s1=sys1.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    int n1=num1.toInt(&ok,s1);
    if(ok==false){
        errorFlag=1;
        return;
    }
    int s2=sys2.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    int n2=num2.toInt(&ok,s2);
    if(ok==false){
        errorFlag=1;
        return;
    }
    QString strN1, strN2;
    strN1.setNum(n1);
    strN2.setNum(n2);
    QString temp;
    if(n1>n2)
        QString temp=num1+"("+sys1+")"+"="+strN1+" > "+num2+"("+sys2+")"+"="+strN2;
    if(n1==n2)
        QString temp=num1+"("+sys1+")"+"="+strN1+" = "+num2+"("+sys2+")"+"="+strN2;
    if(n1<n2)
        QString temp=num1+"("+sys1+")"+"="+strN1+" < "+num2+"("+sys2+")"+"="+strN2;
        ui->lineEdit_Result->setText(temp);
}

void CalculatorFX::fun_comDiv(QString expression){
    QString couple=expression.mid(14,expression.length()-15);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    int n1=num1.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    int n2=num2.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    n1=qFabs(n1);
    n2=qFabs(n2);
    while(n2){
        int temp=n2;
        n2=n1%n2;
        n1=temp;
    }
    int greatComDiv=n1;
    QString comDiv_list;
    QString temp;
    for(int i=1;i<greatComDiv;++i){
        if(greatComDiv%i==0){
            temp.setNum(i);
            comDiv_list=comDiv_list+"±"+temp+",";
        }
    }
    temp.setNum(greatComDiv);
    if(temp=="0")
        comDiv_list="公约数为: "+comDiv_list+temp;
    else
        comDiv_list="公约数为: "+comDiv_list+"±"+temp;
    ui->lineEdit_Result->setText(comDiv_list);
}

void CalculatorFX::fun_lowComMul(QString expression){
    QString couple=expression.mid(14,expression.length()-15);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    int n1=num1.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    int n2=num2.toInt(&ok,10);
    if(ok==false){
        errorFlag=1;
        return;
    }
    if(n1<=0||n2<=0){
        errorFlag=2;
        return;
    }
    int n1_temp=n1;
    int n2_temp=n2;
    while(n2_temp){
        int temp=n2_temp;
        n2_temp=n1_temp%n2_temp;
        n1_temp=temp;
    }
    int greatComDiv=n1_temp;
    int lowestComMul=n1*n2/greatComDiv;
    QString temp;
    temp.setNum(lowestComMul);
    temp="最小公倍数为: "+temp;
    ui->lineEdit_Result->setText(temp);
}

void CalculatorFX::fun_equ11(QString expression){
    QString couple=expression.mid(24,expression.length()-25);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    double a=num1.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double b=num2.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    QString temp;
    if(a==0){
        if(b==0){
            temp="该方程有无穷多个解";
        }
        else{
            temp="该方程无解";
        }
    }
    else{
        double result=-b/a;
        temp.setNum(result, 'G', 11);
        temp="该方程的解为: x= "+temp;
    }
    ui->lineEdit_Result->setText(temp);
}

void CalculatorFX::fun_equ12(QString expression){
    QString couple=expression.mid(31,expression.length()-32);
    if(couple.count(",")!=2){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    QString num3=couple.section(",", 2, 2);
    bool ok;
    double a=num1.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double b=num2.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double c=num3.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double delta=1,x=1,x1=1,x2=1,real=1,image=1;
    QString result;
    if(a==0&&b==0){
        if(c==0)
            result="方程有无穷多个解";
        else
            result="方程无解";
    }
    if(a==0&&b!=0){
        x=-c/b;
        result.setNum(x, 'G', 11);
        result="方程有解 x = "+result;
    }
    if(a!=0){
        delta=b*b-4*a*c;
        if(delta>=0){
            x1=(-b+qSqrt(delta))/(2.0*a);
            x2=(-b-qSqrt(delta))/(2.0*a);
        }
        else{
            image=qSqrt(-delta)/(2.0*a);
            real=(-b)/(2.0*a);
        }
        if(delta==0){
            result.setNum(x1, 'G', 11);
            result="方程有两个相同实数解 x1=x2= "+result;
        }
        if(delta>0){
            QString temp1, temp2;
            temp1.setNum(x1, 'G', 11);
            temp2.setNum(x2, 'G', 11);
            result="方程有两个不同的实数解 x1= "+temp1+" ,x2= "+temp2;
        }
        if(delta<0){
            QString temp1, temp2;
            temp1.setNum(real, 'G', 11);
            temp2.setNum(image, 'G', 11);
            result="方程有两个不同的复数解 x1= "+temp1+"+"+temp2+"i"+" ,x2= "+temp1+"-"+temp2+"i";
        }
    }
    ui->lineEdit_Result->setText(result);
}

void CalculatorFX::fun_equInverse(QString expression){
    QString couple=expression.mid(25,expression.length()-26);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    double a=num1.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double b=num2.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    QString temp;
    if(a==0){
        if(b==0){
            temp="该方程有无穷多个解";
        }
        else{
            temp="该方程无解";
        }
    }
    else{
        if(b==0){
            temp="该方程无解";
        }
        else{
            double result=-a/b;
            temp.setNum(result, 'G', 11);
            temp="该方程的解为: x= "+temp;
        }
    }
    ui->lineEdit_Result->setText(temp);
}

void CalculatorFX::fun_equExp(QString expression){
    QString couple=expression.mid(25,expression.length()-26);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    double a=num1.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double b=num2.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    if(a<0||b>0){
        errorFlag=2;
        return;
    }
    QString temp;
    if(a==0){
        if(b==0){
            temp="该方程有无穷多个解";
        }
        else{
            temp="该方程无解";
        }
    }
    else{
        if(b==0){
            temp="该方程无解";
        }
        else{
            double result=qLn(-b)/qLn(a);
            temp.setNum(result, 'G', 11);
            temp="该方程的解为: x= "+temp;
        }
    }
    ui->lineEdit_Result->setText(temp);
}

void CalculatorFX::fun_equLog(QString expression){
    QString couple=expression.mid(30,expression.length()-31);
    if(couple.count(",")!=1){
        errorFlag=1;
        return;
    }
    QString num1=couple.section(",", 0, 0);
    QString num2=couple.section(",", 1, 1);
    bool ok;
    double a=num1.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    double b=num2.toDouble(&ok);
    if(ok==false){
        errorFlag=1;
        return;
    }
    if(a<=0||a==1){
        errorFlag=2;
        return;
    }
    QString temp;
    double result=qPow(a, -b);
    temp.setNum(result, 'G', 11);
    temp="该方程的解为: x= "+temp;
    ui->lineEdit_Result->setText(temp);
}

















