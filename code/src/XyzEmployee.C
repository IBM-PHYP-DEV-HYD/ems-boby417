#include "XyzEmployee.H"

XyzEmployee::XyzEmployee()
{
    
}

XyzEmployee::XyzEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus empStatusParam)
{
    mEmpName   = nameParam;
    mEmpGender = genderParam;
    mEmpDOB    = dobParam;
    mEmpDOJ    = dojParam;
    mEmpDOL    = dolParam;
    mEmpStatus = empStatusParam;
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

EmpType XyzEmployee::getEmployeeType()
{
    return mEmpType;
}

void XyzEmployee::setEmployeeType(EmpType empTypeParam)
{
    mEmpType = empTypeParam;
}

EmpStatus XyzEmployee::getEmployeeStatus()
{
    return mEmpStatus;
}

void XyzEmployee::setEmployeeStatus(EmpStatus empStatusParam)
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

void XyzEmployee::setNoOfLeaves(int nolParam) {}

int XyzEmployee::getNoOfLeaves() {return 0; }

void XyzEmployee::setAgency(string agencyParam) {}

string XyzEmployee::getAgency() {return " "; }

void XyzEmployee::setCollege(string clgParam) {}

void XyzEmployee::setBranch(string branchParam) {}

string XyzEmployee::getCollege() { return " "; }

string XyzEmployee::getBranch() { return " "; }
