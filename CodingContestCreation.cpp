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
	int t,test,n;
	scanf("%d",&test);
	
	for(t=1;t<=test;t++)
	{
		scanf("%d",&n);
		vector<int>arr(n+1,0);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int c=0,curr=0,last=arr[0]-1;
		
		for(int i=0;i<n;)
		{
			if(arr[i]-last<=10 && arr[i]-last>0)
			{
				last=arr[i];
				i++;
			}
			else
			{
				c++;
				last+=10;
			}
			curr++;

			if(curr==4)
			{
				curr=0;
				last=arr[i]-1;
			}
		}
		
		if(curr!=0)
			c+=(4-curr);
		printf("Case #%d: %d\n",t,c);
	}
}
