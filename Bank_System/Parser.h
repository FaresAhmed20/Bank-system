#pragma once
#include"sstream"
#include"vector"
#include"string"
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
class Employee;
class Admin;


class Parser
{
	static vector<string> split(string line);
public:

	static Client phaser_to_client(string line);
	static Employee phasee_to_employee(string line);
	static Admin phaser_to_admin(string line);
};

