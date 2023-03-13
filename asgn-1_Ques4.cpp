int maxValue(int A[],int size)
{
    int max=A[0],i;
    for(i=1;i<size;i++)
        if(max<A[i])
            max=A[i];
    return max;
}
float avg(int A[],int size)
{
    int sum=0,i;
    for(i=0;i<size;i++)
        sum+=A[i];
    return (float)sum/size;
}
int sum(int A[],int size)
{
    int sum=0,i;
    for(i=0;i<size;i++)
        sum+=A[i];
    return sum;
}
