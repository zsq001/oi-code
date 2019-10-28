#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
#define maxn 1010 
using namespace std;

int t;

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
int alice,bob;

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);	
	read(t);
	while(t--)
	{
		int n,a[maxn]={0};
		alice=0;bob=0;
		read(n);
		deque <int> q;
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
		}
		int l=1,r=n,cnt=0;
		while(l<=r)
		{
			if(cnt%2==0&&cnt<=n)
			{
				if(a[l+1]+a[r-1]<a[r]&&l-1<r-1)
				{
					alice+=a[r];
					r--;
					cnt++;
					continue;
				}
				else
				{
					alice+=a[l];
					l++;
					cnt++;
					continue;
				}
			}
			else if(cnt%2==1&&cnt<=n)
			{
				if(a[l+1]+a[r-1]<a[r]&&l-1<r-1)
				{
					bob+=a[r];
					r--;
					cnt++;
					continue;
				}
				else
				{
					bob+=a[l];
					l++;
					cnt++;
					continue;
				}
			}
		}
		printf("%d\n",alice-bob);
	}
	return 0;
}
