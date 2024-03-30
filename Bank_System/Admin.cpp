#include "Admin.h"


//default constructor
Admin::Admin() {}


//parametrized constructor
Admin::Admin(string name, int id, string password, int salary)
    : Employee(name, id, password, salary) {

    set_name(name);
    set_id(id);
    set_password(password);
    set_salary(salary);
}

