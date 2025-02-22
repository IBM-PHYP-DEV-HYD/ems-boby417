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
    EmsUtility::EmpType mEmpType;
    EmsUtility::EmpStatus mEmpStatus;
    string mEmpDOJ; /* Date of Joining */
    string mEmpDOL; /* Date of Leaving */

    string mEmpNOL; /* Number of Leaves */
    string mEmpAgency;
    string mEmpCollege;
    string mEmpBranch;

    bool mPrintAllVar;

    inline void printAll();
    inline void printAllCommon();
    inline void printCommonRecord();
    inline void printSpecificByType();

};

inline void EmsRecord::printAllCommon()
{
    printElement(mEmpName,EmsUtility::MAX_NAME_LEN);
    printElement(mEmpid,EmsUtility::MAX_ID_LEN+7);
    printElement(getEmploymentTypeFromEnum(mEmpType),EmsUtility::MAX_EQ_LEN);
    printElement(getEmploymentStatusFromEnum(mEmpStatus),EmsUtility::MAX_EQ_LEN);
    printElement(mEmpGender,EmsUtility::MAX_EQ_LEN);
    printElement(mEmpDOB,EmsUtility::MAX_EQ_LEN);
    printElement(mEmpDOJ,EmsUtility::MAX_EQ_LEN);
    printElement(mEmpDOL,EmsUtility::MAX_EQ_LEN);
}

inline void EmsRecord::printAll()
{
    printAllCommon();
    if(mPrintAllVar == true)
    {
        printElement(mEmpNOL,EmsUtility::MAX_ID_LEN+7);
        printElement(mEmpAgency,EmsUtility::MAX_EQ_LEN);
        printElement(mEmpCollege,EmsUtility::MAX_EQ_LEN);
        printElement(mEmpBranch,EmsUtility::MAX_EQ_LEN);
    }
    else
    {
        if(mEmpType == EmsUtility::TYPE_FULL)
        {
            printElement(mEmpNOL,EmsUtility::MAX_ID_LEN+7);
        }
        else if(mEmpType == EmsUtility::TYPE_CONTRACTOR)
        {
            printElement(mEmpAgency,EmsUtility::MAX_EQ_LEN);
        }
        else if(mEmpType == EmsUtility::TYPE_INTERN)
        {
            printElement(mEmpCollege,EmsUtility::MAX_EQ_LEN);
            printElement(mEmpBranch,EmsUtility::MAX_EQ_LEN);
        }
    }
    cout<<endl;
}

inline void EmsRecord::printCommonRecord()
{
    printElementIndividual("Employee Name:",mEmpName,EmsUtility::MAX_EQ_LEN);
    printElementIndividual("Id:",mEmpid,EmsUtility::MAX_EQ_LEN);
    printElementIndividual("Type:",getEmploymentTypeFromEnum(mEmpType),EmsUtility::MAX_EQ_LEN);
    printElementIndividual("Status:",getEmploymentStatusFromEnum(mEmpStatus),EmsUtility::MAX_EQ_LEN);
    printElementIndividual("Gender:",mEmpGender,EmsUtility::MAX_EQ_LEN);
    printElementIndividual("DOB:",mEmpDOB,EmsUtility::MAX_EQ_LEN);
    printElementIndividual("DOJ:",mEmpDOJ,EmsUtility::MAX_EQ_LEN);
    printElementIndividual("DOL:",mEmpDOL,EmsUtility::MAX_EQ_LEN);
}

inline void EmsRecord::printSpecificByType()
{


    if(mEmpType == EmsUtility::TYPE_FULL)
    {
        cout<<"FullTime Employee Data:"<<endl;
    } 
    else if(mEmpType == EmsUtility::TYPE_CONTRACTOR)
    {
        cout<<"Contractor Employee Data:"<<endl;
    }
    else
    {
        cout<<"Intern Employee Data:"<<endl;
    }
   
    printCommonRecord();
    
    if(mEmpType == EmsUtility::TYPE_FULL)
    {
        printElementIndividual("Num of Leaves:",mEmpNOL,EmsUtility::MAX_EQ_LEN);
    } 
    else if(mEmpType == EmsUtility::TYPE_CONTRACTOR)
    {
        printElementIndividual("Agency:",mEmpAgency,EmsUtility::MAX_EQ_LEN);
    }
    else
    {
        printElementIndividual("College:",mEmpCollege,EmsUtility::MAX_EQ_LEN);
        printElementIndividual("Branch:",mEmpBranch,EmsUtility::MAX_EQ_LEN);
    }

}

#endif