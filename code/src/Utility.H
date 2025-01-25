#ifndef Utility_H
#define Utility_H

#include "iostream"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <random>
#include "printMenu.H"

typedef void (*Functionfunc)(void);
#define MIN_AGE_REQUIRED_TO_DO_JOB 21
#define RETIREMENT_AGE 60
#define CURR_YEAR 2025
#define MIN_DATE 1


using namespace std;

namespace EmsUtility
{
    enum
    {
        MAX_NAME_LEN = 20,
        MAX_ID_LEN = 8,
        MAX_EQ_LEN = 16,
    };

    enum EmployeeGender
    {
        MALE = 0x1,
        FEMALE = 0x2,
    };

    enum
    {
        MIN_DOB_YEAR = CURR_YEAR-RETIREMENT_AGE,
        MAX_DOB_YEAR = CURR_YEAR-MIN_AGE_REQUIRED_TO_DO_JOB,
        MAX_DOJ_YEAR = CURR_YEAR,
        MIN_DOB_YEAR_FOR_INTERN = CURR_YEAR-MIN_AGE_REQUIRED_TO_DO_JOB-4,
        MAX_DOB_YEAR_FOR_INTERN = CURR_YEAR-MIN_AGE_REQUIRED_TO_DO_JOB,
    };

    enum ErrorCode
    {
        E_UNEXPECTED = -1,
        E_SUCCESS = 0,
        E_FAILURE = 1,
    };
    
    enum EmpStatus
    {
        STATUS_NONE     = 0x0,
        STATUS_ACTIVE   = 0x1,
        STATUS_INACTIVE = 0x2,
        STATUS_RESIGNED = 0x3,
    };

    enum EmpType
    {
        TYPE_NONE       = 0x0,
        TYPE_FULL       = 0x1,
        TYPE_CONTRACTOR = 0x2,
        TYPE_INTERN     = 0x3,
    };

    enum EmpContractorAgency
    {
        AGENCY_X = 0x1,
        AGENCY_Y = 0x2,
        AGENCY_Z = 0x3,
    };

    enum InterEmpCollege
    {
        COLLEGE_IIT = 0x1,
        COLLEGE_NIT = 0x2,
        COLLEGE_MIT = 0x3,
    };

    enum InternEmpBranch
    {
        BRANCH_CSE = 0x1,
        BRANCH_CSIT = 0x2,
        BRANCH_ECE = 0x3,
    };
}


