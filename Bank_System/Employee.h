#pragma once
#include "iostream"
#include "Person.h"
#include"Client.h"
#include"FileManager.h"
#include"istream"
#include"vector" 




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

    Client* Client_search(int id);

    static void edit_Client_menu(int id);

    static void update_Client(int id);

    void Remove_client(int id);
};

//the vector that stores tha Employee data
static vector<Employee> Employees;