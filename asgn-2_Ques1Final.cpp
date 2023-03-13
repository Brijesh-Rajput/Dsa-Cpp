//1 warning --> line no. 85
#include<iostream>
#include<conio.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    Array();
    void createArray(int cap);//Can i write this-->void create Array(int) ?
    void append(int data);
    void insert(int index,int data);
    void del(int index);
    int search(int data);
    int getData(int index);
    int count();
    void edit(int index,int newdata);
    void view();
    ~Array();
};
Array::Array()
{
    capacity=0;//Don't forget
    lastIndex=-1;
    ptr=NULL;
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[cap];
}
void Array::append(int data)
{
    if(lastIndex+1==capacity)
        cout<<"\nOverflow";
    else
    {
        ++lastIndex;//Or me:- lastIndex++
        ptr[lastIndex]=data;
    }
}
void Array::insert(int index,int data)
{
    int i;
    if(index<0 || index>lastIndex+1)
        cout<<"\nInvalid Index";
    else if(lastIndex+1==capacity)
        cout<<"\nOverflow";
    else
    {
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::del(int index)
{
    int i;
    if(index<0 || index>lastIndex)
        cout<<"\nInvlid Index Or Underflow";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
}
int Array::search(int data)
{
    for(int i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
         return i;
    return -1;
}
int Array::getData(int index)
{
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index";
    else
        return ptr[index];
}
int Array::count()
{
    return lastIndex+1;
}
void Array::edit(int index,int newdata)
{
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index";
    else
        ptr[index]=newdata;
}
void Array::view()
{
    for(int i=0;i<=lastIndex;i++)
        cout<<ptr[i]<<"  ";
}
Array::~Array()
{
   delete []ptr;
}
int main()
{
    int x,Capacity,index,Data;
    Array a1;
  while(1)
  {
    cout<<endl<<"\n";
    cout<<"\t1.CreateArray(int capacity)\n";
    cout<<"\t2.Append(int data)\n";
    cout<<"\t3.insert(int index,int data)\n";
    cout<<"\t4.del(int index)\n";
    cout<<"\t5.search(int data)\n";
    cout<<"\t6.getData(int index)\n";
    cout<<"\t7.Count()\n";
    cout<<"\t8.edit(int index,int newdata)\n";
    cout<<"\t9.view()\n";
    cout<<"\t10.Exit\n";
    cout<<endl<<"Enter Your Choice : ";
    cin>>x;
    switch(x)//Don't forget to write break stmt
    {
    case 1:
        cout<<"\tEnter Capacity of an array : ";
        cin>>Capacity;
        a1.createArray(Capacity);
        break;
    case 2:
        cout<<"\tEnter Data for append it : ";
        cin>>Data;
        a1.append(Data);
        break;
    case 3:
        cout<<"\tEnter index No. and Data to insert in an array \n\t";
        cin>>index>>Data;
        a1.insert(index,Data);
        break;
    case 4:
        cout<<"\tEnter index no. to delete an item : ";
        cin>>index;
        a1.del(index);
        break;
    case 5:
        cout<<"\tEnter an Element to search it in an array : ";
        cin>>Data;
        cout<<"Index No. is "<<a1.search(Data);
        break;
    case 6:
        cout<<"\tEnter index No. : ";
        cin>>index;
        cout<<"Data is "<<a1.getData(index);
        break;
    case 7:
        cout<<a1.count();
        break;
    case 8:
        cout<<"\tEnter index no. and NewData : ";
        cin>>index>>Data;
        a1.edit(index,Data);
        break;
    case 9:
        a1.view();
        break;
    case 10:
        exit(1);
        break;
    default:
       cout<<"\tInValid choice"<<endl;
    }
  }
    getch();
    return 0;//It's Not compulsory to write b'coz Compiler writes automatically but Don't forget this--->write int main in c++ NOT void main Or main
}
