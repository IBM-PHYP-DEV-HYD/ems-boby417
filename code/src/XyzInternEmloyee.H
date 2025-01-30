#ifndef XyzInternEmloyee_H
#define XyzInternEmloyee_H

#include "XyzEmployee.H"

class XyzInternEmloyee: public XyzEmployee
{
public:
    XyzInternEmloyee();
    XyzInternEmloyee(string idParam, string nameParam,
                    string genderParam,string dobParam,
                    string dojParam,string dolParam,
                    EmsUtility::EmpStatus statusParam,
                    string clgParam, string branchParam);
    ~XyzInternEmloyee();

    string mEmpCollege;
    string mEmpBranch;

    void setCollege(string clgParam);
    void setBranch(string branchParam);
    string getCollege();
    string getBranch();

    void printAllEmployeeDetails(EmsRecord& emsRecordParam);
    void printEmployeeDetailsByType(EmsRecord& emsRecordParam);
    void printEmployeeSpecificDetails(EmsRecord& emsRecordParam);
};

#endif