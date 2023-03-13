#include"Array_new_1.cpp"
#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_Array_inherit : private Array_new_1.cpp
{
private:
    int top;
public:
    Stack_Array_inherit();
    void CreateStack(int capacity);
    void push(int data);
    void pop();
    int peek();
    ~Stack_Array_inherit();
};
Stack_Array_inherit::Stack_Array_inherit()
{
    top=-1;
}
void Stack_Array_inherit::push(int data)
{
    if(top+1==capacity)
        cout<<"Overflow\n";
    else
    {
        top++;
        ptr[top]=data;
    }
}
void Stack_Array_inherit::pop()
{
    if(top==-1)
        cout<<"Underflow\n";
    else
        top--;
}
void Stack_Array_inherit::peek()
{
    if(top==-1)
    {
        cout<<"Empty stack"<<endl;
        return -1;
    }
    return ptr[top];
}
void Stack_Array_inherit::CreateStack(int capacity)
{
    if(ptr!=NULL)
        delete []ptr;
    this->capacity=capacity;
    lastindex=-1; //Imp
    ptr=new int[capacity];
}
