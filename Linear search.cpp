//return index of 1st occurrence of the element in the array
#include<iostream>
#include<conio.h>
#define size1 11
using namespace std;
int Linear_search(int *a,int size,int item)
{
    for(int i=0;i<size;i++)
        if(a[i]==item)
            return i;
    return -1;
}
int main()
{
    int x;
    int a[size1]={35,76,45,48,57,49,48,93,75,86,25};
    cout<<"Enter a Element what ou want to do search in an array ";
    cin>>x;
    int index=Linear_search(a,size1,x);
    if(index==-1)
        cout<<"Element Not found\n";
    else
        cout<<"Element found at index "<<index<<endl;
    getch();
}
