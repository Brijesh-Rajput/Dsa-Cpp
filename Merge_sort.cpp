#include<iostream>
#include<conio.h>
#define size1 11 //Why this give me an error ----> #define size 2
void Merge_sort(int a[],int size);
void Merge(int *a,int l,int mid_add_1,int r);
void fun(int *a,int l,int r);
using namespace std;
/*
int main()
{
    int a[10]={26,3,84,59,60,14,26,58,93,85};
   // int b[15]={45,67,31,99,83,50,12,72,58,25,36,8,49,63,81};
    //int b[size1]={99};
    int b[size1]={23,44,6,15,12,89,9,92,56,49,33};
    for(int i=0;i<size1;i++)
        cout<<b[i]<<"  ";
    cout<<endl;
    Merge_sort(b,size1);
    for(int i=0;i<size1;i++)
        cout<<b[i]<<"  ";
    cout<<endl;
    getch();
}
*/
void Merge_sort(int a[],int size) //size can't be zero
{
    int l=0;
    int r=size-1;
    if(l<r)  //or l+1<=r  //l+1<size    //for size zero condition is satisfy
        fun(a,l,r);
}
void fun(int *a,int l,int r) //l=lower index of an array AND r=upperlimit index of an array
{
    if(l!=r)
    {
        int mid=(l+r)/2;
        fun(a,l,mid);
        fun(a,mid+1,r);
        Merge(a,l,mid+1,r);
    }
}
void Merge(int *a,int l,int mid_add_1,int r)
{
    int i=l,j=mid_add_1;
    int size=r+1-i;
    int *ptr=new int[size]; //we can create here statically array //No need to create dynamically array

    for(int z=0;z<=size-1;z++)
    {
        if(i==mid_add_1)   //i>=mid_add_1)
        {
            ptr[z]=a[j];
            j++;
        }
        else if(j>r)
        {
            ptr[z]=a[i];
            i++;
        }
        else if(a[i]<a[j])
        {
           ptr[z]=a[i];
           i++;
        }
        else
        {
            ptr[z]=a[j];
            j++;
        }
    }

    for(int z=0;z<size;z++,l++)
        a[l]=ptr[z];
    delete ptr;
}
/*
void Merge(int *a,int l,int mid_add_1,int r)
{
    int i=l,j=mid_add_1,k=r;
    int size=k+1-i;
    int *ptr=new int[size];

    for(int z=0;z<=size-1;z++)
    {
        if(i==mid_add_1 && j<=r)   //i>=mid_add_1)
        {
            ptr[z]=a[j];
            j++;
        }
        else if(j>r && i<mid_add_1) //no need to write this 2nd condition b'coz obviously i is less then if i>mid then loop is terminate early b'coz there is no space in an array and z==size
        {//Or j==r+1
            ptr[z]=a[i];
            i++;
        }
        else if(a[i]<a[j])  //it shouldn't be written be first b'coz it can contain garbage value
        {
           ptr[z]=a[i];
           i++;
        }
        else
        {
            ptr[z]=a[j];
            j++;
        }
    }

    for(int z=0;z<size;z++,l++)
        a[l]=ptr[z];
    delete ptr;
}
*/
