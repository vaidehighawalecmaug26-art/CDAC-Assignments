#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:
    
    Employee() {
        empId = 1001 + employeeCount;
        employeeCount++;
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 10000.0;
        isActive = true;
    }

  
    void setName(const string& n) {
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty." << endl;
            return;
        }
        name = n;
    }

    void setDepartment(const string& dept) {
        if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations") {
            department = dept;
        } else {
            cout << "ERROR: '" << dept << "' is not a registered department." << endl;
        }
    }

    void setGrade(char g) {
        g = toupper(g);
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D') {
            grade = g;
        } else {
            cout << "ERROR: Invalid grade '" << g << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000) {
            basicSalary = salary;
        } else {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected." << endl;
        }
    }

    void deactivate() {
        isActive = false;
    }

   
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }

   
    double computeAllowances() const {
        double allowancePercent = 0;
        switch (grade) {
            case 'A':
                allowancePercent = 0.40;  
                break;
            case 'B':
                allowancePercent = 0.30;  
                break;
            case 'C':
                allowancePercent = 0.20;  
                break;
            case 'D':
                allowancePercent = 0.10;  
                break;
        }
        return basicSalary * allowancePercent;
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();
        double tax = 0;

        if (gross <= 50000) {
            tax = 0;
        } else if (gross <= 100000) {
            tax = (gross - 50000) * 0.10;
        } else {
            tax = 5000 + (gross - 100000) * 0.20;
        }

        return tax;
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        cout << "============================================" << endl;
        cout << " EMPLOYEE PAYSLIP — AUG 2026" << endl;
        cout << "============================================" << endl;
        cout << "Emp ID : " << empId << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Grade : " << grade << endl;
        cout << "Status : " << (isActive ? "Active" : "Inactive") << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Basic Salary : Rs. " << fixed << setprecision(2) << basicSalary << endl;
        cout << "Allowances (" << (grade == 'A' ? 40 : (grade == 'B' ? 30 : (grade == 'C' ? 20 : 10))) 
             << "%) : Rs. " << computeAllowances() << endl;
        cout << "Gross Salary : Rs. " << computeGrossSalary() << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Tax Deduction : Rs. " << computeTax() << endl;
        cout << "Net Salary : Rs. " << computeNetSalary() << endl;
        cout << "============================================" << endl;
    }

    void acceptDetails() {
        cout << "\n--- Employee " << empId << " Details ---" << endl;

        cout << "Enter name: ";
        string n;
        getline(cin, n);
        setName(n);

        cout << "Enter department (Engineering/HR/Finance/Operations): ";
        string dept;
        getline(cin, dept);
        setDepartment(dept);

        cout << "Enter grade (A/B/C/D): ";
        char g;
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary (10,000 - 5,00,000): ";
        double sal;
        cin >> sal;
        cin.ignore();  
        setBasicSalary(sal);
    }

    static int getEmployeeCount() {
        return employeeCount;
    }
};


int Employee::employeeCount = 0;

int main() {
    
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

   
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    
    e3->deactivate();
    if (!e3->getIsActive()) {
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    }

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}
