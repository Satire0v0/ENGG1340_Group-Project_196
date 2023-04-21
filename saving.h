#ifndef SAVING_H
#define SAVING_H

#include "iostream"
#include "fstream"
#include "map.h"
#include "player.h"
#include "global.h"
#include <unistd.h>
using namespace std;



struct saved_data
{
    int data;
    saved_data *next;

};

void save_data(Player &player, Map &map);

location export_data(Map &map);




#endif