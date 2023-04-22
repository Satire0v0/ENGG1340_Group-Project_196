#ifndef MONSTER_H
#define MONSTER_H

#include "global.h"
#include <iostream>
using namespace std;


#include "base.h"


class Monster{
    private:
        int HP = 50;
        int ATK = 5;
        int maxHP = 100;
        double prob = 0.2; // percentage
 
    public:
        int get_HP();
        int get_ATK();
        int attack();

        void show_info();
        void set(int new_HP, int new_ATK, int new_maxHP, int new_prob);
};

#endif