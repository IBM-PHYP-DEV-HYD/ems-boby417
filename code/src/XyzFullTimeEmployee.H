#ifndef XyzFullTimeEmployee_H
#define XyzFullTimeEmployee_H

#include "XyzEmployee.H"

class XyzFullTimeEmployee : public XyzEmployee
{
public:
    XyzFullTimeEmployee();
    ~XyzFullTimeEmployee();
    XyzFullTimeEmployee(string idParam,
                        string nameParam,
                        string genderParam,
                        string dobParam,
                        string dojParam,
                        string dolParam,
                        EmsUtility::EmpStatus statusParam,
                        int nolParam);
    XyzFullTimeEmployee(XyzEmployeeIF *xyzEmployeeIfPtrParam);

    int mEmpNOL; /* Number of Leaves */
    void setNoOfLeaves(int nolParam);
    int getNoOfLeaves();

    void fillAllEmployeeDetails(EmsRecord& emsRecordParam);
    void fillEmployeeDetailsByType(EmsRecord& emsRecordParam);
    void fillEmployeeSpecificDetails(EmsRecord& emsRecordParam);
};

#endif