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

//The display_info method used display the information of the Amins
void Admin::display_info()
{
    cout << "Name: " << name << endl
        << "Your unique ID is : " << admin_id << endl
        << "Password: " << password << endl
        << "Salary: " << salary << endl;
}

//the add_Client method takes a client type object by reference add take all it's information from the user and add it to the database
void Admin::add_Client(Client& client) {

    FileManager::add_Client(client);
}
//the add_Employee method takes a Employee type object by reference add take all it's information from the user and add it to the database
void Admin::add_Employee(Employee& employee) {

    FileManager::add_Employee(employee);
}

//The List_client method used to list all the information of the clients that is stored in the database
void Admin::list_clients() {

    FilesHelper::display_all_clients();
}

//The list_Employee method used to list all the information of the Employees that is stored in the database
void Admin::list_Employee() {

    FilesHelper::display_all_employee();
}

//the Client_search access the csv file from the FileManger class and search of the data there 
Client* Admin::Client_search(int id) {

   return FileManager::Client_search(id);
}

//the Employee_search access the csv file from the FileManger class and search of the data there 
Employee* Admin::Employee_search(int id) {
    
    return FileManager::Employee_search(id);

}

//the update_Client method start by calling the search method using the client's id
//  if the Client is found then the editing function is called and the user can edit the data then after the user is finish
// the new data restored in the database
void Admin::update_Client(int id) {

    if (FileManager::Client_search(id) != nullptr) {

        Employee::edit_Client_menu(id);
        FilesHelper::Update_Client(id);
    }
    else {
        cout << "Client not found \nNO data to update it";
    }
}

//the edit_Employee_menu function used to show the choses for the edit that the Admin can do 
void Admin::edit_Employee_menu(int id)
{

    string name, password;
    double salary;
    int Case;
    bool flag = true;

    cout << " 1- Name.\n 2- Password.\n 3- Balance.\n 4- All\n\n";
    cout << "Enter Option: ";
    cin >> Case;
    while (flag)
    {
        switch (Case)
        {
        case 1:
            if (FilesHelper::Employee_search(id) != nullptr)
            {
                cout << "New Name: ";
                cin >> name;
                FilesHelper::Client_search(id)->set_name(name);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 2:

            if (FilesHelper::Employee_search(id) != nullptr)
            {
                cout << "New Password: ";
                cin >> password;
                FilesHelper::Employee_search(id)->set_password(password);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 3:
            if (FilesHelper::Employee_search(id) != nullptr)
            {
                cout << "New Balance: ";
                cin >> salary;
                FilesHelper::Employee_search(id)->set_salary(salary);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 4:

            if (FilesHelper::Employee_search(id) != nullptr)
            {
                cout << "New Name: ";
                cin >> name;
                FilesHelper::Employee_search(id)->set_name(name);

                cout << "New Password: ";
                cin >> password;
                FilesHelper::Employee_search(id)->set_password(password);

                cout << "New Balance: ";
                cin >> salary;
                FilesHelper::Employee_search(id)->set_salary(salary);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        default:
            cout << "Invalid Choice!\n";
            cout << "Do you want to renter another chose : (Y/N) ";
            char c;
            cin >> c;
            if (c == 'n' || c == 'N') {
                cout << "No data is updated.";
                flag = false;
                break;
            }
            else {

                Admin::edit_Employee_menu(id);

            }

        }

    }




}

//the update_Employee method start by calling the search method using the Employee's id
//  if the Employee is found then the editing function is called and the user can edit the data then after the user is finish
// the new data restored in the database
void Admin::update_Employee(int id) {


    if (FileManager::Employee_search(id) != nullptr) {

        Admin::edit_Employee_menu(id);
        FileManager::update_all_Employee(id);
    }
    else {
        cout << "Employee not found \nNO data to update it";
    }
}

//The Remove_all_Client used to delete all the Client's data from the database
void Admin::Remove_all_Client() 
{
    FileManager::Remove_all_Clients();
}

//The Remove_all_Employee used to delete all the Employee's data from the database
void Admin::Remove_all_Employee() 
{
    FileManager::Remove_all_Employee();
}

//the Remove_specific_Client method takes the id of the client from the Admin and remove it's data from the csv files
void Admin::Remove_specific_Client(int id)
{
    if (FileManager::Client_search(id) != nullptr) {

        FileManager::Remove_specific_Client(id);
   }
}

//the Remove_specific_Employee method used to remove spacific Employee from the database it takes the id of that Employee and remove it 
void Admin::Remove_specific_Employee(int id)
{

    if (FileManager::Employee_search(id) != nullptr) {

        FileManager::Remove_specific_Employee(id);
    }
}
