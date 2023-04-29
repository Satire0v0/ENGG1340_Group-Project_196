#include "base.h"
#include "global.h"
#include "map.h"
#include "player.h"
#include "saving.h"
#include "monster.h"
#include "game.h"
#include "room.h"
#include <unistd.h>

using namespace std;


int main(){
    // class declaration
    Map map;
    Player player;
    Monster small_monster;
    Monster big_monster;

    // Variable declaration for game operation
    int diff_level = 0; // upgrade with time
    string moving_result; // used for monitoring the special char endiff_levelered by player
    location move_loc;

    char userInput;
    char current_block=' ';
    player.talent.set(1, 1, false, false);
    
    /*Start Game*/

    // New Game or Read Old Game?
    string choice = read_choice();
    
    if (choice == "read"){
        export_data(player, map);
        map.generate_player(player.get_loc());

    }
    else if (choice == "new"){
        if (skip_slot() == false){
            player = train1(player);
        }
        
        map.initialize();
        map.generate_player(player.get_loc());
    }
    
    while (true){
        clear_screen();
        // map_printing
        if (player.talent.super_vision == true) map.super_vision_print();
        else if (player.talent.vision == true) map.vision_print(player.get_loc());
        else map.print_map();

        cout << endl;
        player.show_info();

        cout << endl;
        cout << "******  press 'h' to see the hint | 'e' to stop the game | 'q' to save archive ******" << endl;
        
        userInput = keyboard();
        move_loc = explain_input(userInput, player, map);
    

        moving_result = map.check_block(move_loc, player.get_loc());

        // if not wall or no_update, then the map can update
        if (moving_result != "wall" && moving_result != "no_update"){
            map.update_block(player.get_loc(), current_block); // change the block at player_loc
            player.update_loc(move_loc); // player moves forward
            map.generate_player(player.get_loc()); // regenerate the player by using new player_loc
        }

        // player meets room
        if (meet_room(moving_result)){
            player = trigger_room_slot(moving_result, player, big_monster, map, diff_level);
            current_block = ' ';
        }
        // meeting small monster, attack() occurs
        else if (moving_result == "small_monster"){
            // fight
            player = attack(player, small_monster, map, diff_level);
            current_block = ' ';
        }
        // meeting big monster, difficulty increases, attack() occurs
        else if (moving_result == "big_monster"){
            // upgrade big monster's attributes by 1.5
            big_monster.set(big_monster.get_HP() * 1.5,\
                            big_monster.get_maxHP() * 1.5,\
                            big_monster.get_ATK() * 1.5,\
                            big_monster.get_prob() * 1.5);
            // fight
            player = attack(player, big_monster, map, diff_level);
            current_block = ' ';
        }
        // box, increase attributes
        else if (moving_result == "box"){
            clear_screen();
            player = map.box(player);
            current_block = ' ';
        }
        // meeting hidden box, choose talent
        else if (moving_result == "hidden_box"){
            clear_screen();
            player = map.hiddenbox(player);
            current_block = ' ';
        }
        // meeting hidden monster, random game happens
        else if (moving_result == "hidden_monster"){
            cout<<"A fog suddenly appears, and you faint and enter a dream" << endl;
            randomFunction(player.talent.mult, diff_level);
            diff_level++;
        }
        // reaching end
        else if (moving_result == "E"){
            Monster E;
            E.set(1000,1000,800,0.25);
            cout<< "a grotesque figure staggering towards you, its flesh rotting and dripping with blood. Its eyes are sunken and lifeless, its teeth yellow and jagged. It lets out a guttural roar that chills your bones, and lunges at you with its clawed hands. You barely have time to react as the zombie tries to bite your neck and rip you apart..."<<endl;
            player = attack(player, E, map, diff_level);
        }
        // normal movement
        else if (moving_result == "empty"){
            current_block = ' ';
        }
            
    }
    return 0;
}