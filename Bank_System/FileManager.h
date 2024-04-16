#pragma once
#include"IdGenerator.h"
#include"DataSourceInterface.h"
#include"FilesHelper.h"
#include"Client.h"
#include<iostream>
class Employee;

using namespace std;




//the class that mange the data in the csv files
class FileManager 
{
public:
	static void add_Client(Client &client);
	static void add_Employee(Employee& employee);
	static void add_Admin(Admin& admin);
	static void get_all_Clients();
	static void get_all_Employee();
	static void get_all_Admins();
	static Client* Client_search(int id);
	static Employee* Employee_search(int id);
	static Admin* Admin_search(int id);
	template <class Ty>
	static Ty* Search_all_data(int id);
};

