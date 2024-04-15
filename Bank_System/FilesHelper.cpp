#include "FilesHelper.h"



void FilesHelper::save_Client(Client &client) {

	ifstream file2 ("Client_last_id.txt");

	int last_id;

	file2 >> last_id;
	

	IdGenerator::last_Client_id(last_id);

	ofstream file("Client.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {
		
		file << client.get_name() << "," 
			<< last_id << ',' 
			<< client.get_password() 
			<< ',' << client.get_balance()<<'\n';
		file.close();
	}


	ofstream file3("Client_last_id.txt");

	file3 << last_id;
	file3.close();
}




void FilesHelper::save_Employee(Employee &employee) {

	ifstream file2("Employee_last_id.txt");

	int last_id;

	file2 >> last_id;

	IdGenerator::last_Employee_id(last_id);

	ofstream file("Employee.txt", ios::app); 

		if (!file.is_open()) {

			cout << "Error while opening the file" << endl;
		}
		else {

			file << employee.get_name() << ","
				<< last_id << ","
				<< employee.get_password()<<','
				<< employee.get_salary()<<'\n';
			
			file.close();
		}


		ofstream file3("Employee_last_id.txt");

		file3 << last_id;
		file3.close();
}



void FilesHelper::save_Admins(Admin &admin) {

	ifstream file2("Admin_last_id.txt");
	
	int last_id;

	file2 >> last_id;

	IdGenerator::last_Admin_id(last_id);


	ofstream file("Admin.txt", ios::app);

	if (!file.is_open()) {


		cout << "Error while opening the files" << endl;

	}
	else {

		
		file << admin.get_name() << ","
			<< last_id << ","
			<< admin.get_password()<<","
			<< admin.get_salary()<<'\n';


		file.close();

	}

	ofstream file3("Admin_last_id.txt");

	file3 << last_id;

	file3.close();

}



void FilesHelper::get_all_Clients() {
	
	ifstream file;
	string line;
	file.open("Client.txt" , ios::in);
	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {

		while(getline(file, line)) {
			
			Client client = Parser::phaser_to_client(line);
			clients.push_back(client);
		}
		file.close();

	}
	

}




void FilesHelper::get_all_Employee() {

	ifstream file;
	string line;
	file.open("Employee.txt");
	
	if (!file.is_open()) {
		cout << "Error while opening the file " << endl;
	}
	else {
		
		while (getline(file, line)) {
			
			Employee employee = Parser::phasee_to_employee(line);
			Employees.push_back(employee);
		}
		file.close();
		
	}

	for (auto& s : Employees) {
		 s;
	}
}



void FilesHelper::get_all_Admins() {

	ifstream file;
	string line;

	file.open("Admin.txt");

	if (!file.is_open()) {
		cout << "Admin file can't be retched" << endl;
	}
	else {

		while (getline(file, line)) {

			

			Admin admin = Parser::phaser_to_admin(line);
			Admins.push_back(admin);


		}
		file.close();
	}
}


void FilesHelper::desplay_all_clients() {

	get_all_Clients();

	for (auto& client : clients) {
		
		client.display_info();
		cout << "--------------------" << endl;
	}
	exit;
}


void FilesHelper::desplay_all_employee() {

	for (auto& employee : Employees) {

		employee.display_info();
		cout << "--------------------" << endl;
	}
}



void FilesHelper::desplay_all_admins() {

	for (auto& admin : Admins) {

		admin.display_info();
		cout << "--------------------" << endl;
	}
}


Client* FilesHelper::Client_search(int id) {

	
	get_all_Clients();

	for (auto& Client : clients) {
		
		if (Client.get_id() == id) {

			return &Client;
		}
		exit;
	}

	return NULL;
	
}


Employee* FilesHelper::Employee_search(int id) {

	get_all_Employee();
	
	for (auto &Employee : Employees) {
		
		if (Employee.get_id() == id) {

			return &Employee;
			
		}

	}
	return NULL;
}


Admin* FilesHelper::Admin_search(int id) {

	get_all_Admins();

	for (auto& Admin : Admins) {

		if (Admin.get_id() == id) {

			return &Admin;
		}
	}
}


//
//
//template<class Ty>
//
//Ty* FilesHelper::Search_all_data <Ty>(int id) {
//
//
//	get_all_Admins();
//	get_all_Employee();
//	get_all_Clients();
//
//	int num = id;
//	int temp = 0;
//	while (num)
//	{
//
//		temp = num % 10;
//		num /= 10;
//
//	}
//
//	switch (temp)
//	{
//	case '1':
//		for (auto& Admin : Admins) {
//
//			if (Admin.get_id() = id) {
//
//				return &Admin;
//			}
//		}
//		
//		return nullptr;
//
//	case '2':
//		for (auto Employee : Employees) {
//
//			if (Employee.get_id() == id) {
//
//				return &Employee;
//
//			}
//
//		}
//		return nullptr
//
//	case '3':
//		for (auto& Client : clients) {
//
//			if (Client.get_id() == id){
//
//				return &Client;
//			}
//			
//		}
//
//		return nullptr;
//	}
//	
//}