
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

ll fact[10009];
ll invfact[10009];

ll raise(ll a,ll b)
{
	if(b==0)return 1;
	ll val=raise(a,b/2);
	
	if(b&1)
		return (((val*val)%mod)*a)%mod;
	return (val*val)%mod;
}

void init()
{
	fact[0]=invfact[0]=1;
	
	for(ll i=1;i<=10000;i++)
		fact[i]=(fact[i-1]*i)%mod;
	
	for(ll i=1;i<=10000;i++)
		invfact[i]=raise(fact[i],mod-2);
	return ;
}

ll ncr(ll n,ll r)
{
	return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
ll v[10009];
int main()
{
	init();
	
	ll t,test,n,k;
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		cin>>n>>k;
		
		
		for(ll i=0;i<n;i++)
			cin>>v[i];
		
		sort(v,v+n);
		
		ll ans=0;
	
		for(ll i=n-1;i>=k-1;i--)
			ans=(ans+(v[i]*ncr(i,k-1))%mod)%mod;
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
