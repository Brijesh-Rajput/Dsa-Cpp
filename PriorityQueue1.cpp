#include<iostream>
#include<stdio.h>
using namespace std;
class priority_Queue
{
private:
    int capacity;
    int *front;
    int *rear;
    int **ptr;  //ptr is pointing array of pointer
    int max_priority;
public:
    priority_Queue();
    void createPriorityQueue(int capacity,int max_priority);
    void insert(int data,int priority_no);
    void Delete();
    void view();
    ~priority_Queue();
};
priority_Queue::priority_Queue()
{
    front=NULL;
    rear=NULL;
    ptr=NULL;
    capacity=0;
}
void priority_Queue::createPriorityQueue(int capacity,int max_priority)
{
    this->max_priority=max_priority;
    this->capacity=capacity;
    ptr=new int*[max_priority];  //int* is b'coz this dynamically array will store address of int type
    for(int i=0;i<max_priority;i++)
        ptr[i]=new int[capacity];
    front=new int[max_priority];
    rear=new int[max_priority];
    for(int i=0;i<max_priority;i++)
    {
        rear[i]=-1;
        front[i]=-1;
    }
}
void priority_Queue::insert(int data,int priority_no)
{
    if(priority_no<0 || priority_no>=max_priority)
        cout<<"Invalid priority No.\n";
    else if(rear[priority_no]+1==front[priority_no] || front[priority_no]==0 && rear[priority_no]==capacity-1)
        cout<<"Overflow\n";
    else if(rear[priority_no]==-1) //that means there is no element in the queue
    {                               //thats why front[priority_no] is also equal to -1
        rear[priority_no]=0;
        front[priority_no]=0;
        *(ptr[priority_no]+rear[priority_no])=data;
    }
    else if(rear[priority_no]==capacity-1)  //obviously front[priority_no]!=0
    {
        rear[priority_no]=0;
        *(ptr[priority_no]+rear[priority_no])=data;
    }
    else
    {
        rear[priority_no]++;
        *(ptr[priority_no]+rear[priority_no])=data;
    }
}
void priority_Queue::Delete()
{
    int i;
    for(i=max_priority-1;i>=0;i--)
        if(front[i]!=-1)  //Or front[i]!=-1;
          break;
    if(i==-1)
        cout<<"underflow\n";
    else
    {
        if(rear[i]==front[i])
        {
            rear[i]=-1;
            front[i]=-1;
        }
        else if(front[i]==capacity-1)
        {
            front[i]=0;
        }
        else
        {
            front[i]++; //front+=1;
        }
    }
}
void priority_Queue::view()
{
    for(int i=0,j;i<max_priority;i++)
    {
        j=front[i];
        if(j==-1)
            continue;
        do
        {
            if(j==capacity)
                j=0;
            cout<<"     "<<"i-"<<i<<" "<<"j-"<<j<<"-->"<<*(ptr[i]+j);  //ptr[i][j];
            j++;
        }while(j!=rear[i]+1);
        cout<<endl;
    }
    cout<<endl<<endl;
}
priority_Queue::~priority_Queue()
{
    for(int i=0;i<max_priority;i++)
        delete []ptr[i];
    delete []ptr;
}
int main()
{
    cout<<"i for no. of queues and j for no. values in each queue(rear)\n";
    priority_Queue p1;
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
