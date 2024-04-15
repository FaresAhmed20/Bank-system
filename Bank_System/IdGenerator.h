#pragma once
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
class IdGenerator
{
public:

	static void adminId();
	static void employeeId();
	static void clientId();
	static void last_Admin_id(int& id);
	static void last_Employee_id(int& id);
	static void last_Client_id(int& id);
};

