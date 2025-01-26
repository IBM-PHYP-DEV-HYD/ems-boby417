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

void XyzEmployeeManager::addNewEmployee(EmsUtility::EmpType empTypeParam, string sEmpName,string sEmpGender,string sEmpDOB,
            string sEmpDOJ,string sEmpDOL,EmsUtility::EmpStatus sEmpStatus,int sEmpNol,string sEmpAgency,string sEmpClg, string sEmpBranch)
{
    XyzEmployeeIF *sEmpIfPtr = NULL;
    if(empTypeParam == EmsUtility::TYPE_FULL)
    {
        sEmpIfPtr = new  XyzFullTimeEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
        sEmpIfPtr->setNoOfLeaves(sEmpNol);
    }
    else if (empTypeParam == EmsUtility::TYPE_CONTRACTOR)
    {
        sEmpIfPtr = new  XyzContractorEmployee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
        sEmpIfPtr->setAgency(sEmpAgency);
    }
    else
    {
        sEmpIfPtr = new  XyzInternEmloyee(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);
        sEmpIfPtr->setCollege(sEmpClg);
        sEmpIfPtr->setBranch(sEmpBranch);
    }
    mEmployeeEDLLPtr->pushBack(sEmpIfPtr);
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
        sEmpPtr->printAllResignedEmployees();
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

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        string sEmpid = sEmpIfPtr->getEmployeeId();
        if(sEmpid == empIDParam)
        {
            sEmpIfPtr = mEmployeeEDLLPtr->removeElementAtPosition(itr);
            sEmpIfPtr->setEmployeeStatus(EmsUtility::STATUS_RESIGNED);
            sEmpIfPtr->setEmployeeDOL(getDateStringFromChrono());
            XyzEmployee *sEmpPtr = new XyzEmployee(sEmpIfPtr);
            mResignedEmpEdllPtr->pushBack(static_cast<XyzEmployee*>(sEmpPtr));
            delete sEmpIfPtr;
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

void XyzEmployeeManager::convertToFullTime(string empIdParam)
{
    int sSizeofEDLL = mEmployeeEDLLPtr?mEmployeeEDLLPtr->size():0;
    Node<XyzEmployeeIF>* sFrontOfEDLL = mEmployeeEDLLPtr->getNodeAtPosition(0);

    for(int itr = 0;itr < sSizeofEDLL; itr++)
    {
        XyzEmployeeIF* sEmpIfPtr = sFrontOfEDLL->mDataPtr;
        string sEmpid = sEmpIfPtr->getEmployeeId();
        EmsUtility::EmpType sEmpType = sEmpIfPtr->getEmployeeType();
        if((sEmpType != EmsUtility::TYPE_FULL) && (sEmpid == empIdParam))
        {
            XyzFullTimeEmployee *sNewFullTime = new XyzFullTimeEmployee(sEmpIfPtr);
            sFrontOfEDLL->mDataPtr = sNewFullTime;
        }
        sFrontOfEDLL = sFrontOfEDLL->mNext;
    }
}