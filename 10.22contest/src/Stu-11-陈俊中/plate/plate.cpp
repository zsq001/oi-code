#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#define ll long long 
using namespace std;

ll n,m,p,ans;
int pan[510][510],dis[510];

int main()
{
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
//		int x=0,y=0;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&pan[i][j]);
		}
		dis[i]=abs(pan[i][1]-pan[i][m]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
//			int flag=0;
			int ln=2,rn=m-1;
			if(dis[i]!=dis[j]) 
			{
//				flag=1;
				continue;
			}
			if(abs(pan[i][ln]-pan[i][1])==abs(pan[j][rn]-pan[j][m]))
			{
				ln++;rn--;
			}
			else if(abs(pan[i][ln]-pan[i][1])!=abs(pan[j][rn]-pan[j][m]))
			{
//				flag=1;
				continue;
			}
			ans++;
		}	
	}	
	printf("%lld\n",ans);
	return 0;
}
