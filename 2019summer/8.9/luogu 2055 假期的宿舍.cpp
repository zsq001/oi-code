#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define maxn 1010
#define inf 1<<29
using namespace std;
typedef long long ll;
struct Edge{
	int u,v,ne;
}e[100010];
int T,n,cnt,tot,k,match[110],used[110],mp[60][60],hl[110],sc[60],hm[60];
void init()
{
	memset(match,0,sizeof(match));
	memset(hl,0,sizeof(hl));
	cnt=tot=0;
}
void add(int u,int v)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].ne=hl[u];
	hl[u]=cnt;
}
bool xyl(int x)
{
	for(int i=hl[x];i;i=e[i].ne){
		int v=e[i].v;
		if(used[v]) continue;
		used[v]=1;
		if(!match[v]||xyl(match[v])){
			match[v]=x;
			return true;
		}
	}
	return false;
}
bool pipei()
{
	for(int i=1;i<=n;++i){
		memset(used,0,sizeof(used));
		if(((sc[i]&&(!hm[i]))||(!sc[i]))&&(!xyl(i))) return false;
	}
	return true;
}
bool wantbed(int x){return (sc[x]&&(!hm[x]))||(!sc[x]);}
int main()
{
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&sc[i]); 
		for(int i=1;i<=n;++i) scanf("%d",&hm[i]);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&k);
				if(i==j||(!k)) continue;
				if(wantbed(i)&&sc[j]) add(i,j+n),add(j+n,i);
				if(wantbed(j)&&sc[i]) add(j,i+n),add(i+n,j);
			}
			if(sc[i]&&(!hm[i])) add(i,i+n),add(i+n,i);
		}
		if(pipei()) puts("^_^");
		else puts("T_T");
	}
	return 0;
}
