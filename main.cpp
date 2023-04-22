#include "base.h"
#include "global.h"
#include <unistd.h>
#include "map.h"
#include "player.h"
#include "saving.h"
#include "monster.h"
#include "game.h"
#include "room.h"

using namespace std;


int main(){
    // class declaration
    Map map;
    Player player;
    Monster small_monster;
    Monster big_monster;

    // Variable declaration
    int count=0;
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
        player = train1(player);
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
        cout << moving_result << endl;

        if (moving_result != "wall" && moving_result != "no_update"){
            map.update_block(player.get_loc(), block); // change the block at player_loc
            player.update_loc(move_loc); // player moves forward
            map.generate_player(player.get_loc()); // regenerate the player by using new player_loc
        }

        
        if (moving_result == "1"){
            room2(player);
            block = ' ';
        }else if (moving_result == "2"){
            room3(player);
        }else if (moving_result == "3"){
            room4(player);
        }else if (moving_result == "4"){
            room5(player);
        }else if (moving_result == "5"){
            room6(player);
        }else if (moving_result == "&"){
            room5_Hidden(player);
        }else if (moving_result == "L"){
            room5_Letter(player);
        }else if (moving_result == "6"){
            room7(player);
        }else if (moving_result == "W"){
            room7_window(player, big_monster, count);
        }else if (moving_result == "room7_secret"){
            room7_secretdoor(player);
        }else if (moving_result == "7"){
            room8(player);
        }else if (moving_result== "8"){
            room9(player);
        /*
        }else if (moving_result== "9"){
            room10_secretdoor(player);
        */
      
        }else if (moving_result=="A"){
            room11(player);
        }else if (moving_result=="B"){
            room13(player);
        }else if (moving_result=="room10_secret"){
            room10_secretdoor(player);
        }else if (moving_result=="E"){
            Monster E;
            E.set(1000,1000,800,0.25);
            cout<< "a grotesque figure staggering towards you, its flesh rotting and dripping with blood. Its eyes are sunken and lifeless, its teeth yellow and jagged. It lets out a guttural roar that chills your bones, and lunges at you with its clawed hands. You barely have time to react as the zombie tries to bite your neck and rip you apart..."<<endl;
            player = attack(player, E, count);
        }else if (moving_result == "m"){
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            player = attack(player, small_monster, count);
        }
        else if(moving_result == "M"){
            big_monster.set(big_monster.get_HP() * 1.5,\
                            big_monster.get_maxHP() * 1.5,\
                            big_monster.get_ATK() * 1.5,\
                            big_monster.get_prob() * 1.5);
            player = attack(player, big_monster, count);
        }else if(moving_result=="@"){
            cout<<"A fog suddenly appears, and you faint and enter a dream"<<endl;
            randomFunction(player.talent.mult, count);
        }else if(moving_result=="$"){
            player=map.box(player);
        }else if(moving_result=="*"){
            player=map.hiddenbox(player);
        }
        else if (moving_result == "empty"){
            map.update_block(player.get_loc(), block); // change the block at player_loc
            player.update_loc(move_loc); // player moves forward
            map.generate_player(player.get_loc()); // regenerate the player by using new player_loc
        }
            
    }
    return 0;
}