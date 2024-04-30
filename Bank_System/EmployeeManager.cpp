#include "EmployeeManager.h"

//Method that prints all the Client menu
void EmployeeManager::EmployeeMenu()
{
	system("cls");
	cout << "1-"<<"\x1B[93mDisplay my info\033[0m" << endl;
	cout << "2-"<<"\x1B[93mUpdate Password\033[0m" << endl;
	cout << "3-"<<"\x1B[93mAdd new client\033[0m" << endl;
	cout << "4-"<<"\x1B[93mSearch for client\033[0m" << endl;
	cout << "5-"<<"\x1B[93mList all clients\033[0m" << endl;
	cout << "6-"<<"\x1B[93mEdit client info\033[0m" << endl;
	cout << "7-" << "\x1B[93mLogin as Client\033[0m" << endl;
	cout << "8-" << "\x1B[31mLogout\033[0m" << endl;
}

//method to add new client
Client EmployeeManager::new_Client(Employee* employee)
{
	system("cls");
	Client client;
	employee->add_Client(client);
	FileManager::Delete_all_Clients();
	FileManager::get_all_Clients();
	return client;

}

//Method to list all the Clients that is found in the database
void EmployeeManager::List_all_Clients(Employee* employee)
{
	system("cls");
	employee->list_clients();
}

//Method to search for specific Client in the database using its id
void EmployeeManager::Client_search(Employee* employee)
{
	system("cls");
	cout << "Enter the client id : ";
	int id;
	cin >> id;
	
	bool flag = true;

	while (flag) {


		if (employee->Client_search(id) == nullptr) {

			system("cls");
			cout << "Client not found " << endl;
			cout << "Do you want to search for another id : (Y/N)";
			char ans;
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				system("cls");
				cout << "Enter the new id you want to search for : ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> id;
			}
		}
		else {

			system("cls");
			cout << "\x1B[5mClient Found successfully \033[0m " << endl;
			cout << "To access this account enter Enter : ";
			sleep_until(system_clock::now() + 0.3s);
			cin.get();
			bool flag2 = true;

			while (flag2) {

				if (cin.get() == '\n') {
					cout << "The Client data is : " << endl;
					employee->Client_search(id)->display_info();
					flag = false;
					flag2 = false;
				}
				else {
					cout << "Wrong key please try again : ";
					cin.clear();
					cin.get();
				}
			}

		}
	}
	
}

//Method to Edit the Client info by accessing the Client account using it's id
void EmployeeManager::Edit_Client_info(Employee* employee)
{
	system("cls");
	cout << "Enter the id of the Client : ";
	int id;
	cin >> id;
	employee->update_Client(id);
	system("pause");
}

//Method to update the password of the Employee account
void EmployeeManager::update_pass(int id)
{

	Employee* employee = FileManager::Employee_search(id);

	if (employee != nullptr) {

		string pass;
		cout << "Enter the new password : ";
		cin >> pass;

		employee->set_password(pass);
		FileManager::update_all_Employee(id);
		cout << "\x1B[5mPassword updated successfully\033[0m " << endl;
		return;
	}
}

//The login function of the Employee  takes the Employee id & password and check if the Employee exists in the database or not
Employee* EmployeeManager::login(int id, string pass)
{

	Employee* employee = FileManager::Employee_search(id);

	if (employee != nullptr) {

		if (employee->get_id() == id && employee->get_password() == pass) {


			return employee;

		}
		else {

			return nullptr;
		}


	}

	return nullptr;
	
}

//Method allows the Employee to login as Client using the id & password of that Client
//Which allow the Employee to access that Client account directly 
Client* EmployeeManager::login_as_Client(int id, string pass)
{

	

	bool flag = true;

	while (flag) 
	{
		Client* client = FileManager::Client_search(id);

		if (client != nullptr and client->get_password() == pass) {

			Client* client = ClientManger::login(id, pass);
			ClientManger::Client_options(client);
			flag = false;
		}
		else {
			cout << "The Id or the password is in correct " << endl;
			cout << "Do you want to renter the data : (Y/N) ";
			char ans;
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "The new  id is : ";
				cin >> id;
				cout << "The new password is :";
				cin >> pass;
			}
			else {
				cout << "\x1B[31mLogin failed\033[0m" << endl;
				flag = false;
			}
		}
	}

	return 0;
}

//Method that switch on the Employees option based on the user input
bool EmployeeManager::Employee_options(Employee* employee)
{
	int main_id = employee->get_id();

	EmployeeMenu();

	cout << "Enter your chaise : ";

	int choice;
	cin >> choice;
	if (!cin.fail() and choice >= 1 and choice <= 8) {

		switch (choice)
		{
		case 1:
			system("cls");
			employee->display_info();
			system("pause");
			break;
		case 2:
			system("cls");
			update_pass(main_id);
			system("pause");
			break;
		case 3:
		{
			system("cls");
			Client client = new_Client(employee);
			system("cls");
			cout << "\x1B[5mClient Added successfully\033[0m " << endl;
			cout << "The id of the Client you just added is : ";
			cout << client.get_id() << endl;
			system("pause");
			break;
		}
		case 4:
			system("cls");
			Client_search(employee);
			system("pause");
			break;
		case 5:
			system("cls");
			List_all_Clients(employee);
			system("pause");
			break;
		case 6:
			system("cls");
			Edit_Client_info(employee);
			cout << "\x1B[5mClient Info updated successfully\033[0m " << endl;
			break;
		case 7:
		{
			system("cls");

			Encdec::Decryption("Client.txt");
			ifstream file("Client.txt");

			file.seekg(0, ios::out);

			if (file.tellg() != 0) {
				file.close();
				Encdec::Encryption("Client.txt");
				cout << "Enter the id of the Client account you want to enter : ";
				int id;
				cin >> id;
				cout << "Enter the password of the Client account you want to enter : ";
				string pass;
				cin >> pass;
				login_as_Client(id, pass);
			}
			else {
				cout << "There is no Clients in the Database " << endl;
			}

			system("pause");
			break;
		}
		case 8:
			system("cls");
			cout << " \x1B[5;33m                                          Thank you for using our Bank System  \033[0m                                                ";

				sleep_until(system_clock::now() + 2s);
				return false;
		}

	}
	else {

		cout << "Invalid choice " << endl;
		sleep_until(system_clock::now() + 0.5s);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("Cls");
		Employee_options(employee);
		cin >> choice;

	}
	Employee_options(employee);

}
