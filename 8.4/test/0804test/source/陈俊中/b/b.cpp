#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1000010
using namespace std;

int n,m,p,q,c[maxn];

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

int col(int i,int a,int b,int c)
{
	return (i*a+b)%c+1;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);read(m);read(p);read(q);
	for(int j=m;j>=1;j--)
	{
		int l=col(j,p,q,n),r=col(j,q,p,n);
		for(int i=l;i<=r;i++) 
		{
			if(c[i]==0) c[i]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}
