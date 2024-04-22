#include "Employee.h"
#include "idGenerator.h"



Employee::Employee()
{

    int id;
    IdGenerator::last_Employee_id(id);
    employee_id = id;
}

Employee::Employee(string name, string password, int salary)
    :Person(name, password), salary(salary)
{

    set_name(name);
    set_password(password);
    set_salary(salary);

    int id;
    IdGenerator::last_Employee_id(id);
    employee_id = id;


}

//setters


void Employee::set_id(int employee_id)
{
    Employee::employee_id = employee_id;
}


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


//the display_info used to display the information of the Employee
void Employee::display_info()
{
    cout << "Name: " << name << endl
        << "Your unique ID is : " << employee_id << endl
        << "Password: " << password << endl
        << "Salary: " << salary << endl;
}

//the add_Client method takes a client type object by reference add take all it's information from the user and add it to the database
void Employee::add_Client(Client& client) {

    FileManager::add_Client(client);
}

//the Get_All_Clients used to get all the Clients form the csv file and add it to the vector
void Employee::Get_All_Clients() {

    FileManager::get_all_Clients();

}

//the list_Client method used to display the information of all the Clints in the database
void Employee::list_clients() {

    FilesHelper::display_all_clients();
}

//the Client_search access the csv file from the FileManger class and search of the data there 
void Employee::Client_search(int id) {

    FileManager::Client_search(id);

}

//the edit_Client_menu function used to show the choses for the edit that the Employee can do 
void Employee::edit_Client_menu(int id) {

    string name, password;
    double balance;
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
            if (FilesHelper::Client_search(id) != nullptr)
            {
                cout << "New Name: ";
                cin >> name;
                FilesHelper::Client_search(id)->set_name(name);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 2:

            if (FilesHelper::Client_search(id) != nullptr)
            {
                cout << "New Password: ";
                cin >> password;
                FilesHelper::Client_search(id)->set_password(password);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 3:
            if (FilesHelper::Client_search(id) != nullptr)
            {
                cout << "New Balance: ";
                cin >> balance;
                FilesHelper::Client_search(id)->set_balance(balance);
                cout << "Data updated successfully.";
                flag = false;
            }
            break;

        case 4:

            if (FilesHelper::Client_search(id) != nullptr)
            {
                cout << "New Name: ";
                cin >> name;
                FilesHelper::Client_search(id)->set_name(name);

                cout << "New Password: ";
                cin >> password;
                FilesHelper::Client_search(id)->set_password(password);

                cout << "New Balance: ";
                cin >> balance;
                FilesHelper::Client_search(id)->set_balance(balance);
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
               
                Employee::edit_Client_menu(id);
                
            }
            
        }

    }
}

//the update_Client method start by calling the search method using the client's id
//  if the Client is found then the editing function is called and the user can edit the data then after the user is fenish
// the new data restored in the databasse
void Employee::update_Client(int id) {

    if (FileManager::Client_search(id) != nullptr) {

        Employee::edit_Client_menu(id);
        FileManager::update_all_Clients(id);
    }
    else {
        cout << "Client not found \nNO data to update it";
    }
}





