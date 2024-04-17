#include "Admin.h"
#include "IdGenerator.h"

//default constructor
Admin::Admin()
{

    int id;
    IdGenerator::last_Admin_id(id);
    admin_id = id;


}


//parametrized constructor
Admin::Admin(string name, string password, int salary)
    : Person(name, password), salary(salary)
{

    set_name(name);
    set_password(password);
    set_salary(salary);

    int id;
    IdGenerator::last_Admin_id(id);
    admin_id = id;

}

//setters


void Admin::set_id(int admin_id) {

    Admin::admin_id = admin_id;
}



void Admin::set_salary(int salary) {

    while (true) {

        if (Validation::check_salary(salary)) {
            Admin::salary = salary;
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
double Admin::get_salary()
{
    return salary;
}

int Admin::get_id()
{
    return admin_id;
}

//methods
void Admin::display_info()
{
    cout << "Name: " << name << endl
        << "Your unique ID is : " << admin_id << endl
        << "Password: " << password << endl
        << "Salary: " << salary << endl;
}



void Admin::add_Client(Client& client) {

    FileManager::add_Client(client);
}


void Admin::add_Employee(Employee& employee) {

    FileManager::add_Employee(employee);
}


void Admin::list_clients() {

    FilesHelper::display_all_clients();
}

void Admin::list_Employee() {

    FilesHelper::display_all_employee();
}


void Admin::Client_search(int id) {

    FileManager::Client_search(id);
}


void Admin::Employee_search(int id) {
    
    FileManager::Employee_search(id);

}




