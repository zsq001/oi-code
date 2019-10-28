#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long 
#define maxn 1000010
using namespace std;

int n,t,qaq[11]={1,1,1,1,1,2,3,2,2,2,2};

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
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		if(n==1) printf("\n");
		int x=n/11,y=n%11;
		printf("%d\n",2*x+qaq[y-1]);
	}
	return 0;
}
