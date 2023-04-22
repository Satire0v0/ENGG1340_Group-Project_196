#include "map.h"


void Map::initialize(){
    size map_size;
    map_size = Map::count_size();

    // Count the map size
    MAP_HEIGHT = map_size.height;
    MAP_WIDTH = map_size.width;

    // 2-dimensional dynamic array
    map = new char* [MAP_HEIGHT];
    for (int row=0; row < MAP_HEIGHT; row++){
        map[row] = new char[MAP_WIDTH];
        for (int col=0; col<MAP_WIDTH; col++){
            map[row][col] = ' ';
        }
    }

    // Map::generate_empty_map();
    Map::read_map();
}


void Map::print_map(Player player){
    int row, col;
    row=player.get_loc().row;
    col=player.get_loc().col;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (player.talent.vision==true){  //this is for the nightvision talent
                if (((y==row-1)&&(x==col-1))||((y==row-1)&&(x==col))||((y==row-1)&&(x==col+1))||((y==row)&&(x==col-1))||((y==row)&&(x==col+1))||((y==row+1)&&(x==col-1))||((y==row+1)&&(x==col))||((y==row+1)&&(x==col+1))){
                    cout << map[y][x];
                }else{
                    cout << ' ';
                }
            }else if ((player.talent.vision==false)&&(map[y][x] == HIDDEN_BOX || map[y][x] == HIDDEN_DOOR || map[y][x] == HIDDEN_MONSTER)){
                cout << ' ';
            }else if (player.talent.supernightvision==true){
                cout << map[y][x];
            }else{
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

void Map::read_map(){
    // Read the map from "map.txt"
    int y=0;
    string line;
    ifstream mapFile;

    mapFile.open("map.txt");

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

    if (row <= 0 || row >= MAP_HEIGHT-1 || col <= 0 || col >= MAP_WIDTH-1) {
        return "wall";
    }
    else if (map[row][col] == WALL) {
        return "wall";
    }
    else if (map[row][col] == EMPTY){
        return "empty";
    }
    else if (ONE <= map[row][col] && map[row][col] <= NINE){
        string room_num (1, map[row][col]);
        return room_num;
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

//*****addition*****
size Map::count_size(){
    ifstream map_file;
    size map_size;
    string line;
    int count = 0;

    map_file.open("map.txt");

    getline(map_file, line);
    map_size.width = line.length();
    
    while(line.substr(0,3) != "END"){
        count++;
        getline(map_file, line);
    }
    map_size.height = count;

    map_file.close();
    return map_size;
}

//*****addition*****

Player box(Player player){

    int choice, r=1;
    cout << "--------------------------"<<endl;
    cout << "Choose 1 reward !!!"<<endl;
    vector<string> rewards = {reward1 ,reward2, reward3, reward4,reward5};
    vector<string>result = selectRewards(rewards);
    for (string reward : result) {
        cout << r << ":" << reward << endl;
        r+=1;
    }
    cin >> choice;
    cout << endl ;
    switch(result[choice-1]){
        case reward1:{
            player.HP+=100;
            break;
        }
        case reward2:{
            player.ATK+=10;
            break;
        }
        case reward3:{
            player.Prob+=0.05;
            break;
        }
        case reward4:{
            player.maxHP+=50;
            break;
        }
        case reward5:{
            player.DEF+=10;
            break;
        }
    }
    cout <<"--------------------------"<<endl;
    cout << "Good LUCK!!!"<<endl;
    return player;
}

vector<string> selectRewards(vector<string> rewards) {
    srand(time(nullptr));
    random_shuffle(rewards.begin(), rewards.end());
    return vector<string>(rewards.begin(), rewards.begin() + 3);
}

Player hiddenbox(Player player){

    int choice, r=1;
    cout << "--------------------------"<<endl;
    cout << "Choose 1 talent !!!"<<endl;
    vector<string> talents = {multiple,maxhp,doubleatk,doubledef,vision,accurate};
    if (player.talent.vision==true){
       vector<string> talents = {multiple,maxhp,doubleatk,doubledef,supernightvision,accurate};
    }
    if (player.talent.supernightvision==true){
        vector<string> talents = {multiple,maxhp,doubleatk,doubledef,accurate};
    }
    vector<string>result = selectRewards(talents);
    for (string talents : result) {
        cout << r << ":"<< talents << endl;
        r+=1;
    }
    cin >> choice;
    cout << endl ;
    switch(result[choice-1]){
        case multiple:{
            player.talent.mult+=1;
            break;
        }
        case maxhp:{
            player.maxHP*=2;
            break;
        }
        case accurate:{
            player.Prob=1;
            break;
        }
        case doubleatk:{
            player.ATK*=2;
            break;
        }
        case doubledef:{
            player.DEF*=2;
            break;
        }
        case vision:{
            player.talent.vision=true;
            break;
        }
        case vision:{
            player.talent.supernightvision=true;
            break;
        }
    }
    cout <<"--------------------------"<<endl;
    cout << "Good LUCK!!!"<<endl;
    return player;
}