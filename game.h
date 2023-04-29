#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"
#include "global.h"
#include "map.h"

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
class Map;

using namespace std;

// game
bool rpsgame();
bool guess_dice();
bool number_guess();
bool keyboard_game(int talent_mult, int difficulty);
Player countdown(Player player, Map map, int count);

// normal fight
Player attack(Player player, Monster monster, int diff_level);

// realize randomly choosing game
void randomFunction(int talent_mult, int diff_level);

#endif

