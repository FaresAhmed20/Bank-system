#include "FileManager.h"


//Add_Client method gets the data from the user and add it to the database
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

	//Save_Client the method that saves the client info into the csv file
	FilesHelper::save_Client(client);
	
}

//Add_Employee method gets the data from the user and add it to the database
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

	//Save_Employee the method that saves the client info into the csv file
	FilesHelper::save_Employee(employee);

}

//Add_Admin method gets the data from the user and add it to the database
void FileManager::add_Admin(Admin &admin) 
{

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

	//Save_Admin the method that saves the client info into the csv file
	FilesHelper::save_Admins(admin);

}

//Get_All_Clients access the csv file to get all the data into the vector 
void FileManager::get_all_Clients() 
{
	FilesHelper::get_all_Clients();
}

//Get_All_Employees access the csv file to get all the data into the vector 
void FileManager::get_all_Employee() 
{
	FilesHelper::get_all_Employee();
}
	
//Get_All_Admins access the csv file to get all the data into the vector 
void FileManager::get_all_Admins() 
{
	FilesHelper::get_all_Admins();
}

//The Delete_all_Clients Method delete all the data that exits in the vector 
void FileManager::Delete_all_Clients()
{
	FilesHelper::Delete_all_Clients();
}

//The Delete_all_Employee Method delete all the data that exits in the vector 
void FileManager::Delete_all_Employees()
{
	FilesHelper::Delete_all_Employee();
}

//the Client_Search function gets an id from the user to be searched in the database 
//it uses the Client_search function in the filesHelper class to access the data in the csv file and then search in it
//if the FilesHelper::Client_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
Client* FileManager::Client_search(int id) {



	int temp_id = id;
	int temp = 0;
	while (temp_id) {

		temp = temp_id % 10;
		temp_id /= 10;

	}
	
	if (temp == 3) {

		Client* client = FilesHelper::Client_search(id);

		if(client == nullptr) {


			return  nullptr;

		}
		else {

			return client;

		}

	}
	else {

		return nullptr;
	}


	


}

//the Employee_Search function gets an id from the user to be searched in the database 
//it uses the Employee_search function in the filesHelper class to access the data in the csv file and then search in it
//if the FilesHelper::Employee_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
Employee* FileManager::Employee_search(int id) {

	

	int temp_id = id;
	int temp = 0;
	while (temp_id) {

		temp = temp_id % 10;
		temp_id /= 10;

	}


	if (temp == 2) {

		Employee* employee = FilesHelper::Employee_search(id);

			if ( employee == nullptr) {

				return  nullptr;

			}
			else {

				return employee;

			}

		
	}
	else {
		return nullptr;
	}
	



		

}

//the Admin_Search function gets an id from the user to be searched in the database 
//it uses the Admin_search function in the filesHelper class to access the data in the csv file and then search in it
//if the FilesHelper::Admin_search return a valid data the function return it to the user to access this data
//if not it the user can enter another id or just quit the function
Admin* FileManager::Admin_search(int id) {

	int temp_id = id;
	int temp = 0;
	while (temp_id) {

		temp = temp_id % 10;
		temp_id /= 10;

	}
	
	if (temp == 1) {

		Admin* admin = FilesHelper::Admin_search(id);

		if (admin == nullptr) {

			return nullptr;

		}
		else {

			return admin;

		}

	}
	else {

		
		return nullptr;
	}

	
}

//search_all_data uses the template to search among all the data in the csv file
//if it return a valid data it return it to the user so it can be accessed 
//if not it return a nullptr
template<class Ty>
Ty* FileManager::Search_all_data(int id) {


	FilesHelper::Search_all_data<Ty>(id);

}

//The update_all_Clients used to call the update method from the FileHelper 
void FileManager::update_all_Clients(int id) 
{
	FilesHelper::Update_Client(id);
}

//The update_all_Employee used to call the update method from the FileHelper
void FileManager::update_all_Employee(int id)
{
	FilesHelper::Update_Employee(id);
}

void FileManager::update_all_Admins(int id)
{
	FilesHelper::Update_Admins(id);
}

//The Remove_all_Clients used to call the clear_Files method from the FileHelper 
//then send it the all file names that contains all the Clients data
void FileManager::Remove_all_Clients() 
{
	FilesHelper::Clear_Files("Client.txt", "Client_last_id.txt");
}

//The Remove_all_Employee used to call the Clear_Files method from the FileHelper 
//then send it all the file names that contains all thee Employee data 
void FileManager::Remove_all_Employee()
{
	FilesHelper::Clear_Files("Employee.txt", "Employee_last_id.txt");
}

//The Remove_all_Admins used to call the Clear_Files method from the FileHelper 
//then send it all the file names that contains all thee Admins data 
void FileManager::Remove_all_Admins()
{
	FilesHelper::Clear_Files("Admin.txt", "Admin_last_id.txt");
}

//The Remove_specific_Client method takes the id for specific Client and send it to the File Helper
//to search for that id and remove it 
void FileManager::Remove_specific_Client(int id)
{
	FilesHelper::Remove_specific_Client(id);

}

//The Remove_specific_Employee method takes the id for specific Employee and send it to the File Helper 
//to search for that id and remove it 
void FileManager::Remove_specific_Employee(int id)
{
	FilesHelper::Remove_specific_Employee(id);
}

//The Get_All_Data method used to get all the data from the csv files to the vector 
void FileManager::Get_All_Data()
{
	FilesHelper::get_all_Admins();
	FilesHelper::get_all_Employee();
	FilesHelper::get_all_Clients();
}
