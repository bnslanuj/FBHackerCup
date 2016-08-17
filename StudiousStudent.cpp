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

bool comp(string a,string b)
{
	if(a+b<b+a)return 1;
	return 0;
}
int main()
{
	int t,tt,m;
	cin>>tt;
	
	for(t=1;t<=tt;t++)
	{
		cin>>m;
		vector<string>str(m);
		for(int i=0;i<m;i++)
			cin>>str[i];
		
		sort(str.begin(),str.end(),comp);
		
		string ans;
		
		for(int i=0;i<m;i++)
			ans+=str[i];
		
		printf("Case #%d: ",t);
		cout<<ans<<endl;
	}
	return 0;
}
