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

ostream& operator<<(ostream& ostreamDataParam, XyzInternEmloyee& iEmpDataParam)
{
    /* Print all the relevant data */
    printElementIndividual("Employee Name:",iEmpDataParam.mEmpName,20);
    printElementIndividual("Id:",iEmpDataParam.mEmpid,20);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(iEmpDataParam.mEmpType),20);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(iEmpDataParam.mEmpStatus),20);
    printElementIndividual("Gender:",iEmpDataParam.mEmpGender,20);
    printElementIndividual("DOB:",iEmpDataParam.mEmpDOB,20);
    printElementIndividual("DOJ:",iEmpDataParam.mEmpDOJ,20);
    printElementIndividual("DOL:",iEmpDataParam.mEmpDOL,20);
    printElementIndividual("Branch:",iEmpDataParam.mEmpBranch,20);
    printElementIndividual("College:",iEmpDataParam.mEmpCollege,20);
    return ostreamDataParam;
}

void XyzInternEmloyee::print(ostream& ostreamDataParam)
{
    ostreamDataParam<<*this;
}

istream& operator>>(istream& istreamDataParam, XyzInternEmloyee& iEmpDataParam)
{

    cin.ignore(INT_MAX,'\n');
    int sCollege = 0;
    int sBranch = 0;
    
    /*Get College*/
    while(1)
    {
        cout<<"Select College:\n1.College-IIT\n2.College-NIT\n3.College-MIT"<<endl;
        cin>>sCollege;
        if(cin.fail() || (sCollege<1||sCollege>3))
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            continue;
        }
        iEmpDataParam.mEmpCollege = getInternCollegeAgencyFromEnum(sCollege);
        break;
    }

    /*Get College*/
    while(1)
    {
        cout<<"Select Branch:\n1.CSE\n2.CSIT\n3.ECE"<<endl;
        cin>>sBranch;
        if(cin.fail() || (sBranch<1||sBranch>3))
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            continue;
        }
        iEmpDataParam.mEmpBranch = getInternBranchFromEnum(sBranch);
        break;
    }
    
    return istreamDataParam;
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