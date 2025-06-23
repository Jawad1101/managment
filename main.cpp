#include <iostream>
#include "classes/Doctor.hpp"
#include "classes/Patient.hpp"
#include "classes/Staff.hpp"
using namespace std;

int main()
{
    const string doc_file = "doc_database.txt";
    const string emp_file = "emp_database.txt";
    const string staff_file = "staff_database.txt";

    int choice, i = 1, count = 0;
    Doctor doc;
    Staff staff;
    Patient patient;

main_menu:
    system("cls");

    cout << "enter your choice" << endl
         << "1. doctor" << endl
         << "2. staff" << endl
         << "3. patient" << endl
         << "0. end task" << endl;
    cout << "enter your choice > ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
    doctor_menu:
        system("cls");

        cout << "1. create new account" << endl
             << "2. login account" << endl
             << "0. go back" << endl;
        cout << "enter your choice > ";
        cin >> choice;

        if (choice == 1) // create account
        {
            doc.signup(doc_file);
            doc.desktop();
        }
        else if (choice == 2) // login
        {
            if (doc.login(doc_file))
                doc.desktop();
            else
                std::cout << "error: login unsuccesful - id or password not found\n";
        }
        else if (choice == 0)
            goto main_menu;
        else
            cout << "error: invalid choice - try again\n";

        cin.ignore();
        cin.get();
        goto doctor_menu;
        break;
    }
    case 2:
    {
    staff_menu:
        system("cls");

        cout << "1. create new account" << endl
             << "2. login account" << endl
             << "0. go back" << endl;
        cout << "enter your choice > ";
        cin >> choice;

        if (choice == 1) // create account
        {
            staff.signup(staff_file);
            staff.desktop();
        }
        else if (choice == 2) // login
        {
            if (staff.login(staff_file))
                staff.desktop();
            else
                std::cout << "error: login unsuccesful - id or password not found\n";
        }
        else if (choice == 0)
            goto main_menu;
        else
            cout << "error: invalid choice - try again\n";

        cin.ignore();
        cin.get();
        goto staff_menu;
        break;
    }
    case 3:
    {
    patient_menu:
        system("cls");

        cout << "1. doctor time table" << endl
             << "2. payment method" << endl
             << "0. go back" << endl;
        std::cout << "enter your choice > ";
        cin >> choice;

        if (choice == 1)
        {
            patient.doctor_time_table();
        }
        else if (choice == 2)
        {
            patient.payment();
        }
        else if (choice == 0)
        {
            goto main_menu;
        }
        cin.ignore();
        cin.get();
        goto patient_menu;
        break;
    }
    case 0:
    {
        return 0;
        break;
    }
    default:
    {
        cout << "error: invalid choice - try again\n";
    }
    }
    cin.ignore();
    cin.get();
    goto main_menu;
}