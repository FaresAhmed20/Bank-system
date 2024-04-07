#include "Validation.h"



bool Validation::check_name(string& name) {

	int count = name.size();

	for (char c : name) {


		if (!isalpha(c) && !isspace(c)) {

			return false;

		}
	}
	if (count < 5 || count > 20) {
		return false;
	}

	return true;

}



bool Validation::check_pass(string& password) {

	int count = password.size();

	if (count < 5 || count > 20) {
		return false;
	}
	else {
		return true;
	}

}

bool Validation::check_balance(double& balance) {

	if (balance < 1500) {
		return false;
	}
	return true;

}

bool Validation::check_salary(int& salary) {

	if (salary < 5000) {
		return false;
	}
	return true;

}
