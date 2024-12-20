#include "XyzEmployeeManager.H"

using namespace std;


void dummyEDLLTest()
{
    EDLL<int> *ed = new EDLL<int>();

    for(int i = 0;i<10;i++)
    {
        int *a = new int();
        *a = i;
        ed->pushBack(a);
    }

    for(int i = 0;i<ed->size();i++)
    {
        cout<<*((*ed)[i]) <<endl;
    }
    cout<<"First Print Done size = "<<ed->size()<<"\n"<<endl;

    int *a = new int();
    *a = 10;
    ed->addElementAtPosition(10,a);
    for(int i = 0;i<ed->size();i++)
    {
        cout<<*((*ed)[i]) <<endl;
    }
    cout<<"add Second Print Done size = "<<ed->size()<<"\n"<<endl;

    ed->addElementAtPosition(0,a);
    for(int i = 0;i<ed->size();i++)
    {
        cout<<*((*ed)[i]) <<endl;
    }
   cout<<"add Third Print Done size = "<<ed->size()<<"\n"<<endl;

    ed->removeElementAtPosition(0);
    ed->removeElementAtPosition(10);

    ed->removeElementAtPosition(3);
    for(int i = 0;i<ed->size();i++)
    {
        cout<<*((*ed)[i]) <<endl;
    }
    cout<<"3Remove 4th Print Done size = "<<ed->size()<<"\n"<<endl;

}

int main(int argc, const char * argv[]) {
    
    //dummyEDLLTest();
    XyzEmployeeManager *sEmpManger = new XyzEmployeeManager();
    // sEmpManger->addNewFullTimeEmployee();
    // sEmpManger->addNewInternEmployee();
    // sEmpManger->addNewContractorEmployee();
    // sEmpManger->printAllEmployeesSummary();
    sEmpManger->testEmployeeGeneration();
    sEmpManger->printAllEmployeesSummary();
    sEmpManger->removeEmployee();
    sEmpManger->printAllEmployeesSummary();
    sEmpManger->displayEmployeeDetails();
    sEmpManger->printAllContractorEmployees();
    sEmpManger->printAllFullTimeEmployees();
    sEmpManger->printAllInternEmployees();
}