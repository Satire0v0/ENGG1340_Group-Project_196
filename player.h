#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include <iostream>
using namespace std;

struct Talent{       //maxHP,DEF,翻倍的实现形式:player.atk*=2
    int mult=1;
    bool vision=false;
};

class Player{
    private:
        location loc={2,1};
        string weapon;

        int HP=100;
        int DEF=0;
        int ATK=10;
        int maxHP=100;
        
        
    public:
        Talent talent;
        location get_loc();
        void update_loc(location move_loc={0,0});

        string get_weapon();
        void update_weapon(string new_weapon);
};

#endif
