#ifndef Utility_H
#define Utility_H

#include "iostream"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

enum
{
    MAX_NAME_LEN = 20,
    MAX_ID_LEN = 8,
    MAX_EQ_LEN = 16,
};

enum ErrorCode
{
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

enum InterEmpBranch
{
    BRANCH_CSE = 0x1,
    BRANCH_CSIT = 0x2,
    BRANCH_ECE = 0x3,
};

enum EmployeeGender
{
    MALE = 0x1,
    FEMALE = 0x2,
};

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
        case AGENCY_X:     return "Agency-X";
        case AGENCY_Y:     return "Agency-Y";
        case AGENCY_Z:     return "Agency-Z";
        default:           return "";
    }
}

inline string getInternCollegeAgencyFromEnum(int clgTypeParam)
{
    switch (clgTypeParam)
    {
        case COLLEGE_IIT:   return "College-IIT";
        case COLLEGE_NIT:   return "College-NIT";
        case COLLEGE_MIT:   return "College-MIT";
        default:            return "";
    }
}

inline string getInternBranchFromEnum(int clgTypeParam)
{
    switch (clgTypeParam)
    {
        case BRANCH_CSE:     return "CSE";
        case BRANCH_CSIT:    return "CSIT";
        case BRANCH_ECE:     return "ECE";
        default:             return "";
    }
}


inline string getEmploymentTypeFromEnum(int empTypeParam)
{
    switch (empTypeParam)
    {
        case TYPE_FULL:         return "Full-Time";
        case TYPE_CONTRACTOR:   return "Contractor";
        case TYPE_INTERN:       return "Intern";
        default:                return "";
    }
}

inline string getEmploymentStatusFromEnum(int empStatusParam)
{
    switch (empStatusParam)
    {
        case STATUS_ACTIVE:     return "Active";
        case STATUS_INACTIVE:   return "In-Active";
        case STATUS_RESIGNED:   return "Resigned";
        default:                return "";
    }
}

inline string getEmployeeGenderFromEnum(int empGenderParam)
{
    switch (empGenderParam)
    {
        case MALE:     return "Male";
        case FEMALE:   return "Female";
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

inline string  getEmployeeNameInRandom()
{
    int sRandFirstNameIndex = getRandomNumber(0,29);
    string sEmpName = firstNameArray[sRandFirstNameIndex];
    int sLastNameIndex = getRandomNumber(65,90);
    string sLastNameString;
    sLastNameString = (char)sLastNameIndex;
    sEmpName += " "+sLastNameString;
    return sEmpName;
}

inline string  getEmployeeGenderInRandom()
{
    int sRandGender = getRandomNumber(1,2);
    string sEmpGender = getEmployeeGenderFromEnum(sRandGender);
    return sEmpGender;
}




inline EmpStatus  getEmployeeStatusInRandom()
{
    EmpStatus sRandStatus = static_cast<EmpStatus>(getRandomNumber(1,2));
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

inline void printHeader(EmpType empTypeParam = TYPE_NONE,EmpStatus empStatusParam=STATUS_NONE)
{
    cout<<"\n\n"<<endl;
    int sSum = 0;
    /* Print the Header */
    printElement("Employee Name",MAX_NAME_LEN);
    sSum += MAX_NAME_LEN;
    printElement("ID",MAX_ID_LEN+7);
    sSum += MAX_ID_LEN+7;
    printElement("Type",MAX_EQ_LEN);
    printElement("Status",MAX_EQ_LEN);
    printElement("Gender",MAX_EQ_LEN);
    printElement("Date of birth",MAX_EQ_LEN);
    printElement("Date of joining",MAX_EQ_LEN);
    printElement("Date of Leaving",MAX_EQ_LEN);
    sSum += (6*MAX_EQ_LEN);
    if(empStatusParam != STATUS_RESIGNED)
    {
        if(empTypeParam != TYPE_NONE)
        {
            if(empTypeParam == TYPE_FULL)
            {
                
                printElement("Number of Leaves",MAX_ID_LEN+7);
                sSum += MAX_ID_LEN+7;
            }
            else if(empTypeParam == TYPE_CONTRACTOR)
            {
                printElement("Agency",MAX_EQ_LEN);
                sSum += MAX_EQ_LEN;
            }
            else
            {
                printElement("College",MAX_EQ_LEN);
                printElement("Branch",MAX_EQ_LEN);
                sSum += (2*MAX_EQ_LEN);
            }
            cout<<endl;
            cout << left << setw(sSum+MAX_EQ_LEN) << setfill('-') <<"-";
        }
        else
        {
            printElement("No of Leaves",MAX_ID_LEN+7);
            sSum += MAX_ID_LEN+7;
            printElement("Agency",MAX_EQ_LEN);
            printElement("College",MAX_EQ_LEN);
            printElement("Branch",MAX_EQ_LEN);
            sSum += (4*MAX_EQ_LEN);
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

#endif