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
    int employee_id;

    //default constructor
    Employee();

    //parametrized constructor
    Employee(string name, string password, int salary);

    //setters
    void set_salary(int salary);
    void set_id(int id);

    //getters
    double get_salary();
    int get_id();

    //methods
    void display_info();

    void add_Client(Client& client);

    void Get_All_Clients();

    void list_clients();

    void Client_search(int id);
};

//the vector that stores tha Emplyee data
static vector<Employee> Employees;