#include<iostream>
#include<memory>
using namespace std;
struct A
{
    public:
    void print()
    {
        cout<<"this is struct A"<<endl;
    }
};

int main()
{


    shared_ptr<A> p1(new A());
    //shared_ptr<A> p1 = make_shared<A>();
    //shared_ptr<A> p1 = new A();
    p1->print();
    cout<<"Before calling destructor:"<<p1.use_count()<<endl;
    cout<<p1.get()<<endl;
    p1->~A();
    cout<<"After calling destructor:"<<p1.use_count()<<endl;
    cout<<p1.get()<<endl;
    shared_ptr<A> p2(p1);
    shared_ptr<A> p3 = p2;
    shared_ptr<A> p4 = move(p1);
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;
    cout<<p4.use_count()<<endl;
    cout<<p3.use_count()<<endl;
    return 0;
}
