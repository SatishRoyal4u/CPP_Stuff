//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef unsigned int unit;
template<typename T>
class vector
{
    private:
    size_t m_size =0;
    size_t m_capacity =0;
    T* m_arr = nullptr;
    public:
    vector():m_size(0),m_capacity(0),m_arr(nullptr){}
    vector(size_t size): m_size(size), m_capacity(size), m_arr(new T[m_size]){}
    vector(size_t size, int default_value) : m_size(size), m_capacity(size), m_arr(new T[m_size]) {
        for(auto i=0; i < m_size ; i++)
        {
            m_arr[i]=default_value;
        }
    }
    
    uint size()
    {
        return m_size;
    }
    
    uint capacity()
    {
        return m_capacity;
    }
    
    T&  operator [](int index)
    {
        return m_arr[index];
    }
    
    T& front()
    {
        return m_arr[0];
    }
    
    T& back()
    {
        return m_arr[m_size-1];
    }
    
    T* begin()
    {
        return m_arr;
    }
    
    T* end()
    {
        return m_arr + size();
    }
    
    bool empty()
    {
        return m_size == 0;
    }
    
    void reserve(int capacity)
    {
        if(m_arr == nullptr)
        {
            m_size = 0;
            m_capacity = 0;
        }
        
        T* newarr = new int[capacity];
        for(auto i =0; i < m_size; i++)
        {
            newarr[i] =m_arr[i];
        }
        
        delete [] m_arr;
        m_arr= newarr;
        m_capacity=capacity;
        
    }
    
    void push_back(const T& value)
    {
        if(m_capacity == 0)
           reserve(8);
        
        else if(m_size == m_capacity)
            reserve(2*m_capacity);
        else
           m_arr[m_size++] =value;
    }
    
    void pop_back()
    {
        
        m_size--;
    }
};

int main() {
    
	auto block_index =0;
	{
	    cout<<"BLOCK-"<<++block_index<<endl;
	    vector<int> v;
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    v.push_back(10);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    v.push_back(20);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    v.push_back(30);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    v.push_back(40);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	     v.push_back(50);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    cout<<"v.empty():"<<v.empty()<<endl;
	}
	
	{
	    cout<<"BLOCK-"<<++block_index<<endl;
	    vector<int> v(5);
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	}
	
	{
	    cout<<"BLOCK-"<<++block_index<<endl;
	    vector<int> v(5,0);
	    for(auto i =0; i < v.size();  i++)
	    {
	        cout<<v[i]<<"\t";
	    }
	    cout<<endl;
	    cout<<"v.size():"<<v.size()<<endl;
	    cout<<"v.capacity():"<<v.capacity()<<endl;
	    cout<<endl;
	    cout<<"v.front():"<<v.front()<<endl;
	    cout<<"v.back():"<<v.back()<<endl;
	    cout<<"v.begin():"<<v.begin()<<endl;
	    cout<<"v.end():"<<v.end()<<endl;
	}
	return 0;
}
