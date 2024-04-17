#pragma once
#include "Admin.h"
#include "Employee.h"
#include "Client.h"




//the IdGenerator generate an unique id to every Client , Employee , Admin that uses the system
class IdGenerator
{
public:


	static void last_Admin_id(int& id);
	static void last_Employee_id(int& id);
	static void last_Client_id(int& id);
};

