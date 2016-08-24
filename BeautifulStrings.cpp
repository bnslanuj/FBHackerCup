
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
#define  ll unsigned long long
#define mod 1000000007

using namespace std;

int main()
{
	int t,test;
	cin>>test;
	getchar();
	char c;
	for(t=1;t<=test;t++)
	{
		vector<int>v(26,0);
		while((c=getchar())!='\n')
		{
			if(c>='A'&&c<='Z')
				v[c-'A']++;
			if(c>='a'&&c<='z')
				v[c-'a']++;
		}
		sort(v.begin(),v.end());
		int ans=0;
		for(int i=25,j=26;i>=0;i--,j--)
			ans+=v[i]*j;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
