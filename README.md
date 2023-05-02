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
+ During the game, if the player meet any of the monsters, the player will automatically enter the battle screen, if the player is able to kill the monster and win, the player will have to choose whether to enter the bonus level, if the player chooses to enter the bonus level, they will play a keyboard presssing game, if passed, they can get a reward in the normal box. If the player loses the match, the game ends and the game will restart from the player's last saved record(if the player has saved, if not, the game will restart from the stage 1).

## Features implemented
### 1. Treasure box
Three choices are chosen randomly. There are a number of choices provided for Player. Three of them will be randomly chosen. Some specific choices will not be chosen again once they are acquired by the Player. 

### 2. Interesting bonus games
There are four bonus games. Game 1: Press different times of ‘f’ within 5 seconds to win the game. Game 2: Guess the number on the die: big or small. Game 3: Rock, paper and scissors. Game 4: Fight with an imp. Guess the number bomb within a given range. Range will update if player guess the wrong number. Player loses game if player guess the number right.

Except the game 1, all games are generated randomly. The bonus game that player will play is randomly chosen. 

### 3. Hidden plots
There are some plots hidden from the Player. When Player reaches specific blockes, hidden plots will be displayed. 

### 4. Talent system
One of the most interesting part in the game. A night vision shows 3x3 hidden blocks around the Player. The supervision shows all hidden blocks in the map. The 'mult' talent will change the multiple of times of 'f' pressed in the bonus game 1. For instance, if 'mult' = 2, press 'f' once will be treated as being pressed twice. 

### 5. Save and read archive
The game status can be stored and read, including the attribute of players and monsters and the difficulty of games. 

### 6. Fighting stage
During fighting between Player and monsters, whether Player and monsters can deal damage each other is due to probability. 

## Coding requirements

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

## Problem Collection for Final Assessment

1. Real time reading of user keyboard input (solved) (Hanson-666)  
    When working on local computer, I can realize this function by simply using getch() function in the header file called <conio.h>. However, this library is not installed on HKU server. 

    After consulting with other friends, there is an alternative method, that is getch() introduced in <ncurses.h>. Luckily this header file is installed on server. Whereas, I realized that I needed to adhere to its specific initialization and output formats. It requires me to spend some time studying this library.

    Finally, I unintentionally found that the library <termio.h> could also work well.


2. Dynamic memory management of two-dimensional array named map (solved) (Hanson-666)  
Initially, I used fixed length, which is 200, to realize 2-dimensional array for storing map. However, it is a waste of memory. After studying module 8, I tried to realize dynamic two-dimensional array to make the program run more efficiently. In order to achieve this goal, after consulting a lot of materials, I realized that I needed to use pointers to achieve it. Therefore, the data type of map should be a pointer to the pointer in the project.
    ```C++
    char** map;
    ```

3. Input validation (solved) (Hanson-666)  
In order to avoid that player will enter unrelated input on certain circumstances. After many trials, I choose to use <vector> to store the correct answers first. For convenience, the data type is set as string and all input will be changed to lower case for comparsion. This method fits all input validation needed by the whole project. I also write a common validation function for this.

4. Random function (solved) (Ianwu0907)  
Random events generating functions are used in the game, e.g: the boxes, hidden events. I choose to u0se vectors to store all the choices, and use a random number generating function to make random choices. 

5. Undefined reference of class (solved) (Li Renjie)  
During the process of realising the game, classes are defined in map.h and player.h and used in other files as parameters. When do make main, the undefined reference of classes 'Map' and 'Player' occurs. We redefine the two classes in other files to avoid the error. 

6. Map construction according to plots (solved) (Ianwu0907)  
It takes a lot of effort to perfectly combine the plot with the map. We want to make sure that players have freedom and at the same time, we also hope that players can experience our exciting plot and make choices in different places based on the plot. Therefore, the map was actually constructed by a fixed main road with samll rooms in which player can move freely.

7. Predict the next block the Player will move to (solved) (Hanson-666)  
In order to meet the different needs of the project, we need to predict the next steps that players will take in advance, and then make judgments in advance to facilitate modifications to the map and player attributes.