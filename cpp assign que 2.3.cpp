#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int statusReg = 0b10110001;     
    int controlReg = 0b00000000;     
    int dataReg = 0b11001010;        

    cout << "=== Register Access Demo ===" << endl;


    cout << "\n--- regPtr1 (const int*) ---" << endl;
    const int* regPtr1 = &statusReg;
    cout << "Status Register Value: " << bitset<8>(*regPtr1) << " (" << *regPtr1 << ")" << endl;
    

    cout << "// *regPtr1 = 0b11111111;  [ERROR: Cannot write to const data]" << endl;
    
   
    regPtr1 = &controlReg;  
    cout << "// regPtr1 = &controlReg;  [VALID: Can repoint const int*]" << endl;

    cout << "\n--- regPtr2 (int* const) ---" << endl;
    int* const regPtr2 = &controlReg;
    cout << "Control Register Before: " << bitset<8>(*regPtr2) << " (" << *regPtr2 << ")" << endl;
    
  
    *regPtr2 = 0b10101010;
    cout << "Control Register After: " << bitset<8>(*regPtr2) << " (" << *regPtr2 << ")" << endl;
    
   
    cout << "// regPtr2 = &dataReg;  [ERROR: Cannot repoint int* const]" << endl;


    cout << "\n--- regPtr3 (const int* const) ---" << endl;
    const int* const regPtr3 = &statusReg;
    cout << "Status Register Value: " << bitset<8>(*regPtr3) << " (" << *regPtr3 << ")" << endl;
    
    
    cout << "// *regPtr3 = 0b11111111;  [ERROR: Cannot write to const data]" << endl;
    

    cout << "// regPtr3 = &dataReg;  [ERROR: Cannot repoint const pointer]" << endl;

    cout << "\n=== Summary ===" << endl;
    cout << "const int*       : Can repoint, CANNOT write data" << endl;
    cout << "int* const       : CANNOT repoint, can write data" << endl;
    cout << "const int* const : CANNOT repoint, CANNOT write data" << endl;

    return 0;
}
