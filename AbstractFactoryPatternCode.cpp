 // Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class IButton
{
    public:
    virtual void press()=0;
};

class WindowsButton : public IButton
{
    public:
    void press(){
        cout<<"WindowsButton pressed"<<endl;
    }
};

class MacButton : public IButton
{
    public:
    void press(){
        cout<<"MacButton pressed"<<endl;
    }
};

class ITextBox
{
    public:
    virtual void showText()=0;
};

class WindowsTextBox : public ITextBox
{
    public:
    void showText(){
        cout<<"showing Windows TextBox"<<endl;
    }
};

class MacTextBox : public ITextBox
{
    public:
    void showText(){
        cout<<"showing Mac TextBox"<<endl;
    }
};

class IFactory{
    public:
    virtual IButton*  CerateButton()=0;
    virtual ITextBox*  CreateTextBox()=0;
};

class WinFactory : public IFactory
{
    public:
    IButton* CerateButton()
    {
        return  new WindowsButton();
    }
    
    ITextBox* CreateTextBox()
    {
        return new WindowsTextBox();
    }
};

class MacFactory : public IFactory
{
    public:
    IButton* CerateButton()
    {
        return  new MacButton();
    }
    
    ITextBox* CreateTextBox()
    {
        return new MacTextBox();
    }
};

class GUIAbstractFactory
{
    
    public:
    static IFactory* CreateFactory(string osType)
    {
        if(osType == "windows" )
        {
            return new WinFactory();
        }
        else if(osType =="mac")
        {
            return new MacFactory();
        }
        return new MacFactory();
    }
};

int main() {
  
  cout<<"Enter your machine OS Type"<<endl;
  string osType;
  cin>>osType;
  IFactory* fact = GUIAbstractFactory :: CreateFactory(osType);
  IButton* button =fact->CerateButton();
  button->press();
  ITextBox* textBox=fact->CreateTextBox();
  textBox->showText();
  return 0;
}
