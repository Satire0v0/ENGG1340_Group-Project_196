#include "base.h"


void clear_screen(){
    system("clear"); // used for linux
    // system("cls"); // used for windows powershell
}


string get_word(){
    // As all inputs are texts, therefore getting first effective word is enough
    // this is used for avoiding wrong input
    string sentence, word;

    getline(cin, sentence);

    istringstream line_in(sentence);
    line_in >> word;

    return word;
}


bool leave_or_not(){
    string word;

    cout << "Want to leave? (y/n): ";
    word = get_word();
    // cout << endl; // It seems that return will automatically add endl

    if (word == "y" || word == "Y" || word == "yes" || word == "Yes" || word == "YES"){
        return true;
    }
    else if (word == "n" || word == "N" || word == "no" || word == "No" || word == "NO"){
        return false;
    }
    else{
        return false;
    }
}


void print_hint(){
    char single_str[]={'w', 'a', 's', 'd', 'e', 'O', 'M', 'D'};
    string description[]={
        "Move up",
        "Move left",
        "Move down",
        "Move right",
        "Stop game",
        "Player",
        "Medicine",
        "Drug"
    };

    // find the longest description
    // in order to fit the formats at any time
    int longest=50;

    
    // print the hint
    cout << left;
    for (int i=0; i<sizeof(single_str); i++){
        if (i==0){
            cout << "The description of the operation:" << endl;
        }

        if (i==5){
            cout << endl;
            cout << "The description of the single character:" << endl;
        }

        cout << setw(5) << single_str[i] << setw(longest) << description[i] << endl;
    }

    cout << endl;
}


// the function will return ASCII value of keyboard operation without 'Enter'
int scan_keyboard(){
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


// record specific keys
char keyboard(){
    char word = scan_keyboard();
    char result;

    if (word == 'w' || word == 'W'){
        result = 'w';
    }
    else if (word == 'a' || word == 'A'){
        result = 'a';
    }
    else if (word == 's' || word == 'S'){
        result = 's';
    }
    else if (word == 'd' || word == 'D'){
        result = 'd';
    }
    else if (word == 'h' || word == 'H'){
        result = 'h';
    }
    else if (word == 'e' || word == 'E'){
        result = 'e';
    }
    else if (word == 'q' || word == 'Q'){
        result = 'q';
    }
    else{
        result = ' ';
    }
    
    return result;
}


// specific keys have specific functions
location explain_input(char word, Player &player, Map &map){
    location loc;
    string result;
    bool hintLeave=false;

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
    else if (word == 'h')
    {
        while (not hintLeave){
            clear_screen();
            print_hint();
            hintLeave = leave_or_not();
        }

        loc.row = 0;
        loc.col = 0;
    }
    else if (word == 'e'){
        cout << endl;
        cout << "Want to continue?" << endl;
        cout << "Press 'Enter' to continue, or enter 'Exit' to leave:" << endl;
        
        result = get_word();

        if (result == "exit" || result == "Exit"){
            exit(0); // the game terminates
        }
        else{
            loc.row = 0;
            loc.col = 0;
        }
    }

    else if (word == 'q'){
        /*
        location a;
        Player player;
        a = player.get_loc();
        cout << endl;
        cout << "Want to save current process?" << endl;
        cout << "Press '1', '2' or '3' to choose the archive you wish to save: " << endl;
        cout << a.row << " " << a.col << " a row col " << endl;
        */
        string choice;
        cout << endl;
        cout << "Enter 'save' to save archive | 'read' to restart from previous archive" << endl;
        cin >> choice;
        if (choice == "save")
        {
            save_data(player, map);
            exit(0);
        }
        else if (choice == "read")
        {
            export_data(player,map);
            map.generate_player(player.get_loc());
            //cout << loc.row << " " << loc.col << " loc row col after export data\n";
            //sleep(2);
        }
    }
    else{
        loc.row = 0;
        loc.col = 0;
    }

    return loc;
}


int random_num(int lower_bound, int upper_bound){
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}


double getProbability(){
    return random_num(0, 100) / 100.0; // integer divide integer is integer, therefore 100.0 is here
}


// room
void short_pause(){
    cout << "Press 'Enter' to continue" << endl;
    int user_input = scan_keyboard();
}


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


bool in_range(string user_input, vector<string> ans){
    // user might enter multi-chars
    if (user_input.length() != 1){
        return false;
    }
    else{
        // otherwise
        for (int i=0; i<ans.size(); i++){
        // find whether input is in the range
            if (user_input == ans[i]){
                return true;
            }
        }
    }
    // input is not in the range
    return false;
}


string read_choice(){
    string choice;
    vector<string> ans;
    ans.push_back("new");
    ans.push_back("read");

    while (true){
        clear_screen();
        cout << "Enter 'read' to read archive or enter 'new' to start new game" << endl;
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


bool meet_room(string moving_result){
    if ( ("1" <= moving_result && moving_result <= "8") || ("A" <= moving_result && moving_result <= "B") || \
          moving_result == "&" || moving_result == "L" || moving_result == "W" || \
          moving_result == "room7_secret" || moving_result == "room10_secret"){
            return true;
    }
    else{
        return false;
    }
}

Player trigger_room_slot(string moving_result, Player player, Monster monster, int count){
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
    else if (moving_result == "&") player = room5_Hidden(player);
    else if (moving_result == "L") player = room5_Letter(player);
    else if (moving_result == "9") player = room10_secretdoor(player);
    else if (moving_result == "W") player = room7_window(player, monster, count);
    else if (moving_result == "room7_secret") player = room7_secretdoor(player);
    else if (moving_result == "room10_secret") player = room10_secretdoor(player);
    else if (moving_result == "#") player.setloc({2,10});
    else if (moving_result == "?") player.setloc({6,31});

    return player;
}


bool skip_slot(){
    string choice;
    vector<string> ans;
    ans.push_back("yes");
    ans.push_back("y");
    ans.push_back("no");
    ans.push_back("n");

    while (true){
        clear_screen();
        cout << "There will be a fantastic slot about our game." << endl;
        cout << "Want to skip or not? (yes / no)" << endl;
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
