#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

ll t,a,b,x,y,k;

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

ll gcd (ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

bool pd(ll x,ll y)
{
	return x%k==0&&y%k==0;
}

int main()
{
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	read(t);
	while(t--)
	{
		read(a);read(b);read(x);read(y);
		k=gcd(a,b)*2;
		if(pd(x,y)||pd(x+a,y+b)||pd(x+b,y+a)||pd(x+a+b,y+a+b))
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}
