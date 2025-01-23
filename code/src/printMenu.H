#ifndef PRINTMENU_H
#define PRINTMENU_H
#include "iostream"


using namespace std;

void printMainMenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any Option below          |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Add an Employee.              |"<<endl;
    cout<<"| 2. Remove an employee.           |"<<endl;
    cout<<"| 3. Employee Details              |"<<endl;
    cout<<"| 4. Others.                       |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"|      Press -1 to exit            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeAddOptions(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any option below.         |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Add Employee at Random        |"<<endl;
    cout<<"| 2. Add an Employee (F/C/I)       |"<<endl;
    cout<<"-----------------------------------|"<<endl;
    cout<<"|   Press -1 to Exit.              |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeGenderMenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any option below.         |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Male                          |"<<endl;
    cout<<"| 2. Female                        |"<<endl;
    cout<<"-----------------------------------|"<<endl;
    cout<<"|   Press -1 to Exit.              |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeStatusMenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any option below.         |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Active                          |"<<endl;
    cout<<"| 2. In-Active                        |"<<endl;
    cout<<"-----------------------------------|"<<endl;
    cout<<"|   Press -1 to Exit.              |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}


void printEmployeeTypeMenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose Employee Type.            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Full-time Employee            |"<<endl;
    cout<<"| 2. Contractor Employee           |"<<endl;
    cout<<"| 3. Intern Employee               |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"|      Press -1 to exit            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

/*
void printRemovemenu(void)
{
    cout<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| Choose option to remove              |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| 1. Remove All employees              |"<<endl;
    cout<<"| 2. Remove based on Type.             |"<<endl;
    cout<<"| 3. Remove based on Gender            |"<<endl;
    cout<<"| 4. Remove based on Status            |"<<endl;
    cout<<"| 5. Remove based on ID.               |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<endl<<endl;
}
*/

void printEmployeedetailsMenu(void)
{
    cout<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| Choose Employee Details.             |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| 1. Employee Summary based on type.   |"<<endl;
    cout<<"| 2. Employee Summary based on Gender  |"<<endl;
    cout<<"| 3. Employee Summary based on Status  |"<<endl;
    cout<<"| 4. All Employee Summary.             |"<<endl;
    cout<<"| 5. Resigned Employee Summary.        |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeOtherdetailsMenu(void)
{
    cout<<endl<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"| Others Details                                            |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"| 1. Convert an Employee to Full-Time employee              |"<<endl;
    cout<<"| 2. Search an Employee by ID                               |"<<endl;
    cout<<"| 3. Add number of leaves to Full-Time by ID                |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                                     |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<endl<<endl;
}
#endif