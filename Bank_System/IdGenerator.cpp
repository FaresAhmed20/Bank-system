#include "IdGenerator.h"
#include "cmath"



//Admin_id Generates a unique id for the Admin that start with '1' that make it more easy in the search in the database
void IdGenerator::last_Admin_id(int& id) {

    ifstream file("Admin_last_id.txt");

    file >> id;

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

    file.close();
}

//Employee_id Generates a unique id for the Employee that start with '2' that make it more easy in the search in the database
void IdGenerator::last_Employee_id(int& id) {

    ifstream file("Employee_last_id.txt");

    file >> id;
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

    file.close();
}

//Client_id Generates a unique id for the Client that start with '3' that make it more easy in the search in the database
void IdGenerator::last_Client_id(int& id) {


    ifstream file("Client_last_id.txt");
    file >> id;

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

    file.close();
}