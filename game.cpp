#include "game.h"

using namespace std;


struct gamestatus{
    bool win=false;
};

// Rock Paper SCissors game
bool rpsgame(){
    int userChoice, computerChoice;
    gamestatus rps;
    // short_pause();
    cout << "An imp appears and he wants to play Rock paper scissors with you!\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Your choice: ";
    cin >> userChoice;

    srand(time(0));
    computerChoice = rand() % 3 + 1;

    cout << endl;
    if (computerChoice == 1){
        cout << "The imp shows ROCK!"<<endl;
    }else if (computerChoice ==2){
        cout <<"The imp shows PAPER!"<<endl;
    }else if (computerChoice ==3){
        cout <<"The imp shows SCISSOR!"<<endl;
    }
    if (userChoice == computerChoice) {
        cout << "Draw!\n";
        short_pause();
        return rpsgame() ;
    } else if ((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1)) {
        cout << "You win!\n";
        rps.win=true;
        short_pause();
        return rps.win;
    } else {
        cout << "You lose!\n";
        rps.win=false;
        short_pause();
        return rps.win;
    }
}

// dice Guessing game, guess if the dice is big(>4) or small(<3)
bool guess_dice() {
    // short_pause();
    gamestatus die;
    string player_guess;
    srand(time(0));
    int dice = rand() % 6 + 1;

    cout << "Please guess if the number on the dice is big or small." << endl;
    cout << "Input 'Big' if the number is lower or equal to 3, otherwise please input 'Small'." << endl;
    cout << endl;
    cout << "Your choice -> ";
    cin >> player_guess;
    player_guess = to_lower(player_guess);
    cout << endl;

    while (player_guess != "big" && player_guess != "small"){
        cout << "You can only input 'Big' or 'Small' -> ";
        cin >> player_guess;
    }
    cout << endl;
    // sleep(2);
    sleep(1);
    if (player_guess == "big" && dice > 3) {
        cout << "The number is " << dice << ". You win !!!"<< endl;
        cout << endl;
        die.win=true;

        scan_keyboard(); // unexpected input from server
        short_pause();

        return die.win;
    } else if (player_guess == "small" && dice <= 3) {
        cout << "The number is " << dice << ". You win !!!"<< endl;
        cout << endl;
        die.win=true;

        scan_keyboard(); // unexpected input from server
        short_pause();

        return die.win;
    } else {
        cout << "The number is " << dice << ". You lose ~~~"<< endl;
        cout << endl;
        die.win=false;

        scan_keyboard(); // unexpected input from server
        short_pause();

        return die.win;
    }
}


int return_digit(){
    bool negative=false;
    string userInput;
    userInput = get_word();

    if (userInput[0] == '-'){ // check negative sign first
        negative = true;
        userInput = userInput.substr(1, userInput.length()-1);
    }

    for (int i=0; i<userInput.length(); i++){ // check whether there is non-digit num
        if (not isdigit(userInput[i])){
            return 0;
        }
    }

    int num = 0;
    istringstream iss(userInput);
    iss >> num;

    if (negative) return (-1)*num;
    else return num;
}

