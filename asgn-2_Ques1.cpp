//left alligned policy is followed in this question
//Write everywhere if(ptr!=NULL) then ptr will do something but don't write in Create Array function
#include<iostream>
#include<conio.h>
using namespace std;
class Array
{
private:
  int *ptr;
  int lastindex;  //int lastindex=-1;
  int capacity;
public:
    Array()
    {
        ptr=NULL;
        lastindex=-1;
    }
    void CreateArray(int p)
    {
        //if p is Not zero and positive integer value
       capacity=p;
       ptr=new int[p];
       cout<<"Successfully Array of "<<p<<" elements created!"<<endl;
    }
    void Append_item(int data)
    {
        if(lastindex+1!=capacity)
        {
            //lastindex+=1; //lastindex++;//Wrong step b'coz lastindex indicate the data is store upto that index no.
            if(ptr!=NULL)
            {
               ptr[lastindex+1]=data; //*(ptr+lastindex+1)=data;
               lastindex++;
            }

            /*//OR
            lastindex++;
            ptr[lastindex]=data;
            */
        }
        else
            cout<<"Append of item is Not Possible"<<endl; //Overflow situation
    }
    void Insert(int index,int data)
    {
      if(lastindex+1!=capacity)
      {
        if(index>=0 && index<=lastindex+1)//Acc. to me index<=lastindex+1 instead of index<capacity
        {//instead of below if-else condition we can do function overloading
            //b'coz every time user Don't want to write an index no. for entering data in a sequence
            if(index<=lastindex)
            {
                int i;
                for(i=lastindex+1;i>index;i--)
                    ptr[i]=ptr[i-1];
                ptr[index]=data;//Or ptr[i]=data; b'coz above loop will stop when i==index
            }//code; lastindex++; and right shifted
            else //if(index>lastindex)
            {
                ptr[lastindex+1]=data; //item will only insert at index=lastindex+1
            }//code; lastindex++;
            lastindex++;
        }
        else
           cout<<"Enter a Valid indexNo. "<<endl;
      }
      else
         cout<<"insertion is Not Possible"<<endl; //Overflow situation
    }
    int Cout_totalitem_present()
    {
        return lastindex+1;
    }
    int Get_item(int index)
    {
        return ptr[index];
    }
    void Delete_item_given_index(int index)
    {
      if(index>=0 && index<=lastindex)//Don't write capacity istead of lastindex
      {
        int i;
        for(i=index;i<lastindex;i++)//Don't write here Capacity-1
            ptr[i]=ptr[i+1];//Don't write here index instead of i
        lastindex--;
      }
      else
        cout<<"Enter a Valid indexNo. "<<endl;
    }
    void Edit_item(int index,int data)
    {
        if(index>=0 && index<=lastindex)//Don't write here capacity instead of lastindex //index>-1 && index<=capacity-1
            ptr[index]=data;
        else
            cout<<"Enter a Valid IndexNo."<<endl;
    }
    int Search_item(int data)
    {
        int i;
        for(i=0;i<=lastindex;i++)//Don't write capacity instead of lastindex
            if(ptr[i]==data)
              return i; //index is returning on which data is found
        return -1; //if data is not found in an array
    }
    void View()
    {
        int i;
        cout<<"Elements of an array are :- "<<endl;
        for(i=0;i<=lastindex;i++)//don't write here capacity instead of lastindex
            cout<<i+1<<" Element is : "<<ptr[i];<<"    ";
        cout<<endl;
    }
};
int main()
{
    Array a1;
    int indexNo;
    a1.CreateArray(10);//pass Only integer type value
    a1.append(45);
    a1.Insert(4,56);
    cout<<"Total No. Elements are present in an array is : "<<a1.Cout_totalitem_present();<<endl;
    cout<<"Value at index index is "<<a1.Get_item(index);<<endl;
    a1.Delete_item_given_index(5);//No need to pass an item
    a1.Edit_item(index,data);

    indexNo=a1.Search_item(data);
    if(indexNo==-1)
        cout<<"data is Not found in an array"<<endl;
    else//indexNo
        cout<<"data is found at index "<<indexNo<<endl;

    a1.View();
    getch();
}
//Class Array
/
class Array
{
private:
  int *ptr;
  int lastindex;
  int capacity;
public:
    Array()
    {
        ptr=NULL;
        lastindex=-1;
    }
    void CreateArray(unsigned int p)
    {
      if(p) //p not zero
      {
       capacity=p;
       ptr=new int[p];
       cout<<"Successfully Array of "<<p<<" elements created!"<<endl;
      }
      else
        cout<<"size can't be a zero"<<endl;
    }
    void Append_item(int data)
    {
        if(lastindex+1!=capacity)
        {//we can't remve this body , if we remove then else is consider of this below if not of above if
            if(ptr!=NULL)
            {
               ptr[lastindex+1]=data;
               lastindex++;
            }
        }
        else
            cout<<"Append of item is Not Possible"<<endl; //Overflow situation
    }
    void Insert(int index,int data)
    {
      if(lastindex+1!=capacity)
      {
        if(index>=0 && index<=lastindex+1 && ptr!=NULL)//Acc. to me index<=lastindex+1 instead of index<capacity
        {
            if(index<=lastindex)
            {
                int i;
                for(i=lastindex+1;i>index;i--)
                    ptr[i]=ptr[i-1];
                ptr[index]=data;
            }
            else
            {
                ptr[lastindex+1]=data; //Or ptr[index]=data;
            }
            lastindex++;
        }
        else
           cout<<"Enter a Valid indexNo. "<<endl;
      }
      else
         cout<<"insertion is Not Possible"<<endl;
    }
    int Cout_totalitem_present()
    {
        return lastindex+1;
    }
    int Get_item(int index)  //IMP
    {
        if(index>=0 && index<=lastindex && ptr!=NULL)
           return ptr[index];
    }
    void Delete_item_given_index(int index)
    {
      if(index>=0 && index<=lastindex && ptr!=NULL)
      {
        int i;
        for(i=index;i<lastindex;i++) //i<=lastindex-1
            ptr[i]=ptr[i+1];//Don't write here index instead of i
        lastindex--;
      }
      else
        cout<<"Enter a Valid indexNo. "<<endl;
    }
    void Edit_item(int index,int data)
    {
        if(index>=0 && index<=lastindex && ptr!=NULL)
            ptr[index]=data; //old data will update
        else
            cout<<"Enter a Valid IndexNo."<<endl;
    }
    int Search_item(int data)
    {
        if(ptr!=NULL)
        {
          int i;
          for(i=0;i<=lastindex;i++)
            if(ptr[i]==data)
              return i; //index is returning on which data is found
        }
        return -1; //if data is not found in an array Or ptr==NULL
    }
    void View()
    {
        if(ptr!=NULL)
        {
          int i;
          cout<<"Elements of an array are :- "<<endl;
          for(i=0;i<=lastindex;i++)
            cout<<"arr["<<i<<"]="<<ptr[i]<<"   ";
          cout<<endl;
        }
        else
            cout<<"ptr contains NULL"<<endl;
    }
};
*/
//unsigned int holds zero and positive integer


