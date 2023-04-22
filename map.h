#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "global.h"
#include "player.h"

using namespace std;

string reward1="|||    Treat your injury, HP+20     |||";
string reward2="|||             ATTACK+5            |||";
string reward3="||| Increase your accuracy, Prob+0.005 |||";
string reward4="||| Raise your maximum health by 50 points, maxHP+25 |||";
string reward5="|||   Increase your defence, DEF+5  |||";
string vision= "(Get a night vision device and you can always see hidden objects around you within a 3*3 range)";
string multiple="(The number of the count will be increased by 1 when you press the 'F' button once )";
string maxhp="Your maxHP will be doubled";
string doubleatk="Your ATK will be doubled";
string doubledef="Your DEF will be doubled";
string accurate="(Accurate attack)Your prob will always be 1";
string supernightvision= "(Supernightvision) You can see all the hidden objects in the map.";
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

        Player box(Player player);
        Player hiddenbox(Player player);
        void initialize();
        void print_map(Player player);
        void read_map();
        void update_block(location loc, char block);
        void generate_player(location player_loc);
        string check_block(location move_loc, location player_loc);
        vector<string> selectRewards(vector<string> rewards);
        size count_size();
        void map_reading();
        void generate_empty_map();
        void map_saving();



        
};

#endif