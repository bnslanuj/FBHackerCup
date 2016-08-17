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

int arr[20][20];
int temp[20][20];
void toggle(int x,int y,int mat[][20],int r,int c)
{
	mat[x][y]^=1;
	if(x-1>=1)
		mat[x-1][y]^=1;
	if(y-1>=1)
		mat[x][y-1]^=1;
	if(y+1<=c)
		mat[x][y+1]^=1;
	if(x+1<=r)
		mat[x+1][y]^=1;
	return ;
}
int main()
{
	int t,tt,r,c;
	scanf("%d",&tt);
	
	for(t=1;t<=tt;t++)
	{
		scanf("%d%d",&r,&c);
		string str;
		for(int i=1;i<=r;i++)
		{
			cin>>str;
			for(int j=1;j<=c;j++)
			{
				if(str[j-1]=='X')
					arr[i][j]=1;
				else arr[i][j]=0;
			}
		}
		int ans=INT_MAX;
		for(int i=0;i<(1<<c);i++)
		{
			//make copy.
			for(int j=1;j<=r;j++)
			for(int k=1;k<=c;k++)
				temp[j][k]=arr[j][k];
			
			int count=0;
			
			for(int j=1;j<=c;j++)
			{
				if(((1<<(j-1))&i) && temp[1][j]==0)
				{
					count++;
					toggle(1,j,temp,r,c);
				}
				else if(!((1<<(j-1))&i) && temp[1][j])
				{
					count++;
					toggle(1,j,temp,r,c);
				}
			}
			
			for(int j=2;j<=r;j++)
			{
				for(int k=1;k<=c;k++)
				{
					if(temp[j-1][k]==0)
					{
						count++;
						toggle(j,k,temp,r,c);
					}
				}
			}
			bool isDone=1;
			for(int j=1;j<=c;j++)
			{
				if(temp[r][j]==0)
				{
					isDone=0;break;
				}
			}
			if(isDone)
				ans=min(ans,count);
		}
		if(ans==INT_MAX)ans=-1;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
