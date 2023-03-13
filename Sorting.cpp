#include<iostream>
#include<conio.h>
using namespace std;
class Sorting
{ //no need of Constructor and destructor
public:
    static void Bubblesort(int a[],int size);  //notice argument of function declaration and function defination
    static void Modified_Bubblesort(int a[],int size);
    static void Selectionsort(int a[],int size);
    static void Insertionsort(int a[],int size);
    static void Quicksort(int *a,int size)
    {
       int beg_index=0;
       int end_index=size-1;
       if(beg_index<end_index)
           fun(a,beg_index,end_index);
    }
private:
    static void fun(int *a,int beg_index,int end_index)
    {
        int loc=Quick(a,beg_index,end_index);
        if(beg_index<loc-1) //loc should not be at 2nd last position or at last position
            fun(a,beg_index,loc-1);
        if(loc+1<end_index)
            fun(a,loc+1,end_index);
    }
    static int Quick(int *a,int beg_index,int end_index)
    {
        int temp;
        int left=beg_index;
        int right=end_index;
        int loc=beg_index;

        while(left<right)
        {
           while(left<right)
             if(a[loc]>a[right])
             {
                 temp=a[loc];
                 a[loc]=a[right];
                 a[right]=temp;
                 loc=right;
                 break;
             }
             else
                 right--;

          while(left<right)
             if(a[loc]<a[left])
             {
                temp=a[loc];
                a[loc]=a[left];
                a[left]=temp;
                loc=left;
                break;
             }
             else
                left++;
        }
        return loc;
    }
};
void Sorting::Bubblesort(int *a,int size)
{
    int temp;
    for(int r=1;r<=size-1;r++)
        for(int i=0;i<size-r;i++) //Imp i<size-r
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
}
void Sorting::Modified_Bubblesort(int *a,int size)
{
    int temp,j;
    for(int r=1;r<=size-1;r++)
    {
       for(int i=0,j=0;i<size-r;i++) //Don't write int j=0; //Imp i<size-r
          if(a[i]>a[i+1])
          {
             j++;
             temp=a[i];
             a[i]=a[i+1];
             a[i+1]=temp;
          }
        if(j==0)
            break;
    }
}
void Sorting::Selectionsort(int *a,int size)
{
    int i,j,temp;
    for(i=0;i<size-1;i++) //imp
        for(j=i+1;j<size;j++)
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}
void Sorting::Insertionsort(int *a,int size)
{
    int i,j,temp;
    for(int i=1;i<size;i++)  //i<=size-1
    {
        temp=a[i];
         for(j=i-1;j>=0;j--)
         {
            if(temp<a[j])
                a[j+1]=a[j];
            else
                break;
         }
         a[j+1]=temp;
    }

}
int main()
{
    int a[]={34,65,68,22,96,808,3436,34,93,47};  //34 comes 2 times
  //int a[]={3,4,5,6,7,8,9,10};
  int c[]={12,44,33,89,9,56,16,62,98,6};
  int d[2]={23,16};
  int e[1]={56};
   for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
  // Sorting::Bubblesort(a,7);
 // Sorting::Modified_Bubblesort(a,8);
 // Sorting::Selectionsort(a,10);
//Sorting::Insertionsort(c,10);
Sorting::Quicksort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
   Sorting::Quicksort(d,2);
    cout<<endl;
     for(int i=0;i<2;i++)
        cout<<d[i]<<" ";
    Sorting::Quicksort(e,1);
    cout<<endl;
     for(int i=0;i<1;i++)
        cout<<e[i]<<" ";
    getch();
}
/*
void Sorting::Insertionsort(int *a,int size)
{
    int i,j,temp;
    for(j=1;j<size;j++)
    {
        temp=a[j];
      for(i=j-1;i>=0;i--)
           // temp=a[j]; //Don't write here
         if(temp<a[i])
         {
              a[i+1]=a[i];
              if(i==0) // if temp<a[0]
                a[i]=temp;  //a[0]=temp; //It will automatically break b'coz when i==-1 then condition will become false
         }
         else //when two values are same
          {
              a[i+1]=temp; //not required when temp==a[j]
              break;
          }
    }
}
*/
/*
constructor:- it is used when we have to initialize the variable of an object
destructor:- its important when, we have to destroy dynamically variable
*/
