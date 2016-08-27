
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
	int t,test;
	string str,a,b;
	cin>>test;
	for(t=1;t<=test;t++){
	
	cin>>str;
	a=b=str;
	
	for(int i=0;i<str.size();i++)
	{
		for(int j=i+1;j<str.size();j++)
		{
			string temp=str;
			char c=temp[j];
			if(i==0 && c=='0')continue;
			temp[j]=temp[i];
			temp[i]=c;
			if(temp>a)a=temp;
			if(temp<b)b=temp;
		}
	}
	printf("Case #%d: %s %s\n",t,b.c_str(),a.c_str());}
	return 0;
}
