#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include "base.h"
#include <iostream>
using namespace std;

struct Talent{
        void set(int mult_val, bool vision_val, bool supernightvision_val);
        int mult;
        bool vision;
        bool supernightvision;
      //maxHP,DEF,翻倍的实现形式:player.set_ATK(player.get_ATK() * 2);
    
};

class Player: public Talent
{ 
    private:
        location loc={2,1};
        string weapon;

        int HP = 100;
        int ATK = 10;
        int DEF = 0;
        int maxHP = 100;
        double prob = 0.7; // percentage
        
        
    public:
        Talent talent;
        location get_loc();
        void update_loc(location move_loc={0,0});

        string get_weapon();
        void update_weapon(string new_weapon);

        int get_HP();
        void update_HP(int val);

        int get_ATK();
        void update_ATK(int val);

        int get_DEF();
        void update_DEF(int val);

        int get_maxHP();
        void update_maxHP(int val);

        int get_prob();
        void update_prob(int val);

        void show_info();
        
        int attack();

        void set_ATK(int new_ATK);

        void set_HP(int new_HP);

        void set_DEF(int new_DEF);

        void set_maxHP(int new_maxHP);
        
        void set_prob(double new_prob);
};

#endif
