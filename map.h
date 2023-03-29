#include <string>
using namespace std;

struct size{
    int width;
    int height;
};

struct loc{
    int x;
    int y;
};

struct room
{
    size Size;
    loc Loc;
};


const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 25;
const int ROOM_NUM = 8;
const char WALL = '%';
const char ROOM = '#';
const char CONNECTOR = '_';
const size ROOM_MIN_SIZE = {4, 3};


class Map{
    public:
        char map[MAP_HEIGHT][MAP_WIDTH];
        room rooms[ROOM_NUM];

        void initialize();
        void getRoomLoc();
        void MapRoom();
        void printMap();
};