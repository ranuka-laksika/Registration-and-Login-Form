#include<iostream>
#include<fstream>
#include<string>
#include<chrono> // for sleep function
#include<thread> // for sleep function
#include<unistd.h> // for sleep function
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int c;
    cout << "\t\t\t....................................................\n";
    cout << "\t\t\t                 Welcome To the Page                \n";
    cout << "\t\t\t                      Menu                         \n";
    cout << "\t\t\t......................................................\n\n";

    cout << "                                                     \n";
    cout << "\t|    Press 1 to Login                                  |\n";
    cout << "\t|    Press 2 to Registration                           |\n";
    cout << "\t|    Press 3 if you Forgot your Password               |\n";
    cout << "\t|    Press 4 to Exit                                   |\n";
    cout << "                                                     \n";

    cout << "\n\tPlease Enter your Choice: ";
    cin >> c;

    switch (c) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
            
        case 4:
            cout << "\t\t\t Thank you for using this program" << endl;
            break;
        default:
            system("cls");
            cout << "\t\t\t Invalid Choice - Please Select from the options given above" << endl;
            sleep(2);
            main();
    }
}

void login() {
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter the User name and the password " << endl;
    cout << endl;
    cout << "\t\t\t   USERNAME : ";
    cin >> userId;
    cout << "\t\t\t   PASSWORD : ";
    cin >> password;
    ifstream input("database.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1) {
        cout << "\t\t\t   Welcome to the Page - Login Successfully! " << userId << endl;
        sleep(2);
        main();
    } else {
        cout << "\t\t\t   Login Error - Please Check your Username and Password " << endl;
        sleep(3);
        system("cls");
        main();
    }
}

void registration() {
    string reguserId, regpass, rId, rpass;
    system("cls");
    cout << "\t\t\t   Enter the Username : ";
    cin >> reguserId;
    cout << "\t\t\t   Enter the Password : ";
    cin >> regpass;
    ifstream input("database.txt");

    while (input >> rId >> rpass) {
        if (rId == reguserId) {
            input.close();
            cout << "\t\t\t   User already registered. Please log in instead." << endl;
            sleep(2);
            main();
            return;
        }
    }

    input.close();
    ofstream reg("database.txt", ios::app);
    reg << reguserId << ' ' << regpass << endl;
    reg.close();

    system("cls");
    cout << "\t\t\t   Registration Successful!! " << endl;
    sleep(2);
    main();
}


void forgot() {
    int option;
    system("cls"); // Clear the console screen
    cout << "\t\t\t   You forgot the Password. Don't Worry  " << endl;
    cout << "\t\t\t   Press 1 to Search your Account by Username" << endl;
    cout << "\t\t\t   Press 2 to Go back to the main menu" << endl;
    cout << "\t\t\t   Enter your Choice : ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\t\t\t   Enter the Username : ";
            cin >> suserId;
            ifstream searchu("database.txt");
            while (searchu >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    cout << "\t\t\t   Hurray! Account Found" << endl;
                    cout << "\t\t\t   Your Password is : " << spass << endl;
                    sleep(2);  // Add a 2-second delay
                    searchu.close();
                    main();  // Return to the main menu
                }
            }
            searchu.close();
            if (count == 0) {
                cout << "\t\t\t   Sorry! Account Not Found" << endl;
            }
            break;
        }
        case 2: {
            main();
            break;
        }
        default:
            cout << "\t\t\t   Invalid Choice" << endl;
            forgot();
            break;
    }
}
