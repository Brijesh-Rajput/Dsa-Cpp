//Conclusion:- stack using SLL is Better than DLL. DLL have one extra pointer variable which have no use in Stack
#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_DLL
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *top;
public:
    Stack_DLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_DLL();
};
Stack_DLL::Stack_DLL()
{
    top=NULL;
}
void Stack_DLL::push(int data)
{
    node *t=new node;
    t->prev=NULL;
    t->item=data;
    t->next=top;

    if(top!=NULL)
       top->prev=t;
    top=t;
}
int Stack_DLL::peek()
{
    if(top!=NULL)
      return top->item;
}
void Stack_DLL::pop()
{
    if(top==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=top;
        top=top->next;
        delete temp;
    }
}
Stack_DLL::~Stack_DLL()
{
    while(top)
        pop();
}
int main()
{
    Stack_DLL s1;
    s1.push(45);
    s1.push(23);
    s1.push(39);
    cout<<s1.peek();
    s1.pop();
    cout<<s1.peek();
}
