#ifndef XyzEmployee_H
#define XyzEmployee_H

#include "XyzEmployeeInterface.H"

class XyzEmployee : public XyzEmployeeIF
{
protected:
    string mEmpName;
    string mEmpid;
    string mEmpGender;
    string mEmpDOB; /* Date of Birth */
    EmsUtility::EmpType mEmpType;
    EmsUtility::EmpStatus mEmpStatus;
    string mEmpDOJ; /* Date of Joining */
    string mEmpDOL; /* Date of Leaving */

public:
    XyzEmployee();
    XyzEmployee(XyzEmployeeIF* xyzEmployeeIfPtrParam);
    virtual ~XyzEmployee(){};
    
    XyzEmployee(string idParam,string nameParam,string genderParam,
                string dobParam,string dojParam,string dolParam,
                EmsUtility::EmpStatus empStatusParam,
                EmsUtility::EmpType empTypeParam);

    string getEmployeeName();
    string getEmployeeGender();
    string getEmployeeDOB();

    EmsUtility::EmpType getEmployeeType();
    void setEmployeeType(EmsUtility::EmpType empTypeParam);
    EmsUtility::EmpStatus getEmployeeStatus();
    void setEmployeeStatus(EmsUtility::EmpStatus empStatusParam);
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
    virtual void fillAllEmployeeDetails(EmsRecord& recordParam);
    virtual void fillAllResignedEmployees(EmsRecord& recordParam);
    virtual void fillEmployeeDetailsByType(EmsRecord& recordParam);
    void  fillEmployeeSpecificDetails(EmsRecord& ecordParam);
};

class ResignedEmployee : public XyzEmployee
{
public:
    ResignedEmployee(){}
    string mDOL; /* Date of leaving */
};

#endif