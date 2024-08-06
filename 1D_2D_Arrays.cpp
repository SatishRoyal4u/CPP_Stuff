#include<bits/stdc++.h>
using namespace std;
int main(){

    {

      cout<<"1D array is single pointer"<<endl;
      int* ptr = NULL;
      int n;
      cout<<"enter an array size"<<endl;
      cin>> n;
      ptr = new int[n];
      for(auto i =0; i < n; i++)
      {
        ptr[i] = i*10;
      }

      cout<<"printing the array"<<endl;
      for(auto i =0; i < n; i++)
      {
        cout<<ptr[i]<<endl;
      }

      delete[] ptr;
      ptr=NULL;

    }

    {

      cout<<"2D Array  using double pointer"<<endl;
      int** ptr = NULL;
      int  row, col;
      cout<<"enter the row value"<<endl;
      cin >> row;
      ptr = new int*[row];
      cout<<"enter the column value"<<endl;
      cin>> col;
      for(auto i = 0 ; i < row; i++)
      {
        ptr[i] = new int[col];
      }
      cout<<"Add the elements to an array"<<endl;
      for(auto i = 0 ; i < row; i++)
      {
        for(auto j = 0; j < col; j++)
        {
          ptr[i][j] = ++i;
        }
      }

      cout<<"printing the array"<<endl;
      for(auto i = 0 ; i < row; i++)
      {
        for(auto j = 0; j < col; j++)
        {
          cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
      }
      cout<<"deleting the array"<<endl;
      for(auto i = 0 ; i < row; i++)
      {
        delete[] ptr[i];
      }
      delete [] ptr;
      ptr = NULL;
    }
    return 0;  
}
