#include<iostream>
#include<conio.h>
using namespace std;
int* func(int*);
main()
{
    int x=67;
    cout<<*(func(&x));//Output is blank getch doesn't work //And process returned with -something
    getch();          //Acc. to me when process returned 0 that means normal termination or otherwise forcefully program terminate or program crash
}
int* func(int *p)
{
    //return -1;//--->This shows an Error  //we know that Address can't be negative never
    return NULL; //that means we can return NULL or zero0
}

/*Write below code by using reference operator
#include<iostream>
#include<conio.h>
using namespace std;
void func(int*,int*q);
main()
{
    int x=56;
    func(NULL,&x);//We are passing address of x NOT reference of x
    cout<<endl;
    func(0,&x);
    getch();
}
void func(int *p,int *q)
{
    cout<<p<<"  "<<q<<"  "<<*q;
}
*/

/*By this below program we can conclude that--->we can pass NULL in a pointer as an argument
#include<iostream>
#include<conio.h>
using namespace std;
void func(int*);
main()
{
    func(NULL);
    cout<<endl;
    func(0);
    getch();
}
void func(int *p)
{
    cout<<p;
}
*/

/*What was happened?????
#include<iostream>
#include<conio.h>
using namespace std;
void func(int*);
main()
{
    func(NULL);
    cout<<endl;
    func(0);
    getch();
}
void func(int *p)
{
    cout<<p<<"    "<<*p;
}
*/

