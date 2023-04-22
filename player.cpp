#include "player.h"


location Player::get_loc(){
    return loc;
}


void Player::update_loc(location moveloc){
    loc.row += moveloc.row;
    loc.col += moveloc.col;
}

void Player::update_weapon(string new_weapon){
    weapon = new_weapon;
}

string Player::get_weapon(){
    return weapon;
}

void Talent::set(int mult_val, bool vision_val){
    mult = mult_val;
    vision = vision_val;
}
int Player::get_HP(){
    return HP;
}

void Player::update_HP(int val){
    HP += val;
}


int Player::get_ATK(){
    return ATK;
}

void Player::update_ATK(int val){
    ATK += val;
}

int Player::get_DEF(){
    return DEF;
}

void Player::update_DEF(int val){
    DEF += val;
}

int Player::get_maxHP(){
    return maxHP;
}

void Player::update_maxHP(int val){
    maxHP += val;
}


int Player::get_prob(){
    return prob;
}

void Player::update_prob(int val){
    prob += val;
}

void Player::show_info(){
    cout << "Player -> ";
    cout << "HP: " << HP << "/" << maxHP << " | ";
    cout << "ATK: " << ATK << " | ";
    cout << "Location: " << loc.row << loc.col << endl;
} 

int Player::attack(){
    if (getProbability() <= prob){
        return ATK;
    }
    else{
        return 0;
    }
}