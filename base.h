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
#include <cstdlib>
#include <algorithm>

// local file
#include "global.h"
#include "player.h"
#include "map.h"
#include "saving.h"
#include "room.h"

using namespace std;

// define
class Player;
class Map;
class Monster;


// general functions
void clear_screen();

string get_word();

bool leave_or_not();

void print_hint();

int scan_keyboard();

string to_lower(string user_input);

// main
char keyboard();
location explain_input(char word, Player &player, Map &map);

// slot functions in main.cpp
bool meet_room(string moving_result);
Player trigger_room_slot(string moving_result, Player player, Monster monster, Map map, int count);
string read_choice();
bool skip_slot();

// roles
int random_num();
double getProbability();

// slot functions in room.cpp
bool in_range(string user_input, vector<string> ans);
void short_pause();
string slot_choice(vector<string> ans);

// functions used in box
int box_choice(vector<string> ans);

// die
bool want_to_continue();

#endif