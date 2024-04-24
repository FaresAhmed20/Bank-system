#pragma once
#include "Person.h"
#include"Employee.h"
#include"FileManager.h"
class Employee;

class Admin : public Person
{

private:
	int salary;

public:
	
    int admin_id;

    //default constructor
    Admin();


    //parametrized constructor
    Admin(string name, string password, int salary);

    

    //setters
    void set_salary(int salary);

    void set_id(int admin_id);
 

    //getters
    double get_salary();
    int get_id();
    

    //methods
    void display_info();
    
    void add_Client(Client& client);

    void add_Employee(Employee& employee);

    void list_clients();

    void list_Employee();

    Client* Client_search(int id);

    Employee* Employee_search(int id);

    void update_Client(int id);

    void edit_Employee_menu(int id);

    void update_Employee(int id);

    void Remove_all_Client();

    void Remove_all_Employee();

    void Remove_specific_Client(int id);

    void Remove_specific_Employee(int id);

};

//the vector that stores the Admins data
static vector<Admin> Admins;