#include "XyzFullTimeEmployee.H"

long XyzFullTimeEmployee::mNextEmproll = 0;

XyzFullTimeEmployee::XyzFullTimeEmployee()
{
    mNextEmproll++;
}

XyzFullTimeEmployee::XyzFullTimeEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmsUtility::EmpStatus statusParam):XyzEmployee(nameParam,genderParam,dobParam,dojParam,dolParam,statusParam)
{
    mNextEmproll++;
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"F";
    mEmpType = EmsUtility::TYPE_FULL;
}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam)
{
    mNextEmproll++;
    mEmpName    = xyzEmployeeIfPtrParam->getEmployeeName();
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"F";
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

void XyzFullTimeEmployee::printAllEmployeeDetails()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = true;
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.mEmpAgency = "NA";
    mRecordObj.mEmpCollege = "NA";
    mRecordObj.mEmpBranch = "NA";
    mRecordObj.printAll();
}

void XyzFullTimeEmployee::printEmployeeDetailsByType()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = false;
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.printAll();
}


void XyzFullTimeEmployee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    XyzEmployee::printEmployeeSpecificDetails();
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.printFullTime();
}

void XyzFullTimeEmployee::setNoOfLeaves(int nolParam)
{
    mEmpNOL = nolParam;
}

int XyzFullTimeEmployee::getNoOfLeaves()
{
    return mEmpNOL;
}