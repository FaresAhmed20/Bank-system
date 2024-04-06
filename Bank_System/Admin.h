#pragma once
#include "Person.h"


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
    

};

