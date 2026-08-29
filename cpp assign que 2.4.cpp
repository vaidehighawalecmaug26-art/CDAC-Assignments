#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size, int** outMin, int** outMax) {
    
    if (size <= 0) {
        return false;
    }

    
    int* minPtr = (int*)rawData;  
    int* maxPtr = (int*)rawData;
    
    for (int i = 1; i < size; i++) {
        if (*(rawData + i) < *minPtr) {
            minPtr = (int*)(rawData + i);
        }
        if (*(rawData + i) > *maxPtr) {
            maxPtr = (int*)(rawData + i);
        }
    }

    *outMin = minPtr;
    *outMax = maxPtr;

    return true;
}

int main() {
    int packet[] = {45, 12, 67, 8, 55, 31};
    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}
