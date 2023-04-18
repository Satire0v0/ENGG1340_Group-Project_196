#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include "game.h"


using namespace std;


struct gamestatus{
    bool win=false;
};
bool rpsgame(){
    int userChoice, computerChoice;
    gamestatus rps;
    cout << "Rock paper scissors!\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Your choice: ";
    cin >> userChoice;

    srand(time(0));
    computerChoice = rand() % 3 + 1;
    if (userChoice == computerChoice) {
        cout << "Draw!\n";
        return rpsgame() ;
    } else if ((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1)) {
        cout << "You win!\n";
        rps.win=true;
        return rps.win;
    } else {
        cout << "You lose!\n";
        rps.win=false;
        return rps.win;
    }
}


bool guess_dice() {
    gamestatus die;
    string player_guess;
    srand(time(0));
    int dice = rand() % 6 + 1;
    cout << "Please guess if the number on the dice is big or small, input 'Big' if the number is lower or equal to 3, otherwise please input 'Small'. " << endl;
    cin >> player_guess;
    while ( player_guess != "Big" | player_guess !="Small"){
        cout<<"You can only input 'Big' or 'Small'"<<endl;
        cin >> player_guess;
    }
    if (player_guess == "Big" && dice > 3) {
        cout << "The number is "<< dice << ". You win !!!"<< endl;
        die.win=true;
        return die.win;
    } else if (player_guess == "Small" && dice <= 3) {
        cout << "The number is "<< dice << ". You win !!!"<< endl;
        die.win=true;
        return die.win;
    } else {
        cout << "The number is "<< dice << ". You lose ~~~"<< endl;
        die.win=false;
        return die.win;
    }
}


bool number_guess(){
    int lower = 1;
    int upper = 100;
    int bomb;
    int player_guess;
    int computer_guess;
    bool game_over = false;
    gamestatus numberbomb;
    srand(time(0));
    
    bomb = rand() % 100 + 1;

    cout << "number bomb！" << std::endl;

    while (!game_over) {
        cout << "please guess a number within the range（" << lower << " --- " << upper << "）：";
        cin >> player_guess;
        while (player_guess <lower | player_guess > upper){
            cout << "please guess a number within the range（" << lower << " --- " << upper << "）：";
        }
        if (player_guess == bomb) {
            cout << "You found the bomb! Game OVER. You Lose!" << std::endl;
            game_over = true;
            numberbomb.win=false;

        } else if (player_guess < bomb) {
            lower = player_guess;
        } else {
            upper = player_guess;
        }

        if (!game_over) {
            computer_guess = rand() % (upper - lower + 1) + lower;
            cout << "THE COMPUTER GUESSES：" << computer_guess << std::endl;

            if (computer_guess == bomb) {
                cout << "The computer found the bomb! game over, you win" << std::endl;
                game_over = true;
                numberbomb.win=true;
            } else if (computer_guess < bomb) {
                lower = computer_guess;
            } else {
                upper = computer_guess;
            }
        }
    }
    return numberbomb.win;
}


bool keyboard(int player.talent.keyboard,int difficulty=60){
    int multiple=player.talent.keyboard;
    int count = 0;
    time_t start = time(0);

    cout << "Press f as many times as you can in 10 seconds!" << endl;

    while (true) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 'f') {
                count += multiple;
                cout << count << endl;
            }
        }

        if (time(0) - start >= 10) {
            break;
        }
    }

    if (count > difficulty) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }

}