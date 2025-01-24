#ifndef XyzInternEmloyee_H
#define XyzInternEmloyee_H

#include "XyzEmployee.H"

class XyzInternEmloyee: public XyzEmployee
{
public:
    XyzInternEmloyee();
    XyzInternEmloyee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam);
    ~XyzInternEmloyee();

    string mEmpCollege;
    string mEmpBranch;
    static long mNextEmproll;

    void setCollege(string clgParam);
    void setBranch(string branchParam);
    string getCollege();
    string getBranch();

    void printAllEmployeeDetails();
    void printEmployeeDetailsByType();
    void printEmployeeSpecificDetails();
};

#endif