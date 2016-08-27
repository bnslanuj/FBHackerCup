
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

int main()
{
	int n,t,test,gp,gc,gf;
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		cin>>gp>>gc>>gf>>n;
		
		vector<int>p(n),c(n),f(n);
		
		for(int i=0;i<n;i++)
			cin>>p[i]>>c[i]>>f[i];
		bool isDone=0;
		for(int i=1;i<(1<<n);i++)
		{
			int k,j,tc=0,tf=0,tp=0;
			
			j=i;k=0;
			while(j)
			{
				if(j&1)
				{
					tc+=c[k];
					tf+=f[k];
					tp+=p[k];
				}
				j>>=1;
				k++;
			}
			if(tc==gc && tf==gf && tp==gp)
			{
				isDone=1;break;
			}
		}
		if(isDone)
		printf("Case #%d: yes\n",t);
		else
		printf("Case #%d: no\n",t);
	}
	return 0;
}
