#include "AdminManager.h"


//Method that prints all the Admin menu
void AdminManager::AdminsMenu()
{
	system("cls");
	cout << "1-"<<"\x1B[93mDisplay my info\033[0m" << endl;
	cout << "2-"<<"\x1B[93mUpdate Password\033[0m" << endl;
	cout << "3-"<<"\x1B[93mAdd new client\033[0m" << endl;
	cout << "4-"<< "\x1B[93mDelete Client\033[0m" << endl;
	cout << "5-" << "\x1B[93mDelete all Clients\033[0m" << endl;
	cout << "6-"<<"\x1B[93mSearch for client\033[0m" << endl;
	cout << "7-"<<"\x1B[93mList all clients\033[0m" << endl;
	cout << "8-"<<"\x1B[93mEdit client info\033[0m" << endl;
	cout << "9-" << "\x1B[93mLogin as Client\033[0m" << endl;
	cout << "10-"<<"\x1B[93mAdd new Employee\033[0m" << endl;
	cout << "11-"<< "\x1B[93mDelete Employee\033[0m" << endl;
	cout << "12-" << "\x1B[93mDelete all Employees\033[0m" << endl;
	cout << "13-"<<"\x1B[93mSearch for Employee\033[0m" << endl;
	cout << "14-"<<"\x1B[93mList all Employees\033[0m" << endl;
	cout << "15-"<<"\x1B[93mEdit Employee info\033[0m" << endl;
	cout << "16-" << "\x1B[93mLogin as Employee\033[0m" << endl;
	cout << "17-"<<"\x1B[31mLogout\033[0m" << endl;
}

//method to add new client
Client AdminManager::new_Client(Admin* admin)
{
	system("cls");
	Client client;
	admin->add_Client(client);
	FileManager::Delete_all_Clients();
	FileManager::get_all_Clients();
	return client;
}

//Method to delete the Client from the database
void AdminManager::delete_Client(int id)
{
	FileManager::Remove_specific_Client(id);
	FileManager::Delete_all_Clients();
	FileManager::get_all_Clients();
}

//Method to list all the Clients that exits in the database
void AdminManager::List_all_Clients(Admin* admin)
{
	system("cls");
	admin->list_clients();
}

