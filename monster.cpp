#include "monster.h"


int Monster::get_HP(){
    return HP;
}

void Monster::update_HP(int val){
    if ( (HP + val) >= maxHP ) HP = maxHP;
    else HP += val;
}

int Monster::get_ATK(){
    return ATK;
}

int Monster::get_maxHP(){
    return maxHP;
}

double Monster::get_prob(){
    return prob;
}

void Monster::set_prob(double val){
    prob = val;
}

void Monster::show_info(){
    cout << "Monster -> ";
    cout << "HP: " << HP << "/" << maxHP << " | ";
    cout << "ATK: " << ATK << " | ";
    cout << "Probability: " << prob*100 << '%';
    cout << endl;
} 


void Monster::set(int new_HP, int new_maxHP, int new_ATK, double new_prob){
    if (new_HP >= new_maxHP){
        HP = new_maxHP;
    }
    else{
        HP = new_HP;
    }
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
