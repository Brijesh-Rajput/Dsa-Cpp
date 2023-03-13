#include<iostream>
#include<conio.h>
using namespace std;
class Stack_SLL
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;
public:
    Stack_SLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_SLL();
};
Stack_SLL::Stack_SLL()
{
    start=NULL;
}
void Stack_SLL::push(int data)
{
    node *t=new node;
    t->item=data;
    t->next=NULL;

    if(start==NULL)
        start=t;
    else
    {
       node *temp=start;
       while(temp->next!=NULL)
          temp=temp->next;
       temp->next=t;
    }
}
int Stack_SLL::peek()
{
    if(start!=NULL)
    {
        node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        return temp->item;
    }
}
void Stack_SLL::pop()
{
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;
        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        if(t2==NULL)
            start=NULL; //Or start=t1->next;
        else
            t2->next=NULL; //t2->next=t1->next;
        delete t1;
    }
}
Stack_SLL::~Stack_SLL()
{
    while(start)
        pop();   //more traversing will happen compare to CDLL
}
int main()
{
    Stack_SLL s1;
    s1.push(45);
    s1.push(23);
    s1.push(39);
    cout<<s1.peek();
    s1.pop();
    cout<<s1.peek();
}
