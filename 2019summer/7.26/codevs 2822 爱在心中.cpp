#include<bits/stdc++.h>
#define l 10010 
using namespace std;
stack<int>S;
struct X{
	int v,next;
}e[50010];
int n,m,ans,hl[l],HL[l],jh[l],own[l],vis1[l],vis2[l],low[l],dfn[l],cnt,num;
void add(int x,int y)
{
	e[++cnt].v=y;
	e[cnt].next=hl[x];
	hl[x]=cnt;
}
void tarjan(int x)
{
	vis1[x]=vis2[x]=1;
	dfn[x]=low[x]=++cnt;
	S.push(x);
	for(int i=hl[x];i;i=e[i].next){
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
		for(int j=hl[i];j;j=e[j].next)
			if(jh[i]!=jh[e[j].v]) HL[jh[i]]=++cnt; 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;++i) if(!vis1[i]) tarjan(i);
	rebuild(); 
	for(int i=1;i<=num;++i) if(own[i]>1) ans++; 
 	cout<<ans<<endl; 
	ans=0; 
	for(int i=1;i<=num;++i)
		if(!HL[i]){
			if(ans||own[i]==1){
				cout<<"-1"<<endl; 
				return 0; 
			}
			else ans=i; 
		}
	for(int i=1;i<=n;++i) if(jh[i]==ans) cout<<i<<" "; 
	return 0;
}
