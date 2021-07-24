#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ROW 100
#define COL 100

int solution[ROW][COL];


bool possible(int r,int c,int n)
{
	for(int i = 0;i < c; i++)
	{
		if(solution[r][i] == 1)
			return false;
	}
	
	for(int i = r,j = c; i >= 0 && j >= 0; i--, j--)
	{
		if(solution[i][j] == 1)
			return false;
	}
	
	for(int i = r,j = c;i < n && j >= 0; i++,j--)
	{
		if(solution[i][j] == 1)
			return false;
	}
	
	return true;
	
}


bool n_queen(int queen,int n)
{
	if(queen == n)
	{
		return true;
	}
	for(int row = 0;row < n; row++)
	{
		if(possible(row,queen,n))
		{
			solution[row][queen] = 1;
			if(n_queen(queen+1,n))
				return true;
			solution[row][queen] = 0;
		}
	}
	return false;
}


int main()
{
	int i,j,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			solution[i][j] = 0;
		}
	}
	if(n_queen(0,n))
	{
		for(i=0;i<n;i++)
		{	
			for(j=0;j<n;j++)
			{
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
		}	
	}
	else
		cout<<"No Possible way";
	return 0;
	
}
