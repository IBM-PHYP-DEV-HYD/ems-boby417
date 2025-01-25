#ifndef XyzEmployeeManager_H
#define XyzEmployeeManager_H

#include "EDLL.H"
#include "XyzEmployeeInterface.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmloyee.H"

class XyzEmployeeManager
{
public:
    XyzEmployeeManager();
    ~XyzEmployeeManager();
    EDLL<XyzEmployeeIF>* mEmployeeEDLLPtr;
    EDLL<XyzEmployeeIF>* mResignedEmpEdllPtr;
    
    /* Adding new employees */
    void addNewEmployee(XyzEmployeeIF *empPtrParam);

    void printEmployeeSummaryByType(EmsUtility::EmpType empTypeParam = EmsUtility::TYPE_NONE);
    void printEmployeeSummaryByGender(int empGenderParam);
    void printEmployeeSummaryByStatus(EmsUtility::EmpStatus empStatusParam);
    void printEmployeeDetailsById(string sEmpidParam);
    void printResignedEmpSummary();

    void removeEmployeeByID(string empIDParam);
    void addNumberofLeavesToFullTimeEmployee(string sEmpidParam,int nolParam);
    
    void addEmployee(int numofEmpParam,bool isRandom, EmsUtility::EmpType typeParam= EmsUtility::TYPE_NONE);

    void convertToFullTime(EmsUtility::EmpType typeParam, string empIDParam);

private:
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif