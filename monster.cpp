#include "monster.h"


int Monster::get_HP(){
    return HP;
}


int Monster::get_ATK(){
    return ATK;
}


void Monster::show_info(){
    cout << "Monster -> ";
    cout << "HP: " << HP << "/" << maxHP << " | ";
    cout << "ATK: " << ATK << endl;
} 


void Monster::update(int more_HP=0, int more_ATK=0, int more_maxHP=0){
    
    // HP
    if ((HP + more_HP) > maxHP){
        HP = maxHP;
    }
    else{
        HP += more_HP;
    }

    // ATK
    ATK += more_ATK;

    // maxHP
    maxHP += more_maxHP;
}


int Monster::attack(){
    if (getProbability() <= prob){
        return ATK;
    }
    else{
        return 0;
    }
}