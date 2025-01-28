#include "XyzInternEmloyee.H"


XyzInternEmloyee::XyzInternEmloyee()
{
}

XyzInternEmloyee::XyzInternEmloyee(string idParam, string nameParam,
                    string genderParam,string dobParam,
                    string dojParam,string dolParam,
                    EmsUtility::EmpStatus statusParam,
                    string clgParam, string branchParam)
                    :XyzEmployee(
                    idParam,
                    nameParam,
                    genderParam,
                    dobParam,
                    dojParam,
                    dolParam,
                    statusParam,
                    EmsUtility::TYPE_INTERN),
                    mEmpCollege(clgParam),
                    mEmpBranch(branchParam)
{
}

XyzInternEmloyee::~XyzInternEmloyee()
{
}

void XyzInternEmloyee::printAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL =  "NA";
    emsRecordParam.mEmpAgency = "NA";
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
    emsRecordParam.printAll();
}

void XyzInternEmloyee::printEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
    emsRecordParam.printAll();
}

void XyzInternEmloyee::printEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    /* Print all the relevant data */
    cout<<"\nIntern Employee Data:"<<endl;
    XyzEmployee::printEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
    emsRecordParam.printIntern();
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