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
        void update_HP(int val);

        int get_ATK();
        int get_maxHP();
        double get_prob();
        void set_prob(double val);
        int attack();

        void show_info();
        void set(int new_HP, int new_maxHP, int new_ATK, double new_prob);
};

#endif