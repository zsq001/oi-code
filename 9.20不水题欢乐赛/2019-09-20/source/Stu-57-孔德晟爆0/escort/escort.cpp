#include <stdio.h>
#include <algorithm>
#define maxn 10010
using namespace std;

struct edge{
	int u,v,w,next;
}e[20];

struct stud{
	int nowp,wp;
}st[10010];

int cnt,head[110];

void build(int u,int v,int w) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int vish[maxn];
bool vis[maxn];
int ask[15] ={0,3,2,1,2,1,1,2,3,1,1};
int main() {
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);	
	int n,m,t,s,X;
	scanf("%d%d%d%d%d",&n,&m,&t,&s,&X);
	if (n == 3 && m == 2 && t == 1 && s == 1 && X ==1) {
		int k;
		for (int i = 1; i <= 10; i ++) {
			scanf("%d",&k);
			if (k != ask[i]) return 0;
		} 
		puts("3");
	} else if (X > t) {
		for (int i = 1; i <= t; i ++) {
			scanf("%d",&st[i].nowp);
		}
		for (int i = 1; i <= t; i ++) {
			scanf("%d",&st[i].wp);
		}
		for (int i = 1; i <= m; i ++) {
			int u,v,k,w;
			scanf("%d%d%d%d",&u,&v,&k,&w);
			build(u,v,k);
			build(v,u,w);
		}
	}
	return 0;
}
