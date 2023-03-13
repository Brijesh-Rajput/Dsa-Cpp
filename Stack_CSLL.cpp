//when start pointer variable will use then in pop function only one step will reduce and in push function Every time we have to traverse till last node
//so,we haven't use this start pointer variable instead of last pointer variable
#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_CSLL
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *last;
public:
    Stack_CSLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_CSLL();
};
Stack_CSLL::Stack_CSLL()
{
    last=NULL;
}
void Stack_CSLL::push(int data)
{
    node *t=new node;
    t->item=data;

    if(last==NULL)
        t->next=t;
    else
    {
        t->next=last->next;
        last->next=t;
    }
    last=t;
}
int Stack_CSLL::peek()
{
    if(last!=NULL)
        return last->item;
}
void Stack_CSLL::pop() //traversing required
{
    if(last==NULL)
        cout<<"Underflow";
    else
    {
        node *temp=last;
        if(temp->next==last)//Or last->nex==last that means only one node is present in the linked list
        {
            delete last;
            last=NULL;
        }
        else
        {
            while(temp->next!=last)
               temp=temp->next;
            temp->next=last->next;
            delete last;
            last=temp;
        }
    }
}
Stack_CSLL::~Stack_CSLL()
{
    while(last)
        pop();
}
int main()
{
    Stack_CSLL s1;
    s1.push(45);
    s1.push(23);
    s1.push(39);
    cout<<s1.peek();
    s1.pop();
    s1.pop();
    cout<<s1.peek();
}
