
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
	char ch,p;
	getchar();
	for(t=1;t<=test;t++)
	{
		int s,f,o;
		s=f=o=0;
		p='p';
		bool isDone=1;
		while((ch=getchar())!='\n')
		{
			
			if(ch=='(' && p==':')
				f++;
			if(ch==')' && p==':')
				s++;
			
			if(ch=='(')
				o++;
			else if(ch==')')
			{
				if(o)
				{
					o--;
					if(f>o)
						f=o;
				}
				else if(s)
					s--;
				else isDone=0;
			}
			p=ch;
		}
		if(o<=f && isDone)
			printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
		//getchar();
	}
	return 0;
}
