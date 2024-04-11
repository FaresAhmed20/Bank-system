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
	