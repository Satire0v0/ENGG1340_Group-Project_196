/*
This file contains the functions that all the other files need to use.
*/

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <termio.h>
#include <stdio.h>
#include "global.h"
#include "player.h"
#include "map.h"
#include "saving.h"
#include <cstdlib>

using namespace std;

class Player;
class Map;

void clear_screen();

string get_word();

bool leave_or_not();

void print_hint();

char keyboard();

location explain_input(char word, Player &player, Map &map);

double getProbability();

int random_num();

#endif