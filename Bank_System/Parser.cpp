#include "Parser.h"


vector<string> Parser::split(string line) {

	stringstream linee (line);
	vector<string>data;
	string parameter;

	while (getline(linee, parameter, ',')) {
		
		data.push_back(parameter);
	}
	
	return data;
}



Client Parser::phaser_to_client(string line) {

	vector<string>data = split(line);

	Client client;

	client.set_name(data[0]);
	client.set_password(data[2]);
	client.set_balance(stoi(data[3]));

	

	return client;


}



Employee Parser::phasee_to_employee(string line) {

	vector<string> data = split(line);

	Employee employee;

	employee.set_name(data[0]);
	employee.set_password(data[2]);
	employee.set_salary(stoi(data[3]));

	return employee;
}



Admin Parser::phaser_to_admin(string line) {


	vector<string> data = split(line);

	Admin admin;

	admin.set_name(data[0]);
	admin.set_password(data[2]);
	admin.set_salary(stoi(data[3]));


	return admin;
}