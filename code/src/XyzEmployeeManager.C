#include "XyzEmployeeManager.H"

XyzEmployeeManager::XyzEmployeeManager()
{
    mEmployeeDequePtr = NULL;
}

void XyzEmployeeManager::initializeEmployeeDeque()
{
    if(mEmployeeDequePtr == NULL)
    {
        mEmployeeDequePtr = new EDLL<XyzEmployeeIF>();
    }
}

template<typename TN>
static TN* createCommonEmployee(EmpType empTypeParam)
{
    string sEmpName;
    string sEmpGender;
    string sEmpDOB;
    EmpStatus sEmpStatus;
    string sEmpDOJ;
    string sEmpDOL;


    cout<<"Please enter employee name : "<<endl;
    cin>>sEmpName;
    
    /* Gender */
    int sGenderChoice = 0;
    while(1)
    {
        cout<<"\nPlease select valid Gender ,\n1.Male\n2.Female"<<endl;
        cin>>sGenderChoice;
        if(sGenderChoice == 1 || sGenderChoice == 2)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
    sEmpGender = getEmployeeGenderFromEnum(sGenderChoice);

    /* Date of Birth */
    while(1)
    {
        int sDate = 0;
        int sMonth = 0;
        int sYear = 0;
        cout<<"Collecting the DOB Details: "<<endl;
        cout<<"Year 1964 - 2003"<<endl;
        cin>>sYear;
        if(cin.fail() || sYear >= 2003 || sYear <= 1964)
        {
            cout<<"\nInvalid year"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sYearString = toString(sYear,4);
        cout<<"Valid Month : 1 - 12"<<endl;
        cin>>sMonth;
        if(cin.fail() || sMonth > 12 || sMonth < 1)
        {
            cout<<"\nInvalid Month"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;   
        }
        string sMonthString = getMonthStringFromEnum(sMonth);
        
        cout<<"Valid Date:"<<endl;
        cin>>sDate;
        if(cin.fail() || sDate<1 || sDate>getMaxDateOfMonth(sYear,sMonth))
        {
            cout<<"\nInvalid Date"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sDateString = toString(sDate,2);
        sEmpDOB = sDateString+" "+sMonthString+" "+sYearString;
        cout<<sEmpDOB<<endl;
        break;
    }
    
    /* Employement Status */
    int sIntEmpStatus = 0;
    while(1)
    {
        cout<<"Please select employement status \n1.Active.\n2.In-Active\n3.Resigned"<<endl;
        cin>>sIntEmpStatus;
        if(sIntEmpStatus == 1 || sIntEmpStatus == 2 || sIntEmpStatus == 3)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    sEmpStatus = static_cast<EmpStatus>(sIntEmpStatus);

    /* Date of Joining */
    int sDate = 0;
    int sMonth = 0;
    int sYear = 0;
    while(1)
    {
        cout<<"Collecting the DOJ Details: "<<endl;
        cout<<"Year 1984 - 2023 "<<endl;
        cin>>sYear;
        if(cin.fail() || sYear >= 2024 || sYear <= 1983)
        {
            cout<<"\nInvalid year"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sYearString = toString(sYear,4);
        cout<<"Valid Month : 1 - 12"<<endl;
        cin>>sMonth;
        if(cin.fail() || sMonth > 12 || sMonth < 1)
        {
            cout<<"\nInvalid Month"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;   
        }
        string sMonthString = getMonthStringFromEnum(sMonth);
        
        cout<<"Valid Date:"<<endl;
        cin>>sDate;
        if(cin.fail() || sDate<1 || sDate>getMaxDateOfMonth(sYear,sMonth))
        {
            cout<<"\nInvalid Date"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sDateString = toString(sDate,2);
        sEmpDOJ = sDateString+" "+sMonthString+" "+sYearString;
        cout<<sEmpDOJ<<endl;
        break;
    }

    /* Set DOL for both Contractor and Intern */
    if(empTypeParam == TYPE_FULL)
    {
        sEmpDOL = "NA";
    }
    else if(empTypeParam == TYPE_CONTRACTOR)
    {
        sYear = sYear+1;
        string sYearString = toString(sYear,4);
        string sMonthString = getMonthStringFromEnum(sMonth);
        string sDateString = toString(sDate,2);
        sEmpDOL = sDateString+" "+sMonthString+" "+sYearString;
    }
    else
    {
        sMonth = sMonth+6;
        if(sMonth > 12)
        {
            sYear = sYear+1;
            sMonth = (sMonth%12);
            sDate = (sMonth == 2 && sDate == 29)?28:sDate;
        }
        string sYearString = toString(sYear,4);
        string sMonthString = getMonthStringFromEnum(sMonth);
        string sDateString = toString(sDate,2);
        sEmpDOL = sDateString+" "+sMonthString+" "+sYearString;
        cout<<sEmpDOL<<endl;
    }

    TN *sEmpPtr = new  TN(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
    return sEmpPtr;
}

XyzEmployeeIF* XyzEmployeeManager::createAndGetEmployeeType(int empChoiceParam)
{
    void *sTempNullPtr = NULL;
    XyzEmployeeIF *sEmpIFPtr = NULL;
    XyzFullTimeEmployee *sFullEmpPtr = NULL;
    XyzContractorEmployee *sContractorEmpPtr = NULL;
    XyzInternEmloyee *sInternEmpPtr = NULL;

    do
    {
        switch(empChoiceParam)
        {
            case TYPE_FULL:
            {
                sFullEmpPtr = createCommonEmployee<XyzFullTimeEmployee>(TYPE_FULL);
                cin>>*sFullEmpPtr;
                sEmpIFPtr = sFullEmpPtr;
            }
            break;
            case TYPE_CONTRACTOR:
            {
                sContractorEmpPtr = createCommonEmployee<XyzContractorEmployee>(TYPE_CONTRACTOR);
                cin>>*sContractorEmpPtr;
                sEmpIFPtr = sContractorEmpPtr;
            }
            break;
            case TYPE_INTERN:
            {
                sInternEmpPtr = createCommonEmployee<XyzInternEmloyee>(TYPE_CONTRACTOR);
                cin>>*sInternEmpPtr;
                sEmpIFPtr = sInternEmpPtr;
            }
            break;
            default:
                cout<<"Invalid Type choice"<<endl;
        }
    }while(0);

    return sEmpIFPtr;
}

void XyzEmployeeManager::addNewFullTimeEmployee()
{
    ADD_PRINT("ADDING FULL TIME EMPLOYEE")
    XyzEmployeeIF *sEmpPtr = createAndGetEmployeeType(TYPE_FULL);
    initializeEmployeeDeque();
    int sPos = XyzFullTimeEmployee::mNextEmproll-1;
    cout<<"Postion F = "<<sPos<<endl;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);
}

void XyzEmployeeManager::addNewContractorEmployee()
{
    ADD_PRINT("ADDING CONTRACTOR EMPLOYEE")
    XyzEmployeeIF *sEmpPtr = createAndGetEmployeeType(TYPE_CONTRACTOR);
    initializeEmployeeDeque();
    int sPos = XyzContractorEmployee::mNextEmproll+XyzFullTimeEmployee::mNextEmproll-1;
    cout<<"Postion C = "<<sPos<<endl;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);   
}

void XyzEmployeeManager::addNewInternEmployee()
{
    ADD_PRINT("ADDING INTERN EMPLOYEE")
    XyzEmployeeIF *sEmpPtr = createAndGetEmployeeType(TYPE_INTERN);
    initializeEmployeeDeque();
    int sPos = XyzFullTimeEmployee::mNextEmproll+XyzContractorEmployee::mNextEmproll+XyzInternEmloyee::mNextEmproll-1;
    cout<<"Postion I = "<<sPos<<endl;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);   
}

void XyzEmployeeManager::printAllEmployeesSummary()
{
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;

    cout<<"\n\n\n\n"<<endl;

     /* Print the Header */
    printElement("Employee Name",25);
    printElement("ID",15);
    printElement("Type",20);
    printElement("Status",20);
    printElement("Gender",20);
    printElement("Date of birth",20);
    printElement("Date of joining",20);
    printElement("Date of Leaving",20);
    cout<<endl;
    cout << left << setw(180) << setfill('-') <<"-";
    cout<<endl;
    //Form Employee ID
    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeName(),25);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeId(),15);
        printElement(getEmploymentTypeFromEnum((*mEmployeeDequePtr)[itr]->getEmployeeType()),20);
        printElement(getEmploymentStatusFromEnum((*mEmployeeDequePtr)[itr]->getEmployeeStatus()),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeGender(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOB(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOJ(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOL(),20);
        cout<<endl;
    }
}

void XyzEmployeeManager::printAllFullTimeEmployees()
{
    int sNumOfFulltime = XyzFullTimeEmployee::mNextEmproll;
    for(int itr = 0;itr < sNumOfFulltime; itr++)
    {
        cout<<*(*mEmployeeDequePtr)[itr]<<endl;
    }

}

void XyzEmployeeManager::printAllContractorEmployees()
{
    int sNumOfConttime = XyzContractorEmployee::mNextEmproll;
    int sStartPos = XyzFullTimeEmployee::mNextEmproll;
    for(int itr = sStartPos; itr < sNumOfConttime; itr++)
    {
        cout<<*(*mEmployeeDequePtr)[itr]<<endl;
    }
}

void XyzEmployeeManager::printAllInternEmployees()
{
    int sNumOfConttime = XyzInternEmloyee::mNextEmproll;
    int sStartPos = XyzFullTimeEmployee::mNextEmproll+XyzContractorEmployee::mNextEmproll;
    for(int itr = sStartPos; itr < sNumOfConttime; itr++)
    {
        cout<<*(*mEmployeeDequePtr)[itr]<<endl;
    }
}

void XyzEmployeeManager::removeFullTimeEmployeeByID(string empIDParam)
{
    int sNumOfFulltime = XyzFullTimeEmployee::mNextEmproll;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = 0;itr < sNumOfFulltime; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            break;
        }
    }
}

void XyzEmployeeManager::removeContractorEmployeeByID(string empIDParam)
{
    int sNumOfConttime = XyzContractorEmployee::mNextEmproll;
    int sStartPos = XyzFullTimeEmployee::mNextEmproll;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = sStartPos; itr < sNumOfConttime; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            break;
        }
    }
}

