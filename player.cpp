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