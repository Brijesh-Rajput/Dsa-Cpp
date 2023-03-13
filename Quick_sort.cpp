#include<iostream>
using namespace std;
int Quick(int *a,int beg_index,int end_index)
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
void fun(int *a,int beg_index,int end_index)
    {
        int loc=Quick(a,beg_index,end_index);
        if(beg_index<loc-1) //loc should not be at 2nd last position or at last position
            fun(a,beg_index,loc-1);///Very IMP ----->beg_index<loc-1 -->Donit write like this->beg-index!=loc-1
        if(loc+1<end_index)  ///Don't write this---> loc+1!=end_index                        //false when loc==0 and beg_index==0
            fun(a,loc+1,end_index);       // when loc==3 and end_index==3 then condition will wrong
    }
void Quicksort(int *a,int size)
    {
       int beg_index=0;
       int end_index=size-1;
       if(beg_index<end_index)  //Don't write beg_index!=end_index --->wrong when size is zero
           fun(a,beg_index,end_index);
    }
int main()
{
    int a[10]={12,334,5,6,78,8,9,46,95,287};
    for(int i=0;i<10;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    Quicksort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<"  ";
}
