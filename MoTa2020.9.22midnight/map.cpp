#include "map.h"
#include "ui_map.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>

static int floors[10][15][15]={{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {1,0,0,0,0,30,50,31,0,0,0,0,0,0,1},
                                {1,0,0,0,0,0,30,0,0,30,0,0,0,0,1},
                                {1,0,0,0,31,0,0,0,0,0,0,0,0,0,1},
                                {1,0,0,0,0,0,0,0,0,0,31,0,0,0,1},
                                {1,0,0,0,0,0,31,0,0,0,0,0,0,0,1},
                                {1,0,30,0,0,0,0,30,0,0,0,0,0,0,1},
                                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                {1,0,31,0,0,0,0,0,0,30,0,0,0,0,1},
                                {1,0,0,0,0,0,0,31,0,0,0,0,0,0,1},
                                {1,0,0,0,30,0,0,0,0,0,0,0,0,0,1},
                                {1,0,0,0,0,0,1,20,1,0,0,0,0,0,1},
                                {1,0,0,0,0,0,1,60,1,0,0,0,0,0,1},
                                {1,0,30,0,0,0,1,51,1,0,0,0,0,32,71},
                                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},//第一层。0代表空位，1代表墙，2X代表门，3/4X代表怪物，4代表主角，5X代表钥匙，6X代表道具，70表示下楼，71表示上楼，72代表商店，80/1代表怪物。
                               {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {70,0,0,0,0,0,0,0,0,0,0,0,0,31,1},
                                {1,60,0,0,0,31,0,0,0,0,0,61,0,0,1},
                                {1,0,0,0,50,0,31,0,51,0,0,0,0,0,1},
                                {1,1,1,0,0,0,1,0,0,0,1,0,0,32,1},
                                {1,72,1,60,1,31,0,0,1,32,0,60,1,31,1},
                                {1,0,32,31,0,0,1,0,0,31,1,0,0,0,1},
                                {1,61,1,0,1,0,0,31,1,0,0,0,1,61,1},
                                {1,1,1,0,0,30,1,0,0,61,1,0,0,0,1},
                                {1,32,0,0,0,0,0,0,0,0,0,0,31,30,1},
                                {1,0,0,0,0,0,30,0,0,0,0,0,0,0,1},
                                {1,1,1,1,20,1,1,22,1,1,20,1,1,21,1},
                                {1,32,31,30,31,1,0,33,0,1,62,60,1,50,1},
                                {1,52,50,61,51,1,0,0,0,1,51,32,20,50,1},
                                {1,1,1,1,1,1,1,71,1,1,1,1,1,1,1}},//第二层。
                               {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {1,60,31,32,0,1,0,0,0,0,0,22,34,71,1},
                                {1,31,0,0,32,20,0,50,0,0,0,1,1,1,1},
                                {1,0,32,31,61,1,0,0,0,0,0,0,0,0,1},
                                {1,31,1,1,1,1,1,1,21,1,1,1,1,1,1},
                                {1,0,1,52,50,50,50,1,32,1,33,0,60,61,1},
                                {1,0,1,52,51,51,51,20,0,21,32,0,60,61,1},
                                {1,32,1,1,1,1,1,1,0,1,1,1,1,1,1},
                                {1,0,1,33,32,32,0,0,33,0,0,0,32,0,1},
                                {1,60,1,1,1,1,1,1,0,1,1,1,1,1,1},
                                {1,0,1,61,33,32,31,20,0,21,62,0,1,70,1},
                                {1,0,1,60,33,32,31,1,32,1,63,0,1,0,1},
                                {1,31,1,1,1,1,1,1,1,1,1,1,1,0,1},
                                {1,0,0,61,0,0,0,31,0,0,0,0,0,0,1},
                                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},//第三层。
                               {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {70,0,0,60,0,32,0,0,31,0,0,32,0,0,1},
                                {1,1,1,1,1,1,21,1,1,1,1,1,1,0,1},
                                {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                                {1,0,1,1,1,1,1,1,1,1,1,0,34,0,1},
                                {1,0,1,0,0,0,21,0,0,0,1,0,1,0,1},
                                {1,0,1,0,1,22,1,1,1,0,1,0,1,0,1},
                                {1,0,1,0,1,0,35,71,1,0,1,0,1,0,1},
                                {1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
                                {1,0,34,0,1,0,0,0,0,0,1,0,1,0,1},
                                {1,0,1,0,1,1,1,1,34,1,1,0,1,0,1},
                                {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
                                {1,0,1,1,20,1,1,1,1,1,1,1,1,0,1},
                                {1,0,0,0,0,0,0,0,0,0,0,20,0,0,1},
                                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},//第四层。
                               {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
                                {1,0,0,0,0,1,36,71,37,1,0,0,0,0,1},
                                {1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
                                {1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
                                {1,20,1,0,1,1,0,1,0,1,1,0,1,21,1},
                                {1,0,1,0,0,1,0,1,0,1,0,0,1,0,1},
                                {1,0,1,0,0,0,0,1,0,0,0,0,1,0,1},
                                {1,0,1,0,0,0,0,22,0,0,0,0,1,0,1},
                                {1,0,1,1,1,1,0,1,0,1,1,1,1,0,1},
                                {1,0,0,1,0,1,0,1,0,1,0,1,0,0,1},
                                {1,0,0,21,0,1,1,1,1,1,0,20,0,0,1},
                                {1,0,0,1,0,0,0,0,0,0,0,1,0,0,1},
                                {1,0,0,1,1,1,70,0,0,1,1,1,0,0,1},
                                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},//第五层。
                              };

Map::Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Map)
{
    this->setFixedSize(1000,764);
    ui->setupUi(this);
    for(int ii=0;ii<3;ii++)
    {
        keys[ii]=0;
    }
    memcpy(map,floors[0],900);
    Superman.X=1;
    Superman.Y=1;
    Superman.floor=1;
    map[Superman.Y][Superman.X]=4;
    face_up=3;
    ui->battleScreen->hide();
    ui->item_get->hide();
    //ui->imgSuperman->raise();
    pix1=new QPixmap(":/mota/pictures/down_00.png");
    pix1->scaled(ui->imgSuperman->size(), Qt::KeepAspectRatio);
    ui->imgSuperman->setScaledContents(true);//设置label全填效果
    ui->imgSuperman->setPixmap(*pix1);//把图片放到label中
    delete pix1;
    battleTimer=new QTimer(this);
    getItem=new QTimer(this);
    battleStart=false;
    getStart=false;
    fightWin=false;
    getItemNum=0;
    connect(battleTimer, SIGNAL(timeout()), this, SLOT(fight()));
    connect(getItem, SIGNAL(timeout()), this, SLOT(getItem_screen()));
    connect(&Shop,SIGNAL(saleit()),this,SLOT(getit()));
}

Map::~Map()
{
    delete ui;
}


void Map::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.save();
    printmap(p);
    p.restore();

    printdata();
}

void Map::printdata()
{
    ui->label_num_HP->setText(QString::number(Superman.HP)+"/"+QString::number(Superman.MAX_HP));
    ui->label_num_ATK->setText(QString::number(Superman.atk));
    ui->label_num_Def->setText(QString::number(Superman.defense));
    ui->label_num_EXP->setText(QString::number(Superman.EXP)+"/"+QString::number(Superman.EXP_To_LevelUP));
    ui->label_num_Level->setText(QString::number(Superman.Level));
    ui->label_num_golden->setText(QString::number(Superman.golden));
    ui->label_num_yellow_key->setText(QString::number(keys[0]));
    ui->label_num_blue_key->setText(QString::number(keys[1]));
    ui->label_num_red_key->setText(QString::number(keys[2]));
}

void Map::printmap(QPainter &p)
{
    QPixmap pix;
    pix.load(":/mota/pictures/background.bmp");
    p.drawPixmap(0,14,1000,750,pix);
    for(int ii=0;ii<15;ii++)
        for(int j=0;j<15;j++)
        {
            switch (map[ii][j])
            {
                case 1:pix.load(":/mota/pictures/wall.bmp");
                       p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                       break;
                case 4:mainrole_faceup(pix,p);
                       break;
                case 20:pix.load(":/mota/pictures/yellow_door.bmp");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 21:pix.load(":/mota/pictures/blue_door.bmp");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 22:pix.load(":/mota/pictures/red_door.bmp");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 30:pix.load(":/mota/pictures/monster_00.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 31:pix.load(":/mota/pictures/monster_01.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 32:pix.load(":/mota/pictures/monster_02.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 33:pix.load(":/mota/pictures/monster_03.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 34:pix.load(":/mota/pictures/monster_04.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 35:pix.load(":/mota/pictures/monster_05.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 36:pix.load(":/mota/pictures/monster_06.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 37:pix.load(":/mota/pictures/monster_07.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 38:pix.load(":/mota/pictures/monster_08.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 39:pix.load(":/mota/pictures/monster_09.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 40:pix.load(":/mota/pictures/monster_10.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 41:pix.load(":/mota/pictures/monster_11.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 42:pix.load(":/mota/pictures/monster_12.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 43:pix.load(":/mota/pictures/monster_13.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 44:pix.load(":/mota/pictures/monster_14.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 45:pix.load(":/mota/pictures/monster_15.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 46:pix.load(":/mota/pictures/monster_16.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 47:pix.load(":/mota/pictures/monster_17.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 48:pix.load(":/mota/pictures/monster_18.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 49:pix.load(":/mota/pictures/monster_19.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 50:pix.load(":/mota/pictures/yellow_key.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 51:pix.load(":/mota/pictures/blue_key.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 52:pix.load(":/mota/pictures/red_key.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 60:pix.load(":/mota/pictures/small_medcine.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 61:pix.load(":/mota/pictures/big_medcine.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 62:pix.load(":/mota/pictures/red_stone.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;//修改！！！！
                case 63:pix.load(":/mota/pictures/blue_stone.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;//修改！！！！
                case 70:pix.load(":/mota/pictures/downstairs.bmp");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 71:pix.load(":/mota/pictures/upstairs.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
                case 72:pix.load(":/mota/pictures/merchant.png");
                        p.drawPixmap(250+50*j,14+50*ii,50,50,pix);
                        break;
//                case 80:
//                case 81:
            }
        }
}

void Map::mainrole_faceup(QPixmap pix, QPainter &p)
{
    int ii=Superman.X,j=Superman.Y;
    switch (face_up)
    {
        case 1:pix.load(":/mota/pictures/up_00.png");
               break;
        case 2:pix.load(":/mota/pictures/right_01.png");
               break;
        case 3:pix.load(":/mota/pictures/down_00.png");
               break;
        case 4:pix.load(":/mota/pictures/left_01.png");
               break;
    }
    p.drawPixmap(250+50*ii,14+50*j,50,50,pix);

}

void Map::keyReleaseEvent(QKeyEvent* event)
{
    this->grabKeyboard();
    if(event->key()==Qt::Key_Left)
    {
        if(battleStart==false&&getStart==false){
            move(Superman.X-1,Superman.Y);
            face_up=4;
        }
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(battleStart==false&&getStart==false){
            move(Superman.X+1,Superman.Y);
            face_up=2;
        }
    }
    else if(event->key()==Qt::Key_Up)
    {
        if(battleStart==false&&getStart==false){
            move(Superman.X,Superman.Y-1);
            face_up=1;
        }
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(battleStart==false&&getStart==false){
            move(Superman.X,Superman.Y+1);
            face_up=3;
        }
    }
    update();
}

void Map::move(int i, int j)
{
    in=i;
    jn=j;
    if(map[jn][in]==1||(in<0||in>14)||(jn<0||jn>14))
        return;
    if(map[jn][in]/10==2)
    {
        if(keys[map[jn][in]%10]!=0)
        {
            keys[map[jn][in]%10]--;
            map[jn][in]=0;
            update();
        }
        return;
    }
    if (map[jn][in]/10==3||map[jn][in]/10==4||map[jn][in]==80||map[jn][in]==81)
    {
        monsterFight=map[jn][in];
        int num=monsterFight;
        if(num>=80)//编号20之后的怪物。
            n_mon1=num-60;
        else if(num<50)//编号20之前的怪物。
            n_mon1=num-30;
        Mon[n_mon1].mon(n_mon1);
        Mon[n_mon1].pix.scaled(ui->imgEnemy->size(), Qt::KeepAspectRatio);
        ui->imgEnemy->setScaledContents(true);//设置label全填效果
        ui->imgEnemy->setPixmap(Mon[n_mon1].pix);//把图片放到label中
        ui->hpNum->setText(QString::number(Mon[n_mon1].HP));
        ui->atkNum->setText(QString::number(Mon[n_mon1].atk));
        ui->defNum->setText(QString::number(Mon[n_mon1].defense));
        ui->hpNum_2->setText(QString::number(Superman.HP));
        ui->atkNum_2->setText(QString::number(Superman.atk));
        ui->defNum_2->setText(QString::number(Superman.defense));
        qDebug()<<Mon[n_mon1].atk<<Mon[n_mon1].defense<<Mon[n_mon1].HP;
        m_hp=Mon[n_mon1].HP;
        i_atk=Superman.atk;//i:单次伤害;
        f1=1;
        a=0;
        b=0;
        c=0;
        battleStart=true;
        fightWin=false;
        ui->battleScreen->show();
        battleTimer->start(500);
        return;
    }
    if(map[jn][in]/10==5)
    {
        getItemNum=map[jn][in];
        keys[getItemNum%10]++;
        map[jn][in]=0;
        update();
        getStart=true;
        if(getItemNum==50){
            ui->item_get->setText("获得黄钥匙");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 127);");
        }
        else if(getItemNum==51){
            ui->item_get->setText("获得蓝钥匙");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 255, 255);");
        }
        else if(getItemNum==52){
            ui->item_get->setText("获得红钥匙");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 0, 127);");
        }
        ui->item_get->show();
        getItem->start(350);
        return;

    }  

    if(map[jn][in]/10==6)
    {
        getItemNum=map[jn][in];
        map[jn][in]=0;
        update();
        getStart=true;
        if(getItemNum==60){
            Superman.HP+=10;
            ui->item_get->setText("获得10点生命");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);");
        }
        if(getItemNum==61){
            Superman.HP+=25;
            ui->item_get->setText("获得25点生命");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);");
        }
        if(getItemNum==62){
            Superman.atk+=3;
            ui->item_get->setText("获得3点攻击");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);");
        }
        if(getItemNum==63){
            Superman.defense+=3;
            ui->item_get->setText("获得3点防御");
            ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);");
        }
        if(Superman.HP>Superman.MAX_HP)
            Superman.HP=Superman.MAX_HP;
        ui->item_get->show();
        getItem->start(350);
        return;
    }
    if(map[jn][in]==71)
    {
        upstair(Superman.floor);
        return;
    }
    if(map[jn][in]==70)
    {
        downstair(Superman.floor);
        return;
    }
    if(map[jn][in]==72)
    {
        shopping();
        return;
    }
    map[jn][in]=4;
    Superman.X=in;
    Superman.Y=jn;
    if(Superman.HP_Rec>0)
        {
            int rec=(Superman.MAX_HP-Superman.HP)*Superman.HP_Rec;//修改！！！
            if(Superman.HP<Superman.MAX_HP&&rec==0)
                Superman.HP++;
            else
                Superman.HP+=rec;
            if(Superman.HP>Superman.MAX_HP)
                Superman.HP=Superman.MAX_HP;
        }
    return;
}

void Map::upstair(int floor)
{
    memcpy(floors[floor-1],map,900);
    memcpy(map,floors[floor],900);
    floor+=1;
    switch (floor)
    {
    case 2:{Superman.X=1;
            Superman.Y=1;
            Superman.floor=2;
            break;
           }
    case 3:{Superman.X=13;
            Superman.Y=11;
            Superman.floor=3;
            break;
           }
    case 4:{Superman.X=1;
            Superman.Y=1;
            Superman.floor=4;
            break;
           }
    case 5:{Superman.X=7;
                Superman.Y=13;
                Superman.floor=5;
                break;
           }
    }
    map[Superman.Y][Superman.X]=4;
}

void Map::downstair(int floor)
{
    memcpy(floors[floor-1],map,900);
    memcpy(map,floors[floor-2],900);
    floor-=1;
    switch (floor)
    {
    case 1:{Superman.X=13;
            Superman.Y=13;
            Superman.floor=1;
            break;
           }
    case 2:{Superman.X=7;
            Superman.Y=13;
            Superman.floor=2;
            break;
            }
     case 3:{Superman.X=12;
             Superman.Y=1;//修改！！！
             Superman.floor=3;
             break;
            }
    case 4:{Superman.X=6;
            Superman.Y=7;
            Superman.floor=4;
            break;
           }
    }
    map[Superman.Y][Superman.X]=4;
}

void Map::fight()
{

    srand((unsigned)time(nullptr));
    // for(;m>0&&Superman.HP>0;)
        {if(rand()%100<Superman.Crit*100)
            {i_atk=int(Superman.atk*Superman.Crit_damage);
             a++;
            }
         if(Superman.Double_hit)
            {m_hp-=(i_atk-Mon[n_mon1].defense);
             if(m_hp<=0){
                 m_hp=0;
                 ui->hpNum->setText("0");

             }
            }
         int k=(Mon[n_mon1].atk-Superman.defense);
         if(k>0)
            Superman.HP-=k;
         if((Mon[n_mon1].defense-i_atk)<0)
         m_hp=m_hp+Mon[n_mon1].defense-i_atk;
         c+=i_atk;
         Superman.HP+=i_atk*Superman.Feed_on_Blood;
         b+=i_atk*Superman.Feed_on_Blood;
         if(Superman.HP>Superman.MAX_HP)
            Superman.HP=Superman.MAX_HP;
         if(m_hp<0)
             m_hp=0;
         ui->hpNum->setText(QString::number(m_hp));
         ui->hpNum_2->setText(QString::number(Superman.HP));
        }
     if(Superman.HP<=0)
        {
         //战败。
         fightWin=false;
         battleStart=false;
         ui->battleScreen->hide();
         battleTimer->stop();

         return;
        }
     else if(m_hp<=0)
        {
         getItemNum=map[jn][in];


         fightWin=true;
         battleStart=false;
         ui->battleScreen->hide();
         battleTimer->stop();
         map[jn][in]=0;
         update();
         if((getItemNum>=30&&getItemNum<=49)||getItemNum==80||getItemNum==81){
             int prelevel=Superman.Level;
             Superman.golden+=Mon[n_mon1].golden;
             Superman.EXP+=Mon[n_mon1].EXP;
             Superman.level_up();
             QString temp;
             temp="获得"+QString::number(Mon[n_mon1].golden)+"金币，"+QString::number(Mon[n_mon1].EXP)+"经验";
             ui->item_get->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);");
             if(prelevel<Superman.Level){
                 temp=temp+"\n升级啦！！！";
                 ui->item_get->setStyleSheet("color: rgb(0, 0, 0);"
                                             "background-color: qconicalgradient(cx:0, cy:0, angle:135, "
                                             "stop:0 rgba(255, 255, 0, 69), "
                                             "stop:0.375 rgba(255, 255, 0, 69), "
                                             "stop:0.423533 rgba(251, 255, 0, 145), "
                                             "stop:0.45 rgba(247, 255, 0, 208), "
                                             "stop:0.477581 rgba(255, 244, 71, 130), "
                                             "stop:0.518717 rgba(255, 218, 71, 130), "
                                             "stop:0.55 rgba(255, 255, 0, 255), "
                                             "stop:0.57754 rgba(255, 203, 0, 130), "
                                             "stop:0.625 rgba(255, 255, 0, 69), "
                                             "stop:1 rgba(255, 255, 0, 69));");
             }
             ui->item_get->setText(temp);

         }
         ui->item_get->show();
         getItem->start(600);
         return;
        }

}

void Map::getItem_screen(){
    getStart=false;
    getItem->stop();
    ui->item_get->hide();
}

void Map::shopping()
{
    Shop.init();
    Shop.getgold(Superman.golden);
    Shop.grabKeyboard();
    Shop.show();
    Shop.releaseKeyboard();
}

void Map::getit()//大量修改！！！！！！
{
    switch (Shop.num)
    {
        case 1:{Superman.HP+=10;
                if(Superman.HP>Superman.MAX_HP)
                    Superman.HP=Superman.MAX_HP;
               }break;
        case 2:{Superman.HP+=25;
                if(Superman.HP>Superman.MAX_HP)
                    Superman.HP=Superman.MAX_HP;
               }break;
        case 3:Superman.defense+=8;
               break;//修改！！！
        case 4:{Superman.atk+=3;
                Superman.Crit+=0.1;
               }break;//
        case 5:{Superman.atk+=4;
                Superman.Feed_on_Blood+=0.05;
               }break;//
        case 6:Superman.atk+=8;
               break;//
        case 7:{Superman.atk+=22;
                Superman.Crit+=0.5;
                Superman.Crit_damage+=0.25;
               }break;//
        case 8:{Superman.Double_hit=1;
                Superman.atk+=18;
                Superman.Crit+=0.3;
                Superman.Crit_damage+=0.2;
               }break;//
        case 9:{Superman.atk+=20;
                Superman.Feed_on_Blood+=0.32;
               }break;//
        case 10:{Superman.MAX_HP+=250;
                 Superman.HP+=250;
                 Superman.defense+=20;
                }break;//修改！！！
        case 11:{Superman.MAX_HP+=400;
                 Superman.HP+=400;
                 Superman.defense+=18;//修改！！！
                 Superman.HP_Rec+=0.02;
                }break;//
    }
    Superman.golden-=Shop.mer[Shop.num][2].toInt();
    update();
}
