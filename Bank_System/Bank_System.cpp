#include "iostream"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "Client.h"

using namespace std;

//Newest
int main() {


    string name, password;
    int id, salary;
    double balance;



    Client a("fares", "ffffffff", 5000);
    Client b("ahmed", "ahmed ", 7000);

    a.transfer_to(100000, b);

    cout<<a.get_balance();
    cout << b.get_balance();





    
    //test
    /*for (int i = 1; i <= 150; i++)
    {
        Admin* a = new Admin("OmarSabry", "123456789", 5550);
        a->display_info();
    }

    for (int i = 1; i <= 150; i++)
    {
        Employee* e = new Employee("FaresAhmed", "123456789", 5550);
        e->display_info();
    }

    for (int i = 1; i <= 150; i++)
    {
        Client* c = new Client("SeifKhalid", "123456789", 5550);
        c->display_info();
    }*/



   
   /* Admin a;
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
    a.display_info();*/

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
