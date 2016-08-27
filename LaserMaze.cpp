
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
#define  ll  long long
#define mod 1000000007
using namespace std;
char mat[109][109];
bool visit[4][109][109];
bool danger[4][109][109];
int n,m;

void init()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			visit[0][i][j]=visit[1][i][j]=visit[2][i][j]=visit[3][i][j]=0;
			danger[0][i][j]=danger[1][i][j]=danger[2][i][j]=danger[3][i][j]=0;
		}
	}
	return ;
}
//up->0 right->1 down->2 left->3
void markDanger(int x,int y,int dir,int num)
{
	if(dir==0)
	{
		for(int i=x-1;i>=0;i--)
		{
			if(mat[i][y]=='#' || mat[i][y]=='<' || mat[i][y]=='>' || mat[i][y]=='^' || mat[i][y]=='v')
				break;
			danger[num][i][y]=1;
		}
	}
	else if(dir==1)
	{
		for(int i=y+1;i<m;i++)
		{
			if(mat[x][i]=='#' || mat[x][i]=='<' || mat[x][i]=='>' || mat[x][i]=='^' || mat[x][i]=='v')
				break;
			danger[num][x][i]=1;
		}
	}
	else if(dir==2)
	{
		for(int i=x+1;i<n;i++)
		{
			if(mat[i][y]=='#' || mat[i][y]=='<' || mat[i][y]=='>' || mat[i][y]=='^' || mat[i][y]=='v')
				break;
			danger[num][i][y]=1;
		}
	}
	else
	{
		for(int i=y-1;i>=0;i--)
		{
			if(mat[x][i]=='#' || mat[x][i]=='<' || mat[x][i]=='>' || mat[x][i]=='^' || mat[x][i]=='v')
				break;
			danger[num][x][i]=1;
		}
	}
}
void preCompute()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]=='<')
			{
				markDanger(i,j,3,0);
				markDanger(i,j,0,1);
				markDanger(i,j,1,2);
				markDanger(i,j,2,3);
			}
			else if(mat[i][j]=='^')
			{
				markDanger(i,j,0,0);
				markDanger(i,j,1,1);
				markDanger(i,j,2,2);
				markDanger(i,j,3,3);
			}
			else if(mat[i][j]=='>')
			{
				markDanger(i,j,1,0);
				markDanger(i,j,2,1);
				markDanger(i,j,3,2);
				markDanger(i,j,0,3);
			}
			else if(mat[i][j]=='v')
			{
				markDanger(i,j,2,0);
				markDanger(i,j,3,1);
				markDanger(i,j,0,2);
				markDanger(i,j,1,3);
			}
		}
	}
	return ;
}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool isValid(int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<m && (mat[x][y]=='.'||mat[x][y]=='S'||mat[x][y]=='G') )
		return 1;
	return 0;
}
void print(int num)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",danger[num][i][j]);
		printf("\n");
	}
}
int main()
{
	int t,test;
	
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		cin>>n>>m;
		init();
		for(int i=0;i<n;i++)
			cin>>mat[i];
		
		preCompute();
	
		queue<int>X,Y,S,N;
		
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]=='S')
			{
				X.push(i);
				Y.push(j);
				S.push(0);
				N.push(0);
				visit[0][i][j]=1;
			}
		}
		int ans=INT_MAX;
	
		while(!X.empty())
		{
			int currx=X.front();
			int curry=Y.front();
			int currs=S.front();
			int num=N.front();
			X.pop();Y.pop();S.pop();N.pop();
			
		
			if(mat[currx][curry]=='G' && !danger[num][currx][curry])
			{
				ans=currs;break;
			}
			for(int i=0;i<4;i++)
			{
				int x,y;
				x=currx+dx[i];
				y=curry+dy[i];
				if(isValid(x,y) && !danger[(num+1)%4][x][y] && !visit[(num+1)%4][x][y])
				{
					visit[(num+1)%4][x][y]=1;
					X.push(x);
					Y.push(y);
					S.push(currs+1);
					N.push((num+1)%4);
				}
			}
			
			
		}
		if(ans==INT_MAX)
			printf("Case #%d: impossible\n",t);
		else
			printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
