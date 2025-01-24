#include "XyzInternEmloyee.H"

long XyzInternEmloyee::mNextEmproll = 0;

XyzInternEmloyee::XyzInternEmloyee()
{
    mNextEmproll++;
}

XyzInternEmloyee::XyzInternEmloyee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam):XyzEmployee(nameParam,genderParam,dobParam,dojParam,dolParam,statusParam)
{
    mNextEmproll++;
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"I";
    mEmpType = TYPE_INTERN;
}

XyzInternEmloyee::~XyzInternEmloyee()
{
}

void XyzInternEmloyee::printAllEmployeeDetails()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = true;
    mRecordObj.mEmpNOL =  "NA";
    mRecordObj.mEmpAgency = "NA";
    mRecordObj.mEmpCollege = this->getCollege();
    mRecordObj.mEmpBranch = this->getBranch();
    mRecordObj.printAll();
}

void XyzInternEmloyee::printEmployeeDetailsByType()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = false;
    mRecordObj.mEmpCollege = this->getCollege();
    mRecordObj.mEmpBranch = this->getBranch();
    mRecordObj.printAll();
}

void XyzInternEmloyee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    cout<<"\nIntern Employee Data:"<<endl;
    XyzEmployee::printEmployeeSpecificDetails();
    mRecordObj.mEmpCollege = this->getCollege();
    mRecordObj.mEmpBranch = this->getBranch();
    mRecordObj.printIntern();
}

void XyzInternEmloyee::setCollege(string clgParam)
{
    mEmpCollege = clgParam;
}

void XyzInternEmloyee::setBranch(string branchParam)
{
    mEmpBranch = branchParam;
}

string XyzInternEmloyee::getCollege()
{
    return mEmpCollege;
}

string XyzInternEmloyee::getBranch()
{
    return mEmpBranch;
}