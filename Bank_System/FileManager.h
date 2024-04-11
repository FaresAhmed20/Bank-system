#pragma once
#include"IdGenerator.h"
#include"DataSourceInterface.h"
#include"FilesHelper.h"
#include"Client.h"
#include<iostream>
class Employee;

using namespace std;





class FileManager 
{
public:
	static void add_Client(Client &client);
	static void add_Employee(Employee& employee);
	static void add_Admin(Admin& admin);
	static void get_all_Clients();
	static void get_all_Employee();
	static void get_all_Admins();
};

