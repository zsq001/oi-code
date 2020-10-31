#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define l 1010
#define inf 1<<30
using namespace std;
int n,m,x,map[l][l],dis[l],exi[l],c,ans=inf,pos,vis[l],mind,i,j;
char a,b,ansc;
void dijkstra()
{
	for(i=65;i<=122;++i)
	{
		dis[i]=map[90][i];
	}
	vis[90]=1,dis[90]=0;
	for(i=1;i<=51;++i)
	{
		mind=inf;
		for(j=65;j<=122;++j)
		{
			if(!vis[j]&&mind>dis[j])
			{
				pos=j;
				mind=dis[j];
			}
		}
		vis[pos]=1;
		for(j=65;j<=122;++j)
		{
			if(!vis[j]&&dis[j]>dis[pos]+map[pos][j])
			{
				dis[j]=dis[pos]+map[pos][j];
			}
		}
	}
	for(i=65;i<90;++i)
	{
		if(dis[i]<ans&&exi[i])
		{
			ans=dis[i],ansc=(char)i;
		}
	}
}
int main()
{
	cin>>n;
	for(i=65;i<=122;++i)
	{
		for(j=65;j<=122;++j)
		{
			map[i][j]=inf;
			dis[j]=inf;
		}
	}
	for(i=1;i<=n;++i)
	{
		cin>>a>>b>>c;
		map[a][b]=min(map[a][b],c);
		map[b][a]=map[a][b];
		if(a>='A'&&a<='Y') exi[a]=1;
		if(b>='A'&&b<='Y') exi[b]=1;
	}
	dijkstra();
	cout<<ansc<<" "<<ans<<endl;
	return 0;
}
