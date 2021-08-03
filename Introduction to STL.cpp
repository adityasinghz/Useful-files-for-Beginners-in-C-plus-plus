#include <bits/stdc++.h>
using namespace std;
int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
#define  v  vector<int>
//code line
struct test
{
void operator()(int x){
    cout<<"square of the number: "<<x*x<<"\n\n";
}
};

int main()
{
//begin() and end()

v v1{1,2,3,4,3};
v ::iterator it;
it=v1.begin();
while(it!=v1.end())
{
    cout<<*it<<" ";
    it++;
}
cout<<"\n\n";


//find()

auto loc = find(v1.begin(),v1.end(),3);
if(loc!=v1.end())
{
cout<<"Found the number!\n"<<*loc<<"\n\n";
} 

// for_each()  //methods works in it

test square;
for_each(v1.begin(),v1.end(),square);
for_each(v1.begin(),v1.end(),[](int x){cout<<"Cube of the number: "<<x*x*x<<"\n";});

//reverse() //reverse the vector
cout<<"\n\n";
reverse(v1.begin(),v1.end());
for(auto a:v1){cout<<a<<"\n\n";}

//count()  //count the occurences

int num = count(v1.begin(),v1.end(),3);
cout<<"Occurences : "<<num<<"\n\n";

//count_if() //count the occurences if it satisfies the condition

int num1 = count_if(v1.begin(),v1.end(),[](int x){return x%2==0;});
cout<<"Satisfies the condition: "<<num1<<"\n\n";

//replace() //it replaces one number to another

replace(v1.begin(),v1.end(),1,100);
cout<<"Replacing\n";
for(auto a:v1)
cout<<a<<" ";



//all_of() //tests all the conditions in better manner!
cout<<"\n\n";
v v2{1,2,4,5,2,1};
if(all_of(v2.begin(),v2.end(),[](int x){ return x<4; }))
cout<<"Numbers are <5\n";
else
cout<<"Not all Numbers are <5\n\n";

//any_of() if any of the element satisfies the condition then it will return true;
v v3{1,2,0,32,5,7};
if(any_of(v3.begin(),v3.end(),[](int x){return x<10;}))
cout<<"Some elements are satisfying the condition\n";
else
cout<<"None of the elements\n\n";

//traansform()

string s{"Just for Test\n"};
cout<<"Before Transform\n";
transform(s.begin(),s.end(),s.begin(),::toupper);
putchar(toupper(s[0]));
cout<<"After transform: "<<s;
}
