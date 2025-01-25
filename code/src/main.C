#include "XyzEmployeeManager.H"
#include "printMenu.H"
using namespace std;


void processEmployeeAdding(XyzEmployeeManager *sEmpManger,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            cout<<"Enter Number of Random Employees to Create: ";
            int sNumofRandomEmployees = funcToDoWhileOnUserInputs(true,NULL,1,100,"Please Enter: ");
            sEmpManger->addEmployee(sNumofRandomEmployees,true);
        }
        break;
        case 2:
        {
            int sEmpTypeChoice = funcToDoWhileOnUserInputs(false,printEmployeeTypeMenu,1,3,"Please select Type: ");
            if(sEmpTypeChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManger->addEmployee(1,false,static_cast<EmsUtility::EmpType>(sEmpTypeChoice));
            }
        }
        break;
        default:
        {
            
        }
    }
}

void processEmployeeRemoving(XyzEmployeeManager *sEmpManger)
{
    string sEmpid;
    cout<<"Please enter employee ID to remove :: Eg: Employee Id XYZ0001F/XYZ0001C/XYZ0001I\n"<<endl;
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
            int sEmpTypeChoice = funcToDoWhileOnUserInputs(false,printEmployeeTypeMenu,1,3,"Please Select: ");
            if(sEmpTypeChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManger->printEmployeeSummaryByType(static_cast<EmsUtility::EmpType>(sEmpTypeChoice));
            }  
        }
        break;
        case 2:
        {
            int sEmployeeGenderChoice = funcToDoWhileOnUserInputs(false,printEmployeeGenderMenu,1,2,"Please select Gender: ");
            if(sEmployeeGenderChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManger->printEmployeeSummaryByGender(sEmployeeGenderChoice);
            } 
        }
        break;
        case 3:
        {
            int sEmployeeStatusChoice = funcToDoWhileOnUserInputs(false,printEmployeeStatusMenu,1,2,"Please select Status: ");
            if(sEmployeeStatusChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManger->printEmployeeSummaryByStatus(static_cast<EmsUtility::EmpStatus>(sEmployeeStatusChoice));
            } 
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
        }
    
    }
}

void processEmployeeOtherdetailsMenu(XyzEmployeeManager *sEmpManger,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            int sEmpTypeChoice = funcToDoWhileOnUserInputs(false,printEmployeeTypeForConversionMenu,1,2,"Enter Employee Type: ");
            if(sEmpTypeChoice != EmsUtility::E_UNEXPECTED)
            {
                cout<<"Please enter employee ID to Convert :: Eg: Employee Id XYZ0001C/XYZ0001I\n"<<endl;
                string sEmpid;
                cin>>sEmpid;
                if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
                {
                    cout<<"Invalid Emp Id entered"<<endl;
                    break;
                }
                EmsUtility::EmpType sEmpType;
                if(sEmpTypeChoice == 1)
                {
                    sEmpType = EmsUtility::TYPE_CONTRACTOR;
                }
                else
                {
                    sEmpType = EmsUtility::TYPE_INTERN;
                }
                sEmpManger->convertToFullTime(sEmpType,sEmpid);
            }
        }
        break;
        case 2:
        {
            cout<<"Please enter employee ID to Search :: Eg: Employee Id XYZ0001F/XYZ0001C/XYZ0001I\n"<<endl;
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
        case 3:
        {
            cout<<"Please enter Full time employee ID to Add leaves :: Eg: Employee Id example XYZ0001F\n"<<endl;
            string sEmpid;
            cin>>sEmpid;
            if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
            {
                cout<<"Invalid Emp Id entered"<<endl;
                break;
            }
            cout<<"Number of leaves to be added , must be <=15"<<endl;
            int sNol = funcToDoWhileOnUserInputs(false,NULL,5,15,"Please enter :");
            if(sNol != EmsUtility::E_UNEXPECTED)
            {
                sEmpManger->addNumberofLeavesToFullTimeEmployee(sEmpid,sNol);
            }
        }
        break;
        default:
        {
            if(choiceParam == EmsUtility::E_UNEXPECTED)
            {
                exit(0);
            }
        }
    }
}

int main(int argc, const char * argv[]) 
{

   XyzEmployeeManager *sEmpManger = new XyzEmployeeManager();
   int sMainMenuChoice = 0;
   
   do
   {
        sMainMenuChoice = funcToDoWhileOnUserInputs(false,printMainMenu,1,4,"Please Select: ");
        switch (sMainMenuChoice)
        {
            case 1:
            {
                int sEmpAddOptionChoice = funcToDoWhileOnUserInputs(false,printEmployeeAddOptions,1,2,"Please Select: ");
                if(sEmpAddOptionChoice != EmsUtility::E_UNEXPECTED)
                {
                    processEmployeeAdding(sEmpManger,sEmpAddOptionChoice);
                }
            }
            break;
            case 2:
            {
                processEmployeeRemoving(sEmpManger);
            }
            break;
            case 3:
            {
                int sEmployeeDetailsChoice = funcToDoWhileOnUserInputs(false,printEmployeedetailsMenu,1,5,"Please Select: ");
                if(sEmployeeDetailsChoice != EmsUtility::E_UNEXPECTED)
                {   
                    processEmployeeDetailsPrinting(sEmpManger,sEmployeeDetailsChoice);
                }
            }
            break;
            case 4:
            {
                int sEmployeeDetailsChoice = funcToDoWhileOnUserInputs(false,printEmployeeOtherdetailsMenu,1,3,"Please Select: ");
                if(sEmployeeDetailsChoice != EmsUtility::E_UNEXPECTED)
                {
                    processEmployeeOtherdetailsMenu(sEmpManger,sEmployeeDetailsChoice);
                }
            }
            break;
            default:
            {
            }
            break;
        }
   } while (true);
}