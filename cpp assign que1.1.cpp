#include <iostream>
using namespace std;

int main() {
    double temperature;
    cout << "Enter temperature (°C): ";
    cin >> temperature;

    
    int statusCode;
    if (temperature < 0) {
        statusCode = -1;
    } else if (temperature >= 0 && temperature <= 29) {
        statusCode = 0;
    } else if (temperature >= 30 && temperature <= 44) {
        statusCode = 1;
    } else if (temperature >= 45 && temperature <= 59) {
        statusCode = 2;
    } else {
        statusCode = 3;
    }

    
    double farenheit = (temperature * 9.0 / 5.0) + 32.0;

    
    string averageStatus = (temperature > 25.0) ? "Above Average" : "Below Average";

    
    cout << "\nTemperature : " << temperature << "°C / " << farenheit << "°F" << endl;

    
    cout << "Status : ";
    switch (statusCode) {
        case -1:
            cout << "SENSOR_ERROR" << endl;
            cout << "Action : Sensor fault — check wiring" << endl;
            break;
        case 0:
            cout << "NORMAL" << endl;
            cout << "Action : No action required" << endl;
            break;
        case 1:
            cout << "WARNING" << endl;
            cout << "Action : Alert sent to supervisor" << endl;
            break;
        case 2:
            cout << "CRITICAL" << endl;
            cout << "Action : Cooling system triggered" << endl;
            break;
        case 3:
            cout << "SHUTDOWN" << endl;
            cout << "Action : Emergency shutdown initiated" << endl;
            break;
    }

    cout << "Reading : " << averageStatus << endl;

    return 0;
}