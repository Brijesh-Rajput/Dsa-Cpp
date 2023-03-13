#include<iostream>
#include<stdio.h>
using namespace std;
class Stack_SLL
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *top;
public:
    Stack_SLL();
    void push(int data);
    int peek();
    void pop();
    ~Stack_SLL();
};
Stack_SLL::Stack_SLL()
{
    top=NULL;
}
void Stack_SLL::push(int data)
{
    node *t=new node;
    t->item=data;
    t->next=top;
    top=t;
}
int Stack_SLL::peek()
{
    if(top==NULL)
    {
        cout<<"Empty stack";
        return -1;
    }
    else
      return top->item;
}
void Stack_SLL::pop()
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
Stack_SLL::~Stack_SLL()
{
    while(top)
        pop();
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

