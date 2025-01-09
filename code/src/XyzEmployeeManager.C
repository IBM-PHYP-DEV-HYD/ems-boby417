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

void XyzEmployeeManager::addNewEmployee(XyzEmployeeIF *empPtrParam,EmpType empTypeParam)
{
    XyzEmployeeIF *sEmpPtr = NULL;
    if(!empPtrParam)
    {
        ADD_PRINT("ADDING FULL TIME EMPLOYEE")
        sEmpPtr = createAndGetEmployeeType(empTypeParam);
    }
    else
    {
        sEmpPtr = empPtrParam;
    }
    initializeEmployeeDeque();
    mEmployeeDequePtr->pushBack(sEmpPtr);
}

void printHeader(EmpType empTypeParam = TYPE_NONE,EmpStatus empStatusParam=STATUS_NONE)
{
     cout<<"\n\n"<<endl;

    /* Print the Header */
    printElement("Employee Name",25);
    printElement("ID",15);
    printElement("Type",20);
    printElement("Status",20);
    printElement("Gender",20);
    printElement("Date of birth",20);
    printElement("Date of joining",20);
    printElement("Date of Leaving",20);
    if(empStatusParam != STATUS_RESIGNED)
    {
        if(empTypeParam != TYPE_NONE)
        {
            if(empTypeParam == TYPE_FULL)
            {
                
                printElement("Number of Leaves",15);
            }
            else if(empTypeParam == TYPE_CONTRACTOR)
            {
                printElement("Agency",20);
            }
            else
            {
                printElement("College",20);
                printElement("Branch",20);
            }
            cout<<endl;
            cout << left << setw(220) << setfill('-') <<"-";
            
        }
        else
        {
            printElement("No of Leaves",15);
            printElement("Agency",20);
            printElement("College",20);
            printElement("Branch",20);
            cout<<endl;
            cout << left << setw(240) << setfill('-') <<"-";
        }
    }
    else
    {
        cout<<endl;
        cout << left << setw(180) << setfill('-') <<"-";
    }
    cout<<endl;
   
}

void XyzEmployeeManager::printEmployeeSummaryByType(EmpType empTypeParam,EmpStatus empStatusParam)
{
   
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;

    printHeader(empTypeParam,empStatusParam);

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        if((empTypeParam == TYPE_NONE)  && (empStatusParam == STATUS_NONE))
        {
            if((*mEmployeeDequePtr)[itr]->getEmployeeStatus() != STATUS_RESIGNED)
            {
                (*mEmployeeDequePtr)[itr]->printAllEmployeeDetails(true);
                cout<<endl;
            } 
        }
        else if(empStatusParam == STATUS_RESIGNED)
        {
            if((*mEmployeeDequePtr)[itr]->getEmployeeStatus() == STATUS_RESIGNED)
            {
                (*mEmployeeDequePtr)[itr]->printAllEmployeeDetails(true);
                cout<<endl;
            }
        }
        else
        {
            EmpType sEmpType = (*mEmployeeDequePtr)[itr]->getEmployeeType();
            if(empTypeParam == sEmpType && (*mEmployeeDequePtr)[itr]->getEmployeeStatus() != STATUS_RESIGNED)
            {
                (*mEmployeeDequePtr)[itr]->printAllEmployeeDetails(false);
                cout<<endl;
            }
        }
    }
}

void XyzEmployeeManager::printEmployeeSummaryByGender(int empGenderParam)
{
   
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;

    printHeader();

    string sEmpGenderString = getEmployeeGenderFromEnum(empGenderParam);

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        string sEmpGender = (*mEmployeeDequePtr)[itr]->getEmployeeGender();
        if(sEmpGenderString == sEmpGender)
        {
            (*mEmployeeDequePtr)[itr]->printAllEmployeeDetails(false);
            cout<<endl;
        }
    }
}

void XyzEmployeeManager::printEmployeeSummaryByStatus(EmpStatus empStatusParam)
{
   
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;

    printHeader();

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        EmpStatus sEmpStatus = (*mEmployeeDequePtr)[itr]->getEmployeeStatus();
        if(sEmpStatus == empStatusParam)
        {
            (*mEmployeeDequePtr)[itr]->printAllEmployeeDetails(false);
            cout<<endl;
        }
    }
}

void XyzEmployeeManager::removeEmployeeByID(string empIDParam)
{
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            sEmpPtr->setEmployeeStatus(STATUS_RESIGNED);
            //mEmployeeDequePtr->addElementAtPosition(itr,sEmpPtr);
            break;
        }
    }
}

void XyzEmployeeManager::printEmployeeDetailsById()
{
    int sSizeofDeque = mEmployeeDequePtr?mEmployeeDequePtr->size():0;
    bool empIDFound = false;
    string sEmpid;

    cout<<"\n\nPlease enter employee ID to Search and Display \nEmployee Id example XYZ0001F/XYZ0001C/XYZ0001I"<<endl;
    cin>>sEmpid;
    if((sEmpid.length() != 8) &&  sEmpid.substr(0,3) != "XYZ")
    {
        cout<<"Invalid Emp Id entered"<<endl;
        return;
    }

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        if((*mEmployeeDequePtr)[itr]->getEmployeeId() == sEmpid)
        {
            cout<<*(*mEmployeeDequePtr)[itr];
            cout<<endl;
            empIDFound = true;
            break;
        }
    }

    if(empIDFound == false)
    {
        cout<<"Employee ID Entered is not found"<<endl;
    }
}

void XyzEmployeeManager::addEmployee(int numofEmpParam,bool isRandom, EmpType typeParam)
{
    
    for(int itr= 0;itr<numofEmpParam;itr++)
    {
        XyzEmployeeIF *sEmpPtr  = NULL;
        string sEmpName         = getEmployeeNameInRandom();
        string sEmpGender       = getEmployeeGenderInRandom();
        int sRandomYear         = getRandomNumber(1970,2003);
        string sEmpDOB          = generateRandomDate(sRandomYear);
        sRandomYear             = getRandomNumber(sRandomYear+21,2024);
        string sEmpDOJ          = generateRandomDate(sRandomYear);
        string sEmpDOL          = "NA";
        EmpStatus sEmpStatus    = getEmployeeStatusInRandom();
        if(isRandom == true)
        {
            int sEmpType            = getRandomNumber(1,3);
            if(sEmpType == TYPE_CONTRACTOR)
            {
                sEmpPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
            else if (sEmpType == TYPE_FULL)
            {
                sEmpPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
            else
            {
                sEmpPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
        }
        else
        {
            if(typeParam == TYPE_CONTRACTOR)
            {
                sEmpPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
            else if (typeParam == TYPE_FULL)
            {
                sEmpPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
            else
            {
                sEmpPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                addNewEmployee(sEmpPtr);
            }
        } 
    }
    
    

    cout<<"\n\n"<<endl;    
}
