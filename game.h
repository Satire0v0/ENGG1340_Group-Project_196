#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <termios.h>
#include <unistd.h>
//rpsgame returns an integer value representing the winning status of the game
//if there is a draw, the game will continue untill the player wins or loses

class Monster;
class Player;

using namespace std;
bool rpsgame();
bool guess_die();
bool number_guess();
bool keyboard_game(int talent_mult,int difficulty);
void countdown();
Player attack(Player player, Monster monster);
#endif
