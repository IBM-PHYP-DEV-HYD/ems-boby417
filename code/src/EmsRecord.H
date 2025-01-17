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

};


inline void EmsRecord::printAll()
{
    cout << "| "<< left << setw(MAX_NAME_LEN) << setfill(' ') <<mEmpName;
    cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') <<mEmpid;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<getEmploymentTypeFromEnum(mEmpType);
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<getEmploymentStatusFromEnum(mEmpStatus);
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpGender;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpDOB;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpDOJ;
    cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpDOL;
    if(mPrintAllVar == true)
    {
        cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') <<mEmpNOL;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpAgency;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpCollege;
        cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpBranch;
    }
    else
    {
        if(mEmpType == TYPE_FULL)
        {
            cout << "| "<< left << setw(MAX_ID_LEN+7) << setfill(' ') <<mEmpNOL;
        }
        else if(mEmpType == TYPE_CONTRACTOR)
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpAgency;
        }
        else if(mEmpType == TYPE_INTERN)
        {
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpCollege;
            cout << "| "<< left << setw(MAX_EQ_LEN) << setfill(' ')   <<mEmpBranch;
        }
    }
    cout<<endl;
}
#endif