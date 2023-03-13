//push1,pop1,peek1 --> for stack1
//push2,pop2,peek2 --> for stack2
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Two_way_Stack
{
private:
    int *ptr,capacity,top1,top2;
public:
    Two_way_Stack();
    void CreateArray(int capacity);
    void push1(int data);
    void push2(int data);
    void pop1();
    void pop2();
    int peek1();
    int peek2();
    ~Two_way_Stack();
};
Two_way_Stack::Two_way_Stack()
{
    ptr=NULL;
    capacity=0;
    top1=-1;
    //Imp top2= ??????????;
}
void Two_way_Stack::CreateArray(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    top1=-1;
    top2=capacity;  //Or this->capacity;
    ptr=new int[capacity]; //Or ptr=new int[this->capacity];
}
void Two_way_Stack::push1(int data)
{
    if(top1+1==top2)  //Or top1+top2+1==capacity  //Or top2-1==top1;
        cout<<"Overflow";
    else
    {
        ++top1;
        ptr[top1]=data;
    }
}
void Two_way_Stack::push2(int data)
{
    if(top1+1==top2)  //Or top1+top2+1==capacity  //Or top2-1==top1;
        cout<<"Overflow";
    else
    {//Or top2--;
        --top2;  //if i, then top1+something so that value will enter at correct place
        ptr[top2]=data;
    }
}
void Two_way_Stack::pop1()
{
    if(top1==-1)
        cout<<"Underflow";
    else
        --top1;
}
void Two_way_Stack::pop2()
{
    if(top2==capacity)
        cout<<"Underflow";
    else
        ++top2;
}
int Two_way_Stack::peek1()
{
    if(top1!=-1)
        return ptr[top1];
}
int Two_way_Stack::peek2()
{
    if(top2!=capacity)  //top2 can never be -1 ,similarly top1 can never be equal to capacity
        return ptr[top2];
}
Two_way_Stack::~Two_way_Stack()
{
    delete ptr;
}
int main()
{
    Two_way_Stack a1;
    a1.CreateArray(5);
    a1.push1(45);
    a1.push1(36);
    a1.push1(47);
    a1.push1(465);
    a1.push2(45);
    a1.push2(476);
    a1.pop2();
    a1.pop2();
    cout<<a1.peek2();  //Don't forget to write cout
    a1.pop1();
    cout<<a1.peek1();
    getch();
}