enum Month 
{
    Jan = 1, Feb , Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

inline string firstNameArray[30] = 
                            {
                                "Ganesh","Shivani","Chinna","Stella","Abhay","Dhruvika","Ujwal","Avisha","Viswa","Satya",
                                "Hari","Laxmi","Aryan","Raani","Ram","Mounika","Phani","Paavani" ,"Rudra","Praneetha"
                                "Gopal","Sravani","Chandu","Vineela","Sanjay" ,"Nidhi","Krishna","Radhika","Tanoj","Bhanu"               
                            };


inline string getContractorAgencyFromEnum(int agencyTypeParam)
{
    switch (agencyTypeParam)
    {
        case EmsUtility::AGENCY_X:     return "Agency-X";
        case EmsUtility::AGENCY_Y:     return "Agency-Y";
        case EmsUtility::AGENCY_Z:     return "Agency-Z";
        default:           return "";
    }
}

inline string getInternCollegeAgencyFromEnum(int clgTypeParam)
{
    switch (clgTypeParam)
    {
        case EmsUtility::COLLEGE_IIT:   return "IIT";
        case EmsUtility::COLLEGE_NIT:   return "NIT";
        case EmsUtility::COLLEGE_MIT:   return "MIT";
        default:            return "";
    }
}

inline string getInternBranchFromEnum(int clgTypeParam)
{
    switch (clgTypeParam)
    {
        case EmsUtility::BRANCH_CSE:     return "CSE";
        case EmsUtility::BRANCH_CSIT:    return "CSIT";
        case EmsUtility::BRANCH_ECE:     return "ECE";
        default:             return "";
    }
}


inline string getEmploymentTypeFromEnum(int empTypeParam)
{
    switch (empTypeParam)
    {
        case EmsUtility::TYPE_FULL:         return "Full-Time";
        case EmsUtility::TYPE_CONTRACTOR:   return "Contractor";
        case EmsUtility::TYPE_INTERN:       return "Intern";
        default:                return "";
    }
}

inline string getEmploymentStatusFromEnum(int empStatusParam)
{
    switch (empStatusParam)
    {
        case EmsUtility::STATUS_ACTIVE:     return "Active";
        case EmsUtility::STATUS_INACTIVE:   return "In-Active";
        case EmsUtility::STATUS_RESIGNED:   return "Resigned";
        default:                return "";
    }
}

inline string getEmployeeGenderFromEnum(int empGenderParam)
{
    switch (empGenderParam)
    {
        case EmsUtility::MALE:     return "Male";
        case EmsUtility::FEMALE:   return "Female";
        default:       return "";
    }
}

inline string getMonthStringFromEnum(int monthParam)
{
    switch (monthParam)
    {
    case Jan: return "Jan";
    case Feb: return "Feb";
    case Mar: return "Mar";
    case Apr: return "Apr";
    case May: return "May";
    case Jun: return "Jun";
    case Jul: return "Jul";
    case Aug: return "Aug";
    case Sep: return "Sep";
    case Oct: return "Oct";
    case Nov: return "Nov";
    case Dec: return "Dec";
    default: return "";
    }
}

inline int getMaxDateOfMonth(int yearParam,int monthParam)
{
  switch (monthParam)
  {
    case Jan: return 31;
    case Feb: return (yearParam%400==0) || ((yearParam%100!=0)&&(yearParam%4==0))? 29 : 28;
    case Mar: return 31;
    case Apr: return 30;
    case May: return 31;
    case Jun: return 30;
    case Jul: return 31;
    case Aug: return 31;
    case Sep: return 30;
    case Oct: return 31;
    case Nov: return 30;
    case Dec: return 31;
    default: return 0;
  }
}

inline string toString(int valParam,int digitsCountParam)
{
    ostringstream sOstringStreamObj;
    sOstringStreamObj<<setfill('0')<<setw(digitsCountParam)<<valParam;
    return sOstringStreamObj.str();
}

inline int getRandomNumber(int startNumParm,
                    int endNumParm)
{
    random_device sRandomDevice;
    mt19937 sRandomNumberGenerator(sRandomDevice());
    uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}
inline string generateRandomDate(int sYearParam) {
    int sMonth = getRandomNumber(1,12);
    int sDaysInMonth = getMaxDateOfMonth(sYearParam,sMonth);
    int sDateOfMonth = getRandomNumber(1,sDaysInMonth);
    // Output the randomly generated date in format: DD-MM-YYYY
    string sCompleteDateString = toString(sDateOfMonth,2)+" "+toString(sMonth,2)+" "+toString(sYearParam,4);
    return sCompleteDateString;
}

inline string  getEmployeeNameInRandom(int firstNameIndexParam)
{
    string sEmpName = firstNameArray[firstNameIndexParam];
    int sLastNameIndex = getRandomNumber(65,90);
    string sLastNameString;
    sLastNameString = (char)sLastNameIndex;
    sEmpName += " "+sLastNameString;
    return sEmpName;
}

inline EmsUtility::EmpStatus  getEmployeeStatusInRandom()
{
    EmsUtility::EmpStatus sRandStatus = static_cast<EmsUtility::EmpStatus>(getRandomNumber(1,2));
    return sRandStatus;
}

template<typename TN> void printElement(TN templateParam,int width)
{
    cout << "| "<< left << setw(width) << setfill(' ') <<templateParam;
}

template<typename TN> void printElementIndividual(string str,TN templateParam,int width)
{
    cout << left << setw(width) << setfill(' ') << str<<templateParam<<endl;
}

inline void printHeader(EmsUtility::EmpType empTypeParam = EmsUtility::TYPE_NONE,EmsUtility::EmpStatus empStatusParam=EmsUtility::STATUS_NONE)
{
    cout<<"\n\n"<<endl;
    int sSum = 0;
    /* Print the Header */
    printElement("Employee Name",EmsUtility::MAX_NAME_LEN);
    sSum += EmsUtility::MAX_NAME_LEN;
    printElement("ID",EmsUtility::MAX_ID_LEN+7);
    sSum += EmsUtility::MAX_ID_LEN+7;
    printElement("Type",EmsUtility::MAX_EQ_LEN);
    printElement("Status",EmsUtility::MAX_EQ_LEN);
    printElement("Gender",EmsUtility::MAX_EQ_LEN);
    printElement("Date of birth",EmsUtility::MAX_EQ_LEN);
    printElement("Date of joining",EmsUtility::MAX_EQ_LEN);
    printElement("Date of Leaving",EmsUtility::MAX_EQ_LEN);
    sSum += (6*EmsUtility::MAX_EQ_LEN);
    if(empStatusParam != EmsUtility::STATUS_RESIGNED)
    {
        if(empTypeParam != EmsUtility::TYPE_NONE)
        {
            if(empTypeParam == EmsUtility::TYPE_FULL)
            {
                
                printElement("Number of Leaves",EmsUtility::MAX_ID_LEN+7);
                sSum += EmsUtility::MAX_ID_LEN+7;
            }
            else if(empTypeParam == EmsUtility::TYPE_CONTRACTOR)
            {
                printElement("Agency",EmsUtility::MAX_EQ_LEN);
                sSum += EmsUtility::MAX_EQ_LEN;
            }
            else
            {
                printElement("College",EmsUtility::MAX_EQ_LEN);
                printElement("Branch",EmsUtility::MAX_EQ_LEN);
                sSum += (2*EmsUtility::MAX_EQ_LEN);
            }
            cout<<endl;
            cout << left << setw(sSum+EmsUtility::MAX_EQ_LEN) << setfill('-') <<"-";
        }
        else
        {
            printElement("No of Leaves",EmsUtility::MAX_ID_LEN+7);
            sSum += EmsUtility::MAX_ID_LEN+7;
            printElement("Agency",EmsUtility::MAX_EQ_LEN);
            printElement("College",EmsUtility::MAX_EQ_LEN);
            printElement("Branch",EmsUtility::MAX_EQ_LEN);
            sSum += (4*EmsUtility::MAX_EQ_LEN);
            cout<<endl;
            cout << left << setw(sSum) << setfill('-') <<"-";
        }
    }
    else
    {
        cout<<endl;
        cout << left << setw(sSum) << setfill('-') <<"-";
    }
    cout<<endl;
   
}

inline string addMonths(string dateStringParam, int numOfMonthParam) {
    stringstream sStringStream(dateStringParam);
    int sDay, sMonth, sYear;

    sStringStream >> sDay >> sMonth >> sYear;

    sMonth += numOfMonthParam;
    if (sMonth > 12) {
        sYear += sMonth / 12;
        sMonth %= 12;
    }

    string result = toString(sDay,2) + " " + toString(sMonth,2) + " " + toString(sYear,4);
    return result;
}

inline int funcToDoWhileOnUserInputs(bool repeatMenuParam,Functionfunc fnParam, int lowLimitParam, int upLimitParam,string errStringParam)
{
    int sLoopExit = 0;
    int sChoice;

    do
    {
        if(fnParam != NULL)
        {
            fnParam();
        }
        cin>>sChoice;
        if(cin.fail() || (sChoice<lowLimitParam||sChoice>upLimitParam))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(sChoice == -1)
            {
                exit(0);
            }
            if(repeatMenuParam == true)
            {
               cout<<errStringParam<<" B/W: "<<lowLimitParam<<" and "<<upLimitParam<<endl;
            }
            else
            {
                sChoice = -1;
            }
        }
        else
        {
            sLoopExit = 1;
        }
    }while((repeatMenuParam == true) && (sLoopExit == 0));

