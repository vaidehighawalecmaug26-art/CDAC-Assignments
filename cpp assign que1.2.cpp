#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cout << "Enter number of readings (1-100): ";
    cin >> N;

    if (N < 1 || N > 100) {
        cout << "Invalid input. N must be between 1 and 100." << endl;
        return 1;
    }

    double readings[100];
    int validCount = 0;
    int errorCount = 0;

    
    cout << "Enter " << N << " temperature readings:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Reading " << i + 1 << ": ";
        cin >> readings[i];
    }

    
    cout << "\nValid readings : ";
    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            errorCount++;
            continue;  
        }
        cout << fixed << setprecision(1) << readings[i] << " ";
        validCount++;
    }
    cout << endl;

    cout << "Skipped (errors) : " << errorCount << endl;


    cout << "First CRITICAL : ";
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (readings[i] >= 45) {
            cout << "Index " << i << " → " << fixed << setprecision(1) << readings[i] << "°C" << endl;
            found = true;
            break;  
        }
    }
    if (!found) {
        cout << "No CRITICAL reading found" << endl;
    }

    
    double minTemp = 999, maxTemp = -999, sumTemp = 0;
    int countValid = 0;

    for (int i = 0; i < N; i++) {
        if (readings[i] >= 0) {  
            if (readings[i] < minTemp) minTemp = readings[i];
            if (readings[i] > maxTemp) maxTemp = readings[i];
            sumTemp += readings[i];
            countValid++;
        }
    }

    double avgTemp = (countValid > 0) ? sumTemp / countValid : 0;

    cout << "Min : " << fixed << setprecision(1) << minTemp << "°C "
         << "Max : " << maxTemp << "°C "
         << "Avg : " << setprecision(2) << avgTemp << "°C" << endl;

    
    int normalCount = 0, warningCount = 0, criticalCount = 0, shutdownCount = 0;

    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            
        } else if (readings[i] <= 29) {
            normalCount++;
        } else if (readings[i] <= 44) {
            warningCount++;
        } else if (readings[i] <= 59) {
            criticalCount++;
        } else {
            shutdownCount++;
        }
    }

    cout << "Normal:" << normalCount << " Warning:" << warningCount 
         << " Critical:" << criticalCount << " Shutdown:" << shutdownCount << endl;

    return 0;
}
