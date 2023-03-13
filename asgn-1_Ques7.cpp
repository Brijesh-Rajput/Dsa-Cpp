int* fun(int a[],int b[],int size1,int size2)
{
    int *p;
    p=new int[size1+size2];
    int i;
    for(i=0;i<size1;i++)
        p+i=a[i];
    for(i=0;i<size2;i++)
        p+size1+i=b[i];
    return p;
}
