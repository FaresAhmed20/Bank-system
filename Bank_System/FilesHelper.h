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




class FilesHelper
{
public:
	static void save_Client(Client &client);
	static void save_Employee(Employee &employee);
	static void save_Admins(Admin &admin);
	static void get_all_Clients();
	static void get_all_Employee();
	static void get_all_Admins();
	static void desplay_all_clients();
	static void desplay_all_employee();
	static void desplay_all_admins();
	static Client* Client_search(int id);
	static Employee* Employee_search(int id);
	static Admin* Admin_search(int id);
	/*template <class Ty>
	static Ty* Search_all_data(int id);*/
};

