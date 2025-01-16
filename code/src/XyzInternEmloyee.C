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
    /* Default values*/
    mEmpCollege = getInternCollegeAgencyFromEnum(COLLEGE_IIT);
    mEmpBranch = getInternBranchFromEnum(BRANCH_ECE);
}

XyzInternEmloyee::~XyzInternEmloyee()
{
}

void XyzInternEmloyee::printAllEmployeeDetails()
{
    XyzEmployee::printAllEmployeeDetails();
    printElement("NA", 15);
    printElement("NA", 20);
    printElement(this->getCollege(),20);
    printElement(this->getBranch(),20);
}

void XyzInternEmloyee::printEmployeeDetailsByType()
{
    XyzEmployee::printAllEmployeeDetails();
    printElement(this->getCollege(),20);
    printElement(this->getBranch(),20);
}

void XyzInternEmloyee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    cout<<"\nIntern Employee Data:"<<endl;
    XyzEmployee::printEmployeeSpecificDetails();
    printElementIndividual("Branch:",this->mEmpBranch,20);
    printElementIndividual("College:",this->mEmpCollege,20);
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