// number bomb game , the player and computer will guess a number within the range 1-100 in turn, the person who find the number bomb loses
bool number_guess(){

    int lower = 1;
    int upper = 100;
    int bomb;
    int player_guess;
    int computer_guess;
    bool game_over = false;
    gamestatus numberbomb;
    short_pause();
    srand(time(0));
    
    bomb = rand() % 100 + 1;

    cout << "An imp wants to play number bomb with you! You will guess a number in a range of 1 to 100, and the range will continue to reduce until one of you guesses the number bomb. " << endl;
    cout <<"THE PERSON WHO FIND THE NUMBER BOMB WILL LOSEEEEEEEEEEEEEEEEE!!!"<<endl;
    while (!game_over) {
        cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
        player_guess = return_digit();

        while (player_guess <lower || player_guess > upper){
            cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
            player_guess = return_digit();
        }
        if (player_guess == bomb) {
            cout << "You found the bomb! Game OVER. You Lose!" << endl;
            game_over = true;
            numberbomb.win=false;

        } else if (player_guess < bomb) {
            lower = player_guess;
        } else {
            upper = player_guess;
        }

        if (!game_over) {
            computer_guess = rand() % (upper - lower + 1) + lower;
            cout << "THE IMP GUESSES: " << computer_guess << endl;

            if (computer_guess == bomb) {
                cout << "The imp found the bomb! game over, you win" << endl;
                game_over = true;
                numberbomb.win=true;
            } else if (computer_guess < bomb) {
                lower = computer_guess;
            } else {
                upper = computer_guess;
            }
        }
    }
    sleep(2);
    short_pause();
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

// the player will have to press 'f' at lease (difficulty) times in 5 seconds to win. 
bool keyboard_game(int talent_mult,int difficulty=30){
    // short_pause();
    gamestatus kb;
    int multiple = talent_mult; // if the player have chosen the keyboard talent, pressing 'f' one time will count (mult) times. E.g. The player has chosen keyboard talent twice, mult=3 and pressing once'f' will count 3 times
    int count = 0;
    char leave;
    time_t start = time(0);

    cout << "Press f as many times as you can in 5 seconds! You need to press "<< difficulty <<" times to win!" << endl;

    cout << endl;

    while (true){
        char ch = getch();
        if (ch == 'f') {
            count += multiple;
            cout << count << endl;
        }

        if (time(0) - start >= 5) {
            int now = time(0);
            while (true){
                if ((time(0) - now) > 0.8){
                    break;
                }
                else{
                    if (getch() == 'f'){
                        time_t now = time(0);
                        continue;
                    }
                }
            }
            cout << endl;
            cout << "Game over !!!" << endl;
            cout << "You have pressed " << count << " times." << endl;
            cout << endl;
            break;
        }
    }

    // short_pause();
    if (count > difficulty){
        cout << "You win!" << endl;
        kb.win=true;
    }
    else{
        cout << "You lose!" << endl;
        kb.win=false;
    }
    short_pause();
    return kb.win;
}

// the attack system

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
                    cout << "You win" << endl;
                    short_pause();
                    player=countdown(player, map, diff_level);
                    return player;
                }
                return player;
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

            short_pause();

            player.update_HP( (-1) * monster.attack());
            monster.update_HP( (-1) * player.attack());
        }   
    }
}

// After printing out a notice, the player can choose to enter the reward stage
Player countdown(Player player, Map map, int &count) {
    bool win=false;
    char input;

    while (true){
        int decision = yes_or_no("Now you will have a keyboard game", "Enter the reward stage (y/n)", true);
        if (decision == 1){
            input = 'y';
            break;
        }
        else if (decision == 0){
            input = 'n';
            break;
        }
        else continue;
    }

    if (input == 'y'){
        clear_screen();
        cout << "Press as many as ‘f’ as you can to win an reward!!!" << endl;
        cout << endl;

        short_pause();
        win = keyboard_game(player.talent.mult, 30+10*(count));
        if (win == true){
                count++;
                player = map.box(player);
            }
        return player;
    }
    else {
        sleep(1);
        cout << "Good luck!!!" << endl;
        return player;
    }

}

//@ represents random activities which are hidden to the players, this function will randomly choose one mini game to play when the player encounters @
Player randomFunction(Player player, int talent_mult, int count){
    srand(time(0));
    int randomNum = rand() % 4 + 1;
    bool win = false;

    // clear_screen();
    switch(randomNum) {
        case 1:
            if (number_guess()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.set_HP(player.get_HP()-10);// if the player loses, he 10HP will be deducted.
            }
            break;
        case 2:
            if (guess_dice()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.set_HP(player.get_HP()-10);
            }
            break;
        case 3:
            if (rpsgame()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.set_HP(player.get_HP()-10);
            }
            break;
        case 4:
            win = keyboard_game(talent_mult, 30+count*10);
            if (win){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.set_HP(player.get_HP()-10);
            }
            break;
    }

    cout << endl;
    short_pause();
    return player;
}
