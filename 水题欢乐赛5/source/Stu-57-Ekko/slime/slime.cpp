#include <stdio.h>
#define maxn 500010
struct edge{
	int u,v,next;
}e[maxn<<2];
int n,m,op;
int head[maxn],cnt,in[maxn],out[maxn],jh[maxn];
void add(int u,int v) {
	if(op == 2) {
		out[u] ++;
		in[v] ++;
	}
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = ++cnt;
}
int main() {
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
	scanf("%d%d%d",&n,&m,&op);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	
	if (op == 1) {
		
	} else if (op == 2) {
		
	}
	return 0;
}
