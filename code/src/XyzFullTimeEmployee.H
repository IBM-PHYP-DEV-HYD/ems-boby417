#ifndef XyzFullTimeEmployee_H
#define XyzFullTimeEmployee_H

#include "XyzEmployee.H"

class XyzFullTimeEmployee : public XyzEmployee
{
public:
    XyzFullTimeEmployee();
    ~XyzFullTimeEmployee();
    XyzFullTimeEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus statusParam);
    
    int mEmpNOL; /* Number of Leaves */
    static long mNextEmproll;
    void setNoOfLeaves(int nolParam);
    int getNoOfLeaves();

    void print(ostream& ostreamDataParam);
    void printAllEmployeeDetails(bool printExtraInfoParam);


    friend ostream& operator<<(ostream& ostreamDataParam, const XyzFullTimeEmployee& fEmpDataParam);
    friend istream& operator>>(istream& istreamDataParam, XyzFullTimeEmployee& fEmpDataParam);
};

#endif