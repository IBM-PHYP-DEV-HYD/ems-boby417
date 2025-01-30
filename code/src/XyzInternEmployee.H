#ifndef XyzInternEmloyee_H
#define XyzInternEmloyee_H

#include "XyzEmployee.H"

class XyzInternEmployee: public XyzEmployee
{
public:
    XyzInternEmployee();
    XyzInternEmployee(string idParam,
                    string nameParam,
                    string genderParam,
                    string dobParam,
                    string dojParam,
                    string dolParam,
                    EmsUtility::EmpStatus statusParam,
                    string clgParam,
                    string branchParam);
    ~XyzInternEmployee();

    string mEmpCollege;
    string mEmpBranch;

    void setCollege(string clgParam);
    void setBranch(string branchParam);
    string getCollege();
    string getBranch();

    void fillAllEmployeeDetails(EmsRecord& emsRecordParam);
    void fillEmployeeDetailsByType(EmsRecord& emsRecordParam);
    void fillEmployeeSpecificDetails(EmsRecord& emsRecordParam);
};

#endif