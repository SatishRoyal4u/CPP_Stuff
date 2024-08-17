//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class unique_ptr
{
    private:
    T* ptr =nullptr;;
    public:
    unique_ptr(): ptr(nullptr){}
    unique_ptr(T* ptr=nullptr):ptr(ptr){}

    T& operator *()
    {
        return *ptr;
    }

    T* operator ->()
    {
        return ptr;
    }
    
    T* get()
    {
        return ptr;
    }
    
    T* release()
    {
        T* tmp;
        tmp=ptr;
        ptr=nullptr;
        return tmp;
    }
    
    void reset()
    {
        ptr =nullptr;
    }
    
    //copy constructor
    unique_ptr(const unique_ptr& obj) = delete;
    //assignment operator
    unique_ptr& operator = (const unique_ptr& obj) = delete;
    
    //move copy constructor
    unique_ptr(unique_ptr&&  obj){
        
        ptr =obj.ptr;
        obj.ptr=nullptr;
    }
    
    //move assignment operator
    unique_ptr& operator = (unique_ptr&& obj)
    {
        if(this != & obj)
        {
            delete ptr;
            ptr=obj.ptr;
            obj.ptr=nullptr;
        }
        return *this;
    }
    
    ~unique_ptr()
    {
        if(ptr != nullptr)
        {
            delete ptr;
            ptr =nullptr;
        }
    }
    
};

int main()
{
    {
        unique_ptr<int> ptr1(new int(40));
        cout<<"*ptr1:"<<*ptr1<<endl;
        cout<<"ptr1.get():"<<ptr1.get()<<endl;
       // cout<<"ptr1.release():"<<ptr1.release()<<endl;
        //ptr1.reset();
        
        unique_ptr<int> ptr2(new int(50));
        cout<<"*ptr2:"<<*ptr2<<endl;
        cout<<"ptr2.get():"<<ptr2.get()<<endl;
        //cout<<"ptr2.release():"<<ptr2.release()<<endl;
        //ptr1.reset();
        //cout<<"ptr1.reset():"<<ptr1.reset()<<endl;
        
        //ptr1=ptr2; 
        //unique_ptr<int> ptr3(ptr1);
        unique_ptr<int> ptr3(move(ptr1));
        cout<<"*ptr3:"<<*ptr3<<endl;
        cout<<"ptr3.get():"<<ptr3.get()<<endl;
        
        unique_ptr<int> ptr4(new int(60));
        cout<<"*ptr4:"<<*ptr4<<endl;
        cout<<"ptr4.get():"<<ptr4.get()<<endl;
        ptr1= move(ptr4);
         cout<<"*ptr1:"<<*ptr1<<endl;
        cout<<"ptr1.get():"<<ptr1.get()<<endl;
    }
    return 0;
}
