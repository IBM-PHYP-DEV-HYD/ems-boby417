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
    printHeader(EmsUtility::TYPE_NONE,EmsUtility::STATUS_RESIGNED);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        XyzEmployee *sEmpPtr = static_cast<XyzEmployee*>(sEmpIfPtr);
        sEmpPtr->printAllEmployeeDetails();
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}

void XyzEmployeeManager::printEmployeeSummaryByType(EmsUtility::EmpType empTypeParam)
{
   
    int sSizeofEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->size() : 0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0): NULL;

    printHeader(empTypeParam);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        if(empTypeParam == EmsUtility::TYPE_NONE)
        {
            
            sEmpIfPtr->printAllEmployeeDetails();
        }
        else
        {
            EmsUtility::EmpType sEmpType = sEmpIfPtr->getEmployeeType();
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

void XyzEmployeeManager::printEmployeeSummaryByStatus(EmsUtility::EmpStatus empStatusParam)
{
   
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr ? mEmployeeEDLLPtr->getNodeAtPosition(0) : NULL;

    printHeader();

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        EmsUtility::EmpStatus sEmpStatus = sEmpIfPtr->getEmployeeStatus();
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
            sEmpPtr->setEmployeeStatus(EmsUtility::STATUS_RESIGNED);
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
            if(sEmpIfPtr->getEmployeeType() != EmsUtility::TYPE_FULL)
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

void XyzEmployeeManager::addEmployee(int numofEmpParam,bool isRandom, EmsUtility::EmpType typeParam)
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
            int sEmpType            = getRandomNumber(EmsUtility::TYPE_FULL,EmsUtility::TYPE_INTERN);
            if(sEmpType == EmsUtility::TYPE_CONTRACTOR)
            {
                int sRandomYear         = getRandomNumber(EmsUtility::MIN_DOB_YEAR,EmsUtility::MAX_DOB_YEAR);
                string sEmpDOB          = generateRandomDate(sRandomYear);
                sRandomYear             = getRandomNumber(sRandomYear+MIN_AGE_REQUIRED_TO_DO_JOB,CURR_YEAR);
                string sEmpDOJ          = generateRandomDate(sRandomYear);
                string sEmpDOL          = "NA";
                EmsUtility::EmpStatus sEmpStatus    = getEmployeeStatusInRandom();
                sEmpIfPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sEmpAgency = getContractorAgencyFromEnum(static_cast<EmsUtility::EmpContractorAgency>(getRandomNumber(1,3)));
                sEmpIfPtr->setAgency(sEmpAgency);
                sEmpDOL     = addMonths(sEmpDOJ,12);
                sEmpIfPtr->setEmployeeDOL(sEmpDOL);
                addNewEmployee(sEmpIfPtr);
            }
            else if (sEmpType == EmsUtility::TYPE_FULL)
            {
                int sRandomYear         = getRandomNumber(EmsUtility::MIN_DOB_YEAR,EmsUtility::MAX_DOB_YEAR);
                string sEmpDOB          = generateRandomDate(sRandomYear);
                sRandomYear             = getRandomNumber(sRandomYear+MIN_AGE_REQUIRED_TO_DO_JOB,CURR_YEAR);
                string sEmpDOJ          = generateRandomDate(sRandomYear);
                string sEmpDOL          = "NA";
                EmsUtility::EmpStatus sEmpStatus    = getEmployeeStatusInRandom();
                sEmpIfPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                int sEmpNol = getRandomNumber(10,24);
                sEmpIfPtr->setNoOfLeaves(sEmpNol);
                addNewEmployee(sEmpIfPtr);
            }
            else
            {
                int sRandomYear         = getRandomNumber(EmsUtility::MIN_DOB_YEAR_FOR_INTERN,EmsUtility::MAX_DOB_YEAR_FOR_INTERN);
                string sEmpDOB          = generateRandomDate(sRandomYear);
                string sEmpDOJ          = generateRandomDate(CURR_YEAR);
                string sEmpDOL          = "NA";
                EmsUtility::EmpStatus sEmpStatus    = EmsUtility::STATUS_ACTIVE;
                sEmpIfPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
                string sClg = getInternCollegeAgencyFromEnum(static_cast<EmsUtility::InterEmpCollege>(getRandomNumber(1,3)));
                sEmpIfPtr->setCollege(sClg);
                string sBranch = getInternBranchFromEnum(static_cast<EmsUtility::InternEmpBranch>(getRandomNumber(1,3)));
                sEmpIfPtr->setBranch(sBranch);
                sEmpDOL     = addMonths(sEmpDOJ,6);
                sEmpIfPtr->setEmployeeDOL(sEmpDOL);
                addNewEmployee(sEmpIfPtr);
            }
        }
    }
    else
    {
        if(typeParam == EmsUtility::TYPE_CONTRACTOR)
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzContractorEmployee>(EmsUtility::TYPE_CONTRACTOR);
            addNewEmployee(sEmpIfPtr);
        }
        else if (typeParam == EmsUtility::TYPE_FULL)
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzFullTimeEmployee>(EmsUtility::TYPE_FULL);
            addNewEmployee(sEmpIfPtr);
        }
        else
        {
            sEmpIfPtr = createAnEmployeeOnInputs<XyzInternEmloyee>(EmsUtility::TYPE_INTERN);
            addNewEmployee(sEmpIfPtr);
        }
    }  
}

void XyzEmployeeManager::convertToFullTime(EmsUtility::EmpType empTypeParam, string empIdParam)
{
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr->getNodeAtPosition(0);
    if(empTypeParam != EmsUtility::TYPE_FULL)
    {
        for(int itr = 0;itr < sSizeofEDLL; itr++)
        {
            XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
            string sEmpid = sEmpIfPtr->getEmployeeId();
            EmsUtility::EmpType sEmpType = sEmpIfPtr->getEmployeeType();
            if((sEmpType == empTypeParam) && (sEmpid == empIdParam))
            {
                XyzFullTimeEmployee *sNewFullTime = new XyzFullTimeEmployee(sEmpIfPtr);
                sFrontOfEDLL->mDataPtr = sNewFullTime;
            }
            sFrontOfEDLL = sFrontOfEDLL->mNext;
        }
    }
}