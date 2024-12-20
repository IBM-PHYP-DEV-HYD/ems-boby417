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

void XyzEmployeeManager::addNewFullTimeEmployee(XyzEmployeeIF *empPtrParam)
{
    XyzEmployeeIF *sEmpPtr = NULL;
    if(!empPtrParam)
    {
        ADD_PRINT("ADDING FULL TIME EMPLOYEE")
        sEmpPtr = createAndGetEmployeeType(TYPE_FULL);
    }
    else
    {
        sEmpPtr = empPtrParam;
    }
    initializeEmployeeDeque();
    int sPos = mFulltimeEmployeeCount;
    mFulltimeEmployeeCount++;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);
}

void XyzEmployeeManager::addNewContractorEmployee(XyzEmployeeIF *empPtrParam)
{
    XyzEmployeeIF *sEmpPtr = NULL;
    if(!empPtrParam)
    {
        ADD_PRINT("ADDING CONTRACTOR EMPLOYEE")
        sEmpPtr = createAndGetEmployeeType(TYPE_CONTRACTOR);
    }
    else
    {
        sEmpPtr = empPtrParam;
    }
    initializeEmployeeDeque();
    int sPos = mFulltimeEmployeeCount+mContractorEmployeeCount;
    mContractorEmployeeCount++;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);   
}

void XyzEmployeeManager::addNewInternEmployee(XyzEmployeeIF *empPtrParam)
{
    XyzEmployeeIF *sEmpPtr = NULL;
    if(!empPtrParam)
    {
        ADD_PRINT("ADDING INTERN EMPLOYEE")
        sEmpPtr = createAndGetEmployeeType(TYPE_INTERN);
    }
    else
    {
        sEmpPtr = empPtrParam;
    }
    initializeEmployeeDeque();
    int sPos = mFulltimeEmployeeCount+mContractorEmployeeCount+mInterEmployeeCount;
    mInterEmployeeCount++;
    mEmployeeDequePtr->addElementAtPosition(sPos,sEmpPtr);   
}

void XyzEmployeeManager::printEmployeeSummaryByType(EmpType empTypeParam, int startPosParam,int endPositionParam)
{
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
    if(empTypeParam == TYPE_FULL)
    {
        printElement("Number of Leaves",20);
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
    cout<<endl;
    //Form Employee ID
    for(int itr = startPosParam;itr < endPositionParam; itr++)
    {
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeName(),25);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeId(),15);
        printElement(getEmploymentTypeFromEnum((*mEmployeeDequePtr)[itr]->getEmployeeType()),20);
        printElement(getEmploymentStatusFromEnum((*mEmployeeDequePtr)[itr]->getEmployeeStatus()),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeGender(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOB(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOJ(),20);
        printElement((*mEmployeeDequePtr)[itr]->getEmployeeDOL(),20);
        if(empTypeParam == TYPE_FULL)
        {
            printElement((*mEmployeeDequePtr)[itr]->getNoOfLeaves(),20);
        }
        else if(empTypeParam == TYPE_CONTRACTOR)
        {
            printElement((*mEmployeeDequePtr)[itr]->getAgency(),20);
        }
        else
        {
            printElement((*mEmployeeDequePtr)[itr]->getCollege(),20);
            printElement((*mEmployeeDequePtr)[itr]->getBranch(),20);
        }
        cout<<endl;
    }
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
    int sNumOfFulltime = mFulltimeEmployeeCount;
    printEmployeeSummaryByType(TYPE_FULL,0,sNumOfFulltime);
    cout<<"\n\n"<<endl;
}

void XyzEmployeeManager::printAllContractorEmployees()
{
    int sNumOfConttime = mContractorEmployeeCount;
    int sStartPos = mFulltimeEmployeeCount;
    printEmployeeSummaryByType(TYPE_CONTRACTOR,sStartPos,sStartPos+sNumOfConttime);
    cout<<"\n\n"<<endl;
}

void XyzEmployeeManager::printAllInternEmployees()
{
    int sNumOfIntern = mInterEmployeeCount;
    int sStartPos = mFulltimeEmployeeCount+mContractorEmployeeCount;
    printEmployeeSummaryByType(TYPE_INTERN,sStartPos,sStartPos+sNumOfIntern);
    cout<<"\n\n"<<endl;
}

void XyzEmployeeManager::removeFullTimeEmployeeByID(string empIDParam)
{
    int sNumOfFulltime = mFulltimeEmployeeCount;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = 0;itr < sNumOfFulltime; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            mFulltimeEmployeeCount--;
            break;
        }
    }
}

void XyzEmployeeManager::removeContractorEmployeeByID(string empIDParam)
{
    int sNumOfConttime = mContractorEmployeeCount;
    int sStartPos = mFulltimeEmployeeCount;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = sStartPos; itr < sStartPos+sNumOfConttime; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            mContractorEmployeeCount--;
            break;
        }
    }
}

void XyzEmployeeManager::removeInternEmployeeByID(string empIDParam)
{
    int sNumOfIntern = mInterEmployeeCount;
    int sStartPos = mFulltimeEmployeeCount+mContractorEmployeeCount;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = sStartPos; itr < sStartPos+sNumOfIntern; itr++)
    {
        string sEmpid = (*mEmployeeDequePtr)[itr]->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeDequePtr->removeElementAtPosition(itr);
            // @Todo: Need to add this employee to resigned employee Deque.
            delete sEmpPtr;
            mInterEmployeeCount--;
            break;
        }
    }
}

void XyzEmployeeManager::displayEmployeeDetails()
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

void XyzEmployeeManager::removeEmployee()
{
    int sEmpChoice = 0;
    string sEmpid;
    int sRet = 0;
    cout<<"Please select employee to remove \n1.Full-Time\n2.Contractor\n3.Intern"<<endl;
    cin>>sEmpChoice;

    if(cin.fail() || (sEmpChoice != 1 && sEmpChoice !=2 && sEmpChoice!=3))
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
        if((sEmpid.length() != 8) &&  sEmpid.substr(0,3) != "XYZ")
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

    printAllEmployeesSummary();
    return;
}

void XyzEmployeeManager::testEmployeeGeneration()
{
    srand(time(NULL));

    for(int i= 0;i<50;i++)
    {
        XyzEmployeeIF *sEmpPtr = NULL;
        ostringstream sOstringStreamObj;
        sOstringStreamObj<<setfill('0')<<setw(4)<<i;
        string sEmpName = sOstringStreamObj.str();
        string sEmpGender = i%2==0 ?"Male":"Female";
        string sEmpDOB = generateRandomDate(1970,2003);
        string sEmpDOJ = generateRandomDate(1990,2003);
        string sEmpDOL = "NA";
        EmpStatus sEmpStatus = i%2==0?STATUS_ACTIVE:STATUS_INACTIVE;

        if(i%3 == 0)
        {
            sEmpPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
            addNewContractorEmployee(sEmpPtr);
        }
        else if (i%3 == 1)
        {
            sEmpPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
            addNewFullTimeEmployee(sEmpPtr);
        }
        else
        {
            sEmpPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
            addNewInternEmployee(sEmpPtr);
        }
    }

    cout<<"\n\n"<<endl;    
}
