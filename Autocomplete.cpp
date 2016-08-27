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
struct node
{
	char c;
	struct node *next[26];
};

struct node* newNode(char c)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->c=c;
	for(int i=0;i<26;i++)
		temp->next[i]=NULL;
	return temp;
}

int insert(struct node *root,string &str)
{
	if(root==NULL)return -1;
	
	int c=1,ans=0;
	struct node *trav=root;
	
	for(int i=0;i<str.size();i++)
	{
		if(trav->next[str[i]-'a']==NULL)
		{
			if(ans==0)
				ans=c;
			trav->next[str[i]-'a']=newNode(str[i]);
			trav=trav->next[str[i]-'a'];
		}
		else
		{
			trav=trav->next[str[i]-'a'];
			c++;
		}
	}
	if(ans==0)return c-1;
	return ans;
}

int main()
{
	int test,t,n;
	
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		cin>>n;
		string str;
		int ans=0;
		struct node *root=newNode('#');
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			ans+=insert(root,str);
		
		}
		printf("Case #%d: %d\n",t,ans);
	}
}
