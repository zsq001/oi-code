#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct edge{
	int u,v,next;
}e[2010];
int val[2010],vis[2010];
int pazi[2010];
int head[2010],cnt;

void add(int u,int v) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int main () {
	int T;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&val[i]);
			pazi[i] = val[i];
		}
		sort(pazi+1,pazi+1+n);		
		for (int i = 1; i < n; i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		sort(val+1,val+1+n);
		for(int i = 1; i <= n; i++) {
			printf("%d ",val[i]);
		}
	}
	return 0;
}
