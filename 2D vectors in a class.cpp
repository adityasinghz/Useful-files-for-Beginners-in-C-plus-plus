#include<bits/stdc++.h>
using namespace std;

  
class Matrix {
int n,m;
vector<vector<int>>a;
public:
Matrix();
void method();
};
Matrix::Matrix()
{
    int input;
    vector<int>b;
    cout<<"Enter Size of Matrix : ";
    cin>>n>>m;   
    for(int i=0 ;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>input;
            b.push_back(input);
        }
        a.push_back(b);
    }
    
}
void Matrix::method()
{
    cout<<"The matrix is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main()
{
Matrix m;
m.method();
}
