#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#define maxn 100010
#define ll long long
using namespace std;

ll n;

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
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	int ans=log2(n)+1;
	printf("%d",ans);
	return 0;
}
