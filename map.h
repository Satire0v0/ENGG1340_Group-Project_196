#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>

#include "global.h"

using namespace std;


class Map{
    private:
        int MAP_WIDTH = 60;
        int MAP_HEIGHT = 25;
        int ROOM_NUM = 8;
        size ROOM_MIN_SIZE = {4,3};

        char WALL = '%';
        char ROOM = '#';
        char CONNECTOR = '_';
        char MONSTER = 'M';
        char DRUG = 'D';

        char map[200][200];
    
    public:
        void initialize();
        void print_map();
        void update_whole(char new_map[200][200]);
        void read_map();
        void update_block(int x, int y, char new_block);
        string check_block(location loc, location player_loc);
};

#endif