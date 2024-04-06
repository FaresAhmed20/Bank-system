#pragma once
#include "Person.h"
#include "iostream"

using namespace std;




class Employee : public Person {
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

};

