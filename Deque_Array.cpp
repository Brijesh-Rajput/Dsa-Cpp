//Implement by using inheritance concept
#include<iostream>
#include<stdio.h>
using namespace std;
class Deque_Array
{
private:
    int capacity;
    int *ptr;
    int front,rear;
public:
    Deque_Array();
    void CreateArray(int capacity);
    void insertfront(int data);
    void Deletefront();
    void insertrear(int data);
    void Deleterear();
    void view();
    int count();
    ~Deque_Array();
};
Deque_Array::Deque_Array()
{
    ptr=NULL;
    capacity=0;
    front=-1;
    rear=-1;
}
void Deque_Array::CreateArray(int capacity)
{
    if(ptr!=NULL)
        delete ptr;
    this->capacity=capacity;
    front=-1;
    rear=-1;
    ptr=new int[capacity];  //Or ptr=new int[this->capacity];
}
void Deque_Array::insertfront(int data)
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear+1==front || rear==capacity-1 && front==0)
        cout<<"Overflow\n";
    else if(front==-1)
    {
        front=0;
        rear=0;
        ptr[front]=data;
    }
    else if(front==0)
    {
        front=capacity-1;
        ptr[front]=data;
    }
    else
    {
        front--;
        ptr[front]=data;
    }
}
void Deque_Array::Deletefront()
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(front==-1) //when front==rear then also this if will not execute
        cout<<"Underflow\n";
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
void Deque_Array::insertrear(int data)
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear+1==front || rear==capacity-1 && front==0)
        cout<<"Overflow\n";
    else if(rear==-1) //Or front==-1
    {
        rear++;  //Or rear=0;
        front++; //Or front=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1) //obviously here front is not equal to zero b'coz if this happen then Overflow situation will happen
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
void Deque_Array::Deleterear()
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(rear==-1)  //that means front is also equal to -1
        cout<<"Underflow\n";
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=capacity-1;
    else
        rear--;
}
void Deque_Array::view()
{
    if(ptr==NULL)
        cout<<"Invalid Operation";
    else if(front==-1)
        cout<<"Empty Queue";
    else
    { //for both wen rear<=front and rear>front
        cout<<"Queue:";
        int i=front;
        do
        {
            if(i==capacity)
                i=0;
            cout<<"  "<<i<<"-"<<ptr[i];
            i++;
        }while(i!=rear+1);
    }
    cout<<endl;
}
int Deque_Array::count()
{
    int i=-1;
    if(ptr==NULL)
        cout<<"Invalid Operation";
    else if(front==-1)
        cout<<"Empty Queue";
    else
    {
        int j=front;
        do
        {
            if(j==capacity)
                j=0;
            j++;
            i++;
        }while(j!=rear+1);
    }
    return i+1;
}
Deque_Array::~Deque_Array()
{
    delete []ptr;
}
int main()
{
    Deque_Array d1;
    d1.CreateArray(5);
    d1.Deletefront();
    d1.insertfront(56);
    d1.insertfront(27);
    d1.insertrear(7);
    d1.insertrear(67);
    d1.insertfront(56);
    d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deleterear();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertrear(568);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertfront(256);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.insertfront(264);
    d1.insertrear(5);
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deleterear();
    d1.Deleterear();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
    d1.Deletefront();
     d1.view(); cout<<"count: "<<d1.count()<<endl;
}
/*
int Deque_Array::count()
{
    if(ptr==NULL)
    {
        cout<<"Invalid Operation";
        return -1;
    }
    else if(front==-1)
    {
        cout<<"Empty Queue";
        return -1;
    }
    else
    {
        int i=0,j=front;
        do
        {
            if(j==capacity)
                j=0;
            j++;
            i++;
        }while(j!=rear+1);
       return i;
    }
}
*/
/*
int Deque_Array::count()
{
    if(ptr==NULL)
    {
        cout<<"Invalid Operation";
        return -1;
    }
    else if(front==-1)
    {
        cout<<"Empty Queue";
        return -1;
    }
    int i=0;///this is wrong !!!!1
    else
    {
        int j=front;
        do
        {
            if(j==capacity)
                j=0;
            j++;
            i++;
        }while(j!=rear+1);
    }
    return i;
}
*/
/* wrong code //so here we will use do while loop
void Deque_Array::view()
{
    if(ptr==NULL)
        cout<<"Invalid Operation\n";
    else if(front==-1)
        cout<<"Empty Queue\n";
    else
    {
        cout<<"Queue:";
        int i=front;
        if(rear<front)
            while(i!=rear+1)  //wrong
        while(i!=rear+1) //condition Or code wrong when rear==front-1;
        {
            cout<<"  "<<ptr[i];
            i++;
        }
    }
}
*/
