#include "Client.h"
#include "IdGenerator.h"



//constructor
Client::Client() 
{
    int id;
    IdGenerator::last_Client_id(id);
    client_id = id;
    
}


Client::Client(string name, string password, double balance)
    : Person(name, password), balance(balance)
{
    set_balance(balance);

    int id;
    IdGenerator::last_Client_id(id);
    client_id = id;


}

//setters

void Client::set_id(int client_id)
{
    Client::client_id = client_id;
}



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

//The set_deposit used to add money to the Clients account 
void Client::set_deposit(const double amount)
{
    balance += amount;
}

//The set_withdraw used to withdraw the money from the user account
void Client::set_withdraw(const double amount)
{
    balance -= amount;
}

//The transfer_to used to transfer the data between two accounts
void Client::transfer_to(double amount, Client& recipient)
{

    while (true) {


        if (amount > 0 && amount <= balance)
        {
            set_withdraw(amount);
            recipient.set_deposit(amount);
            cout << "Amount transfer successfully"<<endl;
            return;

        }
        else
        {
            cout << "Amount Exceeded balance!\n";
            cout << "Are you want to try again : (y/n) ";
            char answer;
            cin >> answer;
            
            if (answer == 'y' || answer == 'Y') {
                cin.clear();
                cin.ignore (INT_MAX, '\n');
                cout << "Reenter the transfer amount again : ";
                cin >> amount;
            }
            else  {
                return;
            }


        }

    }

}

//The display_info used to display thee information of the Client
void Client::display_info()
{

    cout << "Name: " << name << endl
        << "You'r unique ID is : " << client_id << endl
        << "Password: " <<password<< endl
        << "Balance: " << balance << endl;
}

