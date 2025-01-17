#include "XyzContractorEmployee.H"

long XyzContractorEmployee::mNextEmproll = 0;

XyzContractorEmployee::XyzContractorEmployee()
{
    mNextEmproll++;
}

XyzContractorEmployee::XyzContractorEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam):XyzEmployee(nameParam,genderParam,dobParam,dojParam,dolParam,statusParam)
{
    mNextEmproll++;
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"C";
    mEmpType = TYPE_CONTRACTOR;
    /* Default values*/
    mEmpAgency = getContractorAgencyFromEnum(AGENCY_X);
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
    printElementIndividual("Agency:",this->mEmpAgency,20);
}


istream& operator>>(istream& istreamDataParam, XyzContractorEmployee& cEmpDataParam)
{
    cin.ignore(INT_MAX,'\n');
    int sAgency = 0;
    
    while(1)
    {
        cout<<"Please Select Proper Agency \n1.Agency-X\n2.Agency-Y\n3.Agency-Z"<<endl;
        cin>>sAgency;
        if(cin.fail() || (sAgency<1||sAgency>3))
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            continue;
        }
        cEmpDataParam.mEmpAgency = getContractorAgencyFromEnum(sAgency);
        break;
    }
    
    return istreamDataParam;
}

void XyzContractorEmployee::setAgency(string agencyParam)
{
    mEmpAgency = agencyParam;
}
string XyzContractorEmployee::getAgency()
{
    return mEmpAgency;
}