#include<bits\stdc++.h>
using namespace std;

class MOVE_ASSIGNMENT_OPERATOR{
char *str;
public:
MOVE_ASSIGNMENT_OPERATOR(); //DEFAULT CONSTRUCTOR
MOVE_ASSIGNMENT_OPERATOR(const char*s); //INITIALIZER
MOVE_ASSIGNMENT_OPERATOR(MOVE_ASSIGNMENT_OPERATOR &&source);  //MOVE CONSTRUCTOR
MOVE_ASSIGNMENT_OPERATOR &operator=(MOVE_ASSIGNMENT_OPERATOR &&rhs);//ASSIGNMENT OVERLOADING
~MOVE_ASSIGNMENT_OPERATOR();//DESTRUCTOR
};
MOVE_ASSIGNMENT_OPERATOR:: MOVE_ASSIGNMENT_OPERATOR()
:str{nullptr}{
 static int count=0;
 count++;
 cout<<" default constructor is been called "<<endl;
 str= new char[1];
 *str='\0';
}
MOVE_ASSIGNMENT_OPERATOR::MOVE_ASSIGNMENT_OPERATOR(const char*c)
:str{nullptr}{
cout<<" Constructor Initializer is been called  "<<endl;
str=new char[strlen(c)+1];
strcpy(str,c);
}
MOVE_ASSIGNMENT_OPERATOR::MOVE_ASSIGNMENT_OPERATOR(MOVE_ASSIGNMENT_OPERATOR &&source)
:str(source.str){
 cout<<" MOVE constructor is been callled "<<endl;
source.str=nullptr;
}
MOVE_ASSIGNMENT_OPERATOR &MOVE_ASSIGNMENT_OPERATOR :: operator =(MOVE_ASSIGNMENT_OPERATOR &&rhs)
{
 cout<<" Assignment Overloading is been called "<<endl;
if(this==&rhs)
return *this;
delete[] this->str;
str=rhs.str;
rhs.str=nullptr;
return *this;
}
MOVE_ASSIGNMENT_OPERATOR::~MOVE_ASSIGNMENT_OPERATOR()
{
 cout<<" Destructor is been called "<<endl;
delete[] str;
}
int main() {
MOVE_ASSIGNMENT_OPERATOR OBJ1{"MOVE"};
MOVE_ASSIGNMENT_OPERATOR OBJ2="HII";
MOVE_ASSIGNMENT_OPERATOR OBJ3;
OBJ1=OBJ2;                                        //This willn't work for move constructor because OBJ2 IS AN L value So for that we have to add a copy constructor
}
