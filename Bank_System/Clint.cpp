#include "Clint.h"




//constructor
Client::Client() {}


Client::Client(string name, int id, string password, double balance)
    : Person(name, id, password), balance(balance)
{
    set_balance(balance);
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

    set_withdraw(amount);
    recipient.set_deposit(amount);

}

void Client::display_info()
{

    cout << "Name: " << name << endl
        << "ID: " << id << endl
        << "Password: " << endl
        << "Balance: " << balance << endl;
}