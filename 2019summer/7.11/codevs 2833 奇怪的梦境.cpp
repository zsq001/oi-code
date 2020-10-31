#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#define maxn 10010
using namespace std;
int rd[maxn],head,tail,hl[maxn],q[maxn],cnt,n,m;
struct edge{
	int u,v,next;
}e[3*maxn];
void add(int u,int v)
{
	rd[v]++;
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=hl[u];
	hl[u]=cnt;
}
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;++i) if(!rd[i]) q[++tail]=i;
	while(tail!=head){
		int x=q[++head];
		for(int i=hl[x];i;i=e[i].next)
		{
			int v=e[i].v;
			rd[v]--;
			if(!rd[v]) q[++tail]=v;
		}
	}
	if(tail<n) printf("T_T\n%d",n-tail);
	else printf("o(กษ_กษ)o\n");
	return 0;
}
