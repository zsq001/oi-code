#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1001][1001];
int main()
{
	freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);	
    int i,n,m,p,t,x,w;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	a[i][j]=0;
	for(i=1;i<=p;i++)
	{scanf("%d%d%d",&t,&x,&w);
	if(t==1) {
		for(int j=1;j<=m;j++)
		a[x][j]=w;
	}
	if(t==2){
		for(int j=1;j<=n;j++)
		a[j][x]=w;
	}
	}
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		printf("%d ",a[i][j]);
		printf("%d\n",a[i][m]);
	}
	return 0;
}
