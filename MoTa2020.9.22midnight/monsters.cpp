#include "monsters.h"

monsters::monsters()
{
}

void monsters::mon(int i)
{
    switch (i)
    {
        case 0:{this->atk=8;this->defense=0;this->HP=15;this->golden=10;this->EXP=8;this->pix.load(":/mota/pictures/monster_00.png");}
               break;
        case 1:{this->atk=10;this->defense=5;this->HP=35;this->golden=25;this->EXP=26;this->pix.load(":/mota/pictures/monster_01.png");}
               break;
        case 2:{this->atk=12;this->defense=10;this->HP=100;this->golden=35;this->EXP=50;this->pix.load(":/mota/pictures/monster_02.png");}
               break;
        case 3:{this->atk=18;this->defense=15;this->HP=280;this->golden=60;this->EXP=75;this->pix.load(":/mota/pictures/monster_03.png");}
               break;
        case 4:{this->atk=25;this->defense=20;this->HP=500;this->golden=95;this->EXP=110;this->pix.load(":/mota/pictures/monster_04.png");}
               break;
        case 5:{this->atk=32;this->defense=22;this->HP=750;this->golden=120;this->EXP=150;this->pix.load(":/mota/pictures/monster_05.png");}
               break;
        case 6:{this->atk=40;this->defense=30;this->HP=900;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_06.png");}
               break;
        case 7:{this->atk=55;this->defense=35;this->HP=1300;this->golden=175;this->EXP=200;this->pix.load(":/mota/pictures/monster_07.png");}
               break;
        case 8:{this->atk=68;this->defense=40;this->HP=1750;this->golden=210;this->EXP=200;this->pix.load(":/mota/pictures/monster_08.png");}
               break;
        case 9:{this->atk=82;this->defense=55;this->HP=1900;this->golden=235;this->EXP=200;this->pix.load(":/mota/pictures/monster_09.png");}
               break;
        case 10:{this->atk=100;this->defense=85;this->HP=2130;this->golden=286;this->EXP=200;this->pix.load(":/mota/pictures/monster_10.png");}
               break;
        case 11:{this->atk=120;this->defense=76;this->HP=2400;this->golden=310;this->EXP=200;this->pix.load(":/mota/pictures/monster_11.png");}
               break;
        case 12:{this->atk=150;this->defense=100;this->HP=2840;this->golden=360;this->EXP=200;this->pix.load(":/mota/pictures/monster_12.png");}
               break;
        case 13:{this->atk=175;this->defense=95;this->HP=3200;this->golden=400;this->EXP=200;this->pix.load(":/mota/pictures/monster_13.png");}
               break;
        case 14:{this->atk=190;this->defense=120;this->HP=3480;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_14.png");}
               break;
        case 15:{this->atk=215;this->defense=135;this->HP=3900;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_15.png");}
               break;
        case 16:{this->atk=248;this->defense=156;this->HP=4200;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_16.png");}
               break;
        case 17:{this->atk=269;this->defense=168;this->HP=4500;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_17.png");}
               break;
        case 18:{this->atk=300;this->defense=184;this->HP=4980;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_18.png");}
               break;
        case 19:{this->atk=350;this->defense=200;this->HP=5200;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_19.png");}
               break;
        case 20:{this->atk=410;this->defense=252;this->HP=6000;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/monster_20.png");}
               break;
        case 21:{this->atk=700;this->defense=400;this->HP=9999;this->golden=150;this->EXP=200;this->pix.load(":/mota/pictures/boss.png");}
               break;
    }
}
