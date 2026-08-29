#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define M_PI 3.14159265359

inline double distanceBetween(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}


inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}


inline bool isInSafeZone(double x, double y, double cx, double cy, double radius) {
    double dist = distanceBetween(x, y, cx, cy);
    return dist <= radius;
}

int main() {
    
    double homeX = 0.0;
    double homeY = 0.0;
    double safeRadius = 50.0;

    cout << "=== Drone Navigation System ===" << endl;
    cout << "Home Position: (" << homeX << ", " << homeY << ")" << endl;
    cout << "Safe Zone Radius: " << safeRadius << " units" << endl;
    cout << "\n";

    
    double waypoints[][2] = {{30.0, 40.0},{60.0, 20.0},{10.0, 15.0}    
    };

    int numWaypoints = 3;

    for (int i = 0; i < numWaypoints; i++) {
        double wpX = waypoints[i][0];
        double wpY = waypoints[i][1];

        
        double dist = distanceBetween(homeX, homeY, wpX, wpY);

        
        bool safe = isInSafeZone(wpX, wpY, homeX, homeY, safeRadius);

        cout << "Waypoint " << i + 1 << ": (" << fixed << setprecision(1) 
             << wpX << ", " << wpY << ")" << endl;
        cout << "  Distance from home: " << dist << " units" << endl;
        cout << "  Status: " << (safe ? "SAFE (within safe zone)" : "CAUTION (outside safe zone)") << endl;
        cout << "\n";
    }

    
    cout << "=== Inline Function Tests ===" << endl;
    
    
    double degrees = 45.0;
    double radians = toRadians(degrees);
    cout << degrees << "° = " << radians << " radians" << endl;

    
    double value = 75.0;
    double clamped = clamp(value, 0.0, 100.0);
    cout << "clamp(" << value << ", 0.0, 100.0) = " << clamped << endl;

    return 0;
}