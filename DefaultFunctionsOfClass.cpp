#include<bits/stdc++.h>
using namespace std;
class Array
{
private:
  int* arr;
  int len;
public:
  Array(); //default constructor
  ~Array(); //defaut destructor
  Array(int len); //paramteterized  ctr
  Array(const Array&  ob); //copy ctr
  Array& operator=(const Array& ob); // assignment ctr
  Array(Array&& ob); // move copy ctr
  Array& operator=(Array&& ob); // move assignment ctr
  void display(); //display Array Obj Elements
};

Array :: Array()
{
  cout<<"Default Constructor is called"<<endl;
  arr =NULL;
  len =0;
}

Array :: ~Array()
{
  cout<<"Default Destructor is called"<<endl;
  if(arr != NULL)
  {
    delete [] arr;
    arr =NULL;
  }
}

Array :: Array(int len)
{
  cout<<"Parameterized Constructor is called"<<endl;
  this->len = len;
  arr = new int[this->len];
  for(auto i =1; i <=len; i++)
  {
    arr[i]= i*10;
  }
}

Array :: Array(const Array&  ob)
{
  cout<<"Copy Constructor is called"<<endl;
  len = ob.len;
  arr = new int[len];
  for(auto i =1; i <=len; i++)
  {
    arr[i]= ob.arr[i];
  }
}

Array&  Array :: operator=(const Array& ob)
{
   cout<<"Assignment Constructor is called"<<endl;
   if(this== &ob)
   {
     return *this;
   }
   len = ob.len;
    if(arr != NULL)
    {
      delete [] arr; 
    }
    else
    {
      cout<<"arr is null"<<endl;
    }
   
    arr = new int[len];
    for(auto i =1; i <= ob.len; i++)
    {
      arr[i]= ob.arr[i];
    }
    return *this;
}

Array ::Array(Array&& ob)
{
   cout<<"Move Copy Constructor is called"<<endl;
   len = ob.len;
   arr=ob.arr;
   ob.len=0;
   ob.arr=NULL;
}

Array&  Array :: operator=(Array&&  ob)
{
  cout<<"Move Assignment Constructor is called"<<endl;
  if(this != &ob)
  {
    len = ob.len;
    if(arr != NULL)
    {
      delete [] arr; 
    }
    else
    {
      cout<<"arr is null"<<endl;
    }
    len = ob.len;
    arr=ob.arr;
    ob.len=0;
    ob.arr=NULL;
  }
    return *this;
}

void Array :: display()
{
   cout<<"Display Array Object Elements"<<endl;
    for(auto i=0;  i < len; i++)
    {
      cout<<arr[i]<<endl;
    }
   cout<<endl;   
}

int main()
{
  {
    Array arr1(5);
    arr1.display(); 
  }

  {
    Array arr2;
    arr2.display();
  } 

  {
    Array arr1(5);
    arr1.display();
    Array arr2(arr1);
    arr2.display(); 
  }

  {
    Array arr1(5);
    arr1.display();
    Array arr2(5);
    arr2.display();
    arr1=arr2;
    arr1.display();
    arr2.display();
  }
   
  {
    Array arr1(5);
    arr1.display();
    Array arr2(move(arr1));
    arr2.display();
  }

  {
    Array arr1(5);
    arr1.display();
    Array arr2(5);
    arr2.display();
    arr1=move(arr2);
    arr1.display();
    arr2.display();
  }
   
    return 0;
}
