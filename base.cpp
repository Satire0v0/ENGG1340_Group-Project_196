#include "base.h"


void clear_screen(){
    system("clear"); // used for linux
    // system("cls"); // used for windows powershell
}


string get_word(){
    // As all inputs are texts, therefore getting first effective word is enough
    // this is used for avoiding wrong input
    string line, word;

    getline(cin, line);

    istringstream line_in(line);
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
    char single_char[]={'w', 'a', 's', 'd', 'e', 'O', 'M', 'D'};
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
    for (int i=0; i<sizeof(single_char); i++){
        if (i==0){
            cout << "The description of the operation:" << endl;
        }

        if (i==5){
            cout << endl;
            cout << "The description of the single character:" << endl;
        }

        cout << setw(5) << single_char[i] << setw(longest) << description[i] << endl;
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
    /*
    jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
    */
    else if (word == 'q' || word == 'E'){
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
    /*
    jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
    */
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
        cout << "Enter 'save' to save archive\n";
        cin >> choice;
        if (choice == "save")
        {
            save_data(player, map);
            loc.row = 0;
            loc.col = 0;
            exit(0);
        }
        else if (choice == "read")
        {
            loc = export_data(player,map);
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