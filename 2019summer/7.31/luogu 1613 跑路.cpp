#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define maxn 10010
#define inf 1<<29
using namespace std;
int n,m,x,y,f[60][60][70],mp[60][60];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) mp[i][j]=inf;
	while(m--){
		scanf("%d%d",&x,&y);
		f[x][y][0]=mp[x][y]=1;
	}
	for(int b=1;b<=64;++b)
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j){
					f[i][j][b]|=f[i][k][b-1]&&f[k][j][b-1];
					if(f[i][j][b]) mp[i][j]=1;
				}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(mp[i][k]+mp[k][j]) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	printf("%d",mp[1][n]);
	return 0;
}
