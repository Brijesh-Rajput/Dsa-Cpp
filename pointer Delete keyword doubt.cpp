------------------------IMP-----------------------
#include<iostream>
#include<conio.h>
using namespace std;
main()
{
    int *ptr;
    ptr=new int;
    *ptr=56;
    cout<<"Address is "<<ptr<<" Value is "<<*ptr<<endl;
    delete ptr;
    cout<<"Address is "<<ptr<<" Value is "<<*ptr;
    getch();
}
By this program output, we can say that Dynamically memory release by delete keyword but pointer value now also contain the same address which was contain before releasing memory of dynamically
