#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
const int mod=80112002;
struct Edge{
    int u,v,next;
}e[500010];
queue<int>Q;
int head[5010],cnt,f[5010],cd[5010],rd[5010],n,m,ans;
void add(int u,int v)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int main()
{
    int u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        add(u,v);
        cd[u]++;rd[v]++;
    }
    for(int i=1;i<=n;++i) 
        if(!rd[i]){
            f[i]=1;
            Q.push(i);
        }
    while(!Q.empty()){
    	int x=Q.front();
    	Q.pop();
    	for(int i=head[x];i;i=e[i].next){
    		int v=e[i].v;
    		rd[v]--;
    		f[v]=(f[v]+f[x])%mod;
    		if(!rd[v]) Q.push(v);
    	}
    	if(!cd[x]) ans=(ans+f[x])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
