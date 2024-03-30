#include "Employee.h"



Employee::Employee()
{}

Employee::Employee(string name, int id, string password, int salary)
    :Person(name, id, password), salary(salary)
{

    set_name(name);
    set_password(password);
    set_salary(salary);
}

//setters

void Employee::set_salary(int salary) {

    while (true) {

        if (Validation::check_salary(salary)) {
            Employee::salary = salary;
            return;
        }
        else {
            cout << "Invalid Salary \n Renter a new salary : ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> salary;
        }

    }




}


//getters
double Employee::get_salary()
{
    return salary;
}

//methods
void Employee::display_info()
{
    cout << "Name: " << name << endl
        << "ID: " << id << endl
        << "Password: " << password << endl
        << "Salary: " << salary << endl;
}
