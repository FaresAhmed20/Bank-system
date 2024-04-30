#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;





class Encdec
{
	static const int key = 32;

public:

	static void Encryption(string FileName);

	static void Decryption(string FileName);







};

