#include "FileManager.h"



void FileManager::add_Client(Client &client) {
	

	string name, password;
	double  balance;


	cout << "Enter the clint name : ";
	cin >> name;
	client.set_name(name);
	cout << "Enter the client password : ";
	cin >> password;
	client.set_password(password);
	cout << "Enter the client Balance : ";
	cin >> balance;
	client.set_balance(balance);

	
	FilesHelper::save_Client(client);
	
}



void FileManager::add_Employee(Employee& employee) {


	string name, pass;
	int salary;

	cout << "Enter the Employee name : ";
	cin >> name;
	employee.set_name(name);
	cout << "Enter the Employee password : ";
	cin >> pass;
	employee.set_password(pass);
	cout << "Enter the Employee salary : ";
	cin >> salary;
	employee.set_salary(salary);


	FilesHelper::save_Employee(employee);

}



void FileManager::add_Admin(Admin &admin) {

	string name, pass;
	int salary;

	cout << "Enter the Admin name : ";
	cin >> name;
	admin.set_name(name);
	cout << "Enter the Admin password : ";
	cin >> pass;
	admin.set_password(pass);
	cout << "Enter the Admin salary : ";
	cin >> salary;
	admin.set_salary(salary);


	FilesHelper::save_Admins(admin);

}



void FileManager::get_all_Clients() {

	FilesHelper::get_all_Clients();
	
}


void FileManager::get_all_Employee() {

	FilesHelper::get_all_Employee();

}
	

Client* FileManager::Client_search(int id) {

	

	while (true) {



		if (FilesHelper::Client_search(id) == nullptr) {

			cout << "Clint not found " << endl;
			cout << "Are you want to search using another id : (y/n) ";
			char c;
			cin >> c;
			if (c == 'y' || c == 'Y') {
				cout << "Enter the new id you want to search for : ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> id;
			}
			else {
				return 0;
			}
			
		}
		else {
			cout << "Client information is : " << endl;
			FilesHelper::Client_search(id)->display_info();
			return 0;
		}

	}

}




Employee* FileManager::Employee_search(int id) {

	

	while (true) {



		if (FilesHelper::Employee_search(id) == nullptr) {

			cout << "Employee is not found " << endl;
			cout << "Are you want to search using another id : (y/n) ";
			char c;
			cin >> c;
			if (c == 'y' || c == 'Y') {
				cout << "Enter the new id you want to search for : ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> id;
			}
			else {
				return 0;
			}

		}
		else {
			cout << "Employee data  is : " << endl;
			FilesHelper::Employee_search(id)->display_info();
			return 0;
		}

	}



}


Admin* FileManager::Admin_search(int id) {

	


	if (FilesHelper::Admin_search(id) == nullptr) {

		cout << "Admin is not found. " << endl;
		cout << "Are you want to search using another id : (y/n) ";
		char c;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			cout << "Enter the new id you want to search for : ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> id;
		}
		else {
			return 0;
		}

	}
	else {
		cout << "Admin information is : " << endl;
		FilesHelper::Admin_search(id)->display_info();
		return 0;
	}
}





