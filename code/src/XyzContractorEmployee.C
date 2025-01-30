#include "XyzContractorEmployee.H"

XyzContractorEmployee::XyzContractorEmployee()
{
}

 XyzContractorEmployee::XyzContractorEmployee(string idParam,
                                              string nameParam,
                                              string genderParam,
                                              string dobParam,
                                              string dojParam,string dolParam,
                                              EmsUtility::EmpStatus statusParam,
                                              string agencyParam)
:XyzEmployee
(idParam
,nameParam
,genderParam
,dobParam
,dojParam
,dolParam
,statusParam
,EmsUtility::TYPE_CONTRACTOR)
,mEmpAgency(agencyParam)
{
}

XyzContractorEmployee::~XyzContractorEmployee()
{
}

void XyzContractorEmployee::fillAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL = "NA";
    emsRecordParam.mEmpAgency = this->getAgency();
    emsRecordParam.mEmpCollege = "NA";
    emsRecordParam.mEmpBranch = "NA";
}

void XyzContractorEmployee::fillEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::fillAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpAgency = this->getAgency();
}

void XyzContractorEmployee::fillEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    /* filll all the relevant data */
    XyzEmployee::fillEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpAgency = this->getAgency();
}

void XyzContractorEmployee::setAgency(string agencyParam)
{
    mEmpAgency = agencyParam;
}
string XyzContractorEmployee::getAgency()
{
    return mEmpAgency;
}