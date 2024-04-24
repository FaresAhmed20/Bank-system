#pragma once
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
class Employee;
class Admin;
using namespace std;



//the class that gets the data from and in the files 
//the only class that can access the files "Read and Write from the file"
class FilesHelper
{
public:
	static void save_Client(Client &client);
	static void save_Employee(Employee &employee);
	static void save_Admins(Admin &admin);
	static void get_all_Clients();
	static void get_all_Employee();
	static void get_all_Admins();
	static void Delete_all_Clients();
	static void Delete_all_Employee();
	static void display_all_clients();
	static void display_all_employee();
	static void display_all_admins();
	static Client* Client_search(int id);
	static Employee* Employee_search(int id);
	static Admin* Admin_search(int id);
	template <class Ty>
	static Ty* Search_all_data(int id);
	static void Clear_Files(string filename, string FileName);
	static void Update_Client(int id);
	static void Update_Employee(int id);
	static void Update_Admins(int id);
	static void Remove_specific_Client(int id);
	static void Remove_specific_Employee(int id);
};

