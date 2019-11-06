#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<cmath>
#include<vector>
const int N=1010;
const int M=5010;
const int inf=1e9+7;
using namespace std;
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
int head[N],tot=0,f[N][2],g[N][M],val[N],n;
vector<int> G[N];
inline void addedge(int u,int v){
	G[u].push_back(v);G[v].push_back(u);
}
inline void dfs(int u,int fa){
	f[u][0]=inf;f[u][1]=inf;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];if(v==fa)continue;
		dfs(v,u);
	}
	for(int i=0;i<2;i++){
		g[0][0]=0;int cur=0;
		for(int j=1;j<=val[u];j++)g[0][j]=inf;
		for(int j=0;j<G[u].size();j++){
            int v=G[u][j];if(v==fa)continue;cur++;
            for(int w=0;w<=val[u];w++) g[cur][w]=inf;
            for(int w=0;w<=val[u];w++){
                if(w+val[v]<=val[u])g[cur][w+val[v]]=min(g[cur-1][w]+f[v][i^1],g[cur][w+val[v]]);
                if(w+f[v][i^1]<=val[u])g[cur][w+f[v][i^1]]=min(g[cur][w+f[v][i^1]],g[cur-1][w]+val[v]);
            }
        }
        for(int w=0;w<=val[u];w++)f[u][i]=min(f[u][i],g[cur][w]);
		//for(int w=0;w<=val[u];w++)printf("g[%d][%d]=%d\n",cur,w,g[cur][w]);
		//printf("f[%d][%d]=%d\n",u,i,f[u][i]);
	}
}
int main(){
	freopen("sciandtech.in","r",stdin);
	freopen("sciandtech.out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++){
		int u=read();addedge(i,u);
	}
	for(int i=1;i<=n;i++)val[i]=read();
	dfs(1,0);
	if(f[1][0]<inf||f[1][1]<inf)puts("ICHOOSEUNIQUE");else puts("ICHOOSEBINGYAN");
}
