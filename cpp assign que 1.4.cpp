#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error : Missing arguments." << endl;
        return 1;
    }

    int warnThreshold = atoi(argv[1]);
    int criticalThreshold = atoi(argv[2]);
    int numReadings = atoi(argv[3]);

    
    if (warnThreshold >= criticalThreshold) {
        cout << "Error : warn_threshold must be less than critical_threshold." << endl;
        return 1;
    }

    if (numReadings < 1 || numReadings > 500) {
        cout << "Error : num_readings must be between 1 and 500." << endl;
        return 1;
    }

    
    cout << "Config : Warn=" << warnThreshold << "°C Critical=" 
         << criticalThreshold << "°C Readings=" << numReadings << endl;

    
    int normalCount = 0, warningCount = 0, criticalCount = 0, shutdownCount = 0;
    
    srand(time(0));

    for (int i = 0; i < numReadings; i++) {
	        int reading = rand() % 70;  

        if (reading >= 60) {
            shutdownCount++;
        } else if (reading >= criticalThreshold) {
            criticalCount++;
        } else if (reading >= warnThreshold) {
            warningCount++;
        } else {
            normalCount++;
        }
    }

    cout << "Results : Normal:" << normalCount << " Warning:" << warningCount 
         << " Critical:" << criticalCount << " Shutdown:" << shutdownCount << endl;

    return 0;
}
