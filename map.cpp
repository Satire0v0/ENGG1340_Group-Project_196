#include "map.h"


void Map::generate_empty_map(){
    for (int i=0; i<200; i++){
        for (int j=0; j<200; j++){
            map[i][j] = UNUSED;
        }
    }
}


void Map::initialize(){
    Map::generate_empty_map();
    Map::read_map();
    MAP_HEIGHT = Map::count_height();
    MAP_WIDTH = Map::count_width();
}


void Map::print_map(){
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            cout << map[y][x];
        }
        cout << endl;
    }
}


void Map::update_whole(char new_map[200][200]){
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = new_map[y][x];
        }
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
    else{
        return "true";
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


// get the number of rows of the map
int Map::count_height(){
    int col=0;
    int count=0;

    for (int row=0; row<200; row++){
        if (map[row][col] == UNUSED){
            return count;
        }
        else{
            count++;
        }
    }
    return count;
}


int Map::count_width(){
    int row=0;
    int count=0;

    for (int col=0; col<200; col++){
        if (map[row][col] == UNUSED){
            return count;
        }
        else{
            count++;
        }
    }
    return count;
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
void Map::map_reading(){
    ifstream readMap;
    string line;
    int y=0;
    readMap.open("savedMap.txt");
    if (readMap.fail()){
        cout << "Error opening savedMap.txt \n";
        exit(0);
    }
    else{
        // Read the line from the map
        // As there is space, it has better to use getline(mapFile, line);
        getline(readMap, line);
        while (line != "END") {
            // Write into the map
            for (int x=0; x<MAP_WIDTH; x++) {
                map[y][x] = line[x];
            }
            getline(readMap, line);
            y++;
        }
    }
}