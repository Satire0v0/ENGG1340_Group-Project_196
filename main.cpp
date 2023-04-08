#include "base.h"
#include "global.h"

#include "map.h"
#include "player.h"

using namespace std;


int main(){
    // class declaration
    Map map;
    Player player;

    // Variable declaration
    string moving_result; // used for monitoring the special char encountered by player
    location move_loc;

    char userInput;
    char block=' ';

    // start the game
    map.initialize();
    map.generate_player(player.get_loc());
    
    while (true){
        clear_screen(); 
        cout << endl;

        map.print_map();

        cout << "******  press 'h' to see the hint | 'e' to stop the game ******" << endl;

        userInput = keyboard();
        move_loc = explain_input(userInput);

        moving_result = map.check_block(move_loc, player.get_loc());

        if (moving_result == "empty"){
            map.update_block(player.get_loc(), block);
            player.update_loc(move_loc);
            map.generate_player(player.get_loc());
        }
    }
    return 0;
}
