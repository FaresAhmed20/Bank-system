#pragma once
#include "iostream"
#include "Person.h"
#include"Client.h"
#include"FileManager.h"




using namespace std;




class Employee : public Person  {
protected:
    int salary;
public:
    
    static int employee_count;
    int employee_id;

    //default constructor
    Employee();

    //parametrized constructor
    Employee(string name, string password, int salary);

    //setters
    void set_salary(int salary);

    //getters
    double get_salary();
    int get_id();

    //methods
    void display_info();

    void add_Client(Client& client);

    void Get_All_Clients();

    void list_clients();
};

static vector<Employee> Employees;