#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,block,cnt;
int pt[200005],st[200005],K[200005],belong[200005];
int l[1005],r[1005];
inline int cal(int x)
{
	int tmp=0;
	while(1)
	{
		tmp+=st[x];
		if(!pt[x])break;
		x=pt[x];
	}
	return tmp;
}
int main()
{
    freopen("sheep.in", "r", stdin);
    freopen("sheep.out", "w", stdout);
	n=read();block=sqrt(n);
	for(int i=1;i<=n;i++)
	    K[i]=read();
	if(n%block)cnt=n/block+1;
	else cnt=n/block;
	for(int i=1;i<=cnt;i++)
	    l[i]=(i-1)*block+1,r[i]=i*block;
	r[cnt]=n;
	for(int i=1;i<=n;i++)
	   belong[i]=(i-1)/block+1;
	for(int i=n;i>0;i--)
	{
		if(i+K[i]>n)st[i]=1;
		else if(belong[i]==belong[i+K[i]])
		    st[i]=st[i+K[i]]+1,pt[i]=pt[i+K[i]];
		else st[i]=1,pt[i]=i+K[i];
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int f=read(),x=read(),y;
		x++;
		if(f==1)printf("%d\n",cal(x));
		else 
		{
			y=read();K[x]=y;
			for(int i=x;i>=l[belong[x]];i--)
			    if(belong[i]==belong[i+K[i]])
		            st[i]=st[i+K[i]]+1,pt[i]=pt[i+K[i]];
		        else st[i]=1,pt[i]=i+K[i];
		}
	}
	return 0;
}