#ifndef XyzEmployee_H
#define XyzEmployee_H

#include "Utility.H"
#include "XyzEmployeeInterface.H"

class XyzEmployee : public XyzEmployeeIF
{
protected:
    string mEmpName;
    string mEmpid;
    string mEmpGender;
    string mEmpDOB; /* Date of Birth */
    EmpType mEmpType;
    EmpStatus mEmpStatus;
    string mEmpDOJ; /* Date of Joining */
    string mEmpDOL; /* Date of Leaving */

public:
    XyzEmployee();
    virtual ~XyzEmployee(){};
    XyzEmployee(string nameParam,string genderParam,string dobParam,string dojParam,string dolParam,EmpStatus empStatusParam);

    string getEmployeeName();
    string getEmployeeGender();
    string getEmployeeDOB();

    EmpType getEmployeeType();
    void setEmployeeType(EmpType empTypeParam);
    EmpStatus getEmployeeStatus();
    void setEmployeeStatus(EmpStatus empStatusParam);
    string getEmployeeDOJ();
    void setEmployeeDOJ(string joiningDateParam);
    string getEmployeeDOL();
    void setEmployeeDOL(string leaveDateParam);

    virtual string getEmployeeId();

    /* Fulltime */
    virtual void setNoOfLeaves(int nolParam);
    virtual int getNoOfLeaves();

    /* Contractor */
    virtual void setAgency(string agencyParam);
    virtual string getAgency();
    
    /* Intern */
    virtual void setCollege(string clgParam);
    virtual void setBranch(string branchParam);
    virtual string getCollege();
    virtual string getBranch();

    /*Printing*/
    virtual void printAllEmployeeDetails(bool printExtraInfoParam);
};

class ResignedEmployee : public XyzEmployee
{
public:
    ResignedEmployee(){}
    string mDOL; /* Date of leaving */
};

#endif