#include<bits/stdc++.h>
using namespace std;

class Unary_Binary_Overloading 
{
char *str;
public:
Unary_Binary_Overloading();
Unary_Binary_Overloading(const Unary_Binary_Overloading &source);
Unary_Binary_Overloading(const char *s);
Unary_Binary_Overloading(Unary_Binary_Overloading &&source);
/*from line 13 the Unary_Binary_Overloading  is a return type which returns an object*/
Unary_Binary_Overloading operator -() const; //Parenthesis must be empty for unary operators
Unary_Binary_Overloading operator +(const Unary_Binary_Overloading &rhs) const;
bool operator==(const Unary_Binary_Overloading &rhs) const;
void display();
int  get_length() const;
};


Unary_Binary_Overloading::Unary_Binary_Overloading()
:str{nullptr}{
str=new char[1];
str='\0';
}
Unary_Binary_Overloading::Unary_Binary_Overloading(const char*s)
:str{nullptr}{
str=new char[strlen(s)+1];
strcpy(str,s);
}
Unary_Binary_Overloading::Unary_Binary_Overloading(const Unary_Binary_Overloading &source)
:str{source.str}{
str=new char[strlen(source.str)+1];
strcpy(str,source.str);
}
Unary_Binary_Overloading::Unary_Binary_Overloading(Unary_Binary_Overloading &&source)
:str{source.str}{
str=source.str;
source.str=nullptr;
}
Unary_Binary_Overloading Unary_Binary_Overloading::operator-() const
{
char *buff=new char[strlen(str)];
strcpy(buff,str);
for(int i=0;i<strlen(buff);i++)
buff[i]=tolower(buff[i]); 
Unary_Binary_Overloading temp{buff};     //we made this to return buff's lower in terms of object
delete[] buff;
return temp;
}

Unary_Binary_Overloading Unary_Binary_Overloading::operator+(const Unary_Binary_Overloading &rhs)const
{
char *buff=new char [strlen(str) + strlen(rhs.str) + 1];
strcpy(buff,str);
strcat(buff,rhs.str);
Unary_Binary_Overloading temp{buff};
delete[] buff;
return temp;
}

bool Unary_Binary_Overloading::operator==(const Unary_Binary_Overloading &source) const
{
 return (strcmp(str,source.str)==0);   
}
void Unary_Binary_Overloading:: display()
{
    cout<<"str length is : "<<get_length()<<endl;
}
int Unary_Binary_Overloading::get_length() const
{
    return strlen(str);
}
int main(){
cout<<boolalpha<<endl;
Unary_Binary_Overloading Aditya{"Aditya"};
Unary_Binary_Overloading Singh{"Singh"};
Unary_Binary_Overloading MyName=Aditya;
Aditya.display();
Singh.display();
cout<<(Aditya==Singh)<<endl;
cout<<(Aditya==MyName)<<endl;
Aditya.display();
Unary_Binary_Overloading Aditya2= -Aditya;
Aditya2.display();
Unary_Binary_Overloading Full=Aditya + "Bhai";
//Unary_Binary_Overloading two_Names="Singh"+Aditya; //Compiler Error
Unary_Binary_Overloading two_Names=Aditya+" "+"Singh"; //Strings must be written after + assignment
two_Names.display();
}
 
