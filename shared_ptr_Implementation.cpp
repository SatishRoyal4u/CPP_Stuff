//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef unsigned int uint;
template<typename T>
class shared_ptr
{
    private:
    T* ptr = nullptr;
    uint* ref_count = nullptr;
    
    void __cleanup__()
    {
        (*ref_count)--;
        if(*ref_count == 0)
        {
            if( ptr != nullptr)
            {
                delete ptr;
            }
            
            if( ref_count != nullptr)
            {
                delete ref_count;
            }
        }
    }
    public:
    //default constructor
    shared_ptr(): ptr(nullptr), ref_count(nullptr){}
    //parameterized constructor
    shared_ptr(T* ptr = nullptr): ptr(ptr),ref_count(new uint(1)){}
    //copy constructor
    shared_ptr(const shared_ptr& obj)
    {
        ptr = obj.ptr;
        ref_count= obj.ref_count;
        *ref_count+= 1;
    }
    //assignment constructor
    shared_ptr& operator = (const shared_ptr& obj)
    {
        if(this != &obj)
        {
            __cleanup__();
            ptr = obj.ptr;
            ref_count= obj.ref_count;
           *ref_count+= 1;
        }
        return *this;
    }
    
    //move copy constructor
    shared_ptr(shared_ptr&& DyingObj)
    {
        ptr = DyingObj.ptr;
        ref_count= DyingObj.ref_count;
        DyingObj.ptr=nullptr;
        DyingObj.ref_count= nullptr;
        
    }
    
    //move assignment constructor
     shared_ptr& operator = (shared_ptr&& DyingObj)
    {
        if(this != &DyingObj)
        {
            __cleanup__();
            ptr = DyingObj.ptr;
            ref_count= DyingObj.ref_count;
            DyingObj.ptr=nullptr;
            DyingObj.ref_count= nullptr;
        }
        return *this;
    }
    
    
    T* get()
    {
        return ptr;
    }
    
    T& operator * ()
    {
        return *ptr;
    }
    
    T* operator -> ()
    {
        return ptr;
    }
    
    uint use_count()
    {
        if(ref_count != nullptr)
        {
          return *ref_count;  
        }
        return 0;
    }
    
    ~shared_ptr()
    {
        __cleanup__();
    }
};

int main()
{
    
    {
        cout<<"BLOCK-1:"<<endl;
        shared_ptr<int> sp1(new int(10));
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
    }
    
    {
        cout<<"BLOCK-2:"<<endl;
        shared_ptr<int> sp1(new int(10));
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
        shared_ptr<int> sp2(sp1);
        cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
    }
    
    {
        cout<<"BLOCK-3:"<<endl;
        shared_ptr<int> sp1(new int(10));
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
        shared_ptr<int> sp2(sp1);
        cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
    }
   
    {
        cout<<"BLOCK-4:"<<endl;
        shared_ptr<int> sp1(new int(10));
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
        
        shared_ptr<int> sp2(new int(10));
        cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        sp1=sp2;
        cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
    }
    
    {
        cout<<"BLOCK-5:"<<endl;
        shared_ptr<int> sp1(new int(10));
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
        
        shared_ptr<int> sp2(new int(70));
        cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        sp1=move(sp2);
        //cout<<"*sp2:"<<*sp2<<endl;
        cout<<"sp2.get():"<<sp2.get()<<endl;
        cout<<"sp2.use_count():"<<sp2.use_count()<<endl;
        cout<<"*sp1:"<<*sp1<<endl;
        cout<<"sp1.get():"<<sp1.get()<<endl;
        cout<<"sp1.use_count():"<<sp1.use_count()<<endl;
    }
    
    return 0;
}
