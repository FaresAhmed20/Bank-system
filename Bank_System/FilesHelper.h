#pragma once
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
class Employee;
class Admin;
using namespace std;




class FilesHelper
{
public:
	static void save_Client(Client client);
	static void save_Employee(Employee employee);
	static void save_Admins(Admin admin);

};

