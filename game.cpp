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

    cout << "number bomb!" << std::endl;

    while (!game_over) {
        cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
        cin >> player_guess;
        while (player_guess <lower | player_guess > upper){
            cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
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
            cout << "THE COMPUTER GUESSES: " << computer_guess << std::endl;

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


int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


bool start_game(){
    string choice;
    vector<string> ans;
    ans.push_back("yes");
    ans.push_back("y");
    ans.push_back("no");
    ans.push_back("n");

    while (true){
        clear_screen();
        cout << "Want to start? (yes / no)" << endl;
        cout << endl;
        cout << "Your choice -> ";
        choice = get_word();
        choice = to_lower(choice);

        for (int i=0; i<ans.size(); i++){
        // find whether input is in the range
            if (choice == ans[i]){
                if (choice == "no" || choice == "n"){
                    return false;
                }
                else if (choice == "yes" || choice == "y"){
                    return true;
                }
            }
        }
    }
}


bool keyboard_game(int talent_mult,int difficulty=30){
    gamestatus kb;
    int multiple = talent_mult;
    int count = 0;
    time_t start = time(0);

    cout << "Press f as many times as you can in 5 seconds! You need to press "<< difficulty <<" times to win!" << endl;

    cout << endl;

    while (true) {

        if (time(0) - start >= 5) {
            cout << "Game over" << endl;
            cout << "You have pressed " << count << " times." << endl;
            cout << endl;
            break;
        }

        char ch = getch();
        if (ch == 'f') {
            count += multiple;
            cout << count << endl;
        }
    }

    if (count > difficulty){
        cout << "You win!" << endl;
        kb.win=true;
    }
    else{
        cout << "You lose!" << endl;
        kb.win=false;
    }
    return kb.win;
}



Player attack(Player player, Monster monster, Map map, int diff_level){
    // fight starts
    while (true){
        // when HP is 0, fight is over
        if (player.get_HP() <= 0 || monster.get_HP() <= 0){

            while (true){
                clear_screen();

                player.show_info();
                monster.show_info();
                cout << endl;

                if (player.get_HP() > 0){
                    cout << "Now you will have a keyboard game" << endl;
                    cout << endl;
                    player=countdown(player, map, diff_level);
                }

                if (leave_or_not()){
                    return player;
                }
            }
        }
        else{
            clear_screen();

            // describe
            cout << "Both players and monsters have a probability to hit each other" << endl;
            cout << endl;
            
            player.show_info();
            monster.show_info();
            
            cout << endl;

            cout << "Press any key to fight" << endl;
            int user_input = scan_keyboard();

            // 
            // cout << endl;

            player.update_HP( (-1) * monster.attack());
            monster.update_HP( (-1) * player.attack());
        }   
    }
}


char getch2(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror("tcsetattr ~ICANON");
    return buf;
 }
Player countdown(Player player, Map map, int count) {
    bool win=false;
    cout << "You have 5 seconds to choose yes or no (enter y or n): ";
    for (int i = 5; i > 0; i--) {
        cout << i << endl;
        cout.flush();
        sleep(1);
    }
    cout << endl;

    char input = getch2();
    if (input == 'Y' || input == 'y') {
        cout << "Press as many as ‘f’ as you can to win an reward!!!";
        win = keyboard_game(player.talent.mult, 30+10*(count));
        if (win == true){
                count++;
                player = map.box(player);
            }
    } else if (input == 'N' || input == 'n') {
        cout << "Good luck!!!";
        return player;
    } else if (input == 0) {
        cout << "No input detected" << endl;
        cout << "Good luck!!!";
        return player;
    } else {
        cout << "Invalid input ";
    }
    return player;
}


void randomFunction(int talent_mult, int count) {
    srand(time(0));
    int randomNum = rand() % 4 + 1;
    bool win = false;

    switch(randomNum) {
        case 1:
            number_guess();
            break;
        case 2:
            guess_dice();
            break;
        case 3:
            rpsgame;
            break;
        case 4:
            win = keyboard_game(talent_mult, 30+count*10);
            if (win){
                count++;
            }
            break;
    }
}
