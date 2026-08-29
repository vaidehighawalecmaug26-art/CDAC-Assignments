#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double grid[3][3];
    
    
    cout << "Enter temperatures for 3 floors (3 rooms each):" << endl;
    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {
            cout << "Floor " << floor + 1 << ", Room " << room + 1 << ": ";
            cin >> grid[floor][room];
        }
    }

    
    cout << "\n\t\tRoom1\t\tRoom2\t\tRoom3" << endl;
    for (int floor = 0; floor < 3; floor++) {
        cout << "Floor " << floor + 1 << " : ";
        for (int room = 0; room < 3; room++) {
            cout << fixed << setprecision(1) << grid[floor][room] << "\t\t";
        }
        cout << endl;
    }

    
    double maxTemp = -999;
    int hotFloor = 0, hotRoom = 0;
    
    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {
            if (grid[floor][room] > maxTemp) {
                maxTemp = grid[floor][room];
                hotFloor = floor;
                hotRoom = room;
            }
        }
    }

    cout << "Hottest Room : Floor " << hotFloor + 1 << ", Room " << hotRoom + 1 
         << " → " << fixed << setprecision(1) << maxTemp << "°C" << endl;


    double maxAvg = -999;
    int hotFloorNum = 0;

    for (int floor = 0; floor < 3; floor++) {
        double floorSum = 0;
        for (int room = 0; room < 3; room++) {
            floorSum += grid[floor][room];
        }
        double floorAvg = floorSum / 3.0;
        
        if (floorAvg > maxAvg) {
            maxAvg = floorAvg;
            hotFloorNum = floor;
        }
    }

    cout << "Hottest Floor : Floor " << hotFloorNum + 1 
         << " (avg " << fixed << setprecision(2) << maxAvg << "°C)" << endl;

    
    int warningRooms = 0;
    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {
            if (grid[floor][room] >= 30) {
                warningRooms++;
            }
        }
    }

    cout << "Rooms at WARNING or above : " << warningRooms << endl;

    return 0;
}