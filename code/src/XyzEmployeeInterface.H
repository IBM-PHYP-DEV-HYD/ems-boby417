#ifndef XyzEmployeeIF_H
#define XyzEmployeeIF_H

#include "Utility.H"
#include "iostream"
#include "EmsRecord.H"

using namespace std;

class XyzEmployeeIF
{

public:
    XyzEmployeeIF(){}
    virtual ~XyzEmployeeIF(){}
    virtual string getEmployeeName() = 0;
    virtual string getEmployeeId() = 0;
    virtual string getEmployeeGender() = 0;
    virtual string getEmployeeDOB() = 0;

    virtual EmsUtility::EmpType getEmployeeType() = 0;
    virtual void setEmployeeType(EmsUtility::EmpType empTypeParam) = 0;
    virtual EmsUtility::EmpStatus getEmployeeStatus() = 0;
    virtual void setEmployeeStatus(EmsUtility::EmpStatus empStatusParam) = 0;
    virtual string getEmployeeDOJ() = 0;
    virtual void setEmployeeDOJ(string joiningDateParam) = 0;
    virtual string getEmployeeDOL() =  0;
    virtual void setEmployeeDOL(string leaveDateParam) =0 ;

    /* Specific to Fulltime Employees */
    virtual void setNoOfLeaves(int nolParam) = 0;
    virtual int getNoOfLeaves() = 0;
    
    /* Specific to Contractor Employees */
    virtual void setAgency(string agencyParam) = 0;
    virtual string getAgency() = 0;

    /* Specific to Intern Employees */
    virtual void setCollege(string clgParam) = 0;
    virtual void setBranch(string branchParam) = 0;
    virtual string getCollege() = 0;
    virtual string getBranch() = 0;
    
    virtual void printAllEmployeeDetails() = 0;
    virtual void printEmployeeDetailsByType() = 0;
    virtual void printEmployeeSpecificDetails() = 0;
};

#endif