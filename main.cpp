#include "base.h"
#include "global.h"
#include <unistd.h>
#include "map.h"
#include "player.h"
#include "saving.h"
#include "monster.h"
#include "game.h"

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
    
    cout << "Enter 'read' to read archive or enter 'new' to start new game \n";
    string choice;
    cin >> choice;
    if (choice == "read")
    {
        export_data(player, map);
    }
    else if (choice == "new")
    {
    // start the game
        map.initialize();
        map.generate_player(player.get_loc());
    }


    
    while (true){
        clear_screen(); 
        cout << endl;

        map.print_map(player);

        cout << "******  press 'h' to see the hint | 'e' to stop the game | 'q' to save archive ******" << endl;

        location a = player.get_loc();
        //cout << a.row << a.col << "a.row and acol" << &player << " player " << endl;
        

        userInput = keyboard();
        move_loc = explain_input(userInput, player, map);
        
        

        moving_result = map.check_block(move_loc, player.get_loc());
        
        if (moving_result == "empty"){
            map.update_block(player.get_loc(), block); // change the block at player_loc
            player.update_loc(move_loc); // player moves forward
            map.generate_player(player.get_loc()); // regenerate the player by using new player_loc
        }
        else if (moving_result == "small_monster")
        { 
            Monster small_monster;
            player = attack(player, small_monster);
        }
        else if (moving_result == "big_monster"){
            Monster big_monster;
            // HP, maxHP, ATK, prob
            big_monster.set(200, 200, 10, 0.5);
            player = attack(player, big_monster);
        }
    }
    return 0;
}
