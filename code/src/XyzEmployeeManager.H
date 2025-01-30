#ifndef XyzEmployeeManager_H
#define XyzEmployeeManager_H

#include "EDLL.H"
#include "XyzEmployeeInterface.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"

class XyzEmployeeManager
{
public:
    XyzEmployeeManager();
    ~XyzEmployeeManager();
    EDLL<XyzEmployeeIF>* mEmployeeEDLLPtr;
    EDLL<XyzEmployeeIF>* mResignedEmpEdllPtr;
    
    /* Adding new employees */
    void addNewEmployee(string& sEmpid,EmsUtility::EmpType empTypeParam,
                        string sEmpName,string sEmpGender,string sEmpDOB,
                        string sEmpDOJ,string sEmpDOL,EmsUtility::EmpStatus sEmpStatus,
                        int sEmpNol,string sEmpAgency,string sEmpClg, string sEmpBranch);

    void printEmployeeSummaryByType(EmsUtility::EmpType empTypeParam = EmsUtility::TYPE_NONE);
    void printEmployeeSummaryByGender(int empGenderParam);
    void printEmployeeSummaryByStatus(EmsUtility::EmpStatus empStatusParam);
    void printEmployeeDetailsById(string sEmpidParam);
    void printResignedEmpSummary();

    void removeEmployeeByID(string empIDParam);
    void addNumberofLeavesToFullTimeEmployee(string sEmpidParam,int nolParam);

    void convertToFullTime(string empIDParam);

private:
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif