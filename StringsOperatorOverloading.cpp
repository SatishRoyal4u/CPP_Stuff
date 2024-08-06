#include<bits/stdc++.h>
using namespace std;
class String
{
    private:
        char* ptr;
        int len;
    public:
        String()
        {
            cout<<"default construcotr is called"<<endl;
            ptr=NULL;
            len=0;
        }

        String(const char* ptr)
        {
            cout<<"parameterized  construcotr is called"<<endl;
            len= strlen(ptr);
            this->ptr = new char[len+1];
            strcpy(this->ptr,ptr);
        }

        ~String()
        {
           cout<<"default destrucotr is called"<<endl;
           delete ptr;
           ptr=NULL;
        }

        String(const String& ob)
        {
            cout<<"copy  construcotr is called"<<endl;
            len = ob.len;
            ptr = new char[len +1];
            strcpy(ptr, ob.ptr);
        }

        String& operator = (const String& ob)
        {
            cout<<"assignment construcotr is called"<<endl;
            if(this != &ob)
            {
                len = ob.len;
                delete [] ptr;
                ptr = new char[len +1];
                strcpy(ptr, ob.ptr);
            }
            
        }

        bool  operator == (const String& ob)
        {
            if(this->len == ob.len)
            {
                if(strcmp(this->ptr,ob.ptr)== 0)
                {
                    cout<<"strings are equal"<<endl;
                    return true;
                }
            }
            cout<<"strings are not equal"<<endl;
            return false;
        }

        String  operator + (const String& ob)
        {
           String s;
           s.ptr = new char[this->len + ob.len + 1];
           strcpy(s.ptr,ptr);
           strcat(s.ptr,ob.ptr);
           s.len = len + ob.len;
           return s;
        }

        void show()
        {
            cout<<ptr<<endl;
        }

};
int main()
{
    {
        cout<<"BLOCK-1"<<endl;
        String s1;
    }
    {
        cout<<"BLOCK-2"<<endl;
        String s1("SATISH");
    }
    {
        cout<<"BLOCK-3"<<endl;
        String s1("SATISH");
        String s2(s1);
    }
    {
        cout<<"BLOCK-4"<<endl;
        String s1("SATISH");
        s1.show();
        String s2("YADUVANSHI");
        s2.show();
        s1=s2;
        s1.show();
    }
    {
        cout<<"BLOCK-5"<<endl;
        String s1("SATISH");
        s1.show();
        String s2("YADUVANSHI");
        s2.show();
        s1==s2;
        //s1.show();
    }
    {
        cout<<"BLOCK-6"<<endl;
        String s1("SATISH");
        s1.show();
        String s2("YADUVANSHI");
        s2.show();
        String s3 = s1 + s2;
        s1.show();
        s2.show();
        s3.show();
    }

    return 0;
}
