/*
WHY WE USE ASSIGNMENT OPERATOR OVERLOADING?
*/
#include<bits\stdc++.h>
using namespace std;

class Assignment_Overloading
{
char *str;                                       //attribute
public:
Assignment_Overloading(); //Default Constructor
Assignment_Overloading(const char *s); //Constructor Overloading 
Assignment_Overloading(const Assignment_Overloading &source); //Copy Constructor
Assignment_Overloading &operator=(const Assignment_Overloading &rhs);//Assignment Overloading
~Assignment_Overloading(); // Destructor
//methods


};
Assignment_Overloading::Assignment_Overloading()
:str{nullptr}{
str=new char[1];
*str='\0';
}
Assignment_Overloading::Assignment_Overloading(const char *s)
:str{nullptr}{
if(s==nullptr){
    str=new char[1];
    *str='\0';
}
else{
    str=new char[strlen(s)+1];
    strcpy(str,s);
}
}
Assignment_Overloading::Assignment_Overloading(const Assignment_Overloading &source)
:str{nullptr}{
str=new char[strlen(source.str)+1];
strcpy(str,source.str);
}
Assignment_Overloading::~Assignment_Overloading()
{
cout<<str<<" you Destroyed!"<<endl;
delete [] str;
}
Assignment_Overloading &Assignment_Overloading::operator=(const Assignment_Overloading &rhs)
{
cout<<"Assignment Overloading is launched !! "<<endl;
if(this==&rhs)
return *this;
delete [] this->str;
str=new char[strlen(rhs.str)+1];
strcpy(this->str,rhs.str);
return *this;
}

int main() {
Assignment_Overloading a{"Aditya SINGH"};
Assignment_Overloading b;
Assignment_Overloading c;
b=a;
c="I am Going to get Copied ! ";
}
