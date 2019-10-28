#include<iostream>
#include<cstdio>
#include<cstring>
#define mmm 500001
char a[mmm];
int b[mmm][2],cnt,c[mmm],d[mmm];
using namespace std;
void build(int &qwq)
{
	qwq=++cnt;
	int now=a[cnt]-'0';
	if(now==0)
		return;
	else if(now==1)
		build(b[qwq][1]);
	else
	{
		build(b[qwq][1]);
		build(b[qwq][2]);
	}
}
int main()
{
	int gen;
	cin>>a+1;
	int n=strlen(a+1);
	build(gen);
	for(int i=n;i>=1;i--)
	{
		c[i]=d[b[i][1]]+d[b[i][2]]+1;
		d[i]=max(c[b[i][1]]+d[b[i][2]],c[b[i][2]]+d[b[i][1]]);
	}
	cout<<max(c[1],d[1])<<" ";
	for(int i=n;i>=1;i--)
	{
		c[i]=d[b[i][1]]+d[b[i][2]]+1;
		d[i]=min(c[b[i][1]]+d[b[i][2]],c[b[i][2]]+d[b[i][1]]);
	}
	cout<<min(c[1],d[1]);
	return 0;
}
