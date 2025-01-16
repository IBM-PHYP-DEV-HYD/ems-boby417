#ifndef XyzContractorEmployee_H
#define XyzContractorEmployee_H

#include "XyzEmployee.H"

class XyzContractorEmployee : public XyzEmployee
{
public:
    XyzContractorEmployee();
    XyzContractorEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam);
    ~XyzContractorEmployee();
    
    string mEmpAgency;
    static long mNextEmproll;

    void setAgency(string agencyParam);
    string getAgency();

    void printAllEmployeeDetails();
    void printEmployeeDetailsByType();
    void printEmployeeSpecificDetails();

    friend istream& operator>>(istream& istreamDataParam, XyzContractorEmployee& cEmpDataParam);
};

#endif