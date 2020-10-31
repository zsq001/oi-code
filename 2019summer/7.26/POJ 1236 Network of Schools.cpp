#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#define l 2510
#define inf 707406378
using namespace std;
stack<int>S;
struct X{
	int v,w,ne;
}e[l],E[l];
int n,m,K,ans,C,R,hl[l],HL[l],jh[l],own[l],vis1[l],vis2[l],low[l],dfn[l],dis[l],cnt,num,cd[l],rd[l];
void init()
{
	memset(hl,0,sizeof(hl));
	memset(HL,0,sizeof(HL));
	memset(vis1,0,sizeof(vis1));
	memset(vis2,0,sizeof(vis2));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(own,0,sizeof(own));
	memset(jh,0,sizeof(jh));
	memset(cd,0,sizeof(cd));
	memset(rd,0,sizeof(rd));
	cnt=num=0;
}
void add(int x,int y)
{
	e[++cnt].v=y;
	e[cnt].ne=hl[x];
	hl[x]=cnt;
}
void tarjan(int x)
{
	vis1[x]=vis2[x]=1;
	dfn[x]=low[x]=++cnt;
	S.push(x);
	for(int i=hl[x];i;i=e[i].ne){
		int to=e[i].v;
		if(!vis1[to]){
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(vis2[to]) low[x]=min(low[x],dfn[to]);
	}
	if(dfn[x]==low[x]){
		int now=-1;
		num++;
		while(now!=x){
			now=S.top();
			S.pop();
			vis2[now]=0;
			jh[now]=num;
			own[num]++;
		}
	}
}
void rebuild()
{
	cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=hl[i];j;j=e[j].ne){
			int v=e[j].v;
			if(jh[i]==jh[v]) continue;
			E[++cnt].v=jh[v];
			E[cnt].w=e[j].w;
			E[cnt].ne=HL[jh[i]];
			HL[jh[i]]=cnt;
			cd[jh[i]]++,rd[jh[v]]++;
		}
}
void spfa(int x)
{
	memset(vis1,0,sizeof(vis1));
	memset(dis,127/3,sizeof(dis));
	queue<int>q;
	q.push(x);
	vis1[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis1[t]=0;
		for(int i=HL[t];i;i=E[i].ne){
			int v=E[i].v,w=E[i].w;
			if(dis[v]>dis[t]+w){
				dis[v]=dis[t]+w;
				if(!vis1[v]){
					vis1[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	init();
	int x,y,t;
	for(int i=1;i<=n;++i){
		while(1){
			scanf("%d",&x);
			if(!x) break;
			add(i,x);
		}
	}
	cnt=0;
	for(int i=1;i<=n;++i) if(!vis1[i]) tarjan(i);
	rebuild();
	for(int i=1;i<=num;++i){
		if(!cd[i]) C++;
		if(!rd[i]) R++;
	}
	if(num==1)
	{
		puts("1");
		puts("0");
		return 0;
	}
	printf("%d\n%d",R,max(C,R));
	puts("");
	return 0;
}
