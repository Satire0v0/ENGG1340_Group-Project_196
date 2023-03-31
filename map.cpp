#include "map.h";


void Map::initialize(){
    // Initialize the map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = WALL;
        }
    }
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
        
        while (line != "END") {
            // Write into the map
            for (int x=0; x<MAP_WIDTH; x++) {
                map[y][x] = line[x];
            }
            getline(mapFile, line);
            y++;
        }
    }
}


string Map::check_block(location loc, location player_loc){
    int row = loc.row+player_loc.row;
    int col = loc.col+player_loc.col;

    if (row <= 0 || row >= MAP_HEIGHT-1 || col <= 0 || col >= MAP_WIDTH-1) {
        return "wall";
    }
    else if (map[row][col] == WALL) {
        return "wall";
    }
    else if (map[row][col] == MONSTER) {
        return "monster";
    }
    else if (map[row][col] == DRUG) {
        return "drug";
    }
    else{
        return "error";
    }
}
/*
void Map::getRoomLoc(){
    // map will equally divided into ROOM_NUM regions
    // therefore even ROOM_NUM is better
    // The function will first determine the exact location of the rooms without determing the sizes of the rooms
    // the loc of each room should be close to the upper left of its own region

    pair<int, int> factors = findFactors(ROOM_NUM);
    int ROW_NUM, COL_NUM;
    
    size regionSize;

    int x_range[2], y_range[2];


    ROW_NUM = factors.first;
    COL_NUM = factors.second;

    regionSize.width = MAP_WIDTH/COL_NUM;
    regionSize.height = MAP_HEIGHT/ROW_NUM;

    // Keep the room size without touch the margin of the region
    x_range[0] = 1;
    x_range[1] = regionSize.width - ROOM_MIN_SIZE.width - 1 - 1;
    y_range[0] = 1;
    y_range[1] = regionSize.height - ROOM_MIN_SIZE.height - 1 - 1;

    // Generate Location of each room
}
*/
