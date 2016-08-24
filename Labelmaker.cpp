
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
	ll t,n,test;
	
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		string str;
		cin>>str>>n;
		
		string ans;
		
		while(n>0)
		{
			ll rem=n%str.size();
			
			if(rem!=0)
			{
				rem--;
				n=n/str.size();
			}
			else
			{
				rem=str.size()-1;
				n=n/str.size()-1;
			}
			ans=str[rem]+ans;
		}
		printf("Case #%d: %s\n",t,ans.c_str());
	}
	return 0;
}
