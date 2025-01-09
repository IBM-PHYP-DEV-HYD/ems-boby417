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
    EDLL<XyzEmployeeIF> *mEmployeeEDLLPtr;
    
    /* Adding new employees */
    void addNewEmployee(XyzEmployeeIF *empPtrParam,EmpType empTypeParam = TYPE_FULL);

    void printEmployeeSummaryByType(EmpType empTypeParam = TYPE_NONE,EmpStatus empStatusParam = STATUS_NONE);
    void printEmployeeSummaryByGender(int empGenderParam);
    void printEmployeeSummaryByStatus(EmpStatus empStatusParam);

    void removeEmployeeByID(string empIDParam);
    
    void printEmployeeDetailsById();

    /* Test code generating some random employee data*/
    void addEmployee(int numofEmpParam,bool isRandom, EmpType typeParam= TYPE_NONE);

private:
    void initializeEmployeeDeque();
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif