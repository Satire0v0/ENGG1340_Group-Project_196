#include "map.h"


string reward1 = "Treat your injury, HP+20";
string reward2 = "ATTACK+5";
string reward3 = "Increase your accuracy, Prob+0.005";
string reward4 = "Raise your maximum health by 50 points, maxHP+50";
string reward5 = "Increase your defence, DEF+5";


string vision= "Get a night vision device and you can always see hidden objects around you within a 3*3 range";
string multiple="The number of the count will be increased by 1 when you play the keyboard game";
string maxhp="Your maxHP will be doubled";
string doubleatk="Your ATK will be doubled";
string doubledef="Your DEF will be doubled";
string accurate="(Accurate attack) Your prob will always be 1";
string supernightvision= "(Supernightvision) You can see all the hidden objects in the map.";


void Map::initialize(){
    Map::count_size("map.txt");

    Map::empty_map();

    Map::read_map("map.txt");
}


void Map::empty_map(){
    // 2-dimensional dynamic array
    map = new char* [MAP_HEIGHT];
    for (int row=0; row < MAP_HEIGHT; row++){
        map[row] = new char[MAP_WIDTH];
        for (int col=0; col<MAP_WIDTH; col++){
            map[row][col] = ' ';
        }
    }
}


void Map::print_map(){
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[y][x] == HIDDEN_BOX || map[y][x] == HIDDEN_MONSTER || map[y][x] == '&' || map[y][x] == 'L'){
                cout << ' ';
            }
            else{
                cout << map[y][x];
            }
        }
        /*
            // room number
            else if(ONE <= map[y][x] && map[y][x] <= NINE || TEN <= map[y][x] && map[y][x] <= ELEVEN){
                cout << ' ';
            }
            */
        cout << endl;
    }
}


bool around_player(int x, int y, location loc){
    if (y == loc.row || y == (loc.row-1) || y == (loc.row+1)){
        if (x == loc.col || x == (loc.col-1) || x == (loc.col+1)){
            return true;
        }
    }

    return false;

}


void Map::vision_print(location player_loc){
    cout << "You are under night vision" << endl;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (around_player(x, y, player_loc)){
                cout << map[y][x];
            }
            else{
                if (map[y][x] == HIDDEN_BOX || map[y][x] == HIDDEN_MONSTER){
                    cout << ' ';
                }
                else{
                    cout << map[y][x];
                }
            }
        }
        /*
            // room number
            else if(ONE <= map[y][x] && map[y][x] <= NINE || TEN <= map[y][x] && map[y][x] <= ELEVEN){
                cout << ' ';
            }
            */
        cout << endl;
    }
}


void Map::super_vision_print(){
    cout << "You are under super night vision" << endl;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
                cout << map[y][x];
        }
        cout << endl;
    }
}


