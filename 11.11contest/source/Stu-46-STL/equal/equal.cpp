#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define maxn 100010

int n,m,xx,yy,aa,bb,fa,cnt,sum;
int head[maxn],f[maxn][25],deep[maxn];
struct edge{int v,next;}e[maxn<<1];

void add(int u,int v){e[++cnt].v=v;e[cnt].next=head[u];head[u]=cnt;}
//int getfa(int x){return f[x]==x?x:f[x]=getfa(f[x]);}
void dfs(int u,int fa){
	deep[u]=deep[fa]+1;
	for(int i=1;(1<<i)<=deep[u];++i) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		f[u][0]=u;
		dfs(v,u);
	}
}

int l(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;--i){
		if(deep[f[x][i]]>=deep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;--i){
		if(f[x][i]!=f[y][i]) {x=f[x][i];y=f[y][i];}
		return f[x][0];
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n;++i){cin>>xx>>yy;add(xx,yy);add(yy,xx);}
	dfs(1,0);
	cin>>m;
	while(m--){
		cin>>aa>>bb;
		if(aa==bb) cout<<n-1<<endl;
	}
	return 0;
}


