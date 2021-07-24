#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ROW 100
#define COL 100



int solution[ROW][COL];
int arr[ROW][COL];

//Checking validity of updated row and column
bool check(int a,int b,int size)
{
	if(a < 0 || b < 0 || a >= size || b >= size || arr[a][b] == 0)
		return false;
	return true;
}


bool path(int r, int c, int d_r, int d_c , int n, string dir)
{
	//destination reached or not check
	if(r == d_r && c == d_c)
	{
		solution[r][c] = 1;
		return true;
	}
	//Checking validity
	if(check(r,c,n))
	{
		solution[r][c] = 1;
		
		//Go down
		if(dir != "up" && path(r+1,c,d_r,d_c,n,"down"))
			return true;
			
		//Go up
		if(dir != "down" && path(r-1,c,d_r,d_c,n,"up"))
			return true;	
		
		//Go right
		if(dir != "left" && path(r,c+1,d_r,d_c,n,"right"))
			return true;
		
		//Go left
		if(dir != "right" && path(r,c-1,d_r,d_c,n,"left"))
			return true;
		
		//If no path backtrack the solution value
		solution[r][c] = 0;
		return false;
	}
	return false;
}


int main()
{
	int i,j,n,src,dest;
	cin>>n;
	//solution matrix to keep track of solution
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
			solution[i][j] = 0;
		}
	}
	//Traverse from (0,0) -> (src,dest)
	cin>>src>>dest;
	if(path(0,0,src,dest,n,"down"))
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
		cout<<"No path found";
	return 0;
}
