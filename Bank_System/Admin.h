#pragma once
#include "Employee.h"



class Admin : public Employee {

public:

    //default constructor
    Admin();

    //parametrized constructor
    Admin(string name, int id, string password, int salary);

};

