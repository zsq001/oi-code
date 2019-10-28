#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int n;
double dis[10][10];
double ox[10],oy[10];



int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	double minR=0x3f3f3f3f,maxR=0,S;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&ox[i],&oy[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=sqrt((ox[i]-ox[j])*(ox[i]-ox[j])+(oy[i]-oy[j])*(oy[i]-oy[j]));
		}
	}
//	int s,e,maxr=0;
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=n;j++)
//	{
//		if(dis[i][j]>maxr)
//		{
//			s=i;e=j;
//		}
//	}
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=n;j++)
//	{
//		
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)minR=min(minR,dis[i][j]);
			maxR=max(maxR,dis[i][j]);
		}
	}
	S=minR*minR+(maxR-minR)*(maxR-minR);
	printf("%.2lf",S);
	return 0;
}
