#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Employee
{
private:
    int empid;
    char name[20];
    float salary;
public:
    void setEmpid(int id)
    {
        empid=id;
    }
    void setName(char name[])
    {
        strcpy(this->name,name);
    }
    void setSalary(float salary)
    {
        this->salary=salary;
    }
    int getEmpid()
    {
        return empid;
    }
    char* getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
};
int main()
{
    Employee e1;
    e1.setEmpid(101231);
    e1.setName("Ritesh");
    e1.setSalary(40563.365);
    cout<<endl<<"Employee Id="<<e1.getEmpid()<<" Employee Name="<<e1.getName()<<" Employee Salary="<<e1.getSalary();
    /*
    cout<<endl<<"Employee Id="<<e1.getEmpid();
    cout<<" Employee Name="<<e1.getName();
    cout<<" Employee Salary="<<e1.getSalary();
    */
    getch();
}
