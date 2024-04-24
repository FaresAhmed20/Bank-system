#pragma once
#include"iostream"
#include <chrono>
#include <thread>
#include"AdminManager.h"
#include"EmployeeManager.h"
#include"ClientManger.h"
#include"FileManager.h"
#include"FilesHelper.h"
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;

class Screen
{
	static void Bank_Name();

	static void Welcome();

	static void login_options();

	static int login_as();

	static void logout();

	static void login_screen(int choice);

	static void First_Admin();

public:

	static void RunApp();
};

