#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#define ll long long
#define maxn 200010
#define esp 1e-7
using namespace std;

int n,a[maxn];
double ans;

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

bool pd(double x)
{
	double now=x,tot=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(now<abs(a[i]-x))
		{
			cnt++;
			now=x-abs(a[i]-x);
		}
		else now-=abs(a[i]-x);
	}
	return cnt<2;
}

int main()
{
	freopen("sep.in","r",stdin);
	freopen("sep.out","w",stdout);
	double l=1e9,r;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		l=min(l,(double)a[i]);
		r+=a[i];
	}
	while(r-l>=esp)
	{
		double mid=(double)(r+l)/2;
		if(pd(mid)) l=mid;
		else r=mid;
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]-l);
	}
	printf("%.7lf",ans);
	return 0;
}
