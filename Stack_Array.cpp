#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_Array   //left aligned policy is used
{
private:
    int *ptr;
    int top;
    int capacity;
public:
    Stack_Array();
    void CreateStack(int capacity);
    void push(int data);
    void pop();
    int peek();
    ~Stack_Array();
};
Stack_Array::Stack_Array()
{
    ptr=NULL;
    top=-1;
    capacity=0;
}
void Stack_Array::CreateStack(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    top=-1;
    ptr=new int[capacity]; //ptr=new int [this->capacity];
}
void Stack_Array::push(int data)
{
    if(top+1==capacity)
        cout<<"Overflow";
    else
    {
        ++top;
        ptr[top]=data;
    }
}
void Stack_Array::pop()
{
    if(top==-1)
        cout<<"Underflow";
    else
        top--;
}
int Stack_Array::peek()
{
    if(top!=-1)
      return ptr[top];
}
Stack_Array::~Stack_Array()
{
    delete ptr;
}
