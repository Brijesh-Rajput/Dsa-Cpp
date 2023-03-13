#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_DynamicArray
{
private:
    int *ptr;
    int top;
    int capacity;
protected:
    void DoubleArray();
    void HalfArray();
public:
    Stack_DynamicArray();
    void CreateStack(int capacity);
    void push(int data);
    void pop();
    int peek();
    ~Stack_DynamicArray();
};
void Stack_DynamicArray::DoubleArray()
{
    int *p=new int[2*capacity]; //Or int *p=new int[capacity*=2];
    for(int i=0;i<=top;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
    capacity*=2;
}
void Stack_DynamicArray::HalfArray()
{
    int *p=new int[capacity/2];
    capacity/=2;
    for(int i=0;i<=top;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
}
Stack_DynamicArray::Stack_DynamicArray()
{
    ptr=NULL;
    top=-1;
    capacity=0;
}
void Stack_DynamicArray::CreateStack(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    top=-1;
    ptr=new int[capacity]; //ptr=new int [this->capacity];
}
void Stack_DynamicArray::push(int data)
{
    if(top+1==capacity)
        DoubleArray();
    ++top;
    ptr[top]=data;
}
void Stack_DynamicArray::pop()
{
    if(top==-1)
        cout<<"Underflow";
    else
    {
        top--;
        if(top<=capacity/2-1 && capacity>1)
            HalfArray();
    }
}
int Stack_DynamicArray::peek()
{
    if(top!=-1)
      return ptr[top];
}
Stack_DynamicArray::~Stack_DynamicArray()
{
    delete ptr;
}
int main()
{
    Stack_DynamicArray s1;
    s1.CreateStack(10);
    s1.push(45);
    s1.push(23);
    s1.push(39);
    cout<<s1.peek();
    s1.pop();
    cout<<s1.peek();
}
