#include "XyzEmployee.H"

XyzEmployee::XyzEmployee()
{
    
}

XyzEmployee::XyzEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus empStatusParam)
{
    mEmpName   = nameParam;
    mEmpGender = genderParam;
    mEmpDOB    = dobParam;
    mEmpDOJ    = dojParam;
    mEmpDOL    = dolParam;
    mEmpStatus = empStatusParam;
}

//Overloading operator<< to work with XyzEmployeeIF* directly
ostream& operator<<(ostream& ostreamDataParam, XyzEmployee& objParam) 
{
    cout<<"Employee Name:\t"<<objParam.mEmpName<<endl;
    cout<<"Employee Id:\t"<<objParam.mEmpid<<endl;
    cout<<"Employee Type:\t"<<getEmploymentTypeFromEnum(objParam.mEmpType)<<endl;
    cout<<"Employee Status:\t"<<getEmploymentTypeFromEnum(objParam.mEmpType)<<endl;
    cout<<"Employee Gender:\t"<<objParam.mEmpGender<<endl;
    cout<<"Employee DOB:\t"<<objParam.mEmpDOB<<endl;
    cout<<"Employee DOJ:\t"<<objParam.mEmpDOJ<<endl;
    
    objParam.print(ostreamDataParam);
    return ostreamDataParam;
}
#if 0
void XyzEmployee::pSetCommonEmpAttributes(EmpType empTypeParam, int empRollNoParam)
{
    cout<<"Please enter employee name : "<<endl;
    getline(cin, mEmpName);
    
    string sEmpRollAsString = toString(empRollNoParam,4);
    mEmpid = "XYZ"+sEmpRollAsString;
    switch(empTypeParam)
    {
        case TYPE_FULL:         mEmpid = mEmpid+"F"; break;
        case TYPE_CONTRACTOR:   mEmpid = mEmpid+"C"; break;
        case TYPE_INTERN:       mEmpid = mEmpid+"I"; break;   
    }

    cout<<mEmpid<<endl;
    /* Gender */
    while(1)
    {
        cout<<"\nPlease enter valid Gender , Male or Female"<<endl;
        cin>>mEmpGender;
        if(mEmpGender == "Male" || mEmpGender == "Female")
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    /* Date of Birth */
    while(1)
    {
        int sDate = 0;
        int sMonth = 0;
        int sYear = 0;
        cout<<"Collecting the DOB Details: "<<endl;
        cout<<"Year 1964 - 2003"<<endl;
        cin>>sYear;
        if(cin.fail() || sYear >= 2003 || sYear <= 1964)
        {
            cout<<"\nInvalid year"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sYearString = toString(sYear,4);
        cout<<"Valid Month : 1 - 12"<<endl;
        cin>>sMonth;
        if(cin.fail() || sMonth > 12 || sMonth < 1)
        {
            cout<<"\nInvalid Month"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;   
        }
        string sMonthString = getMonthStringFromEnum(sMonth);
        
        cout<<"Valid Date:"<<endl;
        cin>>sDate;
        if(cin.fail() || sDate<1 || sDate>getMaxDateOfMonth(sYear,sMonth))
        {
            cout<<"\nInvalid Date"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sDateString = toString(sDate,2);
        mEmpDOB = sDateString+" "+sMonthString+" "+sYearString;
        cout<<mEmpDOB<<endl;
        break;
    }

    mEmpType = empTypeParam;
    
    /* Employement Status */
    int sEmpStatus = 0;
    while(1)
    {
        cout<<"Please select employement status \n1.Active.\n2.In-Active\n3.Resigned"<<endl;
        cin>>sEmpStatus;
        if(sEmpStatus == 1 || sEmpStatus == 2 || sEmpStatus == 3)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    mEmpStatus = static_cast<EmpStatus>(sEmpStatus);

    /* Date of Joining */
    int sDate = 0;
    int sMonth = 0;
    int sYear = 0;
    while(1)
    {
        cout<<"Collecting the DOJ Details: "<<endl;
        cout<<"Year 1984 - 2023 "<<endl;
        cin>>sYear;
        if(cin.fail() || sYear >= 2024 || sYear <= 1983)
        {
            cout<<"\nInvalid year"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sYearString = toString(sYear,4);
        cout<<"Valid Month : 1 - 12"<<endl;
        cin>>sMonth;
        if(cin.fail() || sMonth > 12 || sMonth < 1)
        {
            cout<<"\nInvalid Month"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;   
        }
        string sMonthString = getMonthStringFromEnum(sMonth);
        
        cout<<"Valid Date:"<<endl;
        cin>>sDate;
        if(cin.fail() || sDate<1 || sDate>getMaxDateOfMonth(sYear,sMonth))
        {
            cout<<"\nInvalid Date"<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        string sDateString = toString(sDate,2);
        mEmpDOJ = sDateString+" "+sMonthString+" "+sYearString;
        cout<<mEmpDOJ<<endl;
        break;
    }

    /* Set DOL for both Contractor and Intern */
    if(empTypeParam == TYPE_FULL)
    {
        mEmpDOL = "NA";
    }
    else if(empTypeParam == TYPE_CONTRACTOR)
    {
        sYear = sYear+1;
        string sYearString = toString(sYear,4);
        string sMonthString = getMonthStringFromEnum(sMonth);
        string sDateString = toString(sDate,2);
        mEmpDOL = sDateString+" "+sMonthString+" "+sYearString;
    }
    else
    {
        sMonth = sMonth+6;
        if(sMonth > 12)
        {
            sYear = sYear+1;
            sMonth = (sMonth%12);
            sDate = (sMonth == 2 && sDate == 29)?28:sDate;
        }
        string sYearString = toString(sYear,4);
        string sMonthString = getMonthStringFromEnum(sMonth);
        string sDateString = toString(sDate,2);
        mEmpDOL = sDateString+" "+sMonthString+" "+sYearString;
        cout<<mEmpDOL<<endl;
    }
}
#endif
string XyzEmployee::getEmployeeName()
{
    return mEmpName;
}

string XyzEmployee::getEmployeeGender()
{
    return mEmpGender;
}

string XyzEmployee::getEmployeeDOB()
{
    return mEmpDOB;
}

EmpType XyzEmployee::getEmployeeType()
{
    return mEmpType;
}

void XyzEmployee::setEmployeeType(EmpType empTypeParam)
{
    mEmpType = empTypeParam;
}

EmpStatus XyzEmployee::getEmployeeStatus()
{
    return mEmpStatus;
}

void XyzEmployee::setEmployeeStatus(EmpStatus empStatusParam)
{
    mEmpStatus = empStatusParam;
}

string XyzEmployee::getEmployeeDOJ()
{
    return mEmpDOJ;
}

void XyzEmployee::setEmployeeDOJ(string joiningDateParam)
{
    mEmpDOJ = joiningDateParam;
}

string XyzEmployee::getEmployeeDOL()
{
    return mEmpDOL;
}
void XyzEmployee::setEmployeeDOL(string leaveDateParam)
{
    mEmpDOL = leaveDateParam;
}

string XyzEmployee::getEmployeeId()
{ 
    return mEmpid;
}

void XyzEmployee::setNoOfLeaves(int nolParam) {}

int XyzEmployee::getNoOfLeaves() {return 0; }

void XyzEmployee::setAgency(string agencyParam) {}

string XyzEmployee::getAgency() {return " "; }

void XyzEmployee::setCollege(string clgParam) {}

void XyzEmployee::setBranch(string branchParam) {}

string XyzEmployee::getCollege() { return " "; }

string XyzEmployee::getBranch() { return " "; }
