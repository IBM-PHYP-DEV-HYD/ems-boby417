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

void XyzEmployee::printAllEmployeeDetails()
{
    printElement(this->getEmployeeName(),25);
    printElement(this->getEmployeeId(),15);
    printElement(getEmploymentTypeFromEnum(this->getEmployeeType()),20);
    printElement(getEmploymentStatusFromEnum(this->getEmployeeStatus()),20);
    printElement(this->getEmployeeGender(),20);
    printElement(this->getEmployeeDOB(),20);
    printElement(this->getEmployeeDOJ(),20);
    printElement(this->getEmployeeDOL(),20);
}

void XyzEmployee::printEmployeeDetailsByType()
{

}

void XyzEmployee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    cout<<"\n\nContractor Employee Data:"<<endl;
    printElementIndividual("Employee Name:",this->mEmpName,20);
    printElementIndividual("Id:",this->mEmpid,20);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(this->mEmpType),20);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(this->mEmpStatus),20);
    printElementIndividual("Gender:",this->mEmpGender,20);
    printElementIndividual("DOB:",this->mEmpDOB,20);
    printElementIndividual("DOJ:",this->mEmpDOJ,20);
    printElementIndividual("DOL:",this->mEmpDOL,20);
}

void XyzEmployee::setNoOfLeaves(int nolParam) {}

int XyzEmployee::getNoOfLeaves() {return 0; }

void XyzEmployee::setAgency(string agencyParam) {}

string XyzEmployee::getAgency() {return " "; }

void XyzEmployee::setCollege(string clgParam) {}

void XyzEmployee::setBranch(string branchParam) {}

string XyzEmployee::getCollege() { return " "; }

string XyzEmployee::getBranch() { return " "; }
