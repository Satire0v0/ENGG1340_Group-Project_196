#include <iostream>
#include <cmath>
#include "map.h"
using namespace std;


int random(int min, int max){
    return rand() % (max - min + 1) + min;
}


pair<int, int> findFactors(int num){
    // Find two factors of num with smallest difference
    int smallDiff = num-1, diff;
    int factors[2]={1, num};
    pair<int, int> result; // return 2 values

    for (int factor=2; factor<pow(num, 0.5); factor++){
        if (num%factor==0){
            diff = abs(num/factor - factor);

            /*
            cout << "factor: " << factor << endl;
            cout << "num/factor: " << num/factor << endl;
            */
            
            if (diff < smallDiff){
                smallDiff = diff;
                factors[0] = factor;
                factors[1] = num/factor;
            }
        }
    }

    /*
    cout << "factors[0]: " << factors[0] << endl;
    cout << "factors[1]: " << factors[1] << endl;
    */

    result = make_pair(factors[0], factors[1]);

    return result;
}


void Map::initialize(){
    // Initialize the map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = WALL;
        }
    }
}


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


// Test function
int main(){
    // Test findFactors()
    pair<int, int> result;
    int num;

    cin >> num;
    result = findFactors(num);

    cout << "The power of num: " << pow(num, 0.5) << endl;
    cout << result.first << ' ' << result.second << endl;

    return 0;
}