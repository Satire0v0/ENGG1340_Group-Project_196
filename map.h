#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>

#include "global.h"

using namespace std;


class Map{
    private:
        int MAP_WIDTH = 60;
        int MAP_HEIGHT = 22;
        int ROOM_NUM = 8;
        size ROOM_MIN_SIZE = {4,3};

        char WALL = '%';
        char EMPTY = ' ';
        char PLAYER = 'O';

        char UNUSED = '?';

        char map[200][200]; // set a maximum map initially
    
    public:
        void generate_empty_map();
        void initialize();
        void print_map();
        void update_whole(char new_map[200][200]);
        void read_map();
        void update_block(location loc, char block);
        void generate_player(location player_loc);
        string check_block(location move_loc, location player_loc);
        int count_height();
        int count_width();
};

#endif