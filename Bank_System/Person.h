#pragma once
#include "Validation.h"

#pragma once
#include<iostream>
#include"string"
#include "Validation.h"
using namespace std;


class Person 
{
protected:
    string name, password;
    int id;


public:

    //default constructor
    Person();

    //parametrized constructor
    Person(string name, int id, string password);

    Person(int id, string password);

    //setters
    void set_name(string name);
    void set_id(int id);
    void set_password(string password);

    //getters
    string get_name();
    int get_id();
    string get_password();


    //methods
    virtual void display_info() = 0;


};

