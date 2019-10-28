#include<iostream>
#include<cstdio>
#include<algorithm>
#define mmm 1000000
typedef int int_;
#define int long long
using namespace std;
int v,cnt=0;
int qwq[mmm];
void dfs(int x,int y,int z)
{
	int i=1,j=1,k=1;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(i*j>x)
				break;
			for(k=1;k<=z;k++)
			{
				if(k*i*j>x)
				break;
//				if(k%10*i%10*j%10!=v%10)
//				continue;
				if(k*i*j==x)
				{
					qwq[++cnt]=2*i*j+2*i*k+2*j*k;
				}
			}
		}
	}
}
int_ main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int ans=2147483647;
	cin>>v;
	dfs(v,v,v);
	for(int i=1;i<=cnt;i++)
		ans=min(qwq[i],ans);
	cout<<ans<<endl;
	return 0;
}
