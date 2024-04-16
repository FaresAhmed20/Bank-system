#include "IdGenerator.h"
#include "cmath"



//Admin_id Genrates a unique id for the Admin that start with '1' that make it more easy in the seacrch in the database
void IdGenerator::adminId()
{
    int count = 0, loops = 0, temp_admin_id = Admin::admin_count;
    while (temp_admin_id != 0)
    {
        int last_digit = temp_admin_id % 10;
        if (last_digit == 9)
        {
            count++;
        }
        temp_admin_id /= 10;
        loops++;

    }


    if (count == loops - 1)
    {
        Admin::admin_count = 1 * pow(10, loops);

    }
    else
    {
        Admin::admin_count++;
    }
}
//Employee_id Genrates a unique id for the Employee that start with '2' that make it more easy in the seacrch in the database
void IdGenerator::employeeId()
{
    int count = 0, loops = 0, temp_employee_id = Employee::employee_count;
    while (temp_employee_id != 0) {
        int last_digit = temp_employee_id % 10;
        if (last_digit == 9) {
            count++;
        }
        temp_employee_id /= 10;
        loops++;
    }

    if (count == loops - 1) {
        Employee::employee_count = 2 * pow(10, loops);

    }
    else {
        Employee::employee_count++;

    }
}


//Client_id Genrates a unique id for the Client that start with '3' that make it more easy in the seacrch in the database
void IdGenerator::clientId()
{
    int count = 0, loops = 0, temp_client_id = Client::client_count;
    while (temp_client_id != 0)
    {
        int last_digit = temp_client_id % 10;
        if (last_digit == 9)
        {
            count++;
        }
        temp_client_id /= 10;
        loops++;

    }


    if (count == loops - 1)
    {
        Client::client_count = 3 * pow(10, loops);
    }
    else
    {
        Client::client_count++;
    }

}


void IdGenerator::last_Admin_id(int& id) {

    int count = 0, loops = 0, temp_last = id;
    while (temp_last != 0)
    {
        int last_digit = temp_last % 10;
        if (last_digit == 9)
        {
            count++;
        }
        temp_last /= 10;
        loops++;

    }
    if (count == loops - 1)
    {
        id = 1 * pow(10, loops);


    }
    else
    {
        id++;
    }

}


void IdGenerator::last_Employee_id(int& id) {

    int count = 0, loops = 0, temp_last = id;
    while (temp_last != 0)
    {
        int last_digit = temp_last % 10;
        if (last_digit == 9)
        {
            count++;
        }
        temp_last /= 10;
        loops++;

    }
    if (count == loops - 1)
    {
        id = 2 * pow(10, loops);


    }
    else
    {
        id++;
    }

}


void IdGenerator::last_Client_id(int& id) {


    int count = 0, loops = 0, temp_last = id;
    while (temp_last != 0)
    {
        int last_digit = temp_last % 10;
        if (last_digit == 9)
        {
            count++;
        }
        temp_last /= 10;
        loops++;

    }
    if (count == loops - 1)
    {
        id = 3 * pow(10, loops);


    }
    else
    {
        id++;
    }
}