#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 1010
using namespace std;

int n,m,k,x,s,a[maxn],b[maxn],c[maxn],d[maxn],dp[maxn][maxn],out;
struct node
{
	int a, b;
	double c;
}qaq[maxn],qwq[maxn];

template<class T> inline void read(T &x)
{
    x=0;
    register char c=getchar();
    register bool f=0;
    while (!isdigit(c)) f ^=c=='-',c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}

template <class T> inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar('0'+x%10);
}

bool cmp(node s1,node s2)
{
	return s1.c>s2.c;
}

void su(int g,int sn)
{
	for(int i=sn;i<=n;i++)
	{
		dp[g][i]=i*x;
	}
}

int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	read(n),read(m),read(k);
	read(x);read(s);
	for(int i=1;i<=m;i++)
	{
		read(qaq[i].a);
	}
	for(int i=1;i<=m;i++)
	{
		read(qaq[i].b);
		qaq[i].c=(double)qaq[i].a/qaq[i].b;
	}
	for(int i=1;i<=k;i++)
	{
		read(qwq[i].a);
	}
	for(int i=1;i<=k;i++)
	{
		read(qwq[i].b);
		qwq[i].c=(double)qwq[i].a/qwq[i].b;
	}
	sort(qaq+1,qaq+n+1,cmp);
	sort(qwq+1,qwq+n+1,cmp);
	su(0,0);
	int flag1=0,flag2=0;
	for(int i=0;i<=s;i++)
	{
			for(int l=1;l<=m;l++)
			{
				if(flag1==1&&flag2==1) break;
				if(i-out>=qwq[l].a&&i-out>=qaq[l].a)
				{
					if(dp[i][0]<dp[i][qwq[l].b]-(x-qaq[l].b)&&flag1==0)
					{
						dp[i][qwq[l].b]=dp[i][0];
						out+=qwq[l].a;
						flag1=1;
					}
					else if(flag2==0&&dp[i][0]>dp[i][qwq[l].b]-(x-qaq[l].b))
					{
						x=qaq[l].b;
						su(i,0);
						out+=qaq[l].a;
						flag2=1;
					}
				}
				if(i-out>=qwq[l].a&&flag1==0)
				{
					dp[i][qwq[l].b]=dp[i][0];
					out+=qwq[l].a;
					flag1=1;
				}
				if(i-out>=qaq[l].a&&flag2==0)
				{
					x=qaq[l].b;
					su(i,0);
					out+=qaq[l].a;
					flag2=1;
//					dp[i][j]=min(dp[i][j-1]+x,dp[i][j]);
				}
			}
	}
	int ans=2e9+7;
	for(int i=1;i<=s;i++)
	{
		ans=min(ans,dp[i][n]);
	}
	printf("%d",ans);
	return 0;
}
