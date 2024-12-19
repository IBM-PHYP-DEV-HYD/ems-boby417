#ifndef XyzContractorEmployee_H
#define XyzContractorEmployee_H

#include "XyzEmployee.H"

class XyzContractorEmployee : public XyzEmployee
{
public:
    XyzContractorEmployee();
    XyzContractorEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam);
    
    string mEmpAgency;
    static long mNextEmproll;

    void setAgency(string agencyParam);
    string getAgency();

    friend ostream& operator<<(ostream& ostreamDataParam, XyzContractorEmployee& cEmpDataParam);
    friend istream& operator>>(istream& istreamDataParam, XyzContractorEmployee& cEmpDataParam);
    void print(ostream& ostreamDataParam);
};

#endif