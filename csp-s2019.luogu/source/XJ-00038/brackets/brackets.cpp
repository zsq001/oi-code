#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
typedef int int_;
#define int long long 
#define maxn 100050
using namespace std;
int cnt,head[maxn],vis[maxn],dis[maxn],flag[maxn],n,a[maxn],x,ans=1;
char s[maxn];

struct node{
	int u,v,next,w;
}e[maxn<<1];

void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int las,int now){
	if(vis[now])return ;
	vis[now]=1;
	for(int i=head[las];i;i=e[i].v){
		int v=e[i].v;
		dis[v]+=dis[las];
		if(dis[v]==0)flag[v]++;
		dfs(now,v);
	}
}
int_ main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdin);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='(')a[i]=-1;
		else         a[i]=1;
	}
	for(int i=1;i<=n-1;i++){
		scanf("%lld",&x);
		add(x,i+1,a[i]);
	}
	dfs(0,1);
	for(int i=1;i<=n;i++){
		if(!flag[i])ans+=flag[i]^1;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
