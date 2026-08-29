#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double computeRMS(double* signal, int n) {
    double sumSquares = 0;
    double* ptr = signal;
    
    for (int i = 0; i < n; i++) {
        sumSquares += (*ptr) * (*ptr);
        ptr++;
    }
    
    return sqrt(sumSquares / n);
}


void normalise(double* signal, int n) {
    
    double maxVal = 0;
    double* ptr = signal;
    
    for (int i = 0; i < n; i++) {
        if (fabs(*ptr) > maxVal) {
            maxVal = fabs(*ptr);
        }
        ptr++;
    }
    
    if (maxVal == 0) return;  
    
   
    ptr = signal;
    for (int i = 0; i < n; i++) {
        *ptr = *ptr / maxVal;
        ptr++;
    }
}

int countZeroCrossings(double* signal, int n) {
    int count = 0;
    double* ptr = signal;
    
    for (int i = 0; i < n - 1; i++) {
        double current = *ptr;
        double next = *(ptr + 1);
        
       
        if ((current < 0 && next > 0) || (current > 0 && next < 0)) {
            count++;
        }
        ptr++;
    }
    
    return count;
}


void applyGain(double* signal, int n, double gainFactor) {
    double* ptr = signal;
    
    for (int i = 0; i < n; i++) {
        *ptr = *ptr * gainFactor;
        ptr++;
    }
}

void printArray(double* signal, int n, const string& label) {
    cout << label << ": ";
    double* ptr = signal;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << *ptr << " ";
        ptr++;
    }
    cout << endl;
}

int main() {
    double testSignal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n = 7;
    
   
    double signal[7];
    for (int i = 0; i < 7; i++) {
        signal[i] = testSignal[i];
    }

    double rms = computeRMS(signal, n);
    cout << "RMS: " << fixed << setprecision(4) << rms << endl;

 
    int crossings = countZeroCrossings(signal, n);
    cout << "Zero Crossings: " << crossings << endl;


    for (int i = 0; i < 7; i++) {
        signal[i] = testSignal[i];
    }

    printArray(signal, n, "Before normalise");


    normalise(signal, n);


    printArray(signal, n, "After normalise");


    cout << "\nApplying gain factor 2.0..." << endl;
    applyGain(signal, n, 2.0);

  
    printArray(signal, n, "After applyGain(2.0)");

    return 0;
}
