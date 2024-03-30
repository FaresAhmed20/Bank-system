



#include "iostream"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "Clint.h"


using namespace std;

int main() {


    string name, password;
    int id, salary;
    double balance;
    /*
        cout<<"enter name ";
        cin>>name;
        cout<<"enter id ";
        cin>>id;
        cout<<"enter pass";
        cin>>password;
        cout<<"enter salary";
        cin>>salary;


        Employee s(name , id , password , salary);
    s.display_info();
    */


    Admin a;
    cout << "Name: ";
    cin >> name;
    a.set_name(name);
    cout << "ID: ";
    cin >> id;
    a.set_id(id);
    cout << "Password: ";
    cin >> password;
    a.set_password(password);
    cout << "Salary: ";
    cin >> salary;
    a.set_salary(salary);
    cout << "==============================\n";
    a.display_info();

    /*
        Client c;
        cout << "Name: ";
        cin >> name;
        c.set_name(name);
        cout << "ID: ";
        cin >> id;
        c.set_id(id);
        cout << "Password: ";
        cin >> password;
        c.set_password(password);
        cout << "Balance: ";
        cin >> balance;
        c.set_balance(balance);
        cout << "==============================\n";
        c.display_info();
    */



}
