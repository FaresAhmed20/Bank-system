#include "FilesHelper.h"



void FilesHelper::save_Client(Client &client) {

	
	
	ofstream file("Client.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {
		file << '\n';
		file << client.get_name() << "," 
			<< client.get_id() << ',' 
			<< client.get_password() 
			<< ',' << client.get_balance();
		file.close();
	}

}




void FilesHelper::save_Employee(Employee &employee) {

	IdGenerator::employeeId();
	int id = Employee::employee_count;
	Employee::employee_count++;


	ofstream file("Employee.txt", ios::app); 

		if (!file.is_open()) {

			cout << "Error while opening the file" << endl;
		}
		else {

			file << '\n';
			file << employee.get_name() << ","
				<< id << ","
				<< employee.get_password()
				<< employee.get_salary();

			file.close();
		}

}



void FilesHelper::save_Admins(Admin &admin) {

	IdGenerator::adminId();
	int id = Admin::admin_count;
	Admin::admin_count++;


	ofstream file("Admin.txt", ios::app);

	if (!file.is_open()) {


		cout << "Error while opening the files" << endl;

	}
	else {

		file << '\n';
		file << admin.get_name() << ","
			<< id << ","
			<< admin.get_password()
			<< admin.get_salary();


		file.close();

	}

}



void FilesHelper::get_all_Clients() {
	
	ifstream file;
	string line;
	file.open("Client.txt" , ios::in);
	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {

		while (file.good()) {
			getline(file, line);
			Client client = Parser::phaser_to_client(line);
			clients.push_back(client);
		}
		file.close();

	}


}




void FilesHelper::get_all_Employee() {

	ifstream file;
	string line;
	file.open("Employee.txt", ios::in);

	if (!file.is_open()) {
		cout << "Error while opening the file " << endl;
	}
	else {

		while (file.good()) {

			getline(file, line);

			Employee employee = Parser::phasee_to_employee(line);

			Employees.push_back(employee);
		}
		file.close();
		
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

		while (file.good()) {

			getline(file, line);

			Admin admin = Parser::phaser_to_admin(line);
			Admins.push_back(admin);


		}
		file.close();
	}
}


void FilesHelper::desplay_all_clients() {

	for (auto& client : clients) {

		client.display_info();
		cout << "--------------------" << endl;
	}
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