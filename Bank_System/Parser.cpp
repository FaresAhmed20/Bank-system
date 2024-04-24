#include "Parser.h"



//the split function that gets the line from the csv and split it to  a useful data 
//the function cuts the data at every comma and store it in the data vector 
//since the comma that split the parameter from each other 
vector<string> Parser::split(string line) {

	stringstream linee (line);
	vector<string>data;
	string parameter;

	while (getline(linee, parameter, ',')) {
		
		data.push_back(parameter);
	}
	
	return data;
}


//the phaser_to_client method send every line to the split method and take the return from the method and store it in 
//the right sequance that can be strored and accessed in the main vector
Client Parser::phaser_to_client(string line) {

	vector<string>data = split(line);

	Client client;

	client.set_name(data[0]);
	client.set_id(stoi(data[1]));
	client.set_password(data[2]);
	client.set_balance(stoi(data[3]));

	

	return client;


}


//the phaser_to_Employee method send every line to the split method and take the return from the method and store it in 
//the right sequence that can be stored and accessed in the main vector
Employee Parser::phaser_to_employee(string line) {

	vector<string> data = split(line);
	
	Employee employee;

	employee.set_name(data[0]);
	employee.set_id(stoi(data[1]));
	employee.set_password(data[2]);
	employee.set_salary(stoi(data[3]));


	return employee;
}


//the phaser_to_Admin method send every line to the split method and take the return from the method and store it in 
//the right sequence that can be stored and accessed in the main vector
Admin Parser::phaser_to_admin(string line) {


	vector<string> data = split(line);

	Admin admin;

	admin.set_name(data[0]);
	admin.set_id(stoi(data[1]));
	admin.set_password(data[2]);
	admin.set_salary(stoi(data[3]));


	return admin;
}