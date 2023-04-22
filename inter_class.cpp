#include "inter_class.h"

Player attack(Player player, Monster monster){
    while (true){
        if (player.get_HP() <= 0 || monster.get_HP() <= 0){

            while (true){
                clear_screen();

                player.show_info();
                monster.show_info();
                cout << endl;

                if (leave_or_not()){
                    return player;
                }
            }
        }
        else{
            clear_screen();
            
            player.show_info();
            monster.show_info();
            
            cout << endl;
            cout << "Press any key to fight" << endl;
            keyboard();
            cout << endl;

            player.update( (-1) * monster.attack(), 0, 0 );
            monster.update( (-1) * player.attack(), 0, 0 );
        }   
    }
}
