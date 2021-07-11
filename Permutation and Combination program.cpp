#include <iostream> // header file includes every Standard library
#include<string>
#include<vector>
using namespace std;

//move constructor 
class Permutation{
int n;
int r;
public:
Permutation();
Permutation(int  , int );
int factorial(int);
};

Permutation::Permutation(){                         //Default Constructor
n=0; r=0;
}
Permutation::Permutation(int num , int rn )         //Parametarised Constructor
:n{num}, r{rn}{
cout<<" Perametrized constructor "<<endl;
}
int Permutation::factorial(int n)                      // Recursion function
{
if(n==0||n==1)
return 1;
else
return n*factorial(n-1);
}



int main()
{
int num ,  rn;
cout<<"Write the value of n : ";
cin>>num;
cout<<"Write the total number of selection which we have to arrange : ";
cin>>rn;
Permutation p{num , rn};
int d= num - rn;

cout<<"Total number of permutation is : "<<p.factorial(num)/p.factorial(d)<<endl;
cout<<"Combination = nPr/r!\n";
cout<<"Total number of combination after selecting "<<rn<<" from "<<num<<" number of things is : "
<<p.factorial(num)/p.factorial(d)*1/p.factorial(rn)<<'\n';
}
