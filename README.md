# Rogue

## Team members


He Yijie, Li Renjie, Liu Haisu, Wu Yihan, Xiao Heng

## Introduction


Now it is 22:15 in a snowy and shivering night, you stand on a railway platform, waiting for the last train of the day to go home after a big day. Your home is 100 miles away from where you work.

Suddenly, a gust of wind comes and you hear the sound of the train. At the same time, the station broadcasting says the train will arrive after 15 minutes. “It is quite strange” you whisper quietly.

## Gaming rules


There are two stages in total. For the first stage, the player needs to make appropriate choices to advance the story, and different choices may have an impact on subsequent gameplay (being killed or moving to the next level). 

If the right choice is made, the player can move on to the second stage, which is the main part of our game.

The map on the second level is a dungeon, the player can move by pressing (W, A, S, D), 
+ **%** in the map represents the wall.
+ **M** represents the elite monster which will grow with the story.
+ **m** represents the miscellaneous monsters (their battle information is constant).
+ **number** indicates the story.
+ **#** and **?** represents the secret door (passing through it will be teleported to another location on the map). 
+ **$** represents the normal reward box which can be seen from the map directly.
+ there are also hidden reward boxes which are not visible to the players if they do not have the talent : nightvision. We want to encourage the players to walk around on themselves, therefore the rewards in the hidden boxes would be better than that in the normal boxes.
During the game, if the player meet any of the monsters, the player will automatically enter the battle screen, if the player is able to kill the monster and win, the player will have to choose whether to enter the bonus level, if the player chooses to enter the bonus level, they will play a keyboard presssing game, if passed, they can get a reward in the normal box. If the player loses the match, the game ends and the game will restart from the player's last saved record(if the player has saved, if not, the game will restart from the stage 1).

## Features implemented


### 1. Generation of random game sets or events

In **game.cpp**, we have four mini games. When players walk somewhere on the map, the system will randomly choose a mini game through the function **randomFunction()**.

### 2. Data structures for storing game status

In **player.h**, we use many data structures to store the status of the player.

### 3. Dynamic memory management

In **map.cpp**, we use 2-dimensional dynamic array.

### 4. File input/output

In **saving.cpp**, we achieve the game saving and loading. 
The function **read_map()** in **map.cpp** achieves the map loading.

### 5. Program codes in multiple files

In **main.cpp**, we include all files we need like **player.h**, **room.h**, **game.h**. Therefore, we can use functions from other files.

## Compilation and execution instructions


1. Type **make main**
2. Type **./main**
