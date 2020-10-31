#include<bits/stdc++.h>
#define maxn 100010
#define inf 1<<29
using namespace std;
typedef long long ll;
stack<int>S;
int n,m,cnt,tot,now,ans,jh[maxn],f[maxn],num[maxn],dfn[maxn],vis[maxn],low[maxn],head[maxn];
struct Edge{
    int v,w,next;
}e[maxn<<1];
void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void tarjan(int x){
    vis[x]=1;
    dfn[x]=low[x]=++cnt;
    S.push(x);
    for(int i=head[x];i;i=e[i].next){
        int v=e[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(vis[v]) low[x]=min(low[x],low[v]);
    }
    if(dfn[x]==low[x]){
        tot++;
        now=-1;
        while(now!=x){
            now=S.top();
            S.pop();
            vis[now]=0;
            jh[now]=tot;
            num[tot]++;
        }
    }
}
int dfs(int x){
	if(f[x]) return f[x];
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==x) return f[x]=1;
		return f[x]=dfs(v)+1;
	}
}
int main(){
    int u,v;
    cin>>n; 
	for(int i=1;i<=n;++i){
		cin>>v;
		add(i,v);
	}
    cnt=0;
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;++i) if(num[jh[i]]>1) f[i]=num[jh[i]];
    for(int i=1;i<=n;++i) cout<<dfs(i)<<endl;
	return 0;
}
