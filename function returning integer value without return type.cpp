#include<iostream>
#include<conio.h>
using namespace std;
int func()  //No error
{           //no declaration stmt in cpp then also no error
    if(2==5)
        return 3;
}
float func1()
{
    if(2==3)
        return 56;
}
int main()
{//garbage value is returned by the function
    //float return type function return 0--> is it compulsory or not ?
    cout<<func()<<endl;
    cout<<func()<<endl;
    cout<<func1()<<endl;
    cout<<func1()<<endl;
    getch();
}
