#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#define inf 1<<29
#define maxn 200010
#define mod 10007
using namespace std;
typedef long long ll;
vector<int>son[maxn];
ll ans,sum;
int cnt,n,m,hl[maxn],fa[maxn],w[maxn],len[maxn],maxson[maxn][2],sonsum[maxn];
inline int read()
{
	int ret(0);
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
struct Edge{
	int u,v,ne;
}e[maxn<<1];
void add(int u,int v)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].ne=hl[u];
	hl[u]=cnt;
}
void build(int x,int faa)
{
	for(int i=hl[x];i;i=e[i].ne){
		int v=e[i].v;
		if(v==faa) continue;
		fa[v]=x;
		len[x]++;
		if(w[v]>maxson[x][0]){
			maxson[x][0]=w[v];
			maxson[x][1]=v;
		}
		sonsum[x]+=w[v];
		son[x].push_back(v);
		build(v,x);
	}
}
void fnd(int x,int key,int f)
{
	if(!len[x]) return;
	if(key!=maxson[x][1]){
		ans=max(ans,1ll*w[key]*w[maxson[x][1]]);
		sum+=1ll*sonsum[x]*w[key]-f*w[key]*w[key];
		sum%=mod;
		return;
	}
	else{
		for(int i=0;i<len[x];++i){
			int v=son[x][i];
			if(v==key) continue;
			sum+=1ll*w[key]*w[v];
			ans=max(ans,1ll*w[key]*w[v]);
		}
	}
	sum%=mod;
}
int main()
{
	int x,y;
	n=read();
	for(int i=1;i<n;++i){
		x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i) w[i]=read();
	build(1,0);
	for(int i=1;i<=n;++i){
		if(fa[i]) fnd(fa[i],i,1);
		if(fa[fa[i]]){
			sum=(sum+1ll*w[i]*w[fa[fa[i]]])%mod;
			ans=max(ans,1ll*w[i]*w[fa[fa[i]]]);
		}
		for(int j=0;j<len[i];++j) fnd(son[i][j],i,0);
	}
	printf("%lld %lld\n",ans,sum%mod);
	return 0;
}
