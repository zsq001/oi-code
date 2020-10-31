#include<bits/stdc++.h>
#define maxn 200010
#define inf 1<<29
using namespace std;
typedef long long ll;
stack<int>S;
int n,cnt,ans,tot,now,vis[maxn],dfn[maxn],next[maxn],low[maxn];
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	vis[x]=1;
	S.push(x);
	int v=next[x];
	if(!dfn[v]){
		tarjan(v);
		low[x]=min(low[x],low[v]);
	}
	else if(vis[v]) low[x]=min(low[x],dfn[v]);
	if(dfn[x]==low[x]){
		now=-1;
		tot=0;
		while(now!=x){
			now=S.top();
			S.pop();
			tot++;
			vis[now]=0;
		}
		if(tot>1) ans=min(ans,tot);
	}
}
int main(){
    cin>>n;
    ans=n;
    for(int i=1;i<=n;++i) cin>>next[i];
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	cout<<ans<<endl;
	return 0;
}
