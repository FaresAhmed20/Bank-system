#pragma once
#include "Person.h"
#include "iostream"

using namespace std;




class Employee : public Person {
protected:
    int salary;
public:

    //default constructor
    Employee();

    //parametrized constructor
    Employee(string name, int id, string password, int salary);

    //setters
    void set_salary(int salary);

    //getters
    double get_salary();

    //methods
    void display_info();

};

