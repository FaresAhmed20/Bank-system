#include "FilesHelper.h"



void FilesHelper::save_Client(Client client) {

	
	
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




void FilesHelper::save_Employee(Employee employee) {

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



void FilesHelper::save_Admins(Admin admin) {

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