#include "XyzContractorEmployee.H"

XyzContractorEmployee::XyzContractorEmployee()
{
}

 XyzContractorEmployee::XyzContractorEmployee(string idParam,string nameParam,
                        string genderParam,string dobParam,
                        string dojParam,string dolParam,
                        EmsUtility::EmpStatus statusParam,
                        string agencyParam)
                        :XyzEmployee(
                        idParam,
                        nameParam,
                        genderParam,
                        dobParam,
                        dojParam,
                        dolParam,
                        statusParam,
                        EmsUtility::TYPE_CONTRACTOR),
                        mEmpAgency(agencyParam)
{
}

XyzContractorEmployee::~XyzContractorEmployee()
{
}

void XyzContractorEmployee::printAllEmployeeDetails(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = true;
    emsRecordParam.mEmpNOL = "NA";
    emsRecordParam.mEmpAgency = this->getAgency();
    emsRecordParam.mEmpCollege = "NA";
    emsRecordParam.mEmpBranch = "NA";
    emsRecordParam.printAll();
}

void XyzContractorEmployee::printEmployeeDetailsByType(EmsRecord& emsRecordParam)
{
    XyzEmployee::printAllEmployeeDetails(emsRecordParam);
    emsRecordParam.mPrintAllVar = false;
    emsRecordParam.mEmpAgency = this->getAgency();
    emsRecordParam.printAll();
}

void XyzContractorEmployee::printEmployeeSpecificDetails(EmsRecord& emsRecordParam)
{ 
    /* Print all the relevant data */
    cout<<"\n\nContractor Employee Data:"<<endl;
    XyzEmployee::printEmployeeSpecificDetails(emsRecordParam);
    emsRecordParam.mEmpAgency = this->getAgency();
    emsRecordParam.printContractor();
}

void XyzContractorEmployee::setAgency(string agencyParam)
{
    mEmpAgency = agencyParam;
}
string XyzContractorEmployee::getAgency()
{
    return mEmpAgency;
}