void Map::read_map(string fileName){
    // Read the map from "map.txt"
    int y=0;
    string line;
    ifstream mapFile;

    mapFile.open(fileName.c_str());

    if (mapFile.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    else{
        // Read the line from the map
        // As there is space, it has better to use getline(mapFile, line);
        getline(mapFile, line);
        cout << line << endl;
        
        while (y<MAP_HEIGHT) {
            cout << line << endl;
            // Write into the map
            for (int x=0; x<MAP_WIDTH; x++) {
                map[y][x] = line[x];
            }
            getline(mapFile, line);
            y++;
        }
    }
}


// check the block before the player moves on it
string Map::check_block(location move_loc, location player_loc){
    int row = move_loc.row+player_loc.row;
    int col = move_loc.col+player_loc.col;

    if (row <= -1 || row >= MAP_HEIGHT || col <= 0 || col >= MAP_WIDTH-1) {
        return "wall";
    }
    else if (map[row][col] == WALL) {
        return "wall";
    }
    else if (map[row][col] == EMPTY){
        return "empty";
    }
    else if (ONE <= map[row][col] && map[row][col] <= NINE){
        // turn char into string
        string room_num (1, map[row][col]);
        return room_num;
    }
    else if (map[row][col] == SMALL_MONSTER){
        return "small_monster";
    }
    else if (map[row][col] == BIG_MONSTER){
        return "big_monster";
    }
    else if (map[row][col] == BOX){
        return "box";
    }
    else if (map[row][col] == HIDDEN_BOX){
        return "hidden_box";
    }
    else if (map[row][col] == HIDDEN_MONSTER){
        return "hidden_monster";
    }
    else if (map[row][col] == TEN){
        return "A";
    }
    else if (map[row][col] == ELEVEN){
        return "B";
    }
    else if (map[row][col] == WINDOW){
        return "W";
    }
    else if (map[row][col] == HIDDEN_DOOR){
        return "#";
    }
    else if (map[row][col] == HIDDEN_FIVE){
        return "&";
    }
    else if (map[row][col] == TRANSFER){
        return "?";
    }
    else if (map[row][col] == END){
        return "E";
    }
    else{
        return "no_update";
    }
}


// Update the specific block of map
void Map::update_block(location loc, char block){
    location new_loc;

    // clear the player's current location
    map[loc.row][loc.col] = block;
}


void Map::generate_player(location player_loc){
    map[player_loc.row][player_loc.col] = PLAYER;
}


void Map::count_size(string fileName){
    ifstream map_file;
    // size map_size;
    string line;
    int count = 0;

    map_file.open(fileName.c_str());

    getline(map_file, line);
    // map_size.width = line.length();
    MAP_WIDTH = line.length();
    
    while(line.substr(0,3) != "END"){
        count++;
        getline(map_file, line);
    }
    // map_size.height = count;
    MAP_HEIGHT = count;

    map_file.close();
    //return map_size;
}


vector<string> Map::selectRewards(vector<string> rewards) {
    srand(time(nullptr));
    random_shuffle(rewards.begin(), rewards.end());
    return vector<string>(rewards.begin(), rewards.begin() + 3);
}


Player Map::box(Player player){
    int num_of_separator = 0;
    string title = "Choose 1 reward !!!";

    int choice;

    vector<string> rewards = {reward1 ,reward2, reward3, reward4, reward5};
    vector<string> result = selectRewards(rewards);

    bool check=false;
    vector<string> fixed_ans;
    fixed_ans.push_back("1");
    fixed_ans.push_back("2");
    fixed_ans.push_back("3");

    // find longest string
    for (string reward : result) {
        if (reward.length() > num_of_separator){
            num_of_separator = reward.length();
        }
    }
    num_of_separator += 2;

    while (true){
        clear_screen();
        // print out '-' on the left of title
        for (int i=0; i< ( (num_of_separator - title.length()) / 2); i++){
            cout << '-';
        }

        // show title
        cout << title;

        // print out '-' on the right of title
        for (int i=0; i<( num_of_separator-title.length() - (num_of_separator-title.length()) / 2 ); i++){
            cout << '-';
        }
        cout << endl;

        // show content
        int num = 1;
        for (string reward : result){
            cout << num << ':';
            // print out space on the left of reward
            for (int i=0; i< ( (num_of_separator-reward.length()-2) / 2); i++){
                cout << ' ';
            }
            
            cout << reward;

            // print out space on the right of reward
            for (int i=0; i< (num_of_separator-reward.length()-2 - ((num_of_separator-reward.length()-2)/2)); i++){
                cout << ' ';
            }
            cout << endl;

            num++;
        }
        
        // print out '-' at the end
        for (int i=0; i<(num_of_separator); i++){
            cout << '-';
        }
        cout << endl;

        // show player info
        cout << endl;
        player.show_info();
        cout << endl;

        // user choose
        choice = box_choice(fixed_ans);

        if (choice == -1){
            continue;
        }
        else if (result[choice-1] == reward1){
            player.update_HP(20);
            break;
        }
        else if (result[choice-1] == reward2){
            player.update_ATK(5);
            break;
        }
        else if (result[choice-1] == reward3){
            player.update_prob(0.05);
            break;
        }
        else if (result[choice-1] == reward4){
            player.update_maxHP(50);
            break;
        }
        else if (result[choice-1] == reward5){
            player.update_DEF(10);
            break;
        }
    }

    // show player info after chosen
    cout << endl;
    player.show_info();
    cout << endl;
    
    cout << "Good LUCK!!!" << endl;

    cout << endl;
    // scan_keyboard(); // the progam has unexpectable input
    short_pause();
    return player;
}


Player Map::hiddenbox(Player player){
    string title = "Choose 1 talent !!!";
    int num_of_separator = 0, choice;
    vector<string> talents = {multiple,maxhp,doubleatk,doubledef,vision,accurate};

    // used for checking
    vector<string> fixed_ans;

    if (player.talent.vision==true){
       vector<string> talents = {multiple,maxhp,doubleatk,doubledef,supernightvision,accurate};
    }
    if (player.talent.super_vision==true){
        vector<string> talents = {multiple,maxhp,doubleatk,doubledef,accurate};
    }

    vector<string>result = selectRewards(talents);

    // find longest talent
    int count=1;
    for (string talent : result) {
        // push answers for checking
        fixed_ans.push_back(to_string(count));
        count++;
        // find longest talent
        if (talent.length() > num_of_separator){
            num_of_separator = talent.length();
        }
    }
    // for num
    num_of_separator += 2;

    while (true){
        clear_screen();
        // print out '-' on the left of title
        for (int i=0; i< ( (num_of_separator - title.length()) / 2); i++){
            cout << '-';
        }

        // show title
        cout << title;

        // print out '-' on the right of title
        for (int i=0; i<( num_of_separator-title.length() - (num_of_separator-title.length()) / 2 ); i++){
            cout << '-';
        }
        cout << endl;

        // show content
        int num = 1;
        for (string talent : result){
            cout << num << ':';
            // print out space on the left of reward
            for (int i=0; i< ( (num_of_separator-talent.length()-2) / 2); i++){
                cout << ' ';
            }
            
            cout << talent;

            // print out space on the right of reward
            for (int i=0; i< (num_of_separator-talent.length()-2 - ((num_of_separator-talent.length()-2)/2)); i++){
                cout << ' ';
            }
            cout << endl;

            num++;
        }
        
        // print out '-' at the end
        for (int i=0; i<(num_of_separator); i++){
            cout << '-';
        }
        cout << endl;

        // show player info
        cout << endl;
        player.show_info();
        cout << endl;

        // user choose
        choice = box_choice(fixed_ans);

        if (choice == -1){
            continue;
        }
        else if (result[choice-1] == multiple){
            player.talent.mult+=1;
            break;
        }
        else if (result[choice-1] == maxhp){
            player.set_maxHP(player.get_maxHP() * 2);
            break;
        }
        else if (result[choice-1] == accurate){
            player.set_prob(1);
            break;
        }
        else if (result[choice-1] == doubleatk){
            player.set_ATK(player.get_ATK() * 2);
            break;
        }
        else if (result[choice-1] == doubledef){
            player.set_DEF(player.get_DEF() * 2);
            break;
        }
        else if (result[choice-1] == vision){
            player.talent.vision=true;
            break;
        }
        else if (result[choice-1] == supernightvision){
            player.talent.super_vision=true;
            break;
        }
    }

    player.show_info();
    cout << endl;
    cout << "Good LUCK!!!"<<endl;
    cout << endl;
    
    short_pause();
    return player;
}


// Store map
void Map::map_saving(){
    ofstream saveMap;
    saveMap.open("savedMap.txt");
    if (saveMap.fail()){
        cout << "Error opening savedMap.txt \n";
        exit(0);
    }
    else{
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (map[y][x] == 'O')
                {
                    saveMap << ' ';
                }
                else{
                    saveMap << map[y][x];
                }
            }
            saveMap << endl;
        }

        saveMap << "END";
    }
}