    return sChoice;
}


template<typename TN>
inline TN* createAnEmployeeOnInputs(EmsUtility::EmpType empTypeParam)
{
    string sEmpName,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpGender,sEmpAgency;
    EmsUtility::EmpStatus sEmpStatus;
    TN *sEmpPtr = NULL;


    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
    cout<<"Please enter employee name : "<<endl;
    getline(cin,sEmpName);
    
    int sEmpGenderChoice;
    sEmpGenderChoice        = funcToDoWhileOnUserInputs(true,printEmployeeGenderMenu,1,2,"Please enter proper choice for selecting gender");
    sEmpGender              = getEmployeeGenderFromEnum(sEmpGenderChoice);
    sEmpDOL                 = "NA";
    
    if(empTypeParam != EmsUtility::TYPE_INTERN)
    {
         /* Collecting Date of Birth */
        cout<<"Enter Dob Year : ";
        int sDOBYear            = funcToDoWhileOnUserInputs(true,NULL,EmsUtility::MIN_DOB_YEAR,EmsUtility::MAX_DOB_YEAR,"Please enter proper DOB Year");
        cout<<"Enter Dob Month : ";
        int sDOBMonth           = funcToDoWhileOnUserInputs(true,NULL,Jan,Dec,"Please enter proper DOB Month");
        cout<<"Enter Dob Day : ";
        int sDOBDay             = funcToDoWhileOnUserInputs(true,NULL,MIN_DATE,getMaxDateOfMonth(sDOBYear,sDOBMonth),"Please enter proper DOB Day");
        sEmpDOB          = toString(sDOBDay,2)+" "+toString(sDOBMonth,2)+" "+toString(sDOBYear,4);

        /* Collecting Date of Joining */
        cout<<"Enter DOJ Year : ";
        int sDOJYear            = funcToDoWhileOnUserInputs(true,NULL,sDOBYear+MIN_AGE_REQUIRED_TO_DO_JOB,EmsUtility::MAX_DOJ_YEAR,"Please enter proper DOJ Year");
        cout<<"Enter DOJ Month : ";
        int sDOJMonth           = funcToDoWhileOnUserInputs(true,NULL,Jan,Dec,"Please enter proper DOJ Month");
        cout<<"Enter DOJ Day : ";
        int sDOJDay             = funcToDoWhileOnUserInputs(true,NULL,MIN_DATE,getMaxDateOfMonth(sDOJYear,sDOJMonth),"Please enter proper DOJ Day");
        sEmpDOJ          = toString(sDOJDay,2)+" "+toString(sDOJMonth,2)+" "+toString(sDOJYear,4);

        int sEmpStatusChoice;
        sEmpStatusChoice = funcToDoWhileOnUserInputs(true,printEmployeeStatusMenu,1,2,"Please enter proper choice for selecting Status");
        sEmpStatus    = static_cast<EmsUtility::EmpStatus>(sEmpStatusChoice);
    }
    else
    {
        /* Collecting Date of Birth for Intern*/
        cout<<"Enter Intern DOB Year : ";
        int sDOBYear            = funcToDoWhileOnUserInputs(true,NULL,EmsUtility::MIN_DOB_YEAR_FOR_INTERN,EmsUtility::MAX_DOB_YEAR_FOR_INTERN,"Please enter proper DOB Year");
        cout<<"Enter DOB Month : ";
        int sDOBMonth           = funcToDoWhileOnUserInputs(true,NULL,Jan,Dec,"Please enter proper DOB Month");
        cout<<"Enter DOB Day : ";
        int sDOBDay             = funcToDoWhileOnUserInputs(true,NULL,MIN_DATE,getMaxDateOfMonth(sDOBYear,sDOBMonth),"Please enter proper DOB Day");
        sEmpDOB          = toString(sDOBDay,2)+" "+toString(sDOBMonth,2)+" "+toString(sDOBYear,4);

        /* Collecting Date of Joining for intern in current year*/
        int sDOJYear            = CURR_YEAR;
        cout<<"Enter DOJ Month : ";
        int sDOJMonth           = funcToDoWhileOnUserInputs(true,NULL,Jan,Dec,"Please enter proper DOJ Month");
        cout<<"Enter DOJ Day : ";
        int sDOJDay             = funcToDoWhileOnUserInputs(true,NULL,MIN_DATE,getMaxDateOfMonth(sDOJYear,sDOJMonth),"Please enter proper DOJ Day");
        sEmpDOJ          = toString(sDOJDay,2)+" "+toString(sDOJMonth,2)+" "+toString(sDOJYear,4);

        sEmpStatus = EmsUtility::STATUS_ACTIVE;
    }

    sEmpPtr = new  TN(sEmpName,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpStatus);

   
    if(empTypeParam == EmsUtility::TYPE_CONTRACTOR)
    {
        int sEmpAgencyChoice;
        sEmpAgencyChoice = funcToDoWhileOnUserInputs(true,printEmployeeAgencyMenu,1,2,"Please enter proper choice for selecting Agency");
        sEmpAgency = getContractorAgencyFromEnum(static_cast<EmsUtility::EmpContractorAgency>(sEmpAgencyChoice));
        sEmpPtr->setAgency(sEmpAgency);
        sEmpDOL     = addMonths(sEmpDOJ,12);
        sEmpPtr->setEmployeeDOL(sEmpDOL);
    }
    else if (empTypeParam == EmsUtility::TYPE_FULL)
    {
        int sEmpNol  = getRandomNumber(10,24);
        sEmpPtr->setNoOfLeaves(sEmpNol);
    }
    else
    {
        int sClgChoice;
        sClgChoice = funcToDoWhileOnUserInputs(true,printStudentCollegeMenu,1,3,"Please enter proper choice for selecting College");
        string sClg = getInternCollegeAgencyFromEnum(static_cast<EmsUtility::InterEmpCollege>(sClgChoice));
        sEmpPtr->setCollege(sClg);
        int sBranchChoice;
        sBranchChoice = funcToDoWhileOnUserInputs(true,printStudentBranchMenu,1,3,"Please enter proper choice for selecting Branch");
        string sBranch = getInternBranchFromEnum(static_cast<EmsUtility::InternEmpBranch>(sBranchChoice));
        sEmpPtr->setBranch(sBranch);
        sEmpDOL     = addMonths(sEmpDOJ,6);
        sEmpPtr->setEmployeeDOL(sEmpDOL);
    }

    return sEmpPtr;
}

#endif