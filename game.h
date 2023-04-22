#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"
//rpsgame returns an integer value representing the winning status of the game
//if there is a draw, the game will continue untill the player wins or loses

using namespace std;
bool rpsgame();
bool guess_die();
bool number_guess();
bool keyboard(int player.talent.mult,int difficulty);
void countdown();
Player attack(Player player, Monster monster);
#endif
