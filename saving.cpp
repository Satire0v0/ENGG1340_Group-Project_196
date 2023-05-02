#include "saving.h"

void save_data(Player &player, Map &map, int diff_level)
{
    // Player information
    ofstream saveFile; 
    saveFile.open("saving.txt");

    if (saveFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else{
        // Save player location first
        location loc = player.get_loc();
        saveFile << loc.row << " " << loc.col << endl;

        // Then save other player information
        saveFile << player.get_maxHP() << " " << player.get_ATK() << " " << player.get_DEF() << " " << player.get_HP() << " " << player.get_prob() << " " << player.get_weapon() << endl;
        saveFile << player.talent.mult << " " << player.talent.life << " " << player.talent.vision << " " << player.talent.super_vision << endl;

        // Then save keyboard diffculty
        saveFile << diff_level;

        // save map
        map.map_saving();
    } 
}


void export_data(Player &player, Map &map, int &diff_level)
{
    location loc={0, 0};
    bool vision, supernightvision;

    ifstream saveFile; 
    saveFile.open("saving.txt");

    if (saveFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else{
        // Player basic info
        int HP=0, ATK=0, DEF=0, maxHP=0;
        double prob=0.0;
        string weapon="";

        saveFile >> loc.row;
        saveFile >> loc.col;
        player.set_loc(loc);

        saveFile >> maxHP;
        player.set_maxHP(maxHP);

        saveFile >> ATK;
        player.set_ATK(ATK);

        saveFile >> DEF;
        player.set_DEF(DEF);

        saveFile >> HP;
        player.set_HP(HP);

        saveFile >> prob;
        player.set_prob(prob);

        saveFile >> weapon;
        player.update_weapon(weapon);

        // Player talent info
        int mult=0, life=0;

        saveFile >> mult >> life >> vision >> supernightvision;

        player.talent.set(mult, life, vision, supernightvision);

        saveFile >> diff_level;

        // Initialize the map
        map.count_size("savedMap.txt");
        map.empty_map();
        map.read_map("savedMap.txt");
    }
}

