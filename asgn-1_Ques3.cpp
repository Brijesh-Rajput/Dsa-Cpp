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
    getch();
}
Employee HighestSalary(Employee a[],int size)
{
    int i;
    Employee e;
    float maxslry;
    maxslry=a[0].getSalary;
    for(i=1;i<size;i++)
        if(maxslry<a[i].getSalary)
        {
            maxslry=a[i].getSalary;
            e=a[i];
        }
   return e;
}
