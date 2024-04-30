#include "ClientManger.h"







//Method that prints all the Client menu
void ClientManger::Client_Menu() {

	system("cls");
	cout << "1-"<<"\x1B[93m Display my info\033[0m" << endl;
	cout << "2-"<<"\x1B[93m Check balance \033[0m" << endl;
	cout << "3-"<<"\x1B[93m Update Password\033[0m" << endl;
	cout << "4-"<<"\x1B[93m Withdraw\033[0m" << endl;
	cout << "5-"<<"\x1B[93m Deposit\033[0m" << endl;
	cout << "6-"<<"\x1B[93m Transfer amount \033[0m" << endl;
	cout << "7-" << "\x1B[31mLogout\033[0m" << endl;
}

//Method to update the password of the Client Account 
void ClientManger::Update_Pass(int id) {
	system("cls");
	if (FileManager::Client_search(id) != nullptr) {

		string pass;
		cout << "Enter the new password : " ;
		cin >> pass;

		FilesHelper::Client_search(id)->set_password(pass);
		FileManager::update_all_Clients(id);
		cout << "\x1B[5mPassword updated successfully\033[0m "<<endl;
		return;
	}
}

//The login function of the Client that takes the Client id & password and check if the Client exists in the database or not
Client* ClientManger::login(int id , string pass)
{

	Client* client = FileManager::Client_search(id);

	if (client != nullptr) {


		if (client->get_id() == id && client->get_password() == pass) {


			return client;

		}
		else {
			return nullptr;
		}


	}

	return nullptr;

}

//Method that switch on the Clients option based on the user input
bool ClientManger::Client_options(Client* client)
{
	Employee e;
	int main_id = client->get_id();
	Client_Menu();
	cout << "Enter your choice : ";

	int  choice;
	cin >> choice;

	if (!cin.fail() and choice >= 1 and choice <= 7) {

		switch (choice)
		{

		case 1:
			system("cls");
			client->display_info();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "\x1B[34mYour Balance is : \033[0m";
			cout << client->get_balance() << endl;
			system("pause");
			break;
		case 3:
			Update_Pass(main_id);
			system("pause");
			break;
		case 4:
			system("cls");
			client->display_info();
			cout << "Enter the amount you want to withdraw from the account : ";
			double amount;
			cin >> amount;
			client->set_withdraw(amount);
			FileManager::update_all_Clients(main_id);
			system("cls");
			client->display_info();
			cout << "The Amount withdraw successfully to your account" << endl;
			sleep_until(system_clock::now() + 0.2s);
			system("pause");
			break;
		case 5:
			system("cls");
			client->display_info();
			cout << "Enter the amount you want to deposit into your account : ";
			double num;
			cin >> num;
			client->set_deposit(num);
			FileManager::update_all_Clients(main_id);
			system("cls");
			client->display_info();
			cout << "\x1B[5mAmount Added successfully\033[0m " << endl;
			sleep_until(system_clock::now() + 0.2s);
			system("pause");
			break;
		case 6:
		{
			system("cls");
			bool flag = true;
			cout << "Enter the id of the another account : ";
			int id;;
			cin >> id;

			while (flag)
			{
				if (FileManager::Client_search(id) != nullptr) {

					cout << "Enter the amount you want to transfer to that account : ";
					double amount;
					cin >> amount;
					Client recipient = *FileManager::Client_search(id);
					client->transfer_to(amount, recipient);
					FileManager::update_all_Clients(main_id);
					FileManager::update_all_Clients(id);

					flag = false;

				}
				else {

					cout << "The id you entered is not correct " << endl;
					cout << "Do you want to enter another id : (Y/N)";
					char ans;
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						cout << "Enter the  new id : ";
						int id;
						cin >> id;
					}
					else {

						flag = false;

					}

				}

			}
			cout << "\x1B[35mThank You For Using Our Service\033[0m" << endl;
			system("pause");
			break;
		}
		case 7:
			cout << " \x1B[5;33m                                          Thank you for using our Bank System                                            \033[0m                                                ";
			sleep_until(system_clock::now() + 2s);
			return false;
			break;
		}


	}
	else
	{
		cout << "Invalid choice " << endl;
		sleep_until(system_clock::now() + 0.5s);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("Cls");
		Client_options(client);
		cin >> choice;
	}
	

	Client_options(client);
}

