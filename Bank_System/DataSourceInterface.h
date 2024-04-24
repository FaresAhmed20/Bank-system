#pragma once

#include<vector>
#include"Admin.h"
#include"Employee.h"
#include"Client.h"
class Employee;
class Admin;


class DataSourceInterface
{

	//Abstracted class that inherit the method to the file helper class and the file manger
	virtual void add_Client(Client& client) = 0;
	virtual void add_Employee(Employee& employee) = 0;
	virtual void add_Admin(Admin& admin) = 0;
	virtual vector<Client> get_all_Clients() = 0;
	virtual vector<Employee> get_all_Employee() = 0;
	virtual vector<Admin> get_all_Admins() = 0;
};
