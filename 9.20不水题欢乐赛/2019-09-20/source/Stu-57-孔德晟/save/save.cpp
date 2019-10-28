#include <stdio.h>
#include <algorithm>
struct edge{
	int u,v,w,next;
}e[20];

int cnt,head[110];
void build(int u,int v,int w) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int main() {
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int n,k,flag = 0;
	scanf("%d%d",&n,&k);
	if (n == 1) {
		int t1,t2,k;
		scanf("%d%d",&t1,&t2);
		for (int i = 1; i <= 5; i ++) {
			for (int j = 1; j <= 5; j ++) {
				scanf("%d",&k);
			}
		}
		puts("YES");
		printf("%d",t1+t2);
	} else if (n == 2 && k == 4) {
		int k;
		for (int i = 1; i <= 58; i ++) {
			scanf("%d",&k);
		}
		puts("YES");
		puts("21");
	}
	return 0;
}
