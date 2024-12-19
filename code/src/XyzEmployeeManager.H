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
    EDLL<XyzEmployeeIF> *mEmployeeDequePtr;
    
    /* Adding new employees */
    void addNewFullTimeEmployee();
    void addNewContractorEmployee();
    void addNewInternEmployee();

    /* Print all employees summary*/
    void printAllEmployeesSummary();

    void printAllFullTimeEmployees();
    void printAllContractorEmployees();
    void printAllInternEmployees();

    void removeEmployee();
    void removeFullTimeEmployeeByID(string empIDParam);
    void removeContractorEmployeeByID(string empIDParam);
    void removeInternEmployeeByID(string empIDParam);

private:
    void initializeEmployeeDeque();
    XyzEmployeeIF* createAndGetEmployeeType(int empChoiceParam);
};

#endif