#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include <iostream>
using namespace std;

struct Talent{
    int mult;
    bool vision;
};

class Player{
    private:
        location loc={2,1};
        
        
    public:
        Talent talent;
        location get_loc();
        void update_loc(location move_loc={0,0});
};

#endif