#include "XyzEmployeeManager.H"

XyzEmployeeManager::XyzEmployeeManager()
{
    mEmployeeEDLLPtr    = new EDLL<XyzEmployeeIF>();
    mResignedEmpEdllPtr = new EDLL<XyzEmployeeIF>();
}

XyzEmployeeManager::~XyzEmployeeManager()
{
    delete mEmployeeEDLLPtr;
    mEmployeeEDLLPtr = NULL;
    delete mResignedEmpEdllPtr;
    mResignedEmpEdllPtr = NULL;
}

void XyzEmployeeManager::addNewEmployee(XyzEmployeeIF *empPtrParam)
{
    mEmployeeEDLLPtr->pushBack(empPtrParam);
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

void XyzEmployeeManager::addNumberofLeavesToFullTimeEmployee(string sEmpidParam,int nolParam)
{
    int sSizeofDeque = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) : NULL;
    bool empIDFound = false;

    for(int itr = 0;itr < sSizeofDeque; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        if(sEmpIfPtr->getEmployeeId() == sEmpidParam)
        {
            if(sEmpIfPtr->getEmployeeType() != TYPE_FULL)
            {
                cout<<"Invalid employee TYPE"<<endl;
                break;
            }
            int sNol = sEmpIfPtr->getNoOfLeaves();
            sNol += nolParam;
            sEmpIfPtr->setNoOfLeaves(sNol);
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
    XyzEmployeeIF *sEmpIfPtr  = NULL;
    if(isRandom == true)
    {
        for(int itr= 0;itr<numofEmpParam;itr++)
        {
            sEmpIfPtr  = NULL;
            int sNameRandomIndex    = getRandomNumber(0,29);
            string sEmpName         = getEmployeeNameInRandom(sNameRandomIndex);
            string sEmpGender       = getEmployeeGenderFromEnum((sNameRandomIndex%2)+1);
            int sRandomYear         = getRandomNumber(1970,2003);
            string sEmpDOB          = generateRandomDate(sRandomYear);
            sRandomYear             = getRandomNumber(sRandomYear+21,2024);
            string sEmpDOJ          = generateRandomDate(sRandomYear);
            string sEmpDOL          = "NA";
            EmpStatus sEmpStatus    = getEmployeeStatusInRandom();
            int sEmpType            = getRandomNumber(1,3);
            if(sEmpType == TYPE_CONTRACTOR)
            {
                sEmpIfPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sEmpAgency = getContractorAgencyFromEnum(static_cast<EmpContractorAgency>(getRandomNumber(1,3)));
                sEmpIfPtr->setAgency(sEmpAgency);
                sEmpDOL     = addMonths(sEmpDOJ,12);
                sEmpIfPtr->setEmployeeDOL(sEmpDOL);
                addNewEmployee(sEmpIfPtr);
            }
            else if (sEmpType == TYPE_FULL)
            {
                sEmpIfPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                int sEmpNol = getRandomNumber(10,24);
                sEmpIfPtr->setNoOfLeaves(sEmpNol);
                addNewEmployee(sEmpIfPtr);
            }
            else
            {
                sEmpIfPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sClg = getInternCollegeAgencyFromEnum(static_cast<InterEmpCollege>(getRandomNumber(1,3)));
                sEmpIfPtr->setCollege(sClg);
                string sBranch = getInternBranchFromEnum(static_cast<InterEmpBranch>(getRandomNumber(1,3)));
                sEmpIfPtr->setBranch(sBranch);
                sEmpDOL     = addMonths(sEmpDOJ,6);
                sEmpIfPtr->setEmployeeDOL(sEmpDOL);
                addNewEmployee(sEmpIfPtr);
            }
        }
    }
    else
    {
        if(typeParam == TYPE_CONTRACTOR)
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzContractorEmployee>(TYPE_CONTRACTOR);
            addNewEmployee(sEmpIfPtr);
        }
        else if (typeParam == TYPE_FULL)
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzFullTimeEmployee>(TYPE_FULL);
            addNewEmployee(sEmpIfPtr);
        }
        else
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzInternEmloyee>(TYPE_INTERN);
            addNewEmployee(sEmpIfPtr);
        }
    }  
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