// CPP program to count words in a string
// using stringstream.
#include <bits/stdc++.h>
using namespace std;

class Test{
public:
void Normal_Fumction()//Just a normal method
{
    cout<<"Hi I am a Base class normal Method\n";
}
virtual void Virtual_Function()//It tells compiler to do step binding in runtime so that the Base class pointer which is assigned as Derived class won't get confused.
{
cout<<"Hii I am a Base class Virtual Function\n";
}
virtual void Override_Function() const// Override is used when we have to get those method from those class which is called from int main(); 
{
cout<<"Hii I am a Base class Overriden Function\n";
}
virtual void Final_Specifier_Function() final  // Final specifier works only when the function is virtual, and it will give u error when u try to derive a function of same name in any derived class;
{
cout<<"Hi I am a Base class Final sprcifier Function\n";
}
};
class Test1 final : public Test{  //here I'm using final specifier so that I couldn't derive any other class from Test class as you can see in line number 21 we are getting error
public:
void Normal_Function()
{
    cout<<"Hi I am a Derived class normal Method\n";
}
virtual void Virtual_Function()
{
    cout<<"Hii I am a Derived class Virtual Function\n";
}
virtual void Override_Function() const override //once remove "const override" then you can see the actual meaning of override
{
    cout<<"Hii I am a Derived class Overriden Function\n";
}
virtual void Final_Specifier_Function() // Giving an error because I'm redefining a final specifier function //remove this line if you want to run the program
{
    cout<<"Hi I am a Base class Final sprcifier Function\n";
}

};
class Test2 final :public Test1  //error message because we are deriving from a final class; //remove this line if you want to run the program
{

};



int main()
{
Test *test = new Test();
Test *test1 = new Test1();
vector<Test*>arr{test,test1};
for(int i=0 ; i<arr.size() ; i++)
{
    arr[i]->Normal_Fumction();
    arr[i]->Virtual_Function();
    arr[i]->Override_Function();
}

}
