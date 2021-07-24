#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ROW 100
#define COL 100


// To check valid row or column
bool check(int a,int b,int len)
{
	if(a < 0 || b < 0 || a >= len || b >= len)
		return false;
	return true;
}


stack<pair<int,int>> s;
int visited[ROW][COL];

bool pat(char arr[][COL],string word,int r,int c,int index,int len)
{
	//First letter is not same or checking first cell visited or not
	if(visited[r][c] != 0 || word[index] != arr[r][c])
		return false;
	
	//If word is found
	if(index == word.length()-1)
	{
		visited[r][c] = 1;
		return true;
	}
	
	visited[r][c] =  1;
	
	
	//Down
	if(check(r+1,c,len) && pat(arr,word,r+1,c,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
		
	//Up
	if(check(r-1,c,len) && pat(arr,word,r-1,c,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Right
	if(check(r,c+1,len) && pat(arr,word,r,c+1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Left
	if(check(r,c-1,len) && pat(arr,word,r,c-1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Diagonal Up right
	if(check(r-1,c+1,len) && pat(arr,word,r-1,c+1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Diagonal Up left
	if(check(r-1,c-1,len) && pat(arr,word,r-1,c-1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Diagonal Down left
	if(check(r+1,c-1,len) && pat(arr,word,r+1,c-1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//Diagonal Down right
	if(check(r+1,c+1,len) && pat(arr,word,r+1,c+1,index+1,len))
	{
		s.push(make_pair(r,c));
		return true;
	}
	
	//To backtrack
	visited[r][c] = 0;
	return false;
	
}



int main()
{
	char arr[ROW][COL];
	int i,j,k,n;
	string word;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	cin>>word;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			visited[i][j] = 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			pat(arr,word,i,j,0,n);
		}
	}
	if(s.empty() == true)
		cout<<-1;
	else
	{
		while(!s.empty())
		{	
			pair<int,int> temp = s.top();
			cout<<temp.first<<temp.second<<" ";
			s.pop();
		}
	}
}
