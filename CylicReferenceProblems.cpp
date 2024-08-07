#include<bits/stdc++.h>
using namespace std;
class A
{
private:
//shared_ptr<A> adj;-->causing cylic reference problem
weak_ptr<A> adj; //fixing the cyclic refernce problem
public:
A()
{
    cout<<"A:: A()"<<endl;
}
~A()
{
    cout<<"A:: ~A()"<<endl;
}

void setAdjacency(shared_ptr<A> ptr)
{
    adj =ptr;
}
void print()
{
    cout<<"this is print function"<<endl;
}

};

int main()
{ 
   shared_ptr<A> sp1( new A());
   shared_ptr<A> sp2(new A());
   weak_ptr<A> wp1(sp1);
   wp1.lock()->print();
   cout<<sp1.get()<<endl;
   cout<<sp2.get()<<endl;
   sp1->print();
   sp2->print();
   cout<<sp1.use_count()<<endl;
   sp1->setAdjacency(sp2);
   sp2->setAdjacency(sp1);
   cout<<sp2.use_count()<<endl;
    return 0;
}
