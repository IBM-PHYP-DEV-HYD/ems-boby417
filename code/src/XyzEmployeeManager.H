#ifndef XyzEmployeeManager_H
#define XyzEmployeeManager_H

#include "EDLL.H"
#include "XyzEmployeeInterface.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmloyee.H"

#define ADD_PRINT(msg) \
        cout<<"\n\n************** "<<msg<<" **************"<<endl;

class XyzEmployeeManager
{
public:
    XyzEmployeeManager();
    ~XyzEmployeeManager(){};
    EDLL<XyzEmployeeIF>* mEmployeeEDLLPtr;
    EDLL<XyzEmployeeIF>* mResignedEmpEdllPtr;
    
    /* Adding new employees */
    void addNewEmployee(XyzEmployeeIF *empPtrParam,EmpType empTypeParam = TYPE_FULL);

    void printEmployeeSummaryByType(EmpType empTypeParam = TYPE_NONE);
    void printEmployeeSummaryByGender(int empGenderParam);
    void printEmployeeSummaryByStatus(EmpStatus empStatusParam);
    void printEmployeeDetailsById(string sEmpidParam);
    void printResignedEmpSummary();

    void removeEmployeeByID(string empIDParam);
    void addNumberofLeavesToFullTimeEmployee(string sEmpidParam,int nolParam);
    
    void addEmployee(int numofEmpParam,bool isRandom, EmpType typeParam= TYPE_NONE);

    void convertToFullTime(EmpType typeParam, string empIDParam);

private:
    void initializeEmployeeDeque();
    void initializeResignedEmployeeDeque();
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif