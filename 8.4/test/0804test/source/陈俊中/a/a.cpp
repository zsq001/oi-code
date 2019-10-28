#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200010
using namespace std;

int n,m,dp[maxn],p[maxn];
struct node
{
	int last,next,val,vis,num,flag;
}a[maxn];
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
	return s1.val>s2.val;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n);read(m);
	if(n/2<m)
	{
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		read(a[i].val);
		a[i].num=i;
		a[i].last=i-1;
		a[i].next=i+1;
	}
	a[1].last=n;
	a[n].next=1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[a[j].next].vis==0&&a[a[j].last].vis==0&&a[j].flag==0)
			{
				if(dp[i]<dp[i-1]+a[j].val)
				{
					dp[i]=dp[i-1]+a[j].val;
					a[a[a[j].next].num].flag=1;
					a[a[a[j].last].num].flag=1;
					a[j].vis=1;
					a[j].flag=1;
				}
			}
		}
	}
	printf("%d",dp[m]);
	return 0;
}
