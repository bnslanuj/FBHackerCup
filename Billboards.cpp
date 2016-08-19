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
	int test,t,w,h;
	char c;
	scanf("%d",&test);
	
	for(t=1;t<=test;t++)
	{
		scanf("%d%d",&w,&h);
		getchar();
		vector<string>v;
		string str;
		while((c=getchar())!='\n')
		{
			if(c==' ')
			{
				v.push_back(str);
				str.clear();
			}
			else
				str.push_back(c);
		}
		v.push_back(str);
		int ans=0;
		for(int i=min(w,h); i>=1; i--)
		{
			int pos=0,k=0,j,line=h/i;
			
			for(j=1;j<=line && k<v.size();)
			{
				if(pos+v[k].size()*i<=w)
				{
					pos+=v[k].size()*i+i;
					k++;
				}
				else
				{
					j++;
					pos=0;
				}
			}
			if(k==v.size())
			{
				ans=i;break;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
