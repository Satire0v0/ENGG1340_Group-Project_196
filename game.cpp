#include "game.h"

using namespace std;


struct gamestatus{
    bool win=false;
};


bool rpsgame(){
    int userChoice, computerChoice;
    gamestatus rps;
    short_pause();
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


bool guess_dice() {
    short_pause();
    gamestatus die;
    string player_guess;
    srand(time(0));
    int dice = rand() % 6 + 1;

    cout << "Please guess if the number on the dice is big or small, input 'Big' if the number is lower or equal to 3, otherwise please input 'Small'. " << endl;
    cin >> player_guess;
    while ( player_guess != "Big" && player_guess !="Small"){
        cout<<"You can only input 'Big' or 'Small'"<<endl;
        cin >> player_guess;
    }
    sleep(2);
    if (player_guess == "Big" && dice > 3) {
        cout << "The number is "<< dice << ". You win !!!"<< endl;
        die.win=true;
        short_pause();
        return die.win;
    } else if (player_guess == "Small" && dice <= 3) {
        cout << "The number is "<< dice << ". You win !!!"<< endl;
        die.win=true;
        short_pause();
        return die.win;
    } else {
        cout << "The number is "<< dice << ". You lose ~~~"<< endl;
        die.win=false;
        short_pause();
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
    short_pause();
    srand(time(0));
    
    bomb = rand() % 100 + 1;

    cout << "number bomb!" << std::endl;

    while (!game_over) {
        cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
        cin >> player_guess;
        while (player_guess <lower || player_guess > upper){
            cout << "please guess a number within the range (" << lower << " --- " << upper << "): ";
            cin >> player_guess;
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
    sleep(2);
    short_pause();
    return numberbomb.win;
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


bool keyboard_game(int talent_mult,int difficulty=30){
    short_pause();
    gamestatus kb;
    int multiple = talent_mult;
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
            cout << "Game over" << endl;
            cout << "You have pressed " << count << " times." << endl;
            cout << endl;
            break;
        }
    }

    short_pause();
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


Player countdown(Player player, Map map, int count) {
    bool win=false;
    char input;
    bool judge;

    vector<string> fixed_ans;
    fixed_ans.push_back("yes");
    fixed_ans.push_back("y");
    fixed_ans.push_back("no");
    fixed_ans.push_back("n");
    string choice;


    cout<<"Enter the reward stage (y/n) -> ";

    while (true){
        bool flag = false;
        choice = get_word();
        choice = to_lower(choice);

        for (int i=0; i<fixed_ans.size(); i++){
            if (choice == fixed_ans[i]){
                if (choice == "yes" || choice == "y"){
                    input = 'y';
                    flag = true;
                    break;
                }
                else if (choice == "no" || choice == "n"){
                    input = 'n';
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true){
            break;
        }
    }

    if (input == 'y'){
        
        cout << "Press as many as ‘f’ as you can to win an reward!!!";

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
        cout << "Good luck!!!";
        return player;
    }

}


Player randomFunction(Player player, int talent_mult, int count) {
    srand(time(0));
    int randomNum = rand() % 4 + 1;
    bool win = false;

    switch(randomNum) {
        case 1:
            if (number_guess()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.update_HP(-10);
            }
            break;
        case 2:
            if (guess_dice()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.update_HP(-10);
            }
            break;
        case 3:
            if (rpsgame()){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.update_HP(-10);
            }
            break;
        case 4:
            win = keyboard_game(talent_mult, 30+count*10);
            if (win){
                cout << "After a burst of vertigo, you wake up from where you were" << endl;
            }
            else{
                cout << "You wake up from yelling. You feel more tired" << endl;
                player.update_HP(-10);
            }
            break;
    }
    short_pause();
    return player;
}
