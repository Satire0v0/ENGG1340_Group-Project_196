#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "global.h"

using namespace std;


class Map{
    private:
        int MAP_WIDTH;
        int MAP_HEIGHT;
        int ROOM_NUM = 8;
        size ROOM_MIN_SIZE = {4,3};

        char WALL = '%';
        char EMPTY = ' ';
        char PLAYER = 'O';
        char BIG_MONSTER = 'm';
        char SMALL_MONSTER = 'M';
        char BOX = '$';
        char HIDDEN_BOX = '*'; // invisible
        char HIDDEN_MONSTER = '@'; // invisible
        char WINDOW = 'W';
        char HIDDEN_DOOR = '#'; // invisible
        char END = 'E';

        // room number
        char ONE = '1';
        char TWO = '2';
        char THREE = '3';
        char FOUR = '4';    
        char FIVE = '5';
        char SIX = '6';    
        char SEVEN = '7';    
        char EIGHT = '8';
        char NINE = '9';
        char TEN = 'A';
        char ELEVEN = 'B';
    
        char UNUSED = '?';

        // 2-dimensional dynamic array
        char** map;
    
    public:
        void initialize();
        void print_map(player player);
        void read_map();
        void update_block(location loc, char block);
        void generate_player(location player_loc);
        string check_block(location move_loc, location player_loc);
        
        //*****addition*****
        size count_size();
        //*****addition*****
        
        void map_reading();
        //*****delete*****
        void generate_empty_map();
        //void update_whole(char new_map[200][200]);
        //int count_height();
        //int count_width();
        //*****delete*****


        
};

#endif
