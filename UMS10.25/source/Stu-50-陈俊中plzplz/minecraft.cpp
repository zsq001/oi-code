#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#define maxn 100010
using namespace std;

int b,n,d,m,pos[3][maxn],dis,ans,flag[maxn];

int cal(int x,int y,int z)
{
	int ret=0;
	for(int i=0;i<x;i++)
	{
		ret+=abs(pos[i][y]-pos[i][z]);
	}
	return ret;
}

int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	scanf("%d%d%d%d",&b,&n,&d,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<b;j++)
		{
			scanf("%d",&pos[j][i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dis=cal(b,i,j);
//			if(dis==0) continue;
			if(dis<=d) 
			{
//				flag[i]=1;
//				flag[j]=1;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
