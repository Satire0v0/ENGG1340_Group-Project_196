#include "saving.h"
//txt文件的第一行是玩家位置row
//第二行是玩家位置col
//第三行是地图高。不需要了
//四：地图宽。不需要了
//5：血量。还需要添加
//6：攻击。还需要添加
//还需要根据其他文件的变量更新此文件
void save_data(Player &player, Map &map)
{
    // Player information
    ofstream saveFile; 
    saveFile.open("saving.txt");

    if (saveFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else{
        //cout << " this is the saving cpp \n";
        //row和col在同一行，用空格隔开
        //HP等具体变量
        //Attack等具体变量
        //cout << loc.row << " " << loc.col << " loc row col \n";
        //sleep(1);

        // Save player location first
        location loc = player.get_loc();
        saveFile << loc.row << " " << loc.col << endl;

        // Then save other player information
        saveFile << player.get_HP() << " " << player.get_ATK() << " " << player.get_DEF() << " " << player.get_maxHP() << " " << player.get_prob() << " " << player.get_weapon() << endl;
        saveFile << player.talent.mult << " " << player.talent.life <<  " " << player.talent.vision << " " << player.talent.super_vision << endl;

        // save map
        map.map_saving();
    } 
}


void export_data(Player &player, Map &map)
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
        
        /*
        player_loc = player.get_loc();

        loc.row -= player_loc.row;
        loc.col -= player_loc.col;

        player.update_loc(loc);
        */

        saveFile >> HP;
        player.set_HP(HP);

        saveFile >> ATK;
        player.set_ATK(ATK);

        saveFile >> DEF;
        player.set_DEF(DEF);

        saveFile >> maxHP;
        player.set_maxHP(maxHP);

        saveFile >> prob;
        player.set_prob(prob);

        saveFile >> weapon;
        player.update_weapon(weapon);

        // Player talent info
        int mult=0, life=0;

        saveFile >> mult >> life >> vision >> supernightvision;

        player.talent.set(mult, life, vision, supernightvision);
        //cout << loc.row << " " << loc.col << " loc row col in saving.txt\n";

        // Initialize the map
        map.count_size("savedMap.txt");
        map.empty_map();
        map.read_map("savedMap.txt");
        // map.map_reading();
    }
}