void XyzEmployeeManager::removeInternEmployeeByID(string empIDParam)
{
    int sNumOfConttime = XyzInternEmloyee::mNextEmproll;
    int sStartPos = XyzFullTimeEmployee::mNextEmproll+XyzContractorEmployee::mNextEmproll;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = sStartPos; itr < sNumOfConttime; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            break;
        }
    }
}

void XyzEmployeeManager::removeEmployee()
{
    int sEmpChoice = 0;
    string sEmpid;
    int sRet = 0;
    cout<<"Please select employee to remove \n1.Full-Time\n2.Contractor\n3.Intern"<<endl;
    cin>>sEmpChoice;

    if(cin.fail()|| sEmpChoice != 1 || sEmpChoice !=2 || sEmpChoice!=3)
    {
        cout<<"Invalid choice to remove any employee"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        sRet = E_FAILURE;
    }

    if(!sRet)
    {
        cout<<"Please enter employee ID to remove \n Employee Id example XYZ0001F/XYZ0001C/XYZ0001I"<<endl;
        cin>>sEmpid;
        if((sEmpid.length()<1 ||sEmpid.length()>8) &&  sEmpid.substr(0,3) != "XYZ"  && (sEmpid.substr(7,1)!= "F" || sEmpid.substr(7,1)!="C"|| sEmpid.substr(7,1)!="I"))
        {
            cout<<"Invalid Emp Id entered"<<endl;
            sRet = E_FAILURE;
        }
    }

    if(!sRet)
    {
        switch(sEmpChoice)
        {
            case TYPE_FULL:
            {
                removeFullTimeEmployeeByID(sEmpid);
            }
            break;
            case TYPE_CONTRACTOR:
            {
                removeContractorEmployeeByID(sEmpid);
            }
            break;
            case TYPE_INTERN:
            {
                removeInternEmployeeByID(sEmpid);
            }
            break;
            default: 
            {
                cout<<"Employee choice is invalid"<<endl;
                return ;
            }
        }
    }

    return;
}