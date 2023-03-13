#include<iostream>
#include<stdio.h>
using namespace std;
class priority_Queue_LL_Array
{
private:
    struct node
    {
        int pr; //priority order
        int item;
    };
    int capacity;
    int front;
    int rear;
    node *ptr; //ptr will store the array of node type
public:
    priority_Queue_LL_Array();
    void createPriorityQueue(int capacity);
    void insert(int data,int priority_no);
    void Delete();
    void view();
    ~priority_Queue_LL_Array();
};
priority_Queue_LL_Array::priority_Queue_LL_Array()
{
    front=-1;
    rear=-1;
    ptr=NULL;
    capacity=0;
}
void priority_Queue_LL_Array::createPriorityQueue(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    rear=-1;
    front=-1;
    ptr=new node[capacity]; //Or ptr=new node[this->capacity];
}
void priority_Queue_LL_Array::insert(int data,int pr)
{
    if(rear+1==front || front==0 && rear==capacity-1)
        cout<<"Overflow";
    else if(rear==-1)
    {
        rear=0;
        front=0;
        ptr[rear].item=data;
        ptr[rear].pr=pr;
    }
    else if()
    {

    }
}
int main()
{
    cout<<"i for no. of queues and j for no. values in each queue(rear)\n";
    priority_Queue_LL_Array p1;
    p1.createPriorityQueue(3,3);
    p1.insert(12,1);
    p1.insert(45,0);
    p1.view();
    p1.insert(37,2);
    p1.insert(57,3);
    p1.view();
    p1.insert(43,1);
    p1.view();
    p1.insert(38,0);
    p1.insert(268,2);
    p1.view();
    p1.insert(27,1);
    p1.insert(123,1);
    p1.insert(435,0);
    p1.view();
    p1.insert(337,2);
    p1.insert(567,3);
    p1.view();
    p1.insert(413,1);
    p1.insert(382,0);
    p1.view();
    p1.insert(28,2);
    p1.insert(277,1);
    p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
    p1.view();
     p1.insert(23,1);
     p1.view();
    p1.insert(43,0);
    p1.view();
    p1.insert(37,2);
    p1.view();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
    p1.Delete();
    p1.Delete();
      p1.view();
}