/*
void Insert(int index,int data)
    {
        if(index>=0 && index<capacity)
        {
            if(index<=lastindex)
                code; lastindex++; and right shifted
            else if(index>lastindex)
                code; lastindex++;
        }
        else
           cout<<"Enter a Valid indexNo. "<<endl;
    }
*/

void Array::Delete(int index)
{
    int i;
    if(index<0 || index>lastindex)
        cout<<"\nInvalid Index";
    else //No need to check the value lastindex whether deletion can occur or not
    {    //If we come in this condition that means deletion can occur and array must have minimum one element
        for(i=index;i!=lastindex;i++) //Or i<lastindex   //Or i<=lastindex-1
            ptr[i]=ptr[i+1];
        lastindex--;
    }
}
int Array::Search(int data)
{
    int i;
    for(i=0;i<=lastindex;i++) //Or i!=lastindex+1
        if(ptr[i]==data)
           return i;
    return -1;//That means data is not found in an array
}
int Array::getdata(int index)
{
    if(index<0 || index>lastindex)
        cout<<"\nInvalid Index";
    else
        return ptr[index];
}
int Array::Count()
{
    return lastindex+1;
}
void Array::Edit(int index,int newdata)
{
    if(index<0 || index>lastindex)
        cout<<"\nInvalid index";
    else
        ptr[index]=newdata;
}
void Array::view()
{
    int i;
    for(i=0;i<=lastindex;i++)
        cout<<ptr[i]<<"  ";
}
Array::~Array()
{
   delete []ptr;
}


