#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define maxn 2020

int n,m,cnt,tot,head[maxn],dis[maxn],vis[maxn];
struct edge{
	int v,w,next;
}e[maxn<<1];
priority_queue< pair<int,int> >q;

void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dij(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(0));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].v,w=e[i].w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}

int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	dij();
	double ans;
	tot=m/(n-2)+1;
	if(m==n-1) ans=(double)dis[n]/(double)n;
	else ans=(double)dis[n]/(double)tot;
	printf("%.3lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 6
1 2 1
2 4 6
1 3 2
3 4 4
2 3 3
1 4 8

3 2
1 2 2
2 3 3

5 6
1 2 2
2 3 3
1 3 3
3 5 1
1 4 2
4 5 4
*/
