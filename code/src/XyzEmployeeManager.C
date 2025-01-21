#include "XyzEmployeeManager.H"

XyzEmployeeManager::XyzEmployeeManager()
{
    mEmployeeEDLLPtr = NULL;
}

void XyzEmployeeManager::initializeEmployeeDeque()
{
    if(mEmployeeEDLLPtr == NULL)
    {
        mEmployeeEDLLPtr = new EDLL<XyzEmployeeIF>();
    }
}

void XyzEmployeeManager::initializeResignedEmployeeDeque()
{
    if(mResignedEmpEdllPtr == NULL)
    {
        mResignedEmpEdllPtr = new EDLL<XyzEmployeeIF>();
    }
}

template<typename TN>
static TN* createCommonEmployee(EmpType empTypeParam)
{
    string sEmpName;
    cout<<"Please enter employee name : "<<endl;
    cin>>sEmpName;
    
    string sEmpGender       = getEmployeeGenderInRandom();
    int sRandomYear         = getRandomNumber(1970,2003);
    string sEmpDOB          = generateRandomDate(sRandomYear);
    sRandomYear             = getRandomNumber(sRandomYear+21,2024);
    string sEmpDOJ          = generateRandomDate(sRandomYear);
    string sEmpDOL          = "NA";
    EmpStatus sEmpStatus    = getEmployeeStatusInRandom();
   
    TN *sEmpPtr = new  TN(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
    if(empTypeParam == TYPE_CONTRACTOR)
    {
        string sEmpAgency = getContractorAgencyFromEnum(static_cast<EmpContractorAgency>(getRandomNumber(1,3)));
        sEmpPtr->setAgency(sEmpAgency);
    }
    else if (empTypeParam == TYPE_FULL)
    {
        int sEmpNol = getRandomNumber(10,24);
        sEmpPtr->setNoOfLeaves(sEmpNol);
    }
    else
    {
        string sClg = getInternCollegeAgencyFromEnum(static_cast<InterEmpCollege>(getRandomNumber(1,3)));
        sEmpPtr->setCollege(sClg);
        string sBranch = getInternBranchFromEnum(static_cast<InterEmpBranch>(getRandomNumber(1,3)));
        sEmpPtr->setBranch(sBranch);
    }
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
    mEmployeeEDLLPtr->pushBack(sEmpPtr);
}

void printHeader(EmpType empTypeParam = TYPE_NONE,EmpStatus empStatusParam=STATUS_NONE)
{
    cout<<"\n\n"<<endl;
    int sSum = 0;
    /* Print the Header */
    printElement("Employee Name",MAX_NAME_LEN);
    sSum += MAX_NAME_LEN;
    printElement("ID",MAX_ID_LEN+7);
    sSum += MAX_ID_LEN+7;
    printElement("Type",MAX_EQ_LEN);
    printElement("Status",MAX_EQ_LEN);
    printElement("Gender",MAX_EQ_LEN);
    printElement("Date of birth",MAX_EQ_LEN);
    printElement("Date of joining",MAX_EQ_LEN);
    printElement("Date of Leaving",MAX_EQ_LEN);
    sSum += (6*MAX_EQ_LEN);
    if(empStatusParam != STATUS_RESIGNED)
    {
        if(empTypeParam != TYPE_NONE)
        {
            if(empTypeParam == TYPE_FULL)
            {
                
                printElement("Number of Leaves",MAX_ID_LEN+7);
                sSum += MAX_ID_LEN+7;
            }
            else if(empTypeParam == TYPE_CONTRACTOR)
            {
                printElement("Agency",MAX_EQ_LEN);
                sSum += MAX_EQ_LEN;
            }
            else
            {
                printElement("College",MAX_EQ_LEN);
                printElement("Branch",MAX_EQ_LEN);
                sSum += (2*MAX_EQ_LEN);
            }
            cout<<endl;
            cout << left << setw(sSum) << setfill('-') <<"-";
            
        }
        else
        {
            printElement("No of Leaves",MAX_ID_LEN+7);
            sSum += MAX_ID_LEN+7;
            printElement("Agency",MAX_EQ_LEN);
            printElement("College",MAX_EQ_LEN);
            printElement("Branch",MAX_EQ_LEN);
            sSum += (3*MAX_EQ_LEN);
            cout<<endl;
            cout << left << setw(sSum) << setfill('-') <<"-";
        }
    }
    else
    {
        cout<<endl;
        cout << left << setw(sSum) << setfill('-') <<"-";
    }
    cout<<endl;
   
}

void XyzEmployeeManager::printResignedEmpSummary()
{
    int sSizeofEDLL = mResignedEmpEdllPtr ? mResignedEmpEdllPtr->size() : 0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mResignedEmpEdllPtr ? mResignedEmpEdllPtr->getNodeAtPosition(0) : NULL;
    printHeader(TYPE_NONE,STATUS_RESIGNED);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        XyzEmployee *sEmpPtr = static_cast<XyzEmployee*>(sEmpIfPtr);
        sEmpPtr->printAllEmployeeDetails();
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::printEmployeeSummaryByType(EmpType empTypeParam)
{
   
    int sSizeofEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->size() : 0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0): NULL;

    printHeader(empTypeParam);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        if(empTypeParam == TYPE_NONE)
        {
            
            sEmpIfPtr->printAllEmployeeDetails();
        }
        else
        {
            EmpType sEmpType = sEmpIfPtr->getEmployeeType();
            if(empTypeParam == sEmpType)
            {
                sEmpIfPtr->printEmployeeDetailsByType();
            }
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::printEmployeeSummaryByGender(int empGenderParam)
{
   
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) :  NULL;

    printHeader();

    string sEmpGenderString = getEmployeeGenderFromEnum(empGenderParam);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        string sEmpGender = sEmpIfPtr->getEmployeeGender();
        if(sEmpGenderString == sEmpGender)
        {
            sEmpIfPtr->printAllEmployeeDetails();
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::printEmployeeSummaryByStatus(EmpStatus empStatusParam)
{
   
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) : NULL;

    printHeader();

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        EmpStatus sEmpStatus = sEmpIfPtr->getEmployeeStatus();
        if(sEmpStatus == empStatusParam)
        {
            sEmpIfPtr->printAllEmployeeDetails();
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::removeEmployeeByID(string empIDParam)
{
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) : NULL;
    XyzEmployeeIF *sEmpPtr = NULL;
    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        string sEmpid = sEmpIfPtr->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpPtr = mEmployeeEDLLPtr->removeElementAtPosition(itr);
            initializeResignedEmployeeDeque();
            sEmpPtr->setEmployeeStatus(STATUS_RESIGNED);
            mResignedEmpEdllPtr->pushBack(sEmpPtr);
            break;
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::printEmployeeDetailsById(string sEmpidParam)
{
    int sSizeofDeque = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) : NULL;
    bool empIDFound = false;

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        if(sEmpIfPtr->getEmployeeId() == sEmpidParam)
        {
            sEmpIfPtr->printEmployeeSpecificDetails();
            cout<<endl;
            empIDFound = true;
            break;
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
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
                string sEmpAgency = getContractorAgencyFromEnum(static_cast<EmpContractorAgency>(getRandomNumber(1,3)));
                sEmpPtr->setAgency(sEmpAgency);
                addNewEmployee(sEmpPtr);
            }
            else if (sEmpType == TYPE_FULL)
            {
                sEmpPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                int sEmpNol = getRandomNumber(10,24);
                sEmpPtr->setNoOfLeaves(sEmpNol);
                addNewEmployee(sEmpPtr);
            }
            else
            {
                sEmpPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sClg = getInternCollegeAgencyFromEnum(static_cast<InterEmpCollege>(getRandomNumber(1,3)));
                sEmpPtr->setCollege(sClg);
                string sBranch = getInternBranchFromEnum(static_cast<InterEmpBranch>(getRandomNumber(1,3)));
                sEmpPtr->setBranch(sBranch);
                addNewEmployee(sEmpPtr);
            }
        }
        else
        {
            if(typeParam == TYPE_CONTRACTOR)
            {
                sEmpPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sEmpAgency = getContractorAgencyFromEnum(static_cast<EmpContractorAgency>(getRandomNumber(1,3)));
                sEmpPtr->setAgency(sEmpAgency);
                addNewEmployee(sEmpPtr);
            }
            else if (typeParam == TYPE_FULL)
            {
                sEmpPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                int sEmpNol = getRandomNumber(10,24);
                sEmpPtr->setNoOfLeaves(sEmpNol);
                addNewEmployee(sEmpPtr);
            }
            else
            {
                sEmpPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sClg = getInternCollegeAgencyFromEnum(static_cast<InterEmpCollege>(getRandomNumber(1,3)));
                sEmpPtr->setCollege(sClg);
                string sBranch = getInternBranchFromEnum(static_cast<InterEmpBranch>(getRandomNumber(1,3)));
                sEmpPtr->setBranch(sBranch);
                addNewEmployee(sEmpPtr);
            }
        } 
    }
    
    cout<<"\n\n"<<endl;    
}

void XyzEmployeeManager::convertToFullTime(EmpType empTypeParam, string empIdParam)
{
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr->getNodeAtPosition(0);
    if(empTypeParam != TYPE_FULL)
    {
        for(int itr = 0;itr < sSizeofEDLL; itr++)
        {
            XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
            string sEmpid = sEmpIfPtr->getEmployeeId();
            EmpType sEmpType = sEmpIfPtr->getEmployeeType();
            if((sEmpType == empTypeParam) && (sEmpid == empIdParam))
            {
                XyzFullTimeEmployee *sNewFullTime = new XyzFullTimeEmployee(sEmpIfPtr);
                sFrontOfEDLL->mDataPtr = sNewFullTime;
            }
            sFrontOfEDLL = sFrontOfEDLL->mNext;
        }
    }
}