#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee()
{
}

XyzFullTimeEmployee::XyzFullTimeEmployee(string idParam,
                                        string nameParam,
                                        string genderParam,
                                        string dobParam,
                                        string dojParam,
                                        string dolParam,
                                        EmsUtility::EmpStatus statusParam,
                                        int nolParam)
:XyzEmployee
(idParam
,nameParam
,genderParam
,dobParam
,dojParam
,dolParam
,statusParam
,EmsUtility::TYPE_FULL)
,mEmpNOL(nolParam)
{
}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam)
{
    int sEmpIdRandNum = getRandomNumber(0,MAX_EMPID);
    if(xyzEmployeeIfPtrParam != NULL)
    {
        mEmpid      = "XYZ"+toString(sEmpIdRandNum,4)+"F";
        mEmpName    = xyzEmployeeIfPtrParam->getEmployeeName();
        mEmpGender  = xyzEmployeeIfPtrParam->getEmployeeGender();
        mEmpDOB     = xyzEmployeeIfPtrParam->getEmployeeDOB();
        mEmpDOJ     = xyzEmployeeIfPtrParam->getEmployeeDOJ();
        mEmpDOL     = "NA";
        mEmpStatus  = xyzEmployeeIfPtrParam->getEmployeeStatus();
        mEmpType    = EmsUtility::TYPE_FULL;
        mEmpNOL     = getRandomNumber(10,24);
    }
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
}

void XyzFullTimeEmployee::fillAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
    emsRecordParam.mEmpAgency = "NA";
    emsRecordParam.mEmpCollege = "NA";
    emsRecordParam.mEmpBranch = "NA";
}

void XyzFullTimeEmployee::fillEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
}


void XyzFullTimeEmployee::fillEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    XyzEmployee::fillEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpNOL = to_string(this->getNoOfLeaves());
}

void XyzFullTimeEmployee::setNoOfLeaves(int nolParam)
{
    mEmpNOL = nolParam;
}

int XyzFullTimeEmployee::getNoOfLeaves()
{
    return mEmpNOL;
}