#ifndef XyzContractorEmployee_H
#define XyzContractorEmployee_H

#include "XyzEmployee.H"

class XyzContractorEmployee : public XyzEmployee
{
public:

    XyzContractorEmployee();
    XyzContractorEmployee(string idParam,
                          string nameParam,
                          string genderParam,
                          string dobParam,
                          string dojParam,
                          string dolParam,
                          EmsUtility::EmpStatus statusParam,
                          string agencyParam);
    ~XyzContractorEmployee();
    
    string mEmpAgency;

    void setAgency(string agencyParam);
    string getAgency();

    void fillAllEmployeeDetails(EmsRecord& emsRecordParam);
    void fillEmployeeDetailsByType(EmsRecord& emsRecordParam);
    void fillEmployeeSpecificDetails(EmsRecord& emsRecordParam);
};

#endif