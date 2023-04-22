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
//    Player player;
    ofstream saveFile; 
    saveFile.open("saving.txt");
    if (saveFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else
    {
        location loc = player.get_loc();
        double HP = 0, Attack = 0;
        //cout << " this is the saving cpp \n";
        //row和col在同一行，用空格隔开
        //HP等具体变量
        //Attack等具体变量
        //cout << loc.row << " " << loc.col << " loc row col \n";
        //sleep(1);
        saveFile << loc.row << " " << loc.col << endl << HP << endl;
        saveFile << Attack << endl;
        map.map_saving();
    } 
}

location export_data(Map &map)
{
    ifstream saveFile; 
    saveFile.open("saving.txt");
    location loc;
    loc.row = 0;
    loc.col = 0;
    if (saveFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else
    {
        size mapsize;
        double HP, Attack;
        saveFile >> loc.row;
        saveFile >> loc.col;
        saveFile >> mapsize.height;
        saveFile >> mapsize.width;
        saveFile >> HP;
        saveFile >> Attack;
        //cout << loc.row << " " << loc.col << " loc row col in saving.txt\n";
        map.map_reading();
        sleep(2);
        return loc;
    }
    return loc;
}

