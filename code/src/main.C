#include "XyzEmployeeManager.H"
#include "printMenu.H"
using namespace std;

void processEmployeeAdding(XyzEmployeeManager *sEmpManager,int choiceParam)
{
    string sEmpName,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpGender,sEmpAgency,sEmpClg,sEmpBranch;
    EmsUtility::EmpStatus sEmpStatus;
    int sEmpNol,sEmpType=0;

    switch(choiceParam)
    {
        case 1:
        {
            cout<<"Enter Number of Random Employees to Create: ";
            int sNumofRandomEmployees = funcToDoWhileOnUserInputs(true,NULL,1,100,"Please Enter: ");
            for(int itr = 0;itr<sNumofRandomEmployees;itr++)
            {
                getEmployeeDetailsInRandom(sEmpType,sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus,sEmpNol,sEmpAgency,sEmpClg,sEmpBranch);
                sEmpManager->addNewEmployee(static_cast<EmsUtility::EmpType>(sEmpType),sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus,sEmpNol,sEmpAgency,sEmpClg,sEmpBranch);
            }
        }
        break;
        case 2:
        {
            sEmpType = funcToDoWhileOnUserInputs(false,printEmployeeTypeMenu,1,3,"Please select Type: ");
            if(sEmpType != EmsUtility::E_UNEXPECTED)
            {
                getEmployeeDetailsOnUserInputs(static_cast<EmsUtility::EmpType>(sEmpType),sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus,sEmpNol,sEmpAgency,sEmpClg,sEmpBranch);
                sEmpManager->addNewEmployee(static_cast<EmsUtility::EmpType>(sEmpType),sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus,sEmpNol,sEmpAgency,sEmpClg,sEmpBranch);
            }
        }
        break;
        default:
        {
            //Do-Nothing
        }
        break;
    }
}

void processEmployeeRemoving(XyzEmployeeManager *sEmpManager)
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
        sEmpManager->removeEmployeeByID(sEmpid);
    }
}

void processEmployeeDetailsPrinting(XyzEmployeeManager *sEmpManager,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            int sEmpTypeChoice = funcToDoWhileOnUserInputs(false,printEmployeeTypeMenu,1,3,"Please Select: ");
            if(sEmpTypeChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManager->printEmployeeSummaryByType(static_cast<EmsUtility::EmpType>(sEmpTypeChoice));
            }  
        }
        break;
        case 2:
        {
            int sEmployeeGenderChoice = funcToDoWhileOnUserInputs(false,printEmployeeGenderMenu,1,2,"Please select Gender: ");
            if(sEmployeeGenderChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManager->printEmployeeSummaryByGender(sEmployeeGenderChoice);
            } 
        }
        break;
        case 3:
        {
            int sEmployeeStatusChoice = funcToDoWhileOnUserInputs(false,printEmployeeStatusMenu,1,2,"Please select Status: ");
            if(sEmployeeStatusChoice != EmsUtility::E_UNEXPECTED)
            {
                sEmpManager->printEmployeeSummaryByStatus(static_cast<EmsUtility::EmpStatus>(sEmployeeStatusChoice));
            } 
        }
        break;
        case 4:
        {
            sEmpManager->printEmployeeSummaryByType();
        }
        break;
        case 5:
        {
            sEmpManager->printResignedEmpSummary();
        }
        break;
        default:
        {
            //Do-Nothing
        }
        break;
    }
}

void processEmployeeOtherdetailsMenu(XyzEmployeeManager *sEmpManager,int choiceParam)
{
    switch(choiceParam)
    {
        case 1:
        {
            cout<<"Please enter employee ID to Convert :: Eg: Employee Id XYZ0001C/XYZ0001I\n"<<endl;
            string sEmpid;
            cin>>sEmpid;
            if((sEmpid.length() != 8) ||  sEmpid.substr(0,3) != "XYZ")
            {
                cout<<"Invalid Emp Id entered"<<endl;
                break;
            }
            sEmpManager->convertToFullTime(sEmpid);
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
            sEmpManager->printEmployeeDetailsById(sEmpid);
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
                sEmpManager->addNumberofLeavesToFullTimeEmployee(sEmpid,sNol);
            }
        }
        break;
        default:
        {
           //Do-Nothing
        }
        break;
    }
}

int main(int argc, const char * argv[]) 
{

   XyzEmployeeManager *sEmpManager = new XyzEmployeeManager();
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
                    processEmployeeAdding(sEmpManager,sEmpAddOptionChoice);
                }
            }
            break;
            case 2:
            {
                processEmployeeRemoving(sEmpManager);
            }
            break;
            case 3:
            {
                int sEmployeeDetailsChoice = funcToDoWhileOnUserInputs(false,printEmployeedetailsMenu,1,5,"Please Select: ");
                if(sEmployeeDetailsChoice != EmsUtility::E_UNEXPECTED)
                {   
                    processEmployeeDetailsPrinting(sEmpManager,sEmployeeDetailsChoice);
                }
            }
            break;
            case 4:
            {
                int sEmployeeDetailsChoice = funcToDoWhileOnUserInputs(false,printEmployeeOtherdetailsMenu,1,3,"Please Select: ");
                if(sEmployeeDetailsChoice != EmsUtility::E_UNEXPECTED)
                {
                    processEmployeeOtherdetailsMenu(sEmpManager,sEmployeeDetailsChoice);
                }
            }
            break;
            default:
            {
                //Do-Nothing
            }
            break;
        }
   } while (true);
}