#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 500010
using namespace std;

int n,m;
ll k,a[maxn][3],cnt=1;
priority_queue  <ll> q;


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

int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			q.push(i*j);
		}
	}
	while(q.size()>k)
	{
		q.pop();
	}
	print(q.top());
	return 0;
}
