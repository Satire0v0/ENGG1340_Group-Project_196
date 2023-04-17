#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct gamestatus{
    int win=0;
};
int rpsgame(){
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
        return rpsgame();
    } else if ((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1)) {
        cout << "You win!\n";
        rps.win++;
        return rps.win;
    } else {
        cout << "You lose!\n";
        return rps.win;
    }
}
int main(){
    rpsgame();
}