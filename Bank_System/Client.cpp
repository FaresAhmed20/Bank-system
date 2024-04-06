#include "Client.h"
#include "IdGenerator.h"



//constructor
Client::Client() 
{
    IdGenerator::clientId();
    client_id = client_count;

}


Client::Client(string name, string password, double balance)
    : Person(name, password), balance(balance)
{
    set_balance(balance);
    IdGenerator::clientId();
    client_id = client_count;


}

//setters
void Client::set_balance(double balance) {

    while (true)
    {
        if (Validation::check_balance(balance))
        {
            Client::balance = balance;
            break;

        }
        else
        {
            cout << "Invalid Balance!\nBalance: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> balance;
        }

    }


}

//getters
double Client::get_balance()
{

    return balance;
}

int Client::get_id()
{
    return client_id;
}


//method

void Client::set_deposit(const double amount)
{

    balance += amount;

}

void Client::set_withdraw(const double amount)
{
    balance -= amount;
}

void Client::transfer_to(double amount, Client& recipient)
{

    if (amount > 0 && amount <= balance)
    {
        set_withdraw(amount);
        recipient.set_deposit(amount);

    }
    else
    {
        cout << "Amount Exceeded balance!\n";
    }

}

void Client::display_info()
{

    cout << "Name: " << name << endl
        << "ID: " << client_id << endl
        << "Password: " <<password<< endl
        << "Balance: " << balance << endl;
}

int Client::client_count = 300;