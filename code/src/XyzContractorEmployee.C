#include "XyzContractorEmployee.H"

long XyzContractorEmployee::mNextEmproll = 0;

XyzContractorEmployee::XyzContractorEmployee()
{
    mNextEmproll++;
}

XyzContractorEmployee::XyzContractorEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmsUtility::EmpStatus statusParam):XyzEmployee(nameParam,genderParam,dobParam,dojParam,dolParam,statusParam)
{
    mNextEmproll++;
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"C";
    mEmpType = EmsUtility::TYPE_CONTRACTOR;
}

XyzContractorEmployee::~XyzContractorEmployee()
{
}

void XyzContractorEmployee::printAllEmployeeDetails()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = true;
    mRecordObj.mEmpNOL = "NA";
    mRecordObj.mEmpAgency = this->getAgency();
    mRecordObj.mEmpCollege = "NA";
    mRecordObj.mEmpBranch = "NA";
    mRecordObj.printAll();
}

void XyzContractorEmployee::printEmployeeDetailsByType()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = false;
    mRecordObj.mEmpAgency = this->getAgency();
    mRecordObj.printAll();
}

void XyzContractorEmployee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    cout<<"\n\nContractor Employee Data:"<<endl;
    XyzEmployee::printEmployeeSpecificDetails();
    mRecordObj.mEmpAgency = this->getAgency();
    mRecordObj.printContractor();
}

void XyzContractorEmployee::setAgency(string agencyParam)
{
    mEmpAgency = agencyParam;
}
string XyzContractorEmployee::getAgency()
{
    return mEmpAgency;
}