//Method to search for specific client in the database using the client id
void AdminManager::Client_search(Admin* admin)
{
	system("cls");
	cout << "Enter the client id : ";
	int id;
	cin >> id;

	bool flag = true;

	while (flag) {


		if (admin->Client_search(id) == nullptr) {

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
			else {
				cout << '\n';
				flag = false;
				break;
			}
		}
		else {

			system("cls");
			cout << "Client is found successfully " << endl;
			cout << "To access this account please press Enter . ";
			sleep_until(system_clock::now() + 2s);
			cin.get();

			bool flag2 = true;

			while (flag2) {

				if (cin.get() == '\n') {

					cout << "The Client data is : " << endl;
					admin->Client_search(id)->display_info();
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

//Method to edit the client info by searching for the client in the database and id the client is found the admin can edit it 
// if the client not found it tells the user that the client is not found
void AdminManager::Edit_Client_info(Admin* admin)
{
	system("cls");
	cout << "Enter the id of the Client : ";
	int id;
	cin >> id;
	admin->update_Client(id);
	system("pause");
}

//Method so the Admin can login as client using the id & password of that client to directly access his/her account 
Client* AdminManager::login_as_Client(int id, string pass)
{

	bool flag = true;

	while (flag)
	{
		
		if (FileManager::Client_search(id) != nullptr and FileManager::Client_search(id)->get_password() == pass) {

			EmployeeManager::login_as_Client(id , pass);
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

//Method to add new Employee to the database
Employee AdminManager::new_Employee(Admin* admin)
{
	system("cls");
	Employee employee;
	admin->add_Employee(employee);
	FileManager::Delete_all_Employees();
	FileManager::get_all_Employee();
	return employee;
}

//Method to delete the Employee from the database
void AdminManager::delete_Employee(int id)
{
	FileManager::Remove_specific_Employee(id);
}

//Method to search for specific Employee int the database
void AdminManager::Employee_search(Admin* admin)
{
	system("cls");
	cout << "Enter the client id : ";
	int id;
	cin >> id;

	bool flag = true;

	while (flag) {


		if (admin->Employee_search(id) == nullptr) {

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
			else if (ans == 'N' || ans == 'n') {

				flag = false;
				break;

			}
		}
		else {

			system("cls");
			cout << "Employee is found successfully " << endl;
			cout << "To access this account please press Enter . ";
			sleep_until(system_clock::now() + 0.5s);
			cin.get();
			bool flag2 = true;

			while (flag2) {

				if (cin.get() == '\n') {

					cout << "The Employee data is : " << endl;
					admin->Employee_search(id)->display_info();
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

//Method to list all the Employee that is found in the database
void AdminManager::List_all_Employee(Admin* admin)
{
	system("cls");
	admin->list_Employee();
}

//Method to access the Employee data and edit it
void AdminManager::Edit_Employee_info(Admin* admin)
{
	system("cls");
	cout << "Enter the id of the Employee : ";
	int id;
	cin >> id;
	admin->update_Employee(id);
	system("pause");
}

//Method allows the Admin to login as Employee using the id & password of that Employee
//Which allow the Admin to access that Employee account directly 
void AdminManager::login_as_Employee(int id, string pass)
{
	bool flag = true;

	while (flag)
	{

		Employee* employee = FileManager::Employee_search(id);

		if ( employee != nullptr and employee->get_password() == pass) {

			Employee* Employee = EmployeeManager::login(id, pass);
			EmployeeManager::Employee_options(Employee);
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

	
}

//The login function of the Admin that takes the Admin id & password and check if the Admin exists in the database or not
Admin* AdminManager::login(int id, string pass)
{

	Admin* admin = FileManager::Admin_search(id);


	if ( admin != nullptr) {

		if (admin->get_id() == id && admin->get_password() == pass) {


			return admin;

		}
		else {
			return nullptr;
		}
	}
	
	return nullptr;

	

}

//Method to update the password of the Admin Account 
void AdminManager::update_pass(int id)
{
	Admin* admin = FileManager::Admin_search(id);

	if ( admin != nullptr) {

		string pass;
		cout << "Enter the new password : ";
		cin >> pass;

		admin->set_password(pass);
		FileManager::update_all_Admins(id);
		
		cout << "\x1B[5mPassword updated successfully\033[0m" << endl;
		return;
	}
}

//Method that switch on the admins options
bool AdminManager::Admin_options(Admin* admin)
{
	AdminsMenu();
	int main_id = admin->get_id();
	cout << "Enter your choice : ";
	int choice;
	cin >> choice;

	


	if (!cin.fail() and choice >= 1 and choice <= 17) {



		switch (choice)
		{
		case 1:
			system("cls");
			admin->display_info();
			system("pause");
			break;
		case 2:
			system("cls");
			update_pass(main_id);
			system("pause");
			break;
		case 3:
		{
			Client client = new_Client(admin);
			system("cls");
			cout << "\x1B[5mClient Added successfully\033[0m " << endl;
			cout << "The id of the Client you just added is : ";
			cout << client.get_id()<<endl;
			system("pause");
			break;
		}
		case 4:
		{
			bool flag = true;
			system("cls");
			cout << ("\t\x1b[41m               You are about to delete a client from the database       \x1b[0m") << endl;
			cout << ("\t\x1b[41m                   If you are sure press Enter to continue              \x1b[0m");
			sleep_until(system_clock::now() + 1s);
			cin.get();

			while (flag)
			{


				if (cin.get() == '\n') {
					system("cls");
					cout << "\x1B[31m Enter the id of the Client you want to delete :\033[0m ";
					int id;
					cin >> id;
					if (FileManager::Client_search(id) != nullptr) {

						delete_Client(id);
						cout << "\x1B[5mClient deleted successfully\033[0m " << endl;
						system("pause");
						flag = false;
					}
					else {
						cout << "Client is not found in the database " << endl;
						cout << "Do you want to try another id : (Y/N) ";
						char ans;
						cin >> ans;

						if (ans == 'Y' || ans == 'y') {
							cin.clear();
							cout << "Enter the new id : ";
							cin >> id;
						}
						else {
							cout << "\x1B[5mNo Data is updated\033[0m " << endl;
							flag = false;
						}
					}
				}
				else {

					cout << "You Entered a wrong key , Please Try Again : " << endl;
					cin.clear();
					cin.get();
				}

			}
			system("pause");
			break;
		}
		case 6:
			system("cls");
			Client_search(admin);
			system("pause");
			break;
		case 7:
			List_all_Clients(admin);
			system("pause");
			break;
		case 8:
			Edit_Client_info(admin);
			system("pause");
			break;
		case 9:
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
		case 10:
		{
			Employee employee = new_Employee(admin);
			system("cls");
			cout << "\x1B[5mEmployee updated successfully\033[0m " << endl;
			cout << "The Id of the Employee you just added is : ";
			cout << employee.get_id()<<endl;
			system("pause");
			break;
		}
		case 11:
		{


			system("cls");
			cout << ("\t\x1b[41m You are about to delete a Employee from the database\x1b[0m") << endl;
			cout << ("\t\x1b[41m       If you are sure press Enter to continue       \x1b[0m");
			sleep_until(system_clock::now() + 1s);
			cin.get();
			bool flag = true;

			while (flag)
			{

				if (cin.get() == '\n') {
					system("cls");
					cout << "\x1B[31m Enter the id of the Employee you want to delete :\033[0m ";
					int id;
					cin >> id;
					if (FileManager::Employee_search(id) != nullptr) {

						delete_Employee(id);
						cout << "\x1B[5mEmployee deleted successfully\033[0m " << endl;
						flag = false;
					}
					else {

						cout << "Employee is not found in the database " << endl;


						cout << "Do you want to try another id : (Y/N) ";
						char ans;
						cin >> ans;

						if (ans == 'Y' || ans == 'y') {
							cin.clear();
							cout << "Enter the new id : ";
							cin >> id;
						}
						else {
							cout << "\x1B[5mNo Data is updated\033[0m " << endl;
							flag = false;
						}
					}

				}
				else {
					cout << "You Entered A Wrong Key , Please Try Again : " << endl;
					cin.clear();
					cin.get();
				}

			}
			system("pause");
			break;
		}
		case 13:
			Employee_search(admin);
			system("pause");
			break;
		case 14:
			List_all_Employee(admin);
			system("pause");
			break;
		case 15:
			Edit_Employee_info(admin);
			break;
		case 16:
		{
			system("cls");
			Encdec::Decryption("Employee.txt");
			ifstream file("Employee.txt");

			file.seekg(0, ios::out);

			if (file.tellg() != 0) {
				file.close();
				Encdec::Encryption("Employee.txt");
				cout << "Enter the id of the Employee account you want to enter : ";
				int id;
				cin >> id;
				cout << "Enter the password of the Employee account you want to enter : ";
				string pass;
				cin >> pass;
				login_as_Employee(id, pass);

			}
			else {
				cout << "There is no Employee in the Database " << endl;
			}
			system("pause");
			break;
		}
		case 17:
			system("cls");
			cout << " \x1B[5;33m                                   Thank you for using our Bank System                       \033[0m                                                ";
			sleep_until(system_clock::now() + 2s);
			return false;
			break;
		case 5:
		{
			system("cls");
			cout << ("\t\x1b[41m You are about to delete All Clients from the database\x1b[0m") << endl;
			cout << ("\t\x1b[41m       If you are sure press Enter to continue        \x1b[0m");
			sleep_until(system_clock::now() + 2s);
			cin.get();
			bool flag = true;

			while (flag)
			{

				if (cin.get() == '\n') {
					system("cls");
					cout << "\x1B[31m All Clients Are Going To Be Deleted \033[0m ";
					FileManager::Remove_all_Clients();
					FileManager::Delete_all_Clients();
					system("cls");
					cout << "\x1B[5mClients Deleted Successfully\033[0m " << endl;
					flag = false;
				}
				else {
					cout << "You Entered a wrong key , Please Try Again : " << endl;
					cin.clear();
					cin.get();
				}

			}
			system("pause");
			break;
		}
		case 12:
		{
			system("cls");
			cout << ("\t\x1b[41m You are about to delete All Employees from the database\x1b[0m") << endl;
			cout << ("\t\x1b[41m       If you are sure press Enter to continue          \x1b[0m");
			sleep_until(system_clock::now() + 2s);
			cin.get();
			bool flag = true;

			while (flag)
			{

				if (cin.get() == '\n') {

					system("cls");
					cout << "\x1B[31m All Employees Are Going To Be Deleted \033[0m ";
					FileManager::Remove_all_Employee();
					FileManager::Delete_all_Employees();
					system("cls");
					cout << "\x1B[5mEmployees Deleted Successfully\033[0m " << endl;
					break;

				}

				else {

					cout << "You Entered a wrong key , Please Try Again : " << endl;
					cin.clear();
					cin.get();

				}


			}
			system("pause");
			break;
		}


		}
	}
	else {

		cout << "Invalid choice " << endl;
		sleep_until(system_clock::now() + 0.5s);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("Cls");
		Admin_options(admin);
		cin >> choice;
		
	}

	Admin_options(admin);
}
