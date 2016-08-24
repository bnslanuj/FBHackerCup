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
#define mod 4207849484
using namespace std;

int main()
{
	ll t,test,m,i,j,k,temp;
	cin>>test;
	string str;
	for(t=1;t<=test;t++)
	{
		cin>>m>>str;
		int l=str.size();
		vector<vector<ll> >dp(l+1,vector<ll>(l+1,0));
		
		for(i=1;i<=l;i++)
		{
			temp=atoi(str.substr(i-1,1).c_str());
			if(temp>=1 && temp<=min(9LL,m))
				dp[i][i]=1;
		}
		for(i=1;i<l;i++)
		{
			temp=atoi(str.substr(i-1,2).c_str());
			if(temp/10>=1 && temp/10<=min(9LL,m))
				dp[i][i+1]=dp[i+1][i+1];
			if(temp>=10 && temp<=min(99LL,m))
				dp[i][i+1]++;	
		}
		for(i=1;i<l-1;i++)
		{
			temp=atoi(str.substr(i-1,3).c_str());
			if(temp/100>=1 && temp/100<=min(9LL,m))
				dp[i][i+2]=dp[i+1][i+2];
			if(temp/10>=10 && temp/10<=min(99LL,m))
				dp[i][i+2]+=dp[i+2][i+2];
			if(temp>=100 && temp<=min(255LL,m))
				dp[i][i+2]++;
		}
		
		for(k=4;k<=l;k++)
		{
			i=1;j=k;
			
			while(i<=l && j<=l)
			{
				temp=atoi(str.substr(i-1,3).c_str());
				if(temp/100>=1 && temp/100<=min(9LL,m))
					dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
				if(temp/10>=10 && temp/10<=min(99LL,m))
					dp[i][j]=(dp[i][j]+dp[i+2][j])%mod;
				if(temp>=100 && temp<=min(255LL,m))
					dp[i][j]=(dp[i][j]+dp[i+3][j])%mod;
				i++;j++;
			}
		}

		printf("Case #%lld: %lld\n",t,dp[1][l]);
	}
}
