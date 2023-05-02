#include "base.h"
#include "global.h"
#include "map.h"
#include "player.h"
#include "saving.h"
#include "monster.h"
#include "game.h"
#include "room.h"
using namespace std;


int main(){    
    /*Start Game*/
    while (true){
        /*class declaration*/
        Map map;
        Player player;
        Monster small_monster;
        Monster big_monster;

        /*Variable declaration for game operation*/
        int diff_level = 0; // upgrade with time
        bool transfer = false; // player will transfer when playing
        char userInput; // player's input
        char current_block = ' '; // used to upgrade the map
        string moving_result; // used for monitoring the special char encountered by player
        location move_loc; // player's movement in 4 directions
        bool hidden_room = false; // used for room &
        player.talent.set(1, 1, false, false); // initialize the player's talent

        /*New Game or Read Old Game?*/
        string choice = read_choice();
        
        if (choice == "read"){
            export_data(player, map, diff_level);
        }
        else if (choice == "new"){
            while (true){ // whether watch slots
                int decision = yes_or_no("There will be a fantastic slot later", "Do you want to skip? (y / n)", true);
                if (decision == 1) break;
                else if (decision == 0){
                    player = train1(player);
                    break;
                }
                else continue;
            }
            
            map.initialize(); // initialize
            
            while (true){ // print hint for player
                clear_screen();
                print_hint();
                int decision = yes_or_no("Do you want to leave? (y / n)", "", false);
                if (decision == 1) break;
                else continue;
            }
        }

        map.update_block(player.get_loc(), 'O'); // Generate player on the map
        
        /*player enters map*/
        while (true){
            clear_screen();

            /*Player will transfer during playing*/
            if (transfer = true){
                map.update_block(player.get_loc(), 'O');
                transfer = false;
            }

            /*different talent corresponds to different map printing*/
            if (player.talent.super_vision == true) map.super_vision_print();
            else if (player.talent.vision == true) map.vision_print(player.get_loc());
            else map.print_map();
            // map.super_vision_print(); // for test

            cout << endl;
            player.show_info(); // show player's info

            cout << endl;
            cout << "******  press 'h' to see the hint | 'e' to stop the game | 'q' to save archive ******" << endl; // shortcuts

            /*used for hidden slot*/
            if (moving_result == "&" && ! (player.talent.vision == true || player.talent.super_vision == true)){
                cout << endl;
                cout << "It seems that there is something strange here" << endl;
                cout << endl;
            }
            
            /*player operation*/
            userInput = keyboard(); // detect what player has entered
            move_loc = explain_input(userInput, player, map, diff_level); // explain the meaning of player's input
            moving_result = map.check_block(move_loc, player.get_loc()); // if moving, the next block is first returned

            /*update map*/
            if (moving_result != "%" && moving_result != "no_update"){ // if not wall or no_update, then the map can update
                
                map.update_block(player.get_loc(), current_block); // change the block at player_loc (old location)
                player.update_loc(move_loc); // player moves forward (new location generated)

                if (moving_result == "5" || moving_result == "#" || moving_result == "?" || moving_result == "9"){ // player transfer, therefore new location should be cleared directly
                    map.update_block(player.get_loc(), ' ');
                }
                else{
                    map.update_block(player.get_loc(), 'O'); // regenerate the player through player's new location
                }
                
            }

            /*different results after operation*/
            if (meet_room(moving_result)){ // player meet room num

                if (!(moving_result == "&" && hidden_room == true)){ // if player has met & before, no trigger
                    player = trigger_room_slot(moving_result, player, big_monster, map, diff_level);
                }

                if (moving_result == "5" || moving_result == "#" || moving_result == "?" || moving_result == "9"){
                    transfer = true;
                }

                if (moving_result == "&" && ! (player.talent.vision == true || player.talent.super_vision == true)){
                    current_block = '&';
                }
                else{
                    if (moving_result == "&" && (player.talent.vision == true || player.talent.super_vision == true)){
                        hidden_room = true;
                    }

                    current_block = ' ';
                }
            }

            else if (moving_result == "m"){ // meeting small monster, attack() occurs
                // fight
                player = attack(player, small_monster, map, diff_level);
                current_block = ' ';
                diff_level++;
            }

            else if (moving_result == "M"){ // meeting big monster, attack() occurs and difficulty increases
                /*upgrade big monster's attributes by 1.2*/
                big_monster.set(big_monster.get_HP() * 1.2,\
                                150,\
                                big_monster.get_ATK() * 1.2,\
                                big_monster.get_prob() * 1.8);
                                
                if (big_monster.get_prob() > 1){
                    big_monster.set_prob(1);
                }
                player = attack(player, big_monster, map, diff_level);
                current_block = ' ';
                diff_level++;
            }

            else if (moving_result == "$"){ // box (increase player attributes)
                clear_screen();
                player = map.box(player);
                current_block = ' ';
            }
            
            else if (moving_result == "*"){ // meeting hidden box, choose talent
                clear_screen();
                player = map.hiddenbox(player);
                current_block = ' ';
            }
            
            else if (moving_result == "@"){ // meeting hidden monster, random game happens
                // cout << endl;
                clear_screen();
                cout << "A fog suddenly appears, and you faint and enter a dream" << endl;
                cout << endl;
                player = randomFunction(player, player.talent.mult, diff_level);
                diff_level++;
            }
            
            else if (moving_result == "E"){ // reaching end / facing boss
                Monster E;
                bool endwin;
                E.set(1000,1000,800,0.25);
                // cout << endl;
                clear_screen();
                cout << "A grotesque figure staggering towards you, its flesh rotting and dripping with blood." << endl;
                cout << "Its eyes are sunken and lifeless, its teeth yellow and jagged. It lets out a guttural roar that chills your bones, and lunges at you with its clawed hands. " << endl;
                cout << "You barely have time to react as the zombie tries to bite your neck and rip you apart..." << endl;
                short_pause();
                player = attack(player, E, map, diff_level);
                if (player.get_HP()>0){
                    cout << "After a roar, the teriffiying zombie turned into a pool of blood"<<endl;
                    short_pause();
                    cout<< "The sunlight shone on you mildly from the end of the exit."<<endl;
                    cout<< "You breathed in the fresh air, smiled and walked out...."<<endl;
                    sleep(1);
                    cout<< "Congratulations!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                    sleep(1);
                    cout<<"You have found the exit of this zombie train. The story of this game has reached the end. But you are still able to explore the map."<<endl;
                    short_pause();

                    while (true){
                        int decision = yes_or_no("Do you want to leave? (y / n)", "", false);
                        if (decision == 1) exit(0);
                        else if (decision == 0) break;
                        else continue;
                    }
                }

            }
            
            else if (moving_result == " "){ // normal movement
                current_block = ' ';
            }

            /*when player die*/
            if (player.get_HP() <= 0){
                int decision = 1; // new game by default
                while (true){
                    int decision = yes_or_no("You have died", "Want to restart? (y / n)", true);
                    if (decision == 1) break;
                    else if (decision == 0) exit(0);
                    else continue;                    
                }

                if (decision == 1){
                    break;
                }
                
            }
        // a new game will begin
        }
    }
    return 0;
}
