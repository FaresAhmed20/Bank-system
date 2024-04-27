#include "Screen.h"



//Method to print the Bank name
void Screen::Bank_Name()
{

    cout << "\x1B[36m                       ##############       ########              ###########                        \033[0m   " << endl;
    cout << "\x1B[36m                       #                    #      #              #                                  \033[0m   " << endl;
    cout << "\x1B[36m                       #                    #      #              #                                  \033[0m " << endl;
    cout << "\x1B[36m                       #                    #      #              #                                  \033[0m " << endl;
    cout << "\x1B[36m                       #######              #      #              ###########                        \033[0m " << endl;
    cout << "\x1B[36m                       #                    #      #                        #                        \033[0m " << endl;
    cout << "\x1B[36m                       #                    #      #                        #                        \033[0m " << endl;
    cout << "\x1B[36m                       #                    #      #                        #                        \033[0m " << endl;
    cout << "\x1B[36m                       #                    ########              ###########                        \033[0m " << endl;


}

//Method to print the welcome massage
void Screen::Welcome()
{
    cout << "\x1B[5;36m #                           #   ##############   #                 #################   ############       #              #   ################            \033[0m   " << endl;
    cout << "\x1B[5;36m  #                         #    #                #                 #                   #          #       #  #        #  #   #                           \033[0m   " << endl;
    cout << "\x1B[5;36m   #                       #     #                #                 #                   #          #       #     #   #    #   #                             \033[0m " << endl;
    cout << "\x1B[5;36m    #          #          #      #                #                 #                   #          #       #       #      #   #                             \033[0m " << endl;
    cout << "\x1B[5;36m     #        #  #       #       ############     #                 #                   #          #       #              #   ############                  \033[0m " << endl;
    cout << "\x1B[5;36m      #      #    #     #        #                #                 #                   #          #       #              #   #                             \033[0m " << endl;
    cout << "\x1B[5;36m       #    #      #   #         #                #                 #                   #          #       #              #   #                            \033[0m " << endl;
    cout << "\x1B[5;36m        #  #        # #          #                #                 #                   #          #       #              #   #                             \033[0m " << endl;
    cout << "\x1B[5;36m         #           #           ##############   #############     #################   ############       #              #   ################              \033[0m " << endl;

}

//Method to print the login options
void Screen::login_options()
{
    cout << "Login option is : " << endl;
    cout << "1-Admin " << endl;
    cout << "2-Employee " << endl;
    cout << "3-Client " << endl;
    cout << "4-"<<"\x1B[31mLogout \033[0m" << endl;
}

//Method that takes the user input of the login option
int Screen::login_as()
{
    system("cls");
    login_options();
    cout << "Enter your choice : ";
    int choice;
    bool flag = true;
    cin >> choice;
    while (flag)
    {


       
        
        if (!cin.fail() and choice >= 1 and choice <= 4) {



            if (choice == 1 || choice == 2 || choice == 3) {
                flag = false;
                return choice;
            }
            else if (choice == 4) {
                logout();
            }

        }
        else {

            cout << "Invalid choice " << endl;
            cout << "Renter a Valid choice : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;

        }
    }
}


//The logout ,method used to log out from the system completely
void Screen::logout()
{
    
    system("cls");
    cout << " \x1B[5;33m                                          Thank you for using our Bank System  \033[0m                                                ";
    exit(0);
}

//The login_screen takes the user input from the login_as function and preform it 
void Screen::login_screen(int choice)
{

    int id;
    string pass;
    cout << "Enter the id of your account : ";
    cin >> id;
    cout << "Enter the password of your account : ";
    cin >> pass;

    if (choice == 1) {
        
        if (AdminManager::login(id, pass) != nullptr) {
            while (AdminManager::Admin_options(AdminManager::login(id, pass)) != false);
            login_screen(login_as());;
        }
    }
    else if (choice == 2) {

            if (EmployeeManager::login(id, pass) != nullptr) {

                while (EmployeeManager::Employee_options(EmployeeManager::login(id, pass)) != false);
                login_screen(login_as());;

            }

    }
    else {
        
        if (ClientManger::login(id, pass) != nullptr) {

            while (ClientManger::Client_options(ClientManger::login(id, pass)) != false);
            login_screen(login_as());;
        }
    }
}

//The First_Admin method used to check if there is no data in the admin file it adds one so the user can access the system using that account
void Screen::First_Admin()
{
    Encdec::Decryption("Admin.txt");
    ifstream file("Admin.txt");
    
    file.seekg(0, ios::out);
    
    if (file.tellg() == 0) {

        file.close();
        Encdec::Encryption("Admin.txt");


        Admin admin("Admin", "Admin", 5000);
        
        FilesHelper::save_Admins(admin);
        FileManager::get_all_Admins();
        exit;
    }
    else if (file.tellg() != 0) {

        file.close();
        Encdec::Encryption("Admin.txt");
       
    }
  
  
  
}

//The RunApp method is the method that collects all the App and run it
void Screen::RunApp()
{
    
    FileManager::Get_All_Data();
    First_Admin();
    /*Bank_Name();
    sleep_until(system_clock::now() + 3s);
    system("cls");
    Welcome();
    sleep_until(system_clock::now() + 3s);
    system("cls");*/
    login_screen(login_as());
}
