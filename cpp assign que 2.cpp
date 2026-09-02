
#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    Patient() : patientId(0), name("Unknown"), age(0),
                ward("General"), bloodGroup("O+")
    {
        cout << "Default patient created." << endl;
}
    Patient(int id, const string& n)
        : patientId(id), name(n), age(0),
          ward("Emergency"), bloodGroup("O+")
    {
        cout << "Emergency patient created: " << name << endl;
    }

    Patient(int id, const string& n, int a,
            const string& w, const string& bg)
        : patientId(id), name(n), age(a),
          ward(w), bloodGroup(bg)
    {
        cout << "Patient admitted: " << name << endl;
    }


    ~Patient()
    {
        cout << "Patient " << name << " discharged." << endl;
    }

    void transferWard(const string& newWard)
    {
        cout << "\n" << name << " is transferred from "
             << ward << " to " << newWard << endl;

        ward = newWard;
    }

    void displayRecord() const
    {
        cout << "\nPatient Record" << endl;
        cout << "ID        : " << patientId << endl;
        cout << "Name      : " << name << endl;
        cout << "Age       : " << age << endl;
        cout << "Ward      : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
        cout << "----------------------" << endl;
    }
};


int main()
{
    cout << "Creating patients on stack..." << endl;

    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel");
    Patient p3;

    cout << "\nCreating patients on heap..." << endl;

    Patient* patients = new Patient[4];

    cout << "\nDisplaying heap patients:" << endl;

    for (int i = 0; i < 4; i++)
    {
        patients[i].displayRecord();
    }

    p2.transferWard("ICU");

    cout << "\nDeleting heap patients..." << endl;

    delete[] patients;

    cout << "\nEnd of program." << endl;

    return 0;
}


