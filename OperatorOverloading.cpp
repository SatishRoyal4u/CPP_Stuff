#include<bits/stdc++.h>
using namespace std;
class Value
{
    private:
        int val;
    public:
    Value()
    {
        cout<<"default construcotr is called"<<endl;
        val =0;
    }
    Value(int val)
    {
        cout<<"parameterized construcotr is called"<<endl;
        this->val =val;
    }

    //pre increment
    Value operator ++ ( )
    {
        cout<<"pre increment operator function is called"<<endl;
        Value temp;
        temp.val = ++val;
        return temp;
    }
    //post increment
    Value operator ++ (int )
    {
        cout<<"post increment operator function is called"<<endl;
        Value temp;
        temp.val = val++;
        return temp;
    }
    //pre decrement
    Value operator -- ( )
    { 
        cout<<"pre decrement operator function is called"<<endl;
        Value temp;
        temp.val = --val;
        return temp;
    } 
    //post decrement
    Value operator -- (int )
    {
        cout<<"post decrement operator function is called"<<endl;
        Value temp;
        temp.val = val--;
        return temp;
    }
     
    void display()
    {
        cout<<"value:"<<val<<endl;
    }

    ~Value()
    {
        cout<<"default destrucotr is called"<<endl;
    }
};
int main()
{
    {
        cout<<"perform pre-increment operation"<<endl;
        Value ob1(5);
        ob1.display();
        Value ob2 = ++ob1;
        ob1.display();
        ob2.display();

    }
    {
        cout<<"perform post-increment operation"<<endl;
        Value ob1(5);
        ob1.display();
        Value ob2 = ob1++;
        ob1.display();
        ob2.display();

    }


     {
        cout<<"perform pre-decrement operation"<<endl;
        Value ob1(10);
        ob1.display();
        Value ob2 = --ob1;
        ob1.display();
        ob2.display();

    }
    {
        cout<<"perform post-decrement operation"<<endl;
        Value ob1(10);
        ob1.display();
        Value ob2 = ob1--;
        ob1.display();
        ob2.display();

    }

    return 0;
}
