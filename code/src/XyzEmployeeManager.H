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

    int mFulltimeEmployeeCount;
    int mContractorEmployeeCount;
    int mInterEmployeeCount;


    XyzEmployeeManager();
    ~XyzEmployeeManager(){};
    EDLL<XyzEmployeeIF> *mEmployeeDequePtr;
    
    /* Adding new employees */
    void addNewFullTimeEmployee(XyzEmployeeIF *empPtrParam);
    void addNewContractorEmployee(XyzEmployeeIF *empPtrParam);
    void addNewInternEmployee(XyzEmployeeIF *empPtrParam);

    /* Print all employees summary*/
    void printAllEmployeesSummary();

    void printAllFullTimeEmployees();
    void printAllContractorEmployees();
    void printAllInternEmployees();

    void removeEmployee();
    void removeFullTimeEmployeeByID(string empIDParam);
    void removeContractorEmployeeByID(string empIDParam);
    void removeInternEmployeeByID(string empIDParam);
    void displayEmployeeDetails();

    /* Test code generating some random employee data*/
    void testEmployeeGeneration();

private:
    void initializeEmployeeDeque();
    void printEmployeeSummaryByType(EmpType empTypeParam, int startPosParam,int endPositionParam);
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif