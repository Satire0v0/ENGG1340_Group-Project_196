#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include <iostream>
using namespace std;

class Player{
    private:
        location loc={2,1};
        
    public:
        location get_loc();
        void update_loc(location move_loc={0,0});
};

#endif