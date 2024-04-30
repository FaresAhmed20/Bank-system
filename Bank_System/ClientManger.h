#pragma once
#include<iostream>
#include <chrono>
#include <thread>
#include"FileManager.h"
#include"FilesHelper.h"
#include"Client.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;




class ClientManger
{

	static void Client_Menu();

public:

	static void Update_Pass(int id );

	static Client* login(int id, string pass);

	static bool Client_options(Client* client);
};

