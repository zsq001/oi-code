#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;

int n,q,k,bord,dp[30][maxn],d[maxn];

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
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(d[i]);
	}
	read(q);
	for(int i=1;i<=q;i++)
	{
		read(k);
		for(int j=1;j<n;)
		{
			for(int l=k;l>=1;l--)
			{
				if(d[j+l]<d[j]&&j+l<=n)
				{
					j+=l;
					dp[i][j]=dp[i][j-l];
					break;
				}
				else if(l==1&&d[j+1]>=d[j])
				{
					if(n-j>k)
					{
						j+=k;
						dp[i][j]=dp[i][j-k]+1;
						break;
					}
					else
					{
						dp[i][n]=dp[i][j]+1;
						j=n;
						break;
					}
				}
			}
		}
		
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",dp[i][n]);
	}
	return 0;
}
