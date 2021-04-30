#include<iostream>
#include<iostream>
using namespace std;
//Creating class Complex

//template<typename T>;
class Complex{
int real;
int imaginary;
int real_imaginary;
int real_imaginary1;
int denominator;
public:
Complex();
Complex(int r , int i);
Complex operator+(Complex &c);
Complex operator-(Complex &c);
Complex operator*(Complex &c);
Complex operator/(Complex &c);
string print();
string prod_print();
void div_print();
};
void Complex::div_print()
{
   int real_imaginary_sub=real-imaginary;
   int imaginary_real_sub=real_imaginary+real_imaginary1;
   string s=to_string(real_imaginary_sub);
   string s1=to_string(imaginary_real_sub);
   string s2=to_string(denominator);
   string s3=s +" + "+ s1+"i";
   cout<<s3+"/"+s2;
}
Complex Complex ::operator/(Complex &c)
{
Complex temp;
temp.real=c.real*real;
temp.imaginary=(-c.imaginary)*imaginary;
temp.real_imaginary=real*(-c.imaginary);
temp.real_imaginary1=c.real*imaginary;
temp.denominator=c.real*c.real-c.imaginary*c.imaginary;
return temp;
}
string Complex :: prod_print()
{
   int real_imaginary_sub=real-imaginary;
   int imaginary_real_sub=real_imaginary+real_imaginary1;
   string s=to_string(real_imaginary_sub);
   string s1=to_string(imaginary_real_sub);
   string s3=s +" + "+ s1;
   return s3;
}

Complex Complex::operator*(Complex &c)
{
Complex temp;
temp.real=c.real*real;
temp.imaginary=c.imaginary*imaginary;
temp.real_imaginary=real*c.imaginary;
temp.real_imaginary1=c.real*imaginary;
return temp;
}
string Complex:: print()
{
string s=to_string(real);
string s1=to_string(imaginary);
string s2=s+" + "+s1;
return s2;
}

Complex::Complex()
{
real=0; imaginary=0;
}
Complex::Complex(int r , int i)
{
real=r; imaginary=i;
}
Complex Complex:: operator+(Complex &c)
{
Complex temp;
temp.real=real+c.real;
temp.imaginary=imaginary+c.imaginary;
return temp;
}
Complex Complex:: operator-(Complex &c)
{
    Complex temp;
    temp.real=real-c.real;
    temp.imaginary=imaginary-c.imaginary;
    return temp;
}

int main ()
{
int x , y;
cout<<"Enter 1st complex value : ";
cin>>x>>y;
Complex a(x,y);
cout<<"Enter 2nd complex value : ";
cin>>x>>y;
Complex b(x,y);
Complex c;
c=a+b;
cout<<c.print()<<"i"<<'\n';
c=a-b;
cout<<c.print()<<"i"<<'\n';
c=a*b;
cout<<c.prod_print()<<"i"<<'\n';\
c=a/b;
c.div_print();
}
