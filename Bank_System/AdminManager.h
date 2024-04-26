#pragma once


#include<iostream>
#include <chrono>
#include <thread>
#include"FileManager.h"
#include"FilesHelper.h"
#include"Admin.h"
#include"Client.h"
#include"EmployeeManager.h"
#include "ClientManger.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;






class AdminManager
{

	static void AdminsMenu();

public:

	static void new_Client(Admin* admin);

	static void delete_Client(int id);

	static void List_all_Clients(Admin* admin);

	static void Client_search(Admin* admin);

	static void Edit_Client_info(Admin* admin);

	static Client* login_as_Client(int id, string pass);

	static void new_Employee(Admin* admin);

	static void delete_Employee(int id);

	static void Employee_search(Admin* admin);

	static void List_all_Employee(Admin* admin);

	static void Edit_Employee_info(Admin* admin);

	static void login_as_Employee(int id, string pass);

	static Admin* login(int id, string pass);

	static void update_pass(int id);

	static bool Admin_options(Admin* admin);

};

