
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation
{

public:

    static bool check_name(string& name);

    static bool check_pass(string& password);

    static bool check_balance(double& balance);

    static bool check_salary(int& salary);



};
