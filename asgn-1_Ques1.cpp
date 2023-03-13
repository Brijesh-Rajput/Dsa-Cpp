#include<iostream>
#include<conio.h>
//#include<string.h>
using namespace std;
class Employee
{
private:
    int empid;
    char name[20];
    float salary;
public:
    /*
    void setEmployee(int id,char b[],float slry) //Or char*p
    {
        empid=id;
        strcpy(name,b); //if name same then strcpy(this->name,name)
        salary=slry;
    }
    */
    void setEmployee()
    {
        cout<<"Enter empid,name,salary :-\n";
        cin>>empid;
        cin.ignore();
        cin.getline(name,20);
        cin>>salary;
    }
    void showEmployee()
    {
        cout<<"Employee Id="<<empid<<" Employee Name="<<name<<" Employee salary="<<salary; //(float)salary
    }
};
int main()
{
    Employee e1;
    e1.setEmployee();
    e1.showEmployee();
    getch();
}
