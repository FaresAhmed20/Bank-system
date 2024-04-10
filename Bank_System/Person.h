#pragma once
#include "Validation.h"

#pragma once
#include<iostream>
#include"string"
#include "Validation.h"
#include"vector"
using namespace std;


class Person 
{
protected:
    string name, password;

public:

    //default constructor
    Person();

    //parametrized constructor
    Person(string name, string password);

    Person(string password);

    //setters
    void set_name(string name);

    void set_password(string password);

    //getters
    string get_name();
    string get_password();


    //methods
    virtual void display_info() = 0;


};

