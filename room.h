#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>


#include "game.h"
#include "player.h"
#include "monster.h"
#include "base.h"

using namespace std;

Player train1(Player player);
Player train2(Player player);
Player train3(Player player);
Player train4(Player player);
Player train5(Player player);
Player room1(Player player);
Player room2(Player player);
Player room3(Player player);
Player room4(Player player);
Player room5(Player player);
Player room5_Hidden(Player player);
Player room5_Letter(Player player);
Player room6(Player player);
Player room7(Player player);
Player room7_secretdoor(Player player);
Player room7_window(Player player, Monster monster, Map map, int count);
Player room8(Player player);
Player room9(Player player);
Player room10_secretdoor(Player player);
Player room11(Player player);
Player room13(Player player);

#endif
