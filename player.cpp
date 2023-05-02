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

int Player::get_HP(){
    return HP;
}

void Player::update_HP(int val){
    // if attack
    if (val < 0){
        if (DEF == 0) HP += val;
        else{
            if ( (DEF + val) < 0 ){
                DEF = 0; // DEF less the monster's ATK
                HP += (DEF + val);
            }
            else{
                DEF += val;
            }
        }
    }
    else{
        // could not exceed maxHP
        if ( (HP+val) >= maxHP){
            HP = maxHP;
        }
        else{
            HP += val;
        }
    }

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
    /*
    // Update HP if maxHP increases, when HP == maxHP initially
    if (HP == maxHP){
        maxHP += val;
        HP = maxHP;
    }
    else{
        maxHP += val;
    }
    */
    maxHP += val;
}

double Player::get_prob(){
    return prob;
}

void Player::update_prob(double val){
    if ((prob + val) >= 1) prob = 1;
    else prob += val;
}

void Player::show_info(){
    cout << "Player -> ";
    cout << "HP: " << HP << "/" << maxHP << " | ";
    cout << "DEF: " << DEF << " | ";
    cout << "ATK: " << ATK << " | ";
    cout << "Location: " << loc.row << ' ' << loc.col << " | ";
    cout << "Probability: " << prob*100 << '%';

    // over
    cout << endl;
} 

int Player::attack(){
    if (getProbability() <= prob){
        return ATK;
    }
    else{
        return 0;
    }
}

void Player::set_ATK(int new_ATK){
    ATK = new_ATK;
}

void Player::set_HP(int new_HP){
    if (new_HP >= maxHP) HP = maxHP;
    else HP = new_HP;
}

void Player::set_DEF(int new_DEF){
    DEF = new_DEF;
}

void Player::set_maxHP(int new_maxHP){
    maxHP = new_maxHP;
}
        
void Player::set_prob(double new_prob){
    if (new_prob >= 1) prob = 1;
    else prob = new_prob;
}

void Player::set_loc(location new_loc){
    loc = new_loc;
}
