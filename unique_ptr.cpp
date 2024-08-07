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
   // unique_ptr<A> ptr1 = new A();
   // unique_ptr ptr1 = make_unique<A>();
    unique_ptr<A> ptr1(new A());
    ptr1->print();
    //cout<<ptr1.use_count()<<endl;
    cout<<ptr1.get()<<endl;
    unique_ptr<A> ptr2(ptr1.release());
    cout<<ptr1.get()<<endl;
    cout<<ptr2.get()<<endl;
    unique_ptr<A> ptr3= move(ptr2);
    cout<<ptr1.get()<<endl;
    cout<<ptr2.get()<<endl;
    cout<<ptr3.get()<<endl;
    return 0;
}
