#include "Employee.h"
#include "idGenerator.h"



Employee::Employee()
{

    IdGenerator::employeeId();
    employee_id = employee_count;
}

Employee::Employee(string name, string password, int salary)
    :Person(name, password), salary(salary)
{

    set_name(name);
    set_password(password);
    set_salary(salary);
    IdGenerator::employeeId();
    employee_id = employee_count;


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

int Employee::get_id()
{
    return employee_id;
}

//methods
void Employee::display_info()
{
    cout << "Name: " << name << endl
        << "You'r unique ID is : " << employee_id << endl
        << "Password: " << password << endl
        << "Salary: " << salary << endl;
}

int Employee::employee_count = 200;
