//use last pointer variable instead of start pointer variable
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
    node *start;
public:
    Stack_DLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_DLL();
};
Stack_DLL::Stack_DLL()
{
    start=NULL;
}
void Stack_DLL::push(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(start==NULL)
    {
        t->prev=NULL; //Or t->prev=start;
        start=t;
    }
    else
    {
        node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        t->prev=temp;
        temp->next=t;
    }
}
int Stack_DLL::peek()
{
    if(start!=NULL)
    {
        node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        return temp->item;
    }
}
void Stack_DLL::pop()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev==NULL)
            start=NULL;  //start=temp->next;
        else
            temp->prev->next=temp->next; //Or temp->prev->next=NULL;
        delete temp;
    }
}
Stack_DLL::~Stack_DLL()
{
    while(start)
        pop();
}
//Stack_DLL takes Less time compare to Stack_SLL in destructor
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

