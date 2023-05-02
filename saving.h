#ifndef SAVING_H
#define SAVING_H

#include "iostream"
#include "fstream"
#include "map.h"
#include "player.h"
#include "global.h"
#include <unistd.h>
using namespace std;


class Player;
class Map;


void save_data(Player &player, Map &map, int diff_level);

void export_data(Player &player, Map &map, int &diff_level);

#endif