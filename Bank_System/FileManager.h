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
	static void Delete_all_Clients();
	static void Delete_all_Employees();
	static Client* Client_search(int id);
	static Employee* Employee_search(int id);
	static Admin* Admin_search(int id);
	template <class Ty>
	static Ty* Search_all_data(int id);
	static void update_all_Clients(int id);
	static void update_all_Employee(int id);
	static void update_all_Admins(int id);
	static void Remove_all_Clients();
	static void Remove_all_Employee();
	static void Remove_all_Admins();
	static void Remove_specific_Client(int id);
	static void Remove_specific_Employee(int id);
	static void Get_All_Data();
};

