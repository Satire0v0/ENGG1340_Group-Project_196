#include "base.h"


void clear_screen(){
    system("clear"); // used for linux
    // system("cls"); // used for windows powershell
}


string get_word(){ // As all inputs are texts, therefore getting first effective word is enough
    string sentence, word;

    getline(cin, sentence); // this is used for avoiding wrong input
    istringstream line_in(sentence);
    line_in >> word;

    return word;
}


int yes_or_no(string sentence1, string sentence2, bool clear_all){ // used in final confirmation, accept two input strings
    string choice;
    vector<string> ans;

    ans.push_back("yes");
    ans.push_back("no");
    ans.push_back("y");
    ans.push_back("n");

    if (clear_all) clear_screen();
    if (sentence1 != "") cout << sentence1 << endl;
    if (sentence2 != "") cout << sentence2 << endl;
    cout << endl;
    cout << "Your choice -> ";
    choice = get_word();
    choice = to_lower(choice);

    for (int i=0; i<ans.size(); i++){
        if (choice == ans[i]){
            if (choice == "y" || choice == "yes"){
                return 1;
            }
            else if (choice == "n" || choice == "no"){
                return 0;
            }
        }
    }

    return -1; // user enter other words
}


void print_hint(){ // Player will get the meaning of differenct characters when pressing h
    char single_str[]={'w', 'a', 's', 'd', 'e', '$', 'O', 'm', 'M', '%', 'E'};
    string description[]={
        "Move up",
        "Move left",
        "Move down",
        "Move right",
        "Exit game",
        "Reward",
        "Player",
        "Small Monster",
        "Big Monster",
        "Wall",
        "Final Boss"
    };

    int longest=50; // find the longest description in order to fit the formats at any time
    
    /*print the hint*/
    cout << left;
    for (int i=0; i<11; i++){
        if (i==0) cout << "The description of the operation:" << endl;
        if (i==5){
            cout << endl;
            cout << "The description of the single character:" << endl;
        }
        cout << setw(5) << single_str[i] << setw(longest) << description[i] << endl;
    }
    cout << endl;
}


int scan_keyboard(){ // the function will return ASCII value of keyboard operation without 'Enter'
    int in;

    struct termios new_settings;
    struct termios stored_settings;

    tcgetattr(0,&stored_settings);

    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;

    tcgetattr(0,&stored_settings);

    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0,TCSANOW,&new_settings);
    
    in = getchar();
    
    tcsetattr(0,TCSANOW,&stored_settings);

    return in;
}


char keyboard(){ // detect key letters, which are case-insensitive
    char word = scan_keyboard();
    char result;

    if (word == 'w' || word == 'W') result = 'w';
    else if (word == 'a' || word == 'A') result = 'a';
    else if (word == 's' || word == 'S') result = 's';
    else if (word == 'd' || word == 'D') result = 'd';
    else if (word == 'h' || word == 'H') result = 'h';
    else if (word == 'e' || word == 'E') result = 'e';
    else if (word == 'q' || word == 'Q') result = 'q';
    else result = ' ';
    
    return result;
}


location explain_input(char word, Player player, Map map){ // each key letter has its own unique function
    location loc;
    string result;

    if (word == 'w'){
        loc.row = -1;
        loc.col = 0;
    }
    else if (word == 'a'){
        loc.row = 0;
        loc.col = -1;
    }
    else if (word == 's'){
        loc.row = 1;
        loc.col = 0;
    }
    else if (word == 'd'){
        loc.row = 0;
        loc.col = 1;
    }
    
    else if (word == 'h') // give hint
    {
        while (true){
            clear_screen();
            print_hint();
            int decision = yes_or_no("Do you want to leave? (y / n)", "", false);
            if (decision == 1) break;
            else continue;
        }
        loc.row = 0;
        loc.col = 0;
    }
    
    else if (word == 'e'){ // whether to exit the game
        cout << endl;
        cout << "Want to continue?" << endl;
        cout << "Press any key to continue, or enter 'Exit' to leave:" << endl;
        
        result = get_word();
        if (result == "exit" || result == "Exit") exit(0); // the game terminates
        else{
            loc.row = 0;
            loc.col = 0;
        }
    }
    
    else if (word == 'q'){ // whether to save the game
        string choice;
        cout << endl;
        // cout << "Enter 'save' to save archive | 'read' to restart from previous archive" << endl;
        cout << "Enter 'save' to save archive" << endl;
        cin >> choice;
        if (choice == "save")
        {
            save_data(player, map);
            exit(0);
        }
        else{
            loc.row = 0;
            loc.col = 0;
        }
        /*
        else if (choice == "read")
        {
            export_data(player, map);
            map.update_block(player.get_loc(), 'O');
        }
        */

    }
    
    else{ // otherwise, remain the same
        loc.row = 0;
        loc.col = 0;
    }

    return loc;
}

