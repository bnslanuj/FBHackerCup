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

int main()
{
	vector<ll>v;
	for(ll i=0;i<=50000;i++)
		v.push_back(i*i);
	
	ll n,c,x,nn;
	// freopen("double_squares.txt","r",stdin);
    //freopen("sout.txt", "w",stdout);
	cin>>nn;
	for(n=1;n<=nn;n++)
	{
		cin>>x;
		c=0;
		int i=0,j=v.size()-1;
		while(i<=j)
		{
			if(v[i]+v[j]==x)
			{
				c++;
				i++;j--;
			}
			else if(v[i]+v[j]<x)
				i++;
			else j--;
		}
		printf("Case #%d: %d\n",n,c);
	}
	return 0;
}
