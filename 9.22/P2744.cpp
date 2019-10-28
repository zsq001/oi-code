#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
const int inf=2147483647;
#define mmm 10000
using namespace std;
int q,p;
int flag,a[mmm],b[mmm],c[mmm];
bool emm=false;
void dfs(int u,int v,int s)//结果   剩余奶  现在编号
{
	if(u==flag)
	{
		if(v==0)
		{
			/*for(int i=1;i<=sizeof(b);i++)
				c[i]=b[i];*/
			memcpy(c,b,sizeof(b));
			emm=true;
		}
		return ;
	}
	if(a[s]>c[u]||s>p)
			return ;
	b[u]=a[s];
	for(int i=1;i*a[s]<=v;i++)
		dfs(u+1,v-i*a[s],s+1);
	if(s<p)
		dfs(u,v,s+1);
}
int main()
{
	memset(c,2,sizeof(c));
	cin>>q>>p;
	for(int i=1;i<=p;i++)
		cin>>a[i];
	sort(a+1,a+1+p);
	for(flag=1;flag<=p;flag++)
	{
		dfs(0,q,1);
		if(emm==true)
			break;
	}
	cout<<flag;
	for(int i=0;i<flag;i++)
	cout<<" "<<c[i];
	return 0;
}
