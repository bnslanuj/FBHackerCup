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
ll numRange(vector<ll> &arr, ll b, ll c) {
    if(arr.size()==0)return 0;
    
    vector<ll>cum(arr.size()+1,0);
    cum[1]=arr[0];
    
    for(int i=2;i<=arr.size();i++)
        cum[i]=cum[i-1]+arr[i-1];
    
    ll ans=0,low,high;
    low=high=1;
    for(int i=1;i<=arr.size();i++)
    {
        while(low<=arr.size() && cum[low]-cum[i-1]<b)
            low++;
        while(high<=arr.size() && cum[high]-cum[i-1]<=c)
            high++;
        high--;
        if(low<=high)
            ans+=(high-low+1);
        low=max(low,(ll)i+1);
        high=max(high,(ll)i+1);
        
    }
    return ans;
}

int main()
{
	int t,test;
	cin>>test;
	ll n,p;
	for(t=1;t<=test;t++)
	{
		cin>>n>>p;
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		ll ans=numRange(v,1,p);
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
