#ifndef EMSRECORD_H
#define EMSRECORD_H
#include "Utility.H"

class EmsRecord
{

public:
    string mEmpName;
    string mEmpid;
    string mEmpGender;
    string mEmpDOB; /* Date of Birth */
    EmpType mEmpType;
    EmpStatus mEmpStatus;
    string mEmpDOJ; /* Date of Joining */
    string mEmpDOL; /* Date of Leaving */

    string mEmpNOL; /* Number of Leaves */
    string mEmpAgency;
    string mEmpCollege;
    string mEmpBranch;

    bool mPrintAllVar;

    inline void printAll();
    inline void printFullTime();
    inline void printCommonRecord();
    inline void printContractor();
    inline void printIntern();

};


inline void EmsRecord::printAll()
{
    printElement(mEmpName,MAX_NAME_LEN);
    printElement(mEmpid,MAX_ID_LEN+7);
    printElement(getEmploymentTypeFromEnum(mEmpType),MAX_EQ_LEN);
    printElement(getEmploymentStatusFromEnum(mEmpStatus),MAX_EQ_LEN);
    printElement(mEmpGender,MAX_EQ_LEN);
    printElement(mEmpDOB,MAX_EQ_LEN);
    printElement(mEmpDOJ,MAX_EQ_LEN);
    printElement(mEmpDOL,MAX_EQ_LEN);
    if(mPrintAllVar == true)
    {
        printElement(mEmpNOL,MAX_ID_LEN+7);
        printElement(mEmpAgency,MAX_EQ_LEN);
        printElement(mEmpCollege,MAX_EQ_LEN);
        printElement(mEmpBranch,MAX_EQ_LEN);
    }
    else
    {
        if(mEmpType == TYPE_FULL)
        {
            printElement(mEmpNOL,MAX_ID_LEN+7);
        }
        else if(mEmpType == TYPE_CONTRACTOR)
        {
            printElement(mEmpAgency,MAX_EQ_LEN);
        }
        else if(mEmpType == TYPE_INTERN)
        {
            printElement(mEmpCollege,MAX_EQ_LEN);
            printElement(mEmpBranch,MAX_EQ_LEN);
        }
    }
    cout<<endl;
}

inline void EmsRecord::printCommonRecord()
{
    printElementIndividual("Employee Name:",mEmpName,MAX_EQ_LEN);
    printElementIndividual("Id:",mEmpid,MAX_EQ_LEN);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(mEmpType),MAX_EQ_LEN);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(mEmpStatus),MAX_EQ_LEN);
    printElementIndividual("Gender:",mEmpGender,MAX_EQ_LEN);
    printElementIndividual("DOB:",mEmpDOB,MAX_EQ_LEN);
    printElementIndividual("DOJ:",mEmpDOJ,MAX_EQ_LEN);
    printElementIndividual("DOL:",mEmpDOL,MAX_EQ_LEN);
}

inline void EmsRecord::printFullTime()
{
    cout<<"\nFull-Time Employee Data:"<<endl;
    printCommonRecord();
    printElementIndividual("Num of Leaves:",mEmpNOL,MAX_EQ_LEN);
}

inline void EmsRecord::printContractor()
{
    cout<<"\nContractor Employee Data:"<<endl;
    printCommonRecord();
    printElementIndividual("Agency:",mEmpAgency,MAX_EQ_LEN);
}

inline void EmsRecord::printIntern()
{
    cout<<"Intern Employee Data:"<<endl;
    printCommonRecord();
    printElementIndividual("College:",mEmpCollege,MAX_EQ_LEN);
    printElementIndividual("Branch:",mEmpBranch,MAX_EQ_LEN);
}

#endif