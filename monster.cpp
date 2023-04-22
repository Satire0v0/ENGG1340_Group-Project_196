#include "monster.h"


int Monster::get_HP(){
    return HP;
}


int Monster::get_ATK(){
    return ATK;
}


void Monster::show_info(){
    cout << "Monster -> ";
    cout << "HP: " << HP << "/" << maxHP << " | ";
    cout << "ATK: " << ATK << endl;
} 


void Monster::set(int new_HP, int new_ATK, int new_maxHP, int new_prob){
    HP = new_HP;
    ATK = new_ATK;
    maxHP = new_maxHP;
    prob = new_prob;
}


int Monster::attack(){
    if (getProbability() <= prob){
        return ATK;
    }
    else{
        return 0;
    }
}