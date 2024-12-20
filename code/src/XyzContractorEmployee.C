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

ostream& operator<<(ostream& ostreamDataParam, XyzContractorEmployee& cEmpDataParam)
{ 
    /* Print all the relevant data */
    cout<<"\n\nContractor Employee Data:"<<endl;
    printElementIndividual("Employee Name:",cEmpDataParam.mEmpName,20);
    printElementIndividual("Id:",cEmpDataParam.mEmpid,20);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(cEmpDataParam.mEmpType),20);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(cEmpDataParam.mEmpStatus),20);
    printElementIndividual("Gender:",cEmpDataParam.mEmpGender,20);
    printElementIndividual("DOB:",cEmpDataParam.mEmpDOB,20);
    printElementIndividual("DOJ:",cEmpDataParam.mEmpDOJ,20);
    printElementIndividual("DOL:",cEmpDataParam.mEmpDOL,20);
    printElementIndividual("Agency:",cEmpDataParam.mEmpAgency,20);
    return ostreamDataParam;
}

void XyzContractorEmployee::print(ostream& ostreamDataParam)
{
    ostreamDataParam<<*this;
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