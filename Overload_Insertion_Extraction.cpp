#include<bits/stdc++.h>
using namespace std;
class cmp
{
    private:
        int real;
        int img;
    public:
        cmp():real(0),img(0)
        {
           cout<<"Default Constructor is called"<<endl;
        }
        friend ostream& operator << (ostream& out , cmp& c);
        friend istream& operator >> (istream& in , cmp& c);
};

istream& operator >> (istream& in, cmp& c )
{
    cout<<"enter real part"<<endl;
    in>>c.real;
    cout<<"enter img part"<<endl;
    in>>c.img;
}

ostream& operator << (ostream& out, cmp& c)
{
    cout<<"the complex number is"<<endl;
    out<<c.real<<"+"<<" "<<c.img<<endl;
}
int main()
{
    cmp c1;
    cin >> c1;
    cout << c1;
    return 0;
}
