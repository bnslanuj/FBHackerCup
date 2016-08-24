
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
#define  ll long long
#define mod 1000000007
using namespace std;

int main()
{
	ll test,t,n,k,a,b,c,r;
	cin>>test;

	for(t=1;t<=test;t++)
	{
		cin>>n>>k>>a>>b>>c>>r;
		vector<ll>v(k);
		map<ll,ll>s,s1;
		map<ll,ll>::iterator it;
		v[0]=a;
		s1[a]++;
		for(ll i=1;i<k;i++)
		{
			v[i]=(b*v[i-1]+c)%r;
			s1[v[i]]++;
		}
		for(ll i=0;i<=k;i++)
		{
			if(s1.find(i)==s1.end())
				s[i]++;
		}
		
		n=(n-k-1)%(k+1);
	
		ll ans;
		for(ll i=0;i<=n;i++)
		{
			it=s.begin();
			ans=it->first;
			s.erase(it);
			it=s1.find(v[i]);
			it->second--;
			if(it->second==0)
			{
				s[it->first]++;
				s1.erase(it);
			}
		}
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
