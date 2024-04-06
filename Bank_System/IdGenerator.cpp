#include "IdGenerator.h"
#include "cmath"


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
