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
}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam)
{
    mNextEmproll++;
    mEmpName    = xyzEmployeeIfPtrParam->getEmployeeName();
    string sEmpRollAsString = toString(mNextEmproll,4);
    mEmpid = "XYZ"+sEmpRollAsString+"F";
    mEmpGender  = xyzEmployeeIfPtrParam->getEmployeeGender();
    mEmpDOB     = xyzEmployeeIfPtrParam->getEmployeeDOB();
    mEmpDOJ     = xyzEmployeeIfPtrParam->getEmployeeDOJ();
    mEmpDOL     = xyzEmployeeIfPtrParam->getEmployeeDOL();
    mEmpStatus  = xyzEmployeeIfPtrParam->getEmployeeStatus();
    mEmpType    = TYPE_FULL;
    mEmpNOL     = getRandomNumber(10,24);
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
}

void XyzFullTimeEmployee::printAllEmployeeDetails()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = true;
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.mEmpAgency = "NA";
    mRecordObj.mEmpCollege = "NA";
    mRecordObj.mEmpBranch = "NA";
    mRecordObj.printAll();
}

void XyzFullTimeEmployee::printEmployeeDetailsByType()
{
    XyzEmployee::printAllEmployeeDetails();
    mRecordObj.mPrintAllVar = false;
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.printAll();
}


void XyzFullTimeEmployee::printEmployeeSpecificDetails()
{ 
    /* Print all the relevant data */
    XyzEmployee::printEmployeeSpecificDetails();
    mRecordObj.mEmpNOL = to_string(this->getNoOfLeaves());
    mRecordObj.printFullTime();
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