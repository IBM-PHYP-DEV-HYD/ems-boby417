#include "XyzInternEmployee.H"


XyzInternEmployee::XyzInternEmployee()
{
}

XyzInternEmployee::XyzInternEmployee(string idParam,
                                   string nameParam,
                                   string genderParam,
                                   string dobParam,
                                   string dojParam,
                                   string dolParam,
                                   EmsUtility::EmpStatus statusParam,
                                   string clgParam,
                                   string branchParam)
:XyzEmployee
(idParam
,nameParam
,genderParam
,dobParam
,dojParam
,dolParam
,statusParam
,EmsUtility::TYPE_INTERN)
,mEmpCollege(clgParam)
,mEmpBranch(branchParam)
{
}

XyzInternEmployee::~XyzInternEmployee()
{
}

void XyzInternEmployee::fillAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL =  "NA";
    emsRecordParam.mEmpAgency = "NA";
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
}

void XyzInternEmployee::fillEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
}

void XyzInternEmployee::fillEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    /* fill all the relevant data */
    XyzEmployee::fillEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpCollege = this->getCollege();
    emsRecordParam.mEmpBranch = this->getBranch();
}

void XyzInternEmployee::setCollege(string clgParam)
{
    mEmpCollege = clgParam;
}

void XyzInternEmployee::setBranch(string branchParam)
{
    mEmpBranch = branchParam;
}

string XyzInternEmployee::getCollege()
{
    return mEmpCollege;
}

string XyzInternEmployee::getBranch()
{
    return mEmpBranch;
}