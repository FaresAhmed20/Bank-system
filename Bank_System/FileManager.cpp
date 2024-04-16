#include "FileManager.h"


//Add_Client method gets the data from the user and add it to the darabase
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

	//Save_Client the methode that saves the client info into the csv file
	FilesHelper::save_Client(client);
	
}


//Add_Employee method gets the data from the user and add it to the darabase
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

	//Save_Employee the methode that saves the client info into the csv file
	FilesHelper::save_Employee(employee);

}


//Add_Admin method gets the data from the user and add it to the darabase
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

	//Save_Admin the methode that saves the client info into the csv file
	FilesHelper::save_Admins(admin);

}


//Get_All_Clients access the csv file to get all the data into the vector 
void FileManager::get_all_Clients() {

	FilesHelper::get_all_Clients();
	
}

//Get_All_Employees access the csv file to get all the data into the vector 
void FileManager::get_all_Employee() {

	FilesHelper::get_all_Employee();

}
	
//Get_All_Admins access the csv file to get all the data into the vector 
void FileManager::get_all_Admins() {

	FilesHelper::get_all_Admins();

}

//the Client_Search function gets an id from the user to be searched in the database 
//it uses the Client_search function in the filesHlper class to acess the data in the csv file and then search in it
//if the FilesHelper::Client_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
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
			
		    return FilesHelper::Client_search(id);
			
		}

	}

}




//the Employee_Search function gets an id from the user to be searched in the database 
//it uses the Employee_search function in the filesHlper class to acess the data in the csv file and then search in it
//if the FilesHelper::Employee_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
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
			
			return FilesHelper::Employee_search(id);
			
		}

	}



}


//the Admin_Search function gets an id from the user to be searched in the database 
//it uses the Admin_search function in the filesHlper class to acess the data in the csv file and then search in it
//if the FilesHelper::Admin_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
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
		
		return FilesHelper::Admin_search(id);
		
	}
}



//search_all_data uses the template to search among all the data in the csv file
//if it return a valid data it retun it to the user so it can be accessed 
//if not it return a nullptr
template<class Ty>
Ty* FileManager::Search_all_data(int id) {


	FilesHelper::Search_all_data<Ty>(id);

}
