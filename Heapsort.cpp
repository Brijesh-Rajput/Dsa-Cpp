#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class HeapTree //Max Heap
{
private:
    int capacity;
    int lastindex;
    int *ptr;
protected:
    void DoubleArray();
    void HalfArray();
public:
    HeapTree();
    void CreateHeapTree(int capacity);
    void InsertItem(int data);
  //  void DeleteItem();
    void ViewArray();
  //  ~HeapTree();
};
void HeapTree::DoubleArray()
{
    int *p=new int[2*capacity];
    capacity*=2;
    for(int i=0;i<=lastindex;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
}
void HeapTree::HalfArray()
{
    int *p=new int[capacity/2];  //Acc. to me :- int *p=new int[capacity/=2]; //Imp
    capacity/=2;
    for(int i=0;i<=lastindex;i++)
        p[i]=ptr[i];
    delete ptr;
    ptr=p;
}
HeapTree::HeapTree()
{
    ptr=NULL;
    capacity=0;
    lastindex=-1;
}
void HeapTree::CreateHeapTree(int capacity)
{
    if(ptr!=NULL)
        delete []ptr;
    this->capacity=capacity;
    lastindex=-1;
    ptr=new int[capacity];
}
void HeapTree::InsertItem(int data)
{
    if(ptr==NULL)
        cout<<"No memory is allocated for insertion"<<endl;
    else
    {
        if(lastindex+1==capacity)
            DoubleArray();
        lastindex++;
        int tempraroy_index=lastindex;
        if(lastindex!=0)
        {
            int parent_index=(tempraroy_index-1)/2;
            while(data>ptr[parent_index])
            {
                ptr[tempraroy_index]=ptr[parent_index];
                tempraroy_index=parent_index;
                parent_index=(parent_index-1)/2;
            }
        }
        ptr[tempraroy_index]=data;
        cout<<ptr[tempraroy_index]<<" ";
    }
}
void HeapTree::ViewArray()
{
    if(ptr==NULL)
        cout<<"Heap is Empty";
    else
        for(int i=0;i<=lastindex;i++) //Not i<capacity
            cout<<ptr[i]<<" ";
    cout<<endl;
}
/*
void HeapTree::DeleteItem()
{

}
HeapTree::~HeapTree()
{

}
*/
int main()
{
    int heap[17]={17,28,49,38,85,92,58,71,30,85,53,47,52,41,28,36,47};
    HeapTree h1;
    h1.CreateHeapTree(17);
    for(int i=0;i<17;i++)
        h1.InsertItem(heap[i]);
    h1.ViewArray();
    getch();
}
