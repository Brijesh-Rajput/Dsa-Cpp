//we can use start pointer variable as well as last pointer variable
//But use last pointer variable b'coz we have to perform operation at last of Linked list for stack
//We can perform stack operation easily when we use last pointer variable instead of start pointer variable
#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_CDLL
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *last;
public:
    Stack_CDLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_CDLL();
};
Stack_CDLL::Stack_CDLL()
{
    last=NULL;
}
void Stack_CDLL::push(int data)
{
    node *t=new node;
    t->item=data;

    if(last==NULL)
    {
        t->prev=t;
        t->next=t;
    }
    else
    {
        t->prev=last;
        t->next=last->next;
        last->next->prev=t;
        last->next=t;
    }
    last=t;
}
int Stack_CDLL::peek()
{
    if(last!=NULL)
        return last->item;
}
void Stack_CDLL::pop()
{
    if(last==NULL)
        cout<<"Underflow";
    else
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
            node *temp=last->prev;
            temp->next=last->next;
            last->next->prev=temp;
            delete last;
            last=temp;
        }
    }
}
Stack_CDLL::~Stack_CDLL()
{
    while(last)
        pop();
}
int main()
{
    Stack_CDLL s1;
    s1.push(45);
    s1.push(23);
    s1.push(39);
    cout<<s1.peek();
    s1.pop();
    s1.pop();
    cout<<s1.peek();
}
