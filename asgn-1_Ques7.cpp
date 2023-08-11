// This is 👇 Wrong code. Bcoz: As we are assigning array value into a constant NOT in a variable.
// int* fun(int a[],int b[],int size1,int size2)
// {
//     int *p;
//     p=new int[size1+size2];
//     int i;
//     for(i=0;i<size1;i++)
//         p+i=a[i]; // p+i denotes the address of the first block of the array. And its a value i.e. constant NOT a variable. so, we can't assign a value into that.
//     for(i=0;i<size2;i++)
//         p+size1+i=b[i];
//     return p;
// }


// Correct code 👇
#include<bits/stdc++.h>
using namespace std;
int* fun(int a[],int b[],int size1,int size2)
{
    int *p;
    p=new int[size1+size2];
    int i;
    for(i=0;i<size1;i++)
        *(p+i)=a[i];
    for(i=0;i<size2;i++)
        *(p+size1+i)=b[i];
    return p;
}
int main(){
    int a1[] = {1,2,3,4,5}, a2[] = {10,20,30};
    int *a3 = fun(a1, a2, 5, 3);
    for(int i=0; i<8; i++) cout<<a3[i]<<" ";
}
