#include "XyzEmployeeManager.H"
#include "printMenu.H"
using namespace std;


void processEmployeeAdding(XyzEmployeeManager *sEmpManger,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            sEmpManger->addEmployee(10,true);
        }
        break;
        case 2:
        {
            printEmployeeTypeMenu();
            int sEmpTypeChoice = 0;
            cin>>sEmpTypeChoice;
            if(cin.fail() || (sEmpTypeChoice<1||sEmpTypeChoice>3))
            {
                if(sEmpTypeChoice == -1)
                {
                    exit(0);
                }
                cout<<"Please enter proper choice"<<endl;
                cin.clear();
                cin.ignore();
                break;
            }
            sEmpManger->addEmployee(1,false,static_cast<EmpType>(sEmpTypeChoice));
        }
        break;
        default:
        {
            if(choiceParam == -1)
            {
                exit(0);
            }
        }
    }
}

void processEmployeeRemoving(XyzEmployeeManager *sEmpManger)
{
    string sEmpid;
    cout<<"Please enter employee ID to remove \nEmployee Id example XYZ0001F/XYZ0001C/XYZ0001I"<<endl;
    cin>>sEmpid;
    if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
    {
        cout<<"Invalid Emp Id entered"<<endl;
    }
    else
    {
        sEmpManger->removeEmployeeByID(sEmpid);
    }
    
}

void processEmployeeDetailsPrinting(XyzEmployeeManager *sEmpManger,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            printEmployeeTypeMenu();
            int sEmpTypeChoice = 0;
            cin>>sEmpTypeChoice;
            if(cin.fail() || (sEmpTypeChoice<1||sEmpTypeChoice>3))
            {
                if(sEmpTypeChoice == -1)
                {
                    exit(0);
                }
                cout<<"Please enter proper choice"<<endl;
                cin.clear();
                cin.ignore();
                break;
            }
            sEmpManger->printEmployeeSummaryByType(static_cast<EmpType>(sEmpTypeChoice));
        }
        break;
        case 2:
        {
            printEmployeeGenderMenu();
            int sEmployeeGenderChoice = 0;
            cin>>sEmployeeGenderChoice;
            if(cin.fail() || (sEmployeeGenderChoice<1||sEmployeeGenderChoice>2))
            {
                if(sEmployeeGenderChoice == -1)
                {
                    exit(0);
                }
                cout<<"Please enter proper choice"<<endl;
                cin.clear();
                cin.ignore();
                break;
            }
            sEmpManger->printEmployeeSummaryByGender(sEmployeeGenderChoice);
        }
        break;
        case 3:
        {
            printEmployeeStatusMenu();
            int sEmployeeStatusChoice = 0;
            cin>>sEmployeeStatusChoice;
            if(cin.fail() || (sEmployeeStatusChoice<1||sEmployeeStatusChoice>2))
            {
                if(sEmployeeStatusChoice == -1)
                {
                    exit(0);
                }
                cout<<"Please enter proper choice"<<endl;
                cin.clear();
                cin.ignore();
                break;
            }
            sEmpManger->printEmployeeSummaryByStatus(static_cast<EmpStatus>(sEmployeeStatusChoice));
        }
        break;
        case 4:
        {
            sEmpManger->printEmployeeSummaryByType();
        }
        break;
        case 5:
        {
            sEmpManger->printResignedEmpSummary();
        }
        break;
        default:
        {
            if(choiceParam == -1)
            {
                exit(0);
            }
        }
    
    }
}

void processEmployeeOtherdetailsMenu(XyzEmployeeManager *sEmpManger,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            printEmployeeTypeMenu();
            int sEmpTypeChoice = 0;
            cin>>sEmpTypeChoice;
            if(cin.fail() || (sEmpTypeChoice<2||sEmpTypeChoice>3))
            {
                if(sEmpTypeChoice == -1)
                {
                    exit(0);
                }
                cout<<"Please enter proper choice"<<endl;
                cin.clear();
                cin.ignore();
                break;
            }
            cout<<"Please enter employee ID to Convert \nEmployee Id example XYZ0001F/XYZ0001C/XYZ0001I"<<endl;
            string sEmpid;
            cin>>sEmpid;
            if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
            {
                cout<<"Invalid Emp Id entered"<<endl;
                break;
            }
            sEmpManger->convertToFullTime(static_cast<EmpType>(sEmpTypeChoice),sEmpid);
        }
        break;
        case 2:
        {
            cout<<"Please enter employee ID to Search \nEmployee Id example XYZ0001F/XYZ0001C/XYZ0001I"<<endl;
            string sEmpid;
            cin>>sEmpid;
            if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
            {
                cout<<"Invalid Emp Id entered"<<endl;
                break;
            }
            sEmpManger->printEmployeeDetailsById(sEmpid);
        }
        break;
        default:
        {
            if(choiceParam == -1)
            {
                exit(0);
            }
        }
    }
}

int main(int argc, const char * argv[]) 
{

   XyzEmployeeManager *sEmpManger = new XyzEmployeeManager();
   int sMenu1Choice = 0;
   
   do
   {
        printMainMenu();
        cin>>sMenu1Choice;
        if(cin.fail())
        {
            cout<<"Please enter proper choice"<<endl;
            cin.clear();
            cin.ignore();
            break;
        }
        else
        {
            switch (sMenu1Choice)
            {
                case 1:
                {
                    printEmployeeAddOptions();
                    int sEmpAddOptionChoice = 0;
                    cin>>sEmpAddOptionChoice;
                    if(cin.fail() || (sEmpAddOptionChoice<1||sEmpAddOptionChoice>2))
                    {
                        if(sEmpAddOptionChoice == -1)
                        {
                            exit(0);
                        }
                        cout<<"Please enter proper choice"<<endl;
                        cin.clear();
                        cin.ignore();
                        break;
                    }
                    processEmployeeAdding(sEmpManger,sEmpAddOptionChoice);
                }
                break;
                case 2:
                {
                    processEmployeeRemoving(sEmpManger);
                }
                break;
                case 3:
                {
                    printEmployeedetailsMenu();
                    int sEmployeeDetailsChoice = 0;
                    cin>>sEmployeeDetailsChoice;
                    if(cin.fail() || (sEmployeeDetailsChoice<1||sEmployeeDetailsChoice>5))
                    {
                        if(sEmployeeDetailsChoice == -1)
                        {
                            exit(0);
                        }
                        cout<<"Please enter proper choice"<<endl;
                        cin.clear();
                        cin.ignore();
                        break;
                    }
                    processEmployeeDetailsPrinting(sEmpManger,sEmployeeDetailsChoice);

                }
                break;
                case 4:
                {
                    printEmployeeOtherdetailsMenu();
                    int sEmployeeDetailsChoice = 0;
                    cin>>sEmployeeDetailsChoice;
                    if(cin.fail() || (sEmployeeDetailsChoice<1||sEmployeeDetailsChoice>2))
                    {
                        if(sEmployeeDetailsChoice == -1)
                        {
                            exit(0);
                        }
                        cout<<"Please enter proper choice"<<endl;
                        cin.clear();
                        cin.ignore();
                        break;
                    }
                    processEmployeeOtherdetailsMenu(sEmpManger,sEmployeeDetailsChoice);
                }
                break;
                default:
                {
                    if(sMenu1Choice == -1)
                    {
                        exit(0);
                    }
                }
                break;
            }
        }

   } while (true);

}