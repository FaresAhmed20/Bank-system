#include "FilesHelper.h"


//the save_Client function takes a Client by reference and add it's  data to the csv files 
//every client in a unique row and it's data is separated by a comma 
//it start by opining the file then start writing the info of the client in it 
//it start by checking the next unique id that this Client will take the after that it start writing the data that the user just entered 
// the Client.txt file is open in tha append mode so that if the file not found it creat a new file 
void FilesHelper::save_Client(Client &client) {

	

	int last_id; 
	IdGenerator::last_Client_id(last_id);


	ofstream file("Client.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {
		
		file << client.get_name() << "," 
			<< last_id << ',' 
			<< client.get_password() << ','
			<< client.get_balance()<<'\n';
		file.close();
	}

	ofstream file3("Client_last_id.txt");

	file3 << last_id;
	file3.close();
	return;
}

//the save_Employee function takes a Employee by reference and add it's  data to the csv files 
//every Employee is put in a unique row and it's data is separated by a comma 
//it start by opining the file then start writing the info of the Employee in it 
//it start by checking the next unique id that this Employee will take the after that it start writing the data that the user just entered 
// the Employee.txt file is open in tha append mode so that if the file not found it creat a new file 
void FilesHelper::save_Employee(Employee &employee) {

	

	int last_id;
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

//the save_Admin function takes a Admin by reference and add it's  data to the csv files 
//every Admin in a unique row and it's data is separated by a comma 
//it start by opining the file then start writing the info of the client in it 
//it start by checking the next unique id that this Admin will take the after that it start writing the data that the user just entered 
// the Admin.txt file is open in tha append mode so that if the file not found it creat a new file 
void FilesHelper::save_Admins(Admin &admin) {

	
	int last_id;
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

//the main function that reads every line of the file
// and change it to a suitable kind of data that can be stored in the vector
//then return it so it can be used
void FilesHelper::get_all_Clients() {
	
	ifstream file;
	string line;
	file.open("Client.txt" , ios::in);
	if (!file.is_open()) {
		cout << "Error while opening the file" << endl;
	}
	else {

		while(getline(file, line)) {
			//the Phaser_to_Client method takes every line in the csv file
			//  and cut it and return the data to be stored
			Client client = Parser::phaser_to_client(line);
			clients.push_back(client);
		}
		file.close();

	}
	

}

//the main function that reads every line of the Employee file
// and change it to a suitable kind of data that can be stored in the vector
//then return it so it can be used
void FilesHelper::get_all_Employee() {

	ifstream file;
	string line;
	file.open("Employee.txt");
	
	if (!file.is_open()) {
		cout << "Error while opening the file " << endl;
	}
	else {
		
		while (getline(file, line)) {

			//the Phaser_to_Employee method takes every line in the csv file
			//  and cut it and return the data to be stored
			Employee employee = Parser::phaser_to_employee(line);
			Employees.push_back(employee);
		}
		file.close();
		
	}
}

//the main function that reads every line of the Admin file
// and change it to a suitable kind of data that can be stored in the vector
//then return it so it can be used
void FilesHelper::get_all_Admins() {

	ifstream file;
	string line;

	file.open("Admin.txt");

	if (!file.is_open()) {
		cout << "Admin file can't be retched" << endl;
	}
	else {

		while (getline(file, line)) {

			//the Phaser_to_Admin method takes every line in the csv file
			//  and cut it and return the data to be stored
			Admin admin = Parser::phaser_to_admin(line);
			Admins.push_back(admin);


		}
		file.close();
	}
}

//The Delete_all_Clients method used to delete all the data that is found in the vector 
void FilesHelper::Delete_all_Clients()
{
	clients.erase(clients.begin() , clients.end());
}

//The Delete_all_Employee method used to delete all the data that is found in the vector 
void FilesHelper::Delete_all_Employee()
{
	Employees.erase(Employees.begin(), Employees.end());
}

//the Display_Client function first call the the get_all_Client to store the data in the vector 
// then call the display_info for every client in the vector to print it's unique info
void FilesHelper::display_all_clients() {

	ifstream file("Client.txt");

	file.seekg(0, ios::out);

	if (file.tellg() != 0) {

		for (auto& client : clients) {

			client.display_info();
			cout << "--------------------" << endl;
		}
	}
	else {
		cout << "There is no Clients in the Database "<<endl;
	}

	
}

//the Display_Employee function first call the the get_all_Client to store the data in the vector 
// then call the display_info for every Employee in the vector to print it's unique info
void FilesHelper::display_all_employee() {

	ifstream file("Employee.txt");

	file.seekg(0, ios::out);

	if (file.tellg() != 0) {

		for (auto& Employee : Employees) {

			Employee.display_info();
			cout << "--------------------" << endl;
		}
	}
	else {
		cout << "There is no Employees in the Database " << endl;
	}
}


//the Display_Admin function first call the the get_all_Client to store the data in the vector 
// then call the display_info for every Admin in the vector to print it's unique info
void FilesHelper::display_all_admins() {

	get_all_Admins();

	for (auto& admin : Admins) {

		admin.display_info();
		cout << "--------------------" << endl;
	}
}

//the Client_Search function used to search in the database for a specific client 
//using the unique id that the client have "it's start by calling the get_all_Client function to be sure 
//that all the data place in the vector then by using the auto pointer start searching for the client 
// if the client found it return it's data if not it return nullptr
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

//the Employee_Search function used to search in the database for a specific Employee 
//using the unique id that the Employee have "it's start by calling the get_all_Employee function to be sure 
//that all the data place in the vector then by using the auto pointer start searching for the Employee 
// if the Employee found it return it's data if not it return nullptr
Employee* FilesHelper::Employee_search(int id) {

	get_all_Employee();
	
	for (auto &Employee : Employees) {
		
		if (Employee.get_id() == id) {

			return &Employee;
			
		}

	}
	return NULL;
}

//the Admin_Search function used to search in the database for a specific Admin 
//using the unique id that the client have "it's start by calling the get_all_Client function to be sure 
//that all the data place in the vector then by using the auto pointer start searching for the Admin 
// if the Admin found it return it's data if not it return nullptr
Admin* FilesHelper::Admin_search(int id) {

	get_all_Admins();

	for (auto& Admin : Admins) {

		if (Admin.get_id() == id) {

			return &Admin;
		}
	}
}

//search_all_data function used to search the three types of information in one function using template
//it first get all the data of the Client , Employee and Admin's in the vector 
// then check the for the id type and search in the vector for that specific id 
// if the id found in the searched vector it return the owner's data otherwise it return nullptr
template<class Ty>
Ty* FilesHelper::Search_all_data(int id) {


	get_all_Admins();
	get_all_Employee();
	get_all_Clients();

	int num = id;
	int temp = 0;
	while (num)
	{

		temp = num % 10;
		num /= 10;

	}

	if (temp == 1) {

		for (auto& Admin : Admins) {

			if (Admin.get_id() == id) {
				

				return &Admin;

			}

			return nullptr;
		}


	}
	else if (temp == 2) {


		for (auto& Employee : Employees) {

			if (Employee.get_id() == id) {

				return &Employee;

			}

		}
		return nullptr;

	}
	else {

		for (auto& Client : clients) {

			if (Client.get_id() == clients) {

				return &Client;
			}

		}
		return nullptr;
	}
	
}

//The Clear_Files method takes two file name and clear the data inside them 
void FilesHelper::Clear_Files(string filename, string FileName) {
	
	fstream file1, file2;
	file1.open(filename, ios::out);
	file1.close();
	
	if (FileName[0] == 'C') {

		file2.open(FileName, ios::out);
		file2 << 300;
		file2.close();
		

	}
	else if (FileName[0] == 'E') {

		file2.open(FileName, ios::out);
		file2 << 200;
		file2.close();


	}
	else {

		file2.open(FileName, ios::out);
		file2 << 100;
		file2.close();

	}
	return;
}

//The Update_Client takes the id of the client that it's data have been updated and Renters it in the database 
void FilesHelper::Update_Client(int id) {



	ifstream file("Client.txt");

	ofstream temp_file("Temp_Client.txt", ios::out);

	string line;


	int currentLine = 301;
	while (getline(file, line))
	{
		if (currentLine != id)
		{
			temp_file << line << endl;

		}
		else
		{
			temp_file << FileManager::Client_search(id)->get_name() << ","
				<< FileManager::Client_search(id)->get_id() << ","
				<< FileManager::Client_search(id)->get_password() << ","
				<< FileManager::Client_search(id)->get_balance()<< endl;
		}

		IdGenerator::current_Line_Generator(currentLine);


	}

	file.close();
	temp_file.close();

	string fileName = "Client.txt";


	remove(fileName.c_str());
	rename("Temp_Client.txt", fileName.c_str());
}

//The Update_Employee takes the id of the Employee that it's data have been updated and Renters it in the database
void FilesHelper::Update_Employee(int id) {

	ifstream file("Employee.txt");

	ofstream temp_file("Temp_Employee.txt", ios::out);

	string line;


	int currentLine = 201;
	while (getline(file, line))
	{
		if (currentLine != id)
		{
			temp_file << line << endl;

		}
		else
		{
			temp_file << FileManager::Employee_search(id)->get_name() << ","
				<< FileManager::Employee_search(id)->get_id() << ","
				<< FileManager::Employee_search(id)->get_password() << ","
				<< FileManager::Employee_search(id)->get_salary() << endl;
		}

		IdGenerator::current_Line_Generator(currentLine);


	}

	file.close();
	temp_file.close();

	string fileName = "Employee.txt";


	remove(fileName.c_str());
	rename("Temp_Employee.txt", fileName.c_str());
}

//The Update_Admin takes the id of the Admin that it's data have been updated and Renters it in the database
void FilesHelper::Update_Admins(int id)
{
	ifstream file("Admin.txt");

	ofstream temp_file("Temp_Admin.txt", ios::out);

	string line;


	int currentLine = 101;
	while (getline(file, line))
	{
		if (currentLine != id)
		{
			temp_file << line << endl;

		}
		else
		{
			temp_file << FileManager::Admin_search(id)->get_name() << ","
				<< FileManager::Admin_search(id)->get_id() << ","
				<< FileManager::Admin_search(id)->get_password() << ","
				<< FileManager::Admin_search(id)->get_salary() << endl;
		}

		IdGenerator::current_Line_Generator(currentLine);


	}

	file.close();
	temp_file.close();

	string fileName = "Admin.txt";


	remove(fileName.c_str());
	rename("Temp_Admin.txt", fileName.c_str());
}

//The Remove_specific_Client method takes the id for specific Client and remove it from the database
void FilesHelper::Remove_specific_Client(int id)
{
	ifstream file("Client.txt");

	ofstream temp_file("Temp_Client.txt", ios::out);

	string line;


	int currentLine = 301;
	while (getline(file, line))
	{
		if (currentLine != id)
		{
			temp_file << line << endl;

		}
		

		IdGenerator::current_Line_Generator(currentLine);


	}

	file.close();
	temp_file.close();

	string fileName = "Client.txt";


	remove(fileName.c_str());
	rename("Temp_Client.txt", fileName.c_str());
}

//The Remove_specific_Employee method takes the id for specific Client and remove it from the database
void FilesHelper::Remove_specific_Employee(int id)
{
	ifstream file("Employee.txt");

	ofstream temp_file("Temp_Employee.txt", ios::out);

	string line;


	int currentLine = 201;
	while (getline(file, line))
	{
		if (currentLine != id)
		{
			temp_file << line << endl;

		}
		

		IdGenerator::current_Line_Generator(currentLine);


	}

	file.close();
	temp_file.close();

	string fileName = "Employee.txt";


	remove(fileName.c_str());
	rename("Temp_Employee.txt", fileName.c_str());
}
