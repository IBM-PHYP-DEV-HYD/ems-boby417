#include "XyzFullTimeEmployee.H"
#include "Utility.H"

long XyzFullTimeEmployee::mNextEmproll = 0;

XyzFullTimeEmployee::XyzFullTimeEmployee()
{
    mNextEmproll++;
}

XyzFullTimeEmployee::XyzFullTimeEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam):XyzEmployee(nameParam,genderParam,dobParam,dojParam,dolParam,statusParam)
{
    mNextEmproll++;
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"F";
    mEmpType = TYPE_FULL;
    /* Default values*/
    mEmpNOL = 24;
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
}

ostream& operator<<(ostream& ostreamDataParam, const XyzFullTimeEmployee& fEmpDataParam)
{
    /* Print all the relevant data */
    cout<<"\n\nFull-Time Employee Data:"<<endl;
    printElementIndividual("Employee Name:",fEmpDataParam.mEmpName,20);
    printElementIndividual("Id:",fEmpDataParam.mEmpid,20);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(fEmpDataParam.mEmpType),20);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(fEmpDataParam.mEmpStatus),20);
    printElementIndividual("Gender:",fEmpDataParam.mEmpGender,20);
    printElementIndividual("DOB:",fEmpDataParam.mEmpDOB,20);
    printElementIndividual("DOJ:",fEmpDataParam.mEmpDOJ,20);
    printElementIndividual("Num of Leaves:",fEmpDataParam.mEmpNOL,20);
    return ostreamDataParam;
}

void XyzFullTimeEmployee::print(ostream& ostreamDataParam)
{
    ostreamDataParam<<*this;
}

istream& operator>>(istream& istreamDataParam, XyzFullTimeEmployee& fEmpDataParam)
{
    //fEmpDataParam.pSetCommonEmpAttributes(TYPE_FULL,fEmpDataParam.mNextEmproll);
    cin.ignore(INT_MAX,'\n');
    cout<<"Number of Leaves :"<<endl;
    int sNol = 12;
    cin>>sNol;
    if(cin.fail() || sNol<10)
    {
        sNol = 12;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
    fEmpDataParam.setNoOfLeaves(sNol);
    return istreamDataParam;
}

void XyzFullTimeEmployee::setNoOfLeaves(int nolParam)
{
    mEmpNOL = nolParam;
}

int XyzFullTimeEmployee::getNoOfLeaves()
{
    return mEmpNOL;
}