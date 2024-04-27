#include "Encdec.h"

void Encdec::Encryption(string FileName)
{
	fstream file(FileName , ios::in);
	fstream file2("temp.txt", ios::out);

	char c;

	while (file >> noskipws >> c) {

		c = c + key;
		file2 << c;

	}

	file.close();
	file2.close();

	

	remove(FileName.c_str());

	rename("temp.txt", FileName.c_str());

}


void Encdec::Decryption(string FileName)
{
	fstream file(FileName, ios::in);
	fstream file2("temp.txt", ios::out);

	char c;

	while (file >> noskipws >> c) {

		c = c - key;
		file2 << c;

	}

	file.close();
	file2.close();



	remove(FileName.c_str());
	rename("temp.txt", FileName.c_str());
}
