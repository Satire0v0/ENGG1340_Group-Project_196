#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "global.h"
#include "player.h"

using namespace std;

class Player;

class Map{
    private:
        int MAP_WIDTH;
        int MAP_HEIGHT;
        int ROOM_NUM = 8;
        size ROOM_MIN_SIZE = {4,3};

        char WALL = '%';
        char EMPTY = ' ';
        char PLAYER = 'O';
        char BIG_MONSTER = 'M';
        char SMALL_MONSTER = 'm';
        char BOX = '$';
        char HIDDEN_BOX = '*'; // invisible
        char HIDDEN_MONSTER = '@'; // invisible
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

        char HIDDEN_FIVE = '&';
        char HIDDEN_LETTER = 'L';
        char HIDDEN_DOOR = '#';
        
        char WINDOW = 'W';
        char TRANSFER = '?';

        // 2-dimensional dynamic array
        char** map;
    
    public:
        // basic
        void initialize();
        void print_map();
        void read_map(string fileName);
        void update_block(location loc, char block);
        string check_block(location move_loc, location player_loc);
        void count_size(string fileName);
        void empty_map();

        // reward
        vector<string> selectRewards(vector<string> rewards);

        // box
        Player box(Player player);
        Player hiddenbox(Player player);

        // reward triggers
        void vision_print(location player_loc);
        void super_vision_print();

        // store map
        void map_saving();
};

#endif
