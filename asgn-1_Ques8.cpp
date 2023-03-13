#include<iostream>
#include<conio.h>
using namespace std;
struct Temp
{
private:
    int mintemp;
    int maxtemp;
public:
    void setmintemp(int min){mintemp=min;}
    void setmaxtemp(int max){maxtemp=max;}
    int getmintemp(){return mintemp;}
    int getmaxtemp(){return maxtemp;}
};
float minAvg(Temp[],int);
float maxAvg(Temp[],int);
int main()
{
    Temp t[3];

    t[0].setmintemp(45);
    t[0].setmaxtemp(55);

    t[1].setmintemp(35);
    t[1].setmaxtemp(85);

    t[2].setmintemp(65);
    t[2].setmaxtemp(25);

    cout<<"Average of minimum temp="<<minAvg(t,3)<<"   Average of Maximum temp="<<maxAvg(t,3);
    getch();
}
float minAvg(Temp a[],int totalDays)
{
    int i,sum=0;
    for(i=0;i<totalDays;i++)
        sum+=a[i].getmintemp();
    return (float)sum/totalDays;
}
float maxAvg(Temp a[],int totalDays)
{
    int i,sum=0;
    for(i=0;i<totalDays;i++)
        sum+=a[i].getmaxtemp();
    return (float)sum/totalDays;
}

