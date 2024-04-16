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
	static int admin_count;
    int admin_id;

    //default constructor
    Admin();


    //parametrized constructor
    Admin(string name, string password, int salary);

    

    //setters
    void set_salary(int salary);

 

    //getters
    double get_salary();
    int get_id();
    

    //methods
    void display_info();
    
    void add_Client(Client& client);

    void add_Employee(Employee& employee);

    void list_clients();

    void list_Employee();

    void Client_search(int id);

    void Employee_search(int id);

};

//the vector that stores the Admins data
static vector<Admin> Admins;