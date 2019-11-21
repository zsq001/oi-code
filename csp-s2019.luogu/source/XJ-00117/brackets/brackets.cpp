#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<stack>
#define mmm 1200000
using namespace std;
struct node{
	int v,next;
}e[mmm];
stack<int> s;
char a[mmm],kkk[mmm];
int cnt=0,head[mmm];
int jie(int n)
{
	int ansq=1;
	for(int i=1;i<=n;i++)
	ansq*=i;
	return ansq;
}
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void killall()
{
	while(!s.empty())
		s.pop();
}
int bian[mmm];
vector <char> vv;
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n,vvv=0;
	cin>>n;
	cin>>a+1;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		bian[x]=i;
	}
	int anss=0,ansss=0;
	for(int i=1;i<=n;i++)
	{	
		int youi=0;
		for(int j=1;j;j=bian[j])
		{
			if(a[j]=='(' and youi==0)
			{
				s.push(a[j]);
				ansss++;
			}
			else if(s.empty() and a[j]==')')
			continue;
			else if(a[j]==')')
			{
				s.pop();
				youi=1;
				if(s.empty())
				{
					vvv++;
					vv.push_back('A');
				}
			}
			else if(a[j]=='(' and youi==1)
			{
				killall();
				youi=0;
				s.push(a[j]);
			}
			anss=max(ansss,anss);
		}
			anss^=(jie(vvv)/(jie(vvv-2)*jie(2)));
			cout<<anss<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
