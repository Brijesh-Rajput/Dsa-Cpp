//Apply only on sorted array or sorted linear Data structure
//return index of 1st occurrence of the element in the array
#include"Merge_sort.cpp"
#include<iostream>
#include<conio.h>
using namespace std;
int search_fun(int *a,int l,int u,int item)
{
    if(l>u)
        return -1;
    else
    {
        int mid=(l+u)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            search_fun(a,l,mid-1,item);
        else
            search_fun(a,mid+1,u,item);
    }
}
int Binary_search(int *a,int size,int item)
{
    Merge_sort(a,size);
    int l=0;
    int u=size-1;
    return search_fun(a,l,u,item);
}
int main()
{
    int x;
    int a[9]={35,69,79,40,72,948,437,453,766};
    int b[7]={40,10,30,70,80,20,60};
    int c[9]={40,30,30,20,10,10,60,80,60};
    cout<<"Enter an element which u want to do search in an array ";
    cin>>x;
    int index=Binary_search(c,9,x);
    if(index==-1)
        cout<<"Element Not found in array\n";
    else
        cout<<"Element found at index "<<index<<endl;
    getch();
}
