#include "Admin.h"
#include "IdGenerator.h"

//default constructor
Admin::Admin()
{

    IdGenerator::adminId();
    admin_id = admin_count;



}


//parametrized constructor
Admin::Admin(string name, string password, int salary)
    : Person(name, password), salary(salary)
{

    set_name(name);
    set_password(password);
    set_salary(salary);
    IdGenerator::adminId();
    admin_id = admin_count;

    


}

//setters
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
        << "You'r unique ID is : " << admin_id << endl
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

    FilesHelper::get_all_Clients();
    FilesHelper::desplay_all_clients();
}

void Admin::list_Employee() {

    FilesHelper::get_all_Employee();
    FilesHelper::desplay_all_employee();
}


void Admin::Client_search(int id) {

    FileManager::Client_search(id);
}


void Admin::Employee_search(int id) {
    
    FileManager::Employee_search(id);

}



int Admin::admin_count = 100;
