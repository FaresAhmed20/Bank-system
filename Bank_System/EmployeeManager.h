#pragma once

#include<iostream>
#include <chrono>
#include <thread>
#include"FileManager.h"
#include"FilesHelper.h"
#include"Employee.h"
#include "ClientManger.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;





class EmployeeManager
{

	static void EmployeeMenu();

public:

	static void new_Client(Employee* employee);

	static void List_all_Clients(Employee* employee);

	static void Client_search(Employee* employee);

	static void Edit_Client_info(Employee* employee);

	static void update_pass(int id);

	static Employee* login(int id, string pass);

	static Client* login_as_Client(int id, string pass);

	static bool Employee_options(Employee* employee);

};