// Generate the randon number
int random_num(int lower_bound, int upper_bound){
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}


// calculate random probability used in 
double getProbability(){
    return random_num(0, 100) / 100.0; // integer divide integer is integer, therefore 100.0 is here
}


// the function used at the end of different slot functions
void short_pause(){
    cout << "Press any key to continue" << endl;
    int user_input = scan_keyboard();
}


// transfer into lowercase
string to_lower(string single_str){
    // if already single small char
    if ("a" <= single_str && single_str <= "z"){
        return single_str;
    }
    // if not
    else{
        transform(single_str.begin(), single_str.end(), single_str.begin(), ::tolower);
        return single_str;
    }
}


// choose when having different slot
string slot_choice(vector<string> ans){
    string choice;
    cout << "Your choice -> ";
    choice = get_word();
    choice = to_lower(choice);

    if (not in_range(choice, ans)){
        return "false";
    }
    else{
        return choice;
    }
}


bool in_range(string user_input, vector<string> ans){ // used for validation of choice (single char)
    if (user_input.length() != 1){ // user must enter single-char
        return false;
    }
    else for (int i=0; i<ans.size(); i++) if (user_input == ans[i]) return true; // find whether input is in the range
    return false; // input is not in the range
}


string read_choice(){
    string choice;
    vector<string> ans;

    ifstream saveFile;
    saveFile.open("savedMap.txt");

    char judge_eof;
    saveFile >> judge_eof;

    if (saveFile.eof()){
        ans.push_back("new");
        while (true){
            clear_screen();
            cout << "Enter 'new' to start new game" << endl;
            cout << endl;
            cout << "Your choice -> ";
            choice = get_word();
            choice = to_lower(choice);

            for (int i=0; i<ans.size(); i++){
            // find whether input is in the range
                if (choice == ans[i]){
                    return choice;
                }
            }
        }
    }
    else{
        ans.push_back("new");
        ans.push_back("read");
        while (true){
            clear_screen();
            cout << "Enter 'read' to read archive or enter 'new' to start new game" << endl;
            cout << endl;
            cout << "Your choice -> ";
            choice = get_word();
            choice = to_lower(choice);

            for (int i=0; i<ans.size(); i++){
            // find whether input is in the range
                if (choice == ans[i]){
                    return choice;
                }
            }
        }
    }

}


bool meet_room(string moving_result){
    if ( ("1" <= moving_result && moving_result <= "9") || ("A" <= moving_result && moving_result <= "B") || \
          moving_result == "&" || moving_result == "L" || moving_result == "#" || \
          moving_result == "W" || moving_result == "?"){
            return true;
    }
    else{
        return false;
    }
}


Player trigger_room_slot(string moving_result, Player player, Monster monster, Map map, int count){
    if (moving_result == "1")      player = room2(player);
    else if (moving_result == "2") player = room3(player);
    else if (moving_result == "3") player = room4(player);
    else if (moving_result == "4") player = room5(player);
    else if (moving_result == "5") player = room6(player);
    else if (moving_result == "6") player = room7(player);
    else if (moving_result == "7") player = room8(player);
    else if (moving_result == "8") player = room9(player);
    else if (moving_result == "A") player = room11(player);
    else if (moving_result == "B") player = room13(player);
    else if (moving_result == "&" && (player.talent.vision == true || player.talent.super_vision == true)) player = room5_Hidden(player);
    else if (moving_result == "L"){
        player = room5_Letter(player);
    }
    else if (moving_result == "9") player = room10_secretdoor(player);
    else if (moving_result == "W") player = room7_window(player, monster, map, count);
    else if (moving_result == "#") player = room7_secretdoor(player);
    else if (moving_result == "?") player = room10_secretdoor(player);

    return player;
}


int box_choice(vector<string> ans){
    string choice;
    cout << "Your choice -> ";
    choice = get_word();
    choice = to_lower(choice);

    if (not in_range(choice, ans)){
        return -1;
    }
    else{
        if (choice == "1") return 1;
        else if (choice == "2") return 2;
        else if (choice == "3") return 3;
        else return 1;
    }
}
