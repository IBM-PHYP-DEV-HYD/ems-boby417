#include "XyzEmployee.H"

XyzEmployee::XyzEmployee()
{
    
}

XyzEmployee::XyzEmployee(string idParam,string nameParam,
                        string genderParam,string dobParam,
                        string dojParam,string dolParam,
                        EmsUtility::EmpStatus empStatusParam,
                        EmsUtility::EmpType empTypeParam):
                        mEmpName (nameParam),
                        mEmpid (idParam),
                        mEmpGender (genderParam),
                        mEmpDOB (dobParam),
                        mEmpType (empTypeParam),
                        mEmpStatus (empStatusParam),
                        mEmpDOJ (dojParam),
                        mEmpDOL (dolParam)
{
}

XyzEmployee::XyzEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam)
{
    mEmpName    = xyzEmployeeIfPtrParam->getEmployeeName();
    mEmpid      = xyzEmployeeIfPtrParam->getEmployeeId()  ;
    mEmpGender  = xyzEmployeeIfPtrParam->getEmployeeGender();
    mEmpDOB     = xyzEmployeeIfPtrParam->getEmployeeDOB();
    mEmpDOJ     = xyzEmployeeIfPtrParam->getEmployeeDOJ();
    mEmpDOL     = xyzEmployeeIfPtrParam->getEmployeeDOL();
    mEmpStatus  = xyzEmployeeIfPtrParam->getEmployeeStatus();
    mEmpType    = EmsUtility::TYPE_NONE;
}

string XyzEmployee::getEmployeeName()
{
    return mEmpName;
}

string XyzEmployee::getEmployeeGender()
{
    return mEmpGender;
}

string XyzEmployee::getEmployeeDOB()
{
    return mEmpDOB;
}

EmsUtility::EmpType XyzEmployee::getEmployeeType()
{
    return mEmpType;
}

void XyzEmployee::setEmployeeType(EmsUtility::EmpType empTypeParam)
{
    mEmpType = empTypeParam;
}

EmsUtility::EmpStatus XyzEmployee::getEmployeeStatus()
{
    return mEmpStatus;
}

void XyzEmployee::setEmployeeStatus(EmsUtility::EmpStatus empStatusParam)
{
    mEmpStatus = empStatusParam;
}

string XyzEmployee::getEmployeeDOJ()
{
    return mEmpDOJ;
}

void XyzEmployee::setEmployeeDOJ(string joiningDateParam)
{
    mEmpDOJ = joiningDateParam;
}

string XyzEmployee::getEmployeeDOL()
{
    return mEmpDOL;
}
void XyzEmployee::setEmployeeDOL(string leaveDateParam)
{
    mEmpDOL = leaveDateParam;
}

string XyzEmployee::getEmployeeId()
{ 
    return mEmpid;
}

void XyzEmployee::printAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    
    emsRecordParam.mEmpName     = this->getEmployeeName();
    emsRecordParam.mEmpid       = this->getEmployeeId();
    emsRecordParam.mEmpType     = this->getEmployeeType();
    emsRecordParam.mEmpStatus   = this->getEmployeeStatus();
    emsRecordParam.mEmpGender   = this->getEmployeeGender();
    emsRecordParam.mEmpDOB      = this->getEmployeeDOB();
    emsRecordParam.mEmpDOJ      = this->getEmployeeDOJ();
    emsRecordParam.mEmpDOL      = this->getEmployeeDOL();
    emsRecordParam.printAllCommon();
}

void XyzEmployee::printAllResignedEmployees(EmsRecord& emsRecordParam)
{
    emsRecordParam.mEmpName     = this->getEmployeeName();
    emsRecordParam.mEmpid       = this->getEmployeeId();
    emsRecordParam.mEmpType     = this->getEmployeeType();
    emsRecordParam.mEmpStatus   = this->getEmployeeStatus();
    emsRecordParam.mEmpGender   = this->getEmployeeGender();
    emsRecordParam.mEmpDOB      = this->getEmployeeDOB();
    emsRecordParam.mEmpDOJ      = this->getEmployeeDOJ();
    emsRecordParam.mEmpDOL      = this->getEmployeeDOL();
    emsRecordParam.printAllCommon();
    cout<<endl;
}

void XyzEmployee::printEmployeeDetailsByType(EmsRecord& recordParam)
{

}

void XyzEmployee::printEmployeeSpecificDetails(EmsRecord& recordParam)
{ 
    /* Print all the relevant data */
    cout<<"\n\nContractor Employee Data:"<<endl;
    recordParam.mEmpName = this->getEmployeeName();
    recordParam.mEmpid = this->getEmployeeId();
    recordParam.mEmpType = this->getEmployeeType();
    recordParam.mEmpStatus = this->getEmployeeStatus();
    recordParam.mEmpGender = this->getEmployeeGender();
    recordParam.mEmpDOB = this->getEmployeeDOB();
    recordParam.mEmpDOJ = this->getEmployeeDOJ();
    recordParam.mEmpDOL = this->getEmployeeDOL();
}

void XyzEmployee::setNoOfLeaves(int nolParam) {}

int XyzEmployee::getNoOfLeaves() {return 0; }

void XyzEmployee::setAgency(string agencyParam) {}

string XyzEmployee::getAgency() {return " "; }

void XyzEmployee::setCollege(string clgParam) {}

void XyzEmployee::setBranch(string branchParam) {}

string XyzEmployee::getCollege() { return " "; }

string XyzEmployee::getBranch() { return " "; }
