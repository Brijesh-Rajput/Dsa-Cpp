//for test case capacity of 5 array is taken index=0 to 4
#include<iostream>
#include<stdio.h>
using namespace std;
class Queue_Array1
{
private:
    int capacity;
    int front,rear;
    int *ptr;
public:
    Queue_Array1();
    void CreateQueue(int cap);
    void Insert(int data);
    void Delete();
    void view();
    int count();
    ~Queue_Array1();
};
Queue_Array1::Queue_Array1()
{
    ptr=NULL;
    capacity=0;
    front=-1;
    rear=-1;
}
void Queue_Array1::CreateQueue(int cap)
{
    if(ptr!=NULL)
        delete ptr;
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];  //Or ptr=new int[capacity];
}
void Queue_Array1::Insert(int data)
{
    if(rear+1==front || rear==capacity-1 && front==0)
        cout<<"Overflow";
    else if(rear==-1) //that means front=-1 //In this if condition i have written rear b'cz insertion happen on rear side. we can also write here front.
    {                                       //similarly in Delete function
        rear++;
        ptr[rear]=data;
        front=0; //Or front++;
    }
    else if(rear==capacity-1 && front!=0) ///sir condition rear==capacity-1
    {                                      ///see 1st if condition
        rear=0;
        ptr[rear]=data;
    }
    else//when rear is from -1 to 3
    {
        rear++;
        ptr[rear]=data;
    }
}
void Queue_Array1::Delete()
{
    if(front==-1) //Or rear=-1 --> Queue is Empty //Deletion is happen on front side thats why i have written front . we can also write rear
        cout<<"Underflow"<<endl;
    else if(front==rear)  //satisfy when front==0 && rear==0
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1) //here rear!=capacity-1 --->b'coz if happen this then above else if will execute not this else if
    {//value of rear can be anything but it will not equal to capacity-1
        front=0;
    }
    else
    {
        front++;
    }
}
void Queue_Array1::view()
{
    if(front==-1) //or rear==-1;
        cout<<"Empty Queue";
    else
    {
        cout<<"Queue:  ";
        int i=front;
        do
        {
            if(i==capacity)
                i=0;
            cout<<i<<"-"<<ptr[i]<<"  "; //i is index where element or item is store
              i++;
        }while(i!=rear+1);
    }
    cout<<"\n";
}
int Queue_Array1::count()
{
    int i=front,j=0;
    if(i==-1)
        return j;
    do
    {
        if(i==capacity)
            i=0;
        i++;
        j++;
    }while(i!=rear+1);
    return j;
}
Queue_Array1::~Queue_Array1()
{
    delete ptr; //Don't write this Delete();
}
int main()
{
    Queue_Array1 q1;
    q1.CreateQueue(5);
    q1.view();  cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.Insert(34);
    q1.Insert(12);
    q1.Insert(57);
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.Insert(37);
     q1.Insert(34);
    q1.Insert(12);
    q1.Insert(57);
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.view(); cout<<"count: "<<q1.count()<<endl;
    q1.Delete();
    q1.Insert(37);
    q1.view();  cout<<"count: "<<q1.count()<<endl;
}
/*
int Queue_Array1::count()
{
    if(front==-1) //Or rear==-1;
        return 0;
    else
    {
        int i=front,j=0;
        do
        {
            if(i==capacity)
                i=0;
            i++;
            j++;
        }while(i!=rear+1);
    return j;
    }

}
*/
/*
void Queue_Array1::view()
{
    if(front==-1) //or rear==-1;
        cout<<"Empty Queue"<<endl;
    else
    {
        cout<<"Queue:  ";
        if(rear<front)
        {
            int i=front;
            do
            {
                if(i==capacity)
                    i=0;
                cout<<ptr[i]<<"  ";
                i++;
            }while(i!=rear+1);
        }
        else
            for(int i=front;i<=rear;i++)
                cout<<ptr[i]<<"  ";
    }
}
*/
/*
void Queue_Array1::view()
{
    if(front==-1) //or rear==-1;
        cout<<"Empty Queue"<<endl;
    else
    {
        cout<<"Queue:  ";
        if(rear<front)
        {
            int i=front;
            do
            {
                if(i==capacity)
                    i=0;
                cout<<ptr[i]<<"  ";
                i++;
            }while(i!=rear+1);
            /*
            int i=front;
            do
            {
                if(i==capacity)
                    i=0;
                cout<<ptr[i]<<"  ";
                i++;
            }while(i!=rear);
            */
            /*fully wrong
            for(int i=front;i!=rear;i++)
            {
                 cout<<ptr[i]<<"  ";
                 if(i==capacity-1)
                    i=0;
            }
            */
                /*
            for(int i=front;i<=capacity-1;i++)
                  cout<<ptr[i]<<"  ";
            for(int i=0;i<=rear;i++) //NOTE:- i starts from zero(0)
                cout<<ptr[i]<<"  ";
                /
        }
        else
            for(int i=front;i<=rear;i++)
                cout<<ptr[i]<<"  ";
    }
}
*/
