#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<set>
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;

bool check(string str,int i)
{
	if(str.size()==1 && str[0]=='.')
		return true;
	
	if(i==0 && str[i]=='.' && str[i+1]!='.')
		return true;
	
	if(i==str.size()-1 && str[str.size()-1]=='.' && str[str.size()-2]!='.')
		return true;
	
	if(str[i]=='.' && str[i-1]!='.' && str[i+1]!='.')
		return true;
	return false;
}

bool mark(string &str,int i)
{
	if(str[i]=='.')
	{
		for(int j=i;j>=0 && str[j]=='.';j--)
			str[j]='X';
		for(int j=i+1;j<str.size() && str[j]=='.';j++)
			str[j]='X';
		return true;
	}
	return false;
}
int main()
{
	int test,t,n;
	cin>>test;
	string str[2];
	for(t=1;t<=test;t++)
	{
		cin>>n>>str[0]>>str[1];
		int c=0;
		
		for(int i=0;i<n;i++)
		{
			if(str[0][i]=='.')
			{
				c++;
				while(i<n && str[0][i]=='.')
					i++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(str[1][i]=='.')
			{
				c++;
				while(i<n && str[1][i]=='.')
					i++;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(check(str[0],i) && mark(str[1],i))
				c--;
				
		}
		for(int i=0;i<n;i++)
		{
			if(check(str[1],i) && mark(str[0],i))
				c--;
		}
		printf("Case #%d: %d\n",t,c);
	}
	return 0;
}

