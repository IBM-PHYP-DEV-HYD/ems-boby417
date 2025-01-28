#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee()
{
}

XyzFullTimeEmployee::XyzFullTimeEmployee(string idParam,string nameParam,
                                        string genderParam,string dobParam,
                                        string dojParam,string dolParam,
                                        EmsUtility::EmpStatus statusParam,int nolParam)
                                        :XyzEmployee
                                        (idParam,
                                        nameParam,
                                        genderParam,
                                        dobParam,
                                        dojParam,
                                        dolParam,
                                        statusParam,
                                        EmsUtility::TYPE_FULL),
                                        mEmpNOL(nolParam)
{
}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam)
{
    mEmpid      = xyzEmployeeIfPtrParam->getEmployeeId();
    mEmpName    = xyzEmployeeIfPtrParam->getEmployeeName();
    mEmpGender  = xyzEmployeeIfPtrParam->getEmployeeGender();
    mEmpDOB     = xyzEmployeeIfPtrParam->getEmployeeDOB();
    mEmpDOJ     = xyzEmployeeIfPtrParam->getEmployeeDOJ();
    mEmpDOL     = "NA";
    mEmpStatus  = xyzEmployeeIfPtrParam->getEmployeeStatus();
    mEmpType    = EmsUtility::TYPE_FULL;
    mEmpNOL     = getRandomNumber(10,24);
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
}

void XyzFullTimeEmployee::printAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
    emsRecordParam.mEmpAgency = "NA";
    emsRecordParam.mEmpCollege = "NA";
    emsRecordParam.mEmpBranch = "NA";
    emsRecordParam.printAll();
}

void XyzFullTimeEmployee::printEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
    emsRecordParam.printAll();
}


void XyzFullTimeEmployee::printEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    /* Print all the relevant data */
    XyzEmployee::printEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
    emsRecordParam.printFullTime();
}

void XyzFullTimeEmployee::setNoOfLeaves(int nolParam)
{
    mEmpNOL = nolParam;
}

int XyzFullTimeEmployee::getNoOfLeaves()
{
    return mEmpNOL;
}