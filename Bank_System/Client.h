#pragma once
#include <iostream>
#include<vector>
#include "Person.h"



using namespace std;



class Client : public Person
{

private:
    double balance;

public:
    static int client_count;
    int client_id;

    //default constructor
    Client();

    //parametrized constructors
    Client(string name, string password, double balance);

    //setters
    void set_balance(double balance);
    void set_id(int id);

    //getters
    double get_balance();
    int get_id();

    //methods
    void set_deposit(const double amount);

    void set_withdraw(const double amount);

    void transfer_to(double amount, Client& recipient);

    void display_info();
};

static vector<Client> clients;
static vector<Client>::iterator